// Dictionary Object
//  - contains map of defined complex shapes
//
// Exceptions:
//  - Trying to define shape that already exists
//  - Trying to get shape that is undefined
//  - std::bad_alloc for errors in map memory allocation

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

#include "Dictionary.h"

Dictionary::Dictionary()
{
    #ifdef DEBUG
        std::cout << "[INFO] Calling Dictionary Constructor" << std::endl;
    #endif
    
    // To prevent redefiniton of base shapes
    shapeMap["Circle"] = NULL;
    shapeMap["Rectangle"] = NULL;
}

Dictionary::~Dictionary()
{
    #ifdef DEBUG
        std::cout << "[INFO] Calling Dictionary Destructor" << std::endl;
    #endif

    // Iterate through items in map and delete Complex Shapes    
    for(CShapeMap::iterator iter=shapeMap.begin(); iter != shapeMap.end(); ++iter)
    {
        delete iter->second;
    }
    
    shapeMap.clear();
}

// Adds new shape to dictionary map
void Dictionary::defineComplexShape(std::string name, ComplexShape* shape)
{
    // Check if shape already exists
    if (shapeMap.count(name) != 0)
    {
        #ifdef DEBUG
            std::cout << "[WARNING] Shape '" << name << "' already defined" << std::endl;
        #endif
        
        throw ShapeAlreadyExistsException(name);
    }
    
    #ifdef DEBUG
        std::cout << "[INFO] Defining New Complex Shape: '" << name << "'" << std::endl;
    #endif
    
    shapeMap[name] = shape;
}

// Get complex shape definition from map
ComplexShape* Dictionary::getComplexShape(std::string name)
{
    // Check name exists and it is not Circle or Rectangle
    if (shapeMap.count(name)      != 0 && 
        name.compare("Circle")    != 0 &&
        name.compare("Rectangle") != 0)
    {
        #ifdef DEBUG
            std::cout << "[INFO] Retrieved complex shape '" << name << "' from dictionary" << std::endl;
        #endif
        
        return shapeMap[name];
    }
    
    #ifdef DEBUG
        std::cout << "[ERROR] Unable to retrieve shape '" << name << "' from dictionary" << std::endl;
    #endif
    std::string error = "Shape: ";
    error.append(name);
    error.append(" does not exist.");
    throw ShapeDoesNotExistException(error);
}

