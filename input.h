#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Input
{
public:

	void mouseInput();


	int mouse_x, mouse_y;

private:

	Uint32 buttons;


};

#endif // !INPUT_H