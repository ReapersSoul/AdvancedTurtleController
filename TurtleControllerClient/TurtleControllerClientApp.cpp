#include "TurtleControllerClientApp.h"

wxIMPLEMENT_APP(TurtleControllerClientApp);

bool TurtleControllerClientApp::OnInit()
{
	mp = new TurtleControllerGui();
	mp->Show();
	return true;
}
