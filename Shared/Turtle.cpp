#include "Turtle.h"

Turtle::Turtle(boost::beast::websocket::stream<tcp::socket>* wSock):Computer::Computer(wSock)
{
	IsTurtle = true;
	std::cout << "Computer " << ID << " Is Turtle." << std::endl;
}

Turtle::~Turtle()
{
}

void Turtle::Forward()
{
	Send("Command");
	Send("turtle.forward()");
}

void Turtle::Backward()
{
	Send("Command");
	Send("turtle.back()");
}

void Turtle::Up()
{
	Send("Command");
	Send("turtle.up()");
}

void Turtle::Down()
{
	Send("Command");
	Send("turtle.down()");
}

void Turtle::TurnLeft()
{
	Send("Command");
	Send("turtle.turnLeft()");
}

void Turtle::TurnRight()
{
	Send("Command");
	Send("turtle.turnRight()");
}

float Turtle::GetFuelLevel()
{
	Send("Command");
	Send("print(turtle.getFuelLevel())");
	float Level =atof(PopRecvData().c_str());
	return Level;
}
float Turtle::GetFuelLimit()
{
	Send("Command");
	Send("print(turtle.getFuelLimit())");
	float Limit =atof(PopRecvData().c_str());
	return Limit;
}

Turtle::ItemSlot* Turtle::GetInventory()
{
	for (int i = 1; i < 17; i++)
	{
		ItemSlot IS;
		Send("Command");
		Send("print(turtle.getItemDetail(" + std::to_string(i) + ",true).count)");
		IS.count = atoi(PopRecvData().c_str());
		Send("Command");
		Send("print(turtle.getItemDetail(" + std::to_string(i) + ",true).name)");
		IS.id = PopRecvData().c_str();
		if (IS.id[0] == 'E'|| IS.id[1] == 'R'|| IS.id[2] == 'R'|| IS.id[3] == 'O'|| IS.id[4] == 'R') {
			IS.id = "Nil";
		}
		Inventory[i] = IS;
	}


	return Inventory;
}

Turtle::ItemSlot Turtle::GetEquipedLeft()
{
	
	Send("Command");
	Send("print(turtle.drop())");
	std::string Dropped = PopRecvData();
	Send("Command");
	Send("print(turtle.equipLeft())");
	std::string Equiped = PopRecvData();
	std::stringstream equipedreturn(Equiped);
	std::string Token;
	std::getline(equipedreturn, Token, '\t');
	if (Token == "true") {
		Send("Command");
		Send("print(turtle.getItemDetail(1,true).count)");
		EquipedLeft.count = atoi(PopRecvData().c_str());
		Send("Command");
		Send("print(turtle.getItemDetail(1,true).name)");
		EquipedLeft.id = PopRecvData().c_str();
		if (EquipedLeft.id[0] == 'E' || EquipedLeft.id[1] == 'R' || EquipedLeft.id[2] == 'R' || EquipedLeft.id[3] == 'O' || EquipedLeft.id[4] == 'R') {
			EquipedLeft.id = "Nil";
		}
		Send("Command");
		Send("print(turtle.equipLeft())");
		Equiped = PopRecvData();
		equipedreturn = std::stringstream(Equiped);
		std::getline(equipedreturn, Token, '\t');
		if (Token == "false") {
			std::cout << "couldnt Requip" << std::endl;
		}
	}
	if (Dropped == "true") {
		Send("Command");
		Send("print(turtle.suck())");
		std::string Sucked = PopRecvData();
	}

	return EquipedLeft;
}

Turtle::ItemSlot Turtle::GetEquipedRight()
{
	Send("Command");
	Send("turtle.drop()");
	bool dropped = (atoi(PopRecvData().c_str()));
	Send("Command");
	Send("turtle.equipRight()");
	if (PopRecvData() == "") {
		Send("Command");
		Send("print(turtle.getItemDetail(1,true).count)");
		EquipedRight.count = atoi(PopRecvData().c_str());
		Send("Command");
		Send("print(turtle.getItemDetail(1,true).name)");
		EquipedRight.id = PopRecvData().c_str();
		if (EquipedRight.id[0] == 'E' || EquipedRight.id[1] == 'R' || EquipedRight.id[2] == 'R' || EquipedRight.id[3] == 'O' || EquipedRight.id[4] == 'R') {
			EquipedRight.id = "Nil";
		}
		Send("Command");
		Send("turtle.equipRight()");
	}
	if (dropped) {
		Send("Command");
		Send("turtle.suck()");
		PopRecvData().c_str();
	}

	return EquipedRight;
}
