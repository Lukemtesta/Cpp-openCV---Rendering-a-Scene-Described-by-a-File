//
//  Definition.h
//  OOBcoursework
//

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

#ifndef __OOBcoursework__Definition__
#define __OOBcoursework__Definition__

#include "FileHandler.h"

#include "World.h"

typedef std::pair<int,int> Vec2;

#endif /* defined(__OOBcoursework__Definition__) */

class ComplexShape;

class Definition : public FileHandler
{
    public:
                Definition();
                Definition(int argc, char** argv);
    
                virtual ~Definition();
    
    protected:
                //members
                World* ptrWorld;
    
                //methods
                // reads the contents of a file for dictionary storage, rendering and drawing
                void readFile();
    
                // if exception thrown, find the line containing the last character read
                int getErrorLine(std::istream& fileBuffer);
    
    private:
                // methods
    
                // error check world size and store world variables
                void check_imageHeader(std::istream& fileBuffer);
                // error check and store complex and basic shapes
                void shapeDefinition(std::istream& fileBuffer);
    
                // store a basic shape in the draw buffer
                void renderShape(std::istream& fileBuffer, std::string name);
                // store a complex shape in the dictionary
                void storeComplexShape(std::istream& fileBuffer, std::string name);
};