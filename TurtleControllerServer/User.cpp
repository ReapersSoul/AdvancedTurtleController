#include "User.h"

void User::recvThread_f()
{
	bool stayOpen = true;
	while (stayOpen) {
		try {
			boost::beast::flat_buffer buffer;
			ws->read(buffer);
			std::cout <<"User "<<ID<<": " << boost::beast::buffers_to_string(buffer.cdata()) << std::endl;
			if (boost::beast::buffers_to_string(buffer.cdata())=="SelectComputer") {
				buffer.clear();
				ws->read(buffer);
				SelectComputer(atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str()));
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="ListComputers") {
				ListComputers();
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="Close") {
				//close connection
				std::cout << "User " << ID << " Disconnected!" << std::endl;
				//close socket somehow
				//ws->close(boost::beast::websocket::close_code::normal);
				Users->erase(ID);
				stayOpen = false;
				//std::thread([](std::map<std::string, User*>* users) {users->erase(ID); },Users);
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="GetSelectedComp") {
				ws->write(boost::asio::buffer(std::to_string(selectedComp)));
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="Command") {
				buffer.clear();
				ws->read(buffer);
				bool isshell = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
				buffer.clear();
				ws->read(buffer);
				std::string cmd = boost::beast::buffers_to_string(buffer.cdata());
				SendCommand(cmd, isshell);
				std::cout << std::endl;
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="GetStatus") {
				GetStatus();
			}
			else if (boost::beast::buffers_to_string(buffer.cdata())=="GetInventory") {
				Turtle::ItemSlot * inv = ((Turtle*)computers->find(selectedComp)->second.comp)->GetInventory();
				for (int i = 1; i < 17; i++)
				{
					ws->write(boost::asio::buffer(std::to_string((*(inv + i)).count)));
					ws->write(boost::asio::buffer((*(inv + i)).id));
					
				}
				Turtle::ItemSlot Left = ((Turtle*)computers->find(selectedComp)->second.comp)->GetEquipedLeft();
				Turtle::ItemSlot Right = ((Turtle*)computers->find(selectedComp)->second.comp)->GetEquipedRight();
				ws->write(boost::asio::buffer(std::to_string(Left.count)));
				ws->write(boost::asio::buffer(Left.id)); 
				ws->write(boost::asio::buffer(std::to_string(Right.count)));
				ws->write(boost::asio::buffer(Right.id));
			}
			else{
				
			}
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
			break;
		}
	}
}

void User::SelectComputer(int id)
{
	if (computers->find(id) != computers->end()) {
		if (selectedComp != -1) {
			computers->find(selectedComp)->second.InUse = false;
		}
		selectedComp = id;
		computers->find(selectedComp)->second.InUse = true;
	}
	else {
		ws->write(boost::asio::buffer("Not Availible."));
	}
}

void User::ListComputers()
{
	ws->write(boost::asio::buffer(std::to_string(computers->size())));
	for (std::map<int, ComputerAvalibilityInfo>::iterator it = computers->begin(); it != computers->end(); it++) {
		ws->write(boost::asio::buffer(std::to_string(it->second.comp->IsATurtle())));
		ws->write(boost::asio::buffer(std::to_string(it->second.comp->GetID())));
	}
}

void User::SendCommand(std::string cmd, bool IsShellCmd)
{
	if (computers->find(selectedComp) != computers->end()) {
		if (!IsShellCmd) {
			computers->find(selectedComp)->second.comp->Send("Command");
			computers->find(selectedComp)->second.comp->Send(cmd);
			ws->write(boost::asio::buffer(computers->find(selectedComp)->second.comp->PopRecvData()));
		}
		else {
			computers->find(selectedComp)->second.comp->Send("Shell");
			computers->find(selectedComp)->second.comp->Send(cmd); 
			ws->write(boost::asio::buffer(computers->find(selectedComp)->second.comp->PopRecvData()));
			ws->write(boost::asio::buffer(computers->find(selectedComp)->second.comp->PopRecvData()));
		}		
	}
}

void User::GetStatus()
{
	if (computers->find(selectedComp) != computers->end()) {
		if (computers->find(selectedComp)->second.comp->IsATurtle()) {
			ws->write(boost::asio::buffer(std::to_string(((Turtle*)computers->find(selectedComp)->second.comp)->GetFuelLevel())));
			ws->write(boost::asio::buffer(std::to_string(((Turtle*)computers->find(selectedComp)->second.comp)->GetFuelLimit())));
		}
	}
}

User::User(boost::beast::websocket::stream<tcp::socket> * wSock, std::map<int, ComputerAvalibilityInfo>* comps, std::map<std::string,User*>* users){
	Users = users;
	selectedComp = -1;
	ws = wSock;
	computers = comps;
	boost::beast::flat_buffer buffer;
	ws->read(buffer);
	ID = boost::beast::buffers_to_string(buffer.cdata()).c_str();
	if (users->find(ID) == users->end()) {
		users->insert(std::pair<std::string,User*>(ID, this));
		recvThread = std::thread(&User::recvThread_f, this);
		std::cout << "User " << ID << " Connected." << std::endl;
	}
	else {
		std::cout << "User " << ID << " Already Exists." << std::endl;
		ws->write(boost::asio::buffer("User "+ID+" Already Exists.\n"));
	}

}

User::~User()
{
}
