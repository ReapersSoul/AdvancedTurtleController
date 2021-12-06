#pragma once
#include <iostream>
#include <map>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;
#include "../Shared/ComputerCraft.h"


class User {
	std::string ID;
	boost::beast::websocket::stream<tcp::socket> * ws;
	std::thread recvThread;
	std::map<int, ComputerAvalibilityInfo>* computers;
	std::map<std::string, User*>* Users;
	int selectedComp;

	void recvThread_f();
public:

	void SelectComputer(int id);
	void ListComputers();
	void SendCommand(std::string cmd, bool IsShellCmd);
	void GetStatus();

	User(boost::beast::websocket::stream<tcp::socket> * wSock, std::map<int, ComputerAvalibilityInfo>* comps, std::map<std::string, User*>* users);
	~User();
};