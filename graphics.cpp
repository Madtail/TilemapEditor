#include "graphics.h"
#include "editor.h"
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Graphics::tile default = {};

Graphics::Graphics()
{	
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &this->_window, &Editor::renderer);
	SDL_SetWindowTitle(this->_window, "Tilemap Editor");
	SDL_SetRenderDrawColor(Editor::renderer, 255, 255, 255, 255);
	_textures.insert(std::pair<std::string, tile>());
}

Graphics::~Graphics()
{
	
}

/*SDL_Surface* Graphics::loadTexture(std::string &filepath)
{
	
}*/

void Graphics::blitTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(Editor::renderer, texture, sourceRectangle, destinationRectangle);
}

SDL_Rect Graphics::getSize(SDL_Texture* texture) {
	SDL_Rect size;
	SDL_QueryTexture(texture, NULL, NULL, &size.w, &size.h);
	return size;
}



void Graphics::flip()
{
	SDL_RenderPresent(Editor::renderer);
}

void Graphics::drawTiles()
{

}