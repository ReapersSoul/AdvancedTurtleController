#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include "GUI.h"
#include <iostream>
#include <sstream>
#include <fstream>

#include <filesystem>
#include <wx/glcanvas.h>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

//create glpane and glcontext for world rendering




class TurtleControllerGui :public MainFrame
{
protected:
	std::string eraseAllSubStr(std::string mainStr,std::string toErase)
	{
		std::string tmp = mainStr;
		size_t pos = std::string::npos;
		// Search for the substring in string in a loop untill nothing is found
		while ((pos = tmp.find(toErase)) != std::string::npos)
		{
			// If found then erase it from string
			tmp.erase(pos, toErase.length());
		}
		return tmp;
	}
	bool Connected = false;
	std::string ip;
	std::string port;
	std::string UID;
	int icoWidth = 72;
	int icoHeight = 72;

	// The io_context is required for all I/O
	net::io_context ioc;
	std::vector<wxStaticText> LuaHistoryText;

	// These objects perform our I/O
	tcp::resolver resolver{ ioc };


	std::string getAssetPath(std::string id);

	void TabChanged(wxNotebookEvent& event);
	void OnClose(wxCloseEvent& event);
	void OnTextChanged(wxCommandEvent& event);

	struct KeywordSet {
		wxColour color;
		std::vector<std::string> tokens;
	};

	std::vector<KeywordSet> keysets;

	bool editingCompFile=false;

	bool Destroy();
	void ExecuteCommand(wxCommandEvent& event);
	void SelectComputer(wxCommandEvent& event);
	void ConnectServer(wxCommandEvent& event);
	void OnEditorSave(wxCommandEvent& event);
	void LocalFileRunOnClick(wxCommandEvent& event);
	void LocalFileUploadOnClick(wxCommandEvent& event);
	void LocalFileEditOnClick(wxCommandEvent& event);
	void CompFilesRun(wxCommandEvent& event);
	void CompFilesDownload(wxCommandEvent& event);
	void CompFilesEdit(wxCommandEvent& event);
public:
	websocket::stream<tcp::socket> ws{ ioc };
	void SelectComputer(int id);
	void ListComputers();
	void SendCommand(std::string cmd, bool IsShellCmd);
	void GetStatus();
	TurtleControllerGui();
	~TurtleControllerGui();
	void Disconect() {};
};