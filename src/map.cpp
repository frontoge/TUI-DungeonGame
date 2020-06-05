#include "map.hpp"

#include <fstream>

///Constructors

//Default Constructor
Map::Map()
:length(0), width(0)
{
    tiles = nullptr;
}

//Load map from data file
Map::Map(const std::string& path)
{
    //create ifstream
    std::ifstream fin(path);

    //read in length and width parameters
    fin >> length >> width;

    //allocate memory for the tiles
    tiles = new char[length * width];

    //populate the tiles
    for (int y = 0; y < length; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fin >> tiles[width * y + x];
        }
    }

    //close ifstream
    fin.close();
}

//Copy Constructor
Map::Map(const Map& old)
{
    //Get the length and width properties from the other object
    length = old.length;
    width = old.width;
    
    //Allocate new memory for the tiles to prevent a shallow copy
    tiles = new char[length * width];

    //Copy data from other objects map in
    for (int y = 0; y < length; y++)
    {
        for (int x = 0; x < width; x++)
        {
            tiles[width * y + x] = old.tiles[width * y + x];
        }
    }
}

//Deconstructor
Map::~Map()
{
    delete[] tiles;
}

///Accessors

//Get the date from a tile
char Map::getTile(int x, int y)
{
    return tiles[width * y + x];
}

///Mutators
bool Map::loadMap(const std::string& path)
{   
    //free old memeory
    if (tiles)
        delete[] tiles;

    //Create ifstream
    std::ifstream fin(path);

    if (!fin) return false;

    //load new map size
    fin >> length >> width;

    //allocate new memory   
    tiles = new char[length * width];

    //Read in tiles
    for (int y = 0; y < length; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fin >> tiles[width * y + x];
        }
    }
    
    //close filestream
    fin.close();
}