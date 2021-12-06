#include "Computer.h"

void Computer::recvThread_f()
{
	while (true) {
		try {
			boost::beast::flat_buffer buffer;
			ws->read(buffer);
			std::cout << "Computer " << ID << ":" << boost::beast::buffers_to_string(buffer.cdata()) << std::endl;
			recvData.push_back(boost::beast::buffers_to_string(buffer.cdata()));
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
			break;
		}
	}
}

Computer::Computer(boost::beast::websocket::stream<tcp::socket> * wSock){
	IsTurtle = false;
	ws = wSock;
	boost::beast::flat_buffer buffer;
	ws->read(buffer);
	ID = atoi(boost::beast::buffers_to_string(buffer.cdata()).c_str());
	recvThread = std::thread(&Computer::recvThread_f,this);
	std::cout << "Computer " << ID << " Connected." << std::endl;
}

Computer::~Computer() {
}

std::string Computer::PopRecvData()
{
	while (recvData.empty()) {
		
	}
	std::string tmp = recvData[recvData.size() - 1];
	recvData.pop_back();
	return tmp;
}

int Computer::RecvDataSize()
{
	return recvData.size();
}

bool Computer::IsATurtle()
{
    return IsTurtle;
}

int Computer::GetID() {
	return ID;
}