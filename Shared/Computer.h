#pragma once
#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;
class Computer
{
protected:
	int ID;
	bool IsTurtle;
	boost::beast::websocket::stream<tcp::socket> * ws;

	std::vector<std::string> recvData;
	std::thread recvThread;

	void recvThread_f();
public:
	Computer(boost::beast::websocket::stream<tcp::socket> * wSock);
	~Computer();

	void Send(std::string str) {
		ws->write(boost::asio::buffer(str));
	}
	std::string PopRecvData();
	int RecvDataSize();
	bool IsATurtle();
	int GetID();

};

