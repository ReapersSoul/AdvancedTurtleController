// TurtleServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <map>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include "../ComputerCraft.h"
#include "User.h"



std::map<int, ComputerAvalibilityInfo> CompAvalibility;
std::map<std::string, User*> users;

using tcp = boost::asio::ip::tcp;

int main()
{
	boost::asio::ip::address addr = boost::asio::ip::make_address("127.0.0.1");
	unsigned short port = static_cast<unsigned short>(std::atoi("8083"));

	boost::asio::io_context ioc{1};

	tcp::acceptor acceptor{ ioc,{addr,port } };

	while (true)
	{
		tcp::socket socket{ ioc };
		acceptor.accept(socket);
		std::cout << "sockaccept" << std::endl;

		ComputerAvalibilityInfo cai;

		boost::beast::websocket::stream<tcp::socket> ws{ std::move(const_cast<tcp::socket&>(socket)) };
		boost::beast::flat_buffer buffer;
		ws.read(buffer);
		if (boost::beast::buffers_to_string(buffer.cdata())=="Computer") {
			cai.comp = new Computer{ std::move(const_cast<boost::beast::websocket::stream<tcp::socket>&>(ws)) };

			if (CompAvalibility.find(cai.comp->GetID()) != CompAvalibility.end()) {
				CompAvalibility.insert(std::pair<int, ComputerAvalibilityInfo>(cai.comp->GetID(), cai));
			}
		}
		else if(boost::beast::buffers_to_string(buffer.cdata()) == "User"){
			User h{ std::move(const_cast<boost::beast::websocket::stream<tcp::socket>&>(ws)),&CompAvalibility, &users};
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
