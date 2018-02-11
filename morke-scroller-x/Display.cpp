#include "Display.hpp"
#include "Config.hpp"

Display::Display()
{
	Config& c = Config::getInstance();
	int flags = SDL_WINDOW_OPENGL;
	flags = c.getValue<bool>("fullscreen") ? (flags | SDL_WINDOW_FULLSCREEN) : flags;
	flags = c.getValue<bool>("borderless") ? (flags | SDL_WINDOW_BORDERLESS) : flags;
	int disp = c.getValue<int>("display");
	window = SDL_CreateWindow("Pipo", SDL_WINDOWPOS_CENTERED_DISPLAY(disp), SDL_WINDOWPOS_CENTERED_DISPLAY(disp), c.getValue<int>("width"), c.getValue<int>("height"), flags);
	int rendererFlags = SDL_RENDERER_ACCELERATED;
	rendererFlags = c.getValue<bool>("vsync") ? (rendererFlags | SDL_RENDERER_PRESENTVSYNC) : rendererFlags;
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	SDL_SetWindowResizable(window, SDL_bool::SDL_FALSE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, c["antialiasing"].c_str());
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
