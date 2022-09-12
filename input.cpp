#include <SDL.h>

#include "input.h"



void Input::mouseInput()
{

	buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

	SDL_Log("Mouse cursor is at %d, %d", mouse_x, mouse_y);
	if ((buttons & SDL_BUTTON_LMASK) != 0) {
		SDL_Log("Mouse Button 1 (left) is pressed.");
	}
}