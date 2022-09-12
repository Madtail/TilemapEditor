#ifndef MAP_H
#define MAP_H


/*	Draw array of tiles based on input. 
	The input is the width of tiles and the height of tiles, columns = width, rows = height.
	Every element is a tile with a key from the std::map template. The key is the name of 
	the texture. With keys you can select the name/key with the corresponding texture you
	want. When a texture is imported to the program, input the key for the texture,
	then it is added to the std::map. The elements of std::map are displayed on screen as names.
	Texture is selected by input, the key is input to a function for getting the corresponding texture.
	Texture can be inputed with the mouse on a grid. Always check which tile the mouse pointer is in
	to know where to place the tile. Pointer to the [row][column]. 
*/

class Map
{
public:

	Map();
	~Map();

	void createTilemap();

private:




};


#endif // !MAP_H