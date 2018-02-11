#pragma once
#include <SDL.h>

class Display
{
	SDL_Window * window;
	SDL_Renderer * renderer;
public:
	bool shouldClose = false;
	Display();
	~Display();

	void pollEvents();
	void swapBuffers();

};