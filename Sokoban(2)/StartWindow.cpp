#include "Forms_headers/FormWin.h"
#include "Forms_headers/Level_1.h"
#include "Forms_headers/StartWindow.h"

using namespace Sokoban2;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew StartWindow());

	return 0;
}

