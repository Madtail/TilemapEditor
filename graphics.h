/*
File containing all graphical functions: Window, rendering, drawing, etc. Underscores (_) mean private.
*/
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <iostream>
#include <map>
#include <vector>

class Graphics
{
public:

	Graphics();
	~Graphics();

	// Load image function
	SDL_Surface* loadTexture(std::string &filepath);

	// Draw image on specified area of the screen
	void blitTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	// Get the width and height of a texture
	SDL_Rect getSize(SDL_Texture* texture);

	// Flip the drawn stuff from the back buffer to the front buffer
	void flip();
	
	// Clear the screen
	void clear();

	void drawTiles();

	// tile type
	typedef struct tile{
		SDL_Texture* texture;
		SDL_Rect* location;
	} tile;

	// Data structure with all textures used on tiles
	std::map<std::string, tile> _textures;

	// One row with all textures
	std::vector<SDL_Rect> row;

	// All rows that need to be drawn
	std::vector<int> rows;

private:

	SDL_Window* _window;

};

#endif // !GRAPHICS_H


