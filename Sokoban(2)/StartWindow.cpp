#include "Level_1.h"
#include "StartWindow.h"

using namespace Sokoban2;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew StartWindow());

	Application::Run(gcnew Level_1());

	return 0;
}

