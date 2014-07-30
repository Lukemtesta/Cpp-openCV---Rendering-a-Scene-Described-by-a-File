// World Object
//  - contains vector of shapes for drawing
//
// Exceptions:
//  - std::bad_alloc for errors in vector memory allocation

/*

Copyright (c) 2014 Luke Marcus Biagio Testa, Oliver Chilton and Alex Freestone
All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that the above copyright notice and this paragraph are
duplicated in all such forms and that any documentation,
advertising materials, and other materials related to such
distribution and use acknowledge that the software was developed
by the Luke Marcus Biagio Testa. The name of the
Luke Marcus Biagio Testa, Oliver Chilton and Alex Freestone may not be used to endorse or promote products derived
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

#include "World.h"

// Default constructor
World::World(): width(640), height(480), display(640, 480)
{
#ifdef DEBUG
    std::cout << "[INFO] Calling World Default Constructor" << std::endl;
#endif
}

// Parameter Constructor - containing width, height values of window
World::World(int w, int h): width(w), height(h), display(w, h)
{
#ifdef DEBUG
    std::cout << "[INFO] Calling World Parameter Constructor" << std::endl;
#endif
}

World::~World()
{
#ifdef DEBUG
    std::cout << "[INFO] Calling World Destructor" << std::endl;
#endif
    
    // Loop through vector and delete Shape pointers
    if (!drawVector.empty())
    {
        for(unsigned int i = 0; i<drawVector.size(); i++)
        {
            delete drawVector[i];
        }
        drawVector.clear();
    }
}

void World::drawShape(BaseShape* shape)
{
    // Reserve memory
    drawVector.reserve(drawVector.size() + 1);
    
    #ifdef DEBUG
        std::cout << "[INFO] Adding Shape to Draw Vector" << std::endl;
    #endif
    
    // Add to vector
    drawVector.push_back(shape);
}

void World::drawComplexShape(std::string name, int xOffset, int yOffset)
{
    // Create new complex shape and push onto the drawvector
    ComplexShape* newShape = new ComplexShape(getComplexShape(name), xOffset, yOffset);
    
    drawVector.reserve(drawVector.size() + 1);
    drawVector.push_back(newShape);
}

void World::drawWorld()
{
    #ifdef DEBUG
        std::cout << "[INFO] Drawing Scene" << std::endl;
    #endif

    // Loop through draw vector calling the generic (virtual) draw function    
    for(unsigned int i = 0; i < drawVector.size(); i++)
    {
        drawVector[i]->draw(&display, 0, 0);
    }
    
    display.show();
}

