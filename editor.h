#ifndef EDITOR_H
#define EDITOR_H

#include <SDL.h>

#include "graphics.h"
#include "input.h"

class Editor
{
public:

	Editor();
	~Editor();

	static SDL_Renderer* renderer;

	// Function containing the program loop
	void editorLoop();

	// Function for drawing everything
	void draw(Graphics& graphics);

	// Function for updating every frame
	void update();

private:
	
};


#endif // !EDITOR_H