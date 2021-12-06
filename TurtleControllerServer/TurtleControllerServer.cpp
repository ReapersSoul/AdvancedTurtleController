// TurtleServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <map>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include "../Shared/ComputerCraft.h"
#include "User.h"

std::vector< boost::beast::websocket::stream<tcp::socket>*> sockets;
std::map<int, ComputerAvalibilityInfo> CompAvalibility;
std::map<std::string, User*> users;

using tcp = boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	if (argc < 3) {
		return -1;
	}
	std::cout << "Starting server on IP: " << argv[1] << " Port: " << argv[2] << std::endl;
	boost::asio::ip::address addr = boost::asio::ip::make_address(argv[1]);
	unsigned short port = static_cast<unsigned short>(std::atoi(argv[2]));

	boost::asio::io_context ioc{ 1 };

	tcp::acceptor acceptor{ ioc,{addr,port } };

	while (true)
	{
		tcp::socket socket{ ioc };
		acceptor.accept(socket);
		std::cout << "sockaccept" << std::endl;

		ComputerAvalibilityInfo cai;
		
		sockets.push_back(new boost::beast::websocket::stream<tcp::socket>{ std::move(const_cast<tcp::socket&>(socket)) });
		sockets[sockets.size() - 1]->accept();
		boost::beast::flat_buffer buffer;
		sockets[sockets.size() - 1]->read(buffer);

		if (boost::beast::buffers_to_string(buffer.cdata()) == "Computer") {
			cai.comp = new Computer(sockets[sockets.size()-1]);

			if (CompAvalibility.find(cai.comp->GetID()) == CompAvalibility.end()) {
				CompAvalibility.insert(std::pair<int, ComputerAvalibilityInfo>(cai.comp->GetID(), cai));
			}
		}
		else if (boost::beast::buffers_to_string(buffer.cdata()) == "Turtle") {
			cai.comp = new Turtle(sockets[sockets.size() - 1]);

			if (CompAvalibility.find(cai.comp->GetID()) == CompAvalibility.end()) {
				CompAvalibility.insert(std::pair<int, ComputerAvalibilityInfo>(cai.comp->GetID(), cai));
			}
		}
		else if (boost::beast::buffers_to_string(buffer.cdata()) == "User") {
			new User(sockets[sockets.size() - 1],&CompAvalibility, &users);
		}
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
