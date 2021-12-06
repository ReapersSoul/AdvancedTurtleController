#include "TurtleControllerGui.h"

void TurtleControllerGui::OnClose(wxCloseEvent& event)
{
	Destroy();  // you may also do:  event.Skip();
				// since the default event handler does call Destroy(), too
}
void TurtleControllerGui::OnTextChanged(wxCommandEvent& event)
{
	//std::string text = RichText->GetValue().ToStdString();
	//while(RichText->is)
	//RichText->WriteText("hia");

}
bool TurtleControllerGui::Destroy()
{
	if (Connected) {
		ws.write(boost::asio::buffer(std::string("Close")));
	}
	return wxFrame::Destroy();
}


void TurtleControllerGui::ExecuteCommand(wxCommandEvent& event)
{
	if (CommandTypeSelector->GetStringSelection().ToStdString() == "Lua") {
		SendCommand(Commandfeild->GetValue().ToStdString(), false);
	}
	else if (CommandTypeSelector->GetStringSelection().ToStdString() == "Shell") {
		SendCommand(Commandfeild->GetValue().ToStdString(), true);
	}

	// This buffer will hold the incoming message
	beast::flat_buffer buffer;

	// Read a message into our buffer
	ws.read(buffer);

	std::string ntmp = boost::beast::buffers_to_string(buffer.cdata());

	wxStaticText * tmp= new wxStaticText(LuaHistoryHolder, wxID_ANY, boost::beast::buffers_to_string(buffer.cdata()));

	tmp->SetSize(wxSize(tmp->GetSize().x,20));
	LuaHistory->Add(tmp,0,wxALIGN_TOP);

	if (CommandTypeSelector->GetStringSelection().ToStdString() == "Shell") {
		buffer.clear();
		ws.read(buffer);


		tmp = new wxStaticText(LuaHistoryHolder, wxID_ANY, boost::beast::buffers_to_string(buffer.cdata()));

		tmp->SetSize(wxSize(tmp->GetSize().x, 20));
		LuaHistory->Add(tmp, 0, wxALIGN_TOP);
	}

	LuaHistory->Layout();
	LuaHistoryHolder->FitInside();

	event.Skip();
}

void TurtleControllerGui::ConnectServer(wxCommandEvent& event)
{
	try {
		ip = IPfeild->GetValue().ToStdString();
		port = Portfeild->GetValue().ToStdString();
		UID = UIDfeild->GetValue().ToStdString();
		// Look up the domain name
		auto const results = resolver.resolve(ip, port);
		// Make the connection on the IP address we get from a lookup
		net::connect(ws.next_layer(), results.begin(), results.end());

		// Set a decorator to change the User-Agent of the handshake
		ws.set_option(websocket::stream_base::decorator(
			[](websocket::request_type& req)
			{
				req.set(http::field::user_agent,
					std::string(BOOST_BEAST_VERSION_STRING) +
					" websocket-client-coro");
			}));

		// Perform the websocket handshake
		ws.handshake(ip, "/");
		ws.write(boost::asio::buffer(std::string("User")));
		ws.write(boost::asio::buffer(UID));
		ConnStatus->SetLabelText("Connected!");
		Connected = true;
	}
	catch (std::exception e) {
		ConnStatus->SetLabelText(e.what());
	}

	event.Skip();
}

void TurtleControllerGui::OnEditorSave(wxCommandEvent& event)
{
	if(editingCompFile){
		std::string path = EditorFile->GetPath().ToStdString();
		std::string data = RichText->GetValue().ToStdString();
		std::string ModData = "";
		for (std::string::iterator i = data.begin(); i != data.end(); i++)
		{
			switch (*i)
			{
			case '\n':
				ModData.push_back('\\');
				ModData.push_back('n');
				break;
			case '\\':
				ModData.push_back('\\');
				ModData.push_back('\\');
				break;
			default:
				ModData.push_back(*i);
				break;
			}
		}
		SendCommand("file=fs.open(\"" +path + "\",\"w\")\nfile.write(\'"+ModData+"\')\nfile.close()", false);
		beast::flat_buffer buffer;
		ws.read(buffer);
	}
	else {
		std::string path = EditorFile->GetPath().ToStdString();
		std::ofstream out(path);
		out.write(RichText->GetValue(), RichText->GetValue().size());
		out.close();
	}
}

void TurtleControllerGui::LocalFileRunOnClick(wxCommandEvent& event)
{
	std::string path =LocalFileFilePicker->GetPath().ToStdString();
	std::ifstream in(path);
	std::string filedata((std::istreambuf_iterator<char>(in)),(std::istreambuf_iterator<char>()));
	SendCommand(filedata, false);
	beast::flat_buffer buffer;
	ws.read(buffer);
}

void TurtleControllerGui::LocalFileUploadOnClick(wxCommandEvent& event)
{
	std::string path = LocalFileFilePicker->GetPath().ToStdString();
	std::ifstream in(path);
	std::string filedata((std::istreambuf_iterator<char>(in)), (std::istreambuf_iterator<char>()));
	std::string ModData = "";
	for (std::string::iterator i = filedata.begin(); i != filedata.end(); i++)
	{
		switch (*i)
		{
		case '\n':
			ModData.push_back('\\');
			ModData.push_back('n');
			break;
		case '\\':
			ModData.push_back('\\');
			ModData.push_back('\\');
			break;
		default:
			ModData.push_back(*i);
			break;
		}
	}
	std::string cmd = "file=fs.open(\""+LocalFileFileNameText->GetValue().ToStdString()+"\",\"w\")\nfile.write(\"" + filedata + "\")\nfile.close()";
	SendCommand(cmd, false);
	beast::flat_buffer buffer;
	ws.read(buffer);
}

void TurtleControllerGui::LocalFileEditOnClick(wxCommandEvent& event)
{
	editingCompFile = false;
	std::string path = LocalFileFilePicker->GetPath().ToStdString();
	std::ifstream in(path);
	std::string filedata((std::istreambuf_iterator<char>(in)), (std::istreambuf_iterator<char>()));
	EditorFile->SetPath(path);
	NoteBook->SetSelection(3);
	RichText->Clear();
	RichText->WriteText(filedata);
}

void TurtleControllerGui::CompFilesRun(wxCommandEvent& event)
{
	std::string filename = CompFileDirList->GetStringSelection().ToStdString();
	filename.erase(filename.end() - 4, filename.end());
	SendCommand(filename, true);
	beast::flat_buffer buffer;
	ws.read(buffer);
	ws.read(buffer);
}

void TurtleControllerGui::CompFilesDownload(wxCommandEvent& event)
{
	std::string filename = CompFileDirList->GetStringSelection().ToStdString();
	std::string path =CompDownloadPicker->GetPath().ToStdString();
	SendCommand("file=fs.open(\"" + filename + "\",\"r\")\n filedata=file.readAll()\n_G.str=filedata\n", false);
	beast::flat_buffer buffer;
	ws.read(buffer);
	std::string filedata = boost::beast::buffers_to_string(buffer.cdata());
	std::ofstream out(path);
	out.write(filedata.c_str(), filedata.size());
	out.close();
}

void TurtleControllerGui::CompFilesEdit(wxCommandEvent& event)
{
	editingCompFile = true;
	std::string filename = CompFileDirList->GetStringSelection().ToStdString();
	std::string path = CompDownloadPicker->GetPath().ToStdString();
	SendCommand("file=fs.open(\"" + filename + "\",\"r\")\n filedata=file.readAll()\n_G.str=filedata\n", false);
	beast::flat_buffer buffer;
	ws.read(buffer);
	std::string filedata = boost::beast::buffers_to_string(buffer.cdata());
	EditorFile->SetPath(filename);
	NoteBook->SetSelection(3);
	RichText->Clear();
	RichText->WriteText(filedata);
}

void TurtleControllerGui::SendCommand(std::string cmd, bool IsShellCmd)
{
	ws.write(net::buffer(std::string("Command")));
	ws.write(boost::asio::buffer(std::to_string(IsShellCmd)));
	ws.write(net::buffer(cmd));
}

void TurtleControllerGui::GetStatus()
{
	beast::flat_buffer buffer;
	float FuelPercent;
	int FuelBlocks;
	int FuelLimit;
	//get status of computers and display
	ws.write(boost::asio::buffer(std::string("GetStatus")));
	ws.read(buffer);
	FuelBlocks = atof(boost::beast::buffers_to_string(buffer.cdata()).c_str());
	buffer.clear();
	ws.read(buffer);
	FuelLimit = atof(boost::beast::buffers_to_string(buffer.cdata()).c_str());
	if (FuelLimit != 0) {
		FuelPercent = FuelBlocks / FuelLimit;
	}
	else {
		FuelPercent = 0;
	}
	FuelText->SetLabelText("Fuel: %" + std::to_string(FuelPercent) + " Fuel in Blocks: " + std::to_string(FuelBlocks));
	FuelGauge->SetValue(FuelPercent);
}

std::string TurtleControllerGui::getAssetPath(std::string id)
{
	std::stringstream strem(id);
	std::string first;
	std::getline(strem, first, ':');
	std::string second;
	std::getline(strem, second, ':');
	return "Assets\\" + first + "\\" + second + ".png";
}

void TurtleControllerGui::TabChanged(wxNotebookEvent& event) {
	beast::flat_buffer buffer;
	int numComps;
	int count = 0;
	std::string id = "";
	std::string tmp;
	std::string files = boost::beast::buffers_to_string(buffer.cdata());
	std::stringstream stream(files);
	std::string File;
	std::vector<std::string> filelist;
	switch (event.GetSelection())
	{
	case 8:
		//display world view
		if (Connected) {
			ws.write(boost::asio::buffer(std::string("GetSelectedComp")));
			ws.read(buffer);
			if (atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()) != -1) {
				buffer.clear();
				
			}
		}
		break;
	case 2:
		if (Connected) {
			//ready computer for lua command input
			ws.write(boost::asio::buffer(std::string("GetSelectedComp")));
			ws.read(buffer);
			if (atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()) != -1) {
				buffer.clear();
				//code here
			}
		}
		break;
	case 6:
		if (Connected) {
			ws.write(boost::asio::buffer(std::string("GetSelectedComp")));
			ws.read(buffer);
			if (atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()) != -1) {
				buffer.clear();
				//get inventory and display
				ws.write(boost::asio::buffer(std::string("GetInventory")));
				for (int i = 0; i < 16; i++)
				{
					
					ws.read(buffer);
					count = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
					buffer.clear();
					ws.read(buffer);
					id = boost::beast::buffers_to_string(buffer.cdata());
					wxStaticText* label = nullptr;
					if (i == 0) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot1bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth, icoHeight)));
						}
						InvSlot1->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 1) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot2bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth, icoHeight)));
						}
						InvSlot2->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 2) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot3bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot3->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 3) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot4bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot4->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 4) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot5bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot5->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 5) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot6bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot6->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 6) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot7bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot7->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 7) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot8bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot8->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 8) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot9bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot9->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 9) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot10bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot10->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 10) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot11bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot11->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 11) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot12bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot12->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 12) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot13bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot13->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 13) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot14bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot14->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 14) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot15bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot15->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
					if (i == 15) {
						if (id != "Nil") {
							if (std::filesystem::exists(getAssetPath(id)))
								slot16bmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth,icoHeight)));
						}
						InvSlot16->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
					}
				}
				buffer.clear();
				ws.read(buffer);
				count = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
				buffer.clear();
				ws.read(buffer);
				id = boost::beast::buffers_to_string(buffer.cdata());
				if (id != "Nil") {
					if (std::filesystem::exists(getAssetPath(id)))
						EquipedLeftbmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth, icoHeight)));
				}
				EquippedLeftLabel->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
				buffer.clear();
				ws.read(buffer);
				count = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
				buffer.clear();
				ws.read(buffer);
				id = boost::beast::buffers_to_string(buffer.cdata());
				if (id != "Nil") {
					if (std::filesystem::exists(getAssetPath(id)))
						EquipedRightbmp->SetBitmap(wxBitmap(wxImage(getAssetPath(id)).Rescale(icoWidth, icoHeight)));
				}
				EquippedRightLabel->SetLabelText("ID: " + id + " Count: " + std::to_string(count));
			}
		}
		break;
	case 7:
		if (Connected) {
			ws.write(boost::asio::buffer(std::string("GetSelectedComp")));
			ws.read(buffer);
			if (atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()) != -1) {
				buffer.clear();
				GetStatus();
			}
		}
		break;
	case 1:
		if (Connected) {
			ComputersListBox->Clear();
			//load list of computers
			ws.write(boost::asio::buffer(std::string("ListComputers")));

			ws.read(buffer);
			numComps = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
			buffer.clear();
			for (int i = 0; i < numComps; i++)
			{
				ws.read(buffer);
				bool isTurtle = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
				buffer.clear();
				ws.read(buffer);
				int ID = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
				buffer.clear();
				if (isTurtle) {
					ComputersListBox->AppendString("Turtle " + std::to_string(ID));
				}
				else {
					ComputersListBox->AppendString("Computer " + std::to_string(ID));
				}

			}
		}
		break;
	case 0:
		//connect tab nothing to do here right now


		break;
	case 3:
		//editor tab nothing to do here right now


		break;
	case 4:
		//local files tab nothing to do here right now


		break;
	case 5:
		if (Connected) {
			ws.write(boost::asio::buffer(std::string("GetSelectedComp")));
			ws.read(buffer);
			if (atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()) != -1) {
				CompFileDirList->Clear();
				buffer.clear();
				//comp files tab
				SendCommand("ls", true);
				ws.read(buffer);
				buffer.clear();
				ws.read(buffer);
				files = boost::beast::buffers_to_string(buffer.cdata());
				stream = std::stringstream(files);
				while (std::getline(stream, File, '\n')) {
					filelist.push_back(File);
				}
				for (int i = 0; i < filelist.size(); i++) {
					CompFileDirList->AppendString(filelist[i]);
				}
			}
		}
		break;
	default:
		break;
	}
	event.Skip();
}
void TurtleControllerGui::SelectComputer(wxCommandEvent& event) {
	std::string selected = ComputersListBox->GetStringSelection().ToStdString();
	if (selected != "") {
		ws.write(boost::asio::buffer(std::string("SelectComputer")));
		std::stringstream stream(selected);
		std::string token;
		std::getline(stream, token, ' ');
		std::getline(stream, token, ' ');
		ws.write(boost::asio::buffer(token));
		ConnectedLabel->SetLabelText("Connected " + selected);
	}
}



TurtleControllerGui::TurtleControllerGui() : MainFrame(nullptr)
{
	wxInitAllImageHandlers();

	KeywordSet Objects;
	Objects.color = wxColour(40,255,162,255);
	Objects.tokens.push_back("turtle");
	Objects.tokens.push_back("computer");
	Objects.tokens.push_back("term");
	Objects.tokens.push_back("io");

	KeywordSet Functions;
	Functions.color = wxColour(234, 255, 40, 255);

	KeywordSet Variables;
	Variables.color = wxColour(192, 40, 255, 255);

	keysets.push_back(Objects);
	keysets.push_back(Functions);
	keysets.push_back(Variables);
}

TurtleControllerGui::~TurtleControllerGui()
{
}
