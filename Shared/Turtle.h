#pragma once
#include <string>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include "Computer.h"
#include <rapidjson/document.h>


class Turtle: public Computer
{
public:
	struct ItemSlot {
		std::string id;
		int count;
		std::string metaData;
	};
	Turtle(boost::beast::websocket::stream<tcp::socket>* wSock);
	~Turtle();
	void Forward();
	void Backward();
	void Up();
	void Down();
	void TurnLeft();
	void TurnRight();
	float GetFuelLevel();
	float GetFuelLimit();
	ItemSlot* GetInventory();
	ItemSlot GetEquipedLeft();
	ItemSlot GetEquipedRight();

protected:
	ItemSlot Inventory[16];
	ItemSlot EquipedRight;
	ItemSlot EquipedLeft;
};

