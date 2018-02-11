#include "Display.hpp"
#include "Config.hpp"

Display::Display()
{
	Config& c = Config::getInstance();
	int flags = SDL_WINDOW_OPENGL;
	flags = c.getValue<bool>("fullscreen") ? (flags | SDL_WINDOW_FULLSCREEN) : flags;
	flags = c.getValue<bool>("borderless") ? (flags | SDL_WINDOW_BORDERLESS) : flags;

	window = SDL_CreateWindow("Pipo", 100, 100, c.getValue<int>("width"), c.getValue<int>("height"), flags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
}

Display::~Display()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Display::pollEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EventType::SDL_QUIT:
			shouldClose = true;
			break;
		}
	}
}

void Display::swapBuffers()
{
	SDL_RenderPresent(renderer);
}
