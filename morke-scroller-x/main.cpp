#include "Display.hpp"
#undef main
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

int main()
{
	Display d;
	while (!d.shouldClose)
	{
		// Input
		d.pollEvents();



		// Swap Buffers
		d.swapBuffers();
	}
}