#include "editor.h"
#include <SDL_image.h>
#include <iostream>


SDL_Renderer* Editor::renderer;

Editor::Editor()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	int imgFlags = IMG_INIT_PNG;
	IMG_Init((imgFlags) & imgFlags);
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else {
		this->editorLoop();
	}

}

Editor::~Editor()
{

}

void Editor::editorLoop()
{
	Graphics graphics;
	SDL_Event event;
	Input input;

	SDL_Surface* image_surface;
	SDL_Texture* image_texture;

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	
	const char* path = "../media/test.png";
	image_surface = IMG_Load(path);
	if (image_surface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}

	image_texture = SDL_CreateTextureFromSurface(renderer, image_surface);
	SDL_FreeSurface(image_surface);

	SDL_Rect srcrect = graphics.getSize(image_texture);
	SDL_Rect destrect;

	srcrect.x = destrect.x = 50;
	srcrect.y = destrect.y = 50;
	destrect.w = 32;
	destrect.h = 32;
	
	graphics.blitTexture(image_texture, &srcrect, &destrect);
	graphics.flip();

	while(1) {
		frameStart = SDL_GetTicks();
	//--------------------------------
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
				return;
			}
		}
		
		input.mouseInput();
		

		//----------------------------
		frameTime = SDL_GetTicks();
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

}