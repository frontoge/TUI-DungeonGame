#pragma once

#include <string>

class Map 
{
    public:
        ///Constructors
        Map();
        Map(const std::string& path);
        Map(const Map& old);
        ~Map();

        ///Accessors

        //Gets length of map
        inline int getLength() {return length;};
        //Gets width of map
        inline int getWidth() {return width;};
        //Gets the data stored at a specific tile on the map
        char getTile(int x, int y);

        ///Mutators

        //Loads a map in from a file
        bool loadMap(const std::string& path);
        //Sets the data of a specific tile on the map
        void setTile(char data, int x, int y);
        
        ///Operators

        Map& operator=(const Map& old);

    private:
        char* tiles;//array to hold all the data on the map
        int length;//Length property of map
        int width;//Width property of map
};
