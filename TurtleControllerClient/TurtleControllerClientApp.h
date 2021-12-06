#pragma once
#include "TurtleControllerGui.h"
#include <wx/wx.h>
#include <thread>


class TurtleControllerClientApp : public wxApp
{
	TurtleControllerGui* mp;
public:
	TurtleControllerClientApp() {};
	~TurtleControllerClientApp() {};
	virtual bool OnInit();
};

