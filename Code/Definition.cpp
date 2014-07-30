//
//  Definition.cpp
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

#include "Definition.h"
#include "ComplexShape.h"
#include "World.h"

#include <sstream>

// Constructors

Definition::Definition() : FileHandler(), ptrWorld(NULL) {};

Definition::Definition(int argc, char** argv) : FileHandler(argc, argv), ptrWorld(NULL)
{
    readFile();
    ptrWorld->drawWorld();
};


// Destructors

Definition::~Definition()
{
    delete ptrWorld;
    //std::cerr << "Deleting [Definition Class]" << std::endl;
};


// Methods


// Stores complexShapes/shapes into draw buffer
void Definition::renderShape(std::istream& fileBuffer, std::string name)
{
    if( !name.compare("Circle") )
    {
        Circle* tempShape = new Circle();
        fileBuffer >> *tempShape;
        
        // render circle
        ptrWorld->drawShape(tempShape);
    }
    else if ( !name.compare("Rectangle") )
    {
        Rectangle* tempShape = new Rectangle();
        fileBuffer >> *tempShape;
        
        // render rectangle
        ptrWorld->drawShape(tempShape);
    }
    else
    {
        // get name of object and location
        std::string parameter;
        fileBuffer >> parameter;
        
        if( !parameter.compare("position") )
        {
            Vec2 position;
            
            // remove equal operator
            fileBuffer >> parameter;
            
            // store position of define object to draw
            fileBuffer >> position.first >> position.second;
            
            // Check position parameters
            if( parameter.compare("=") || fileBuffer.fail() )
            {
                std::string error = "Invalid Position Parameter for Shape: ";
                error.append(name);
                error.append(" in draw function");
                
                throw InvalidDefineTerminationException(error);
            }
            
            // add complex shape to scene buffer
            ptrWorld->drawComplexShape(name, position.first, position.second);
            
            // check done
            fileBuffer >> parameter;
            
            if ( parameter.compare("done") )
                throw InvalidDefineTerminationException("Invalid Define Object Termination");
        }
    }
    
};


// Stores and check complex shape definition
void Definition::storeComplexShape(std::istream& fileBuffer, std::string name)
{
    std::string action;
    
    // read in shape action
    fileBuffer >> action;
    
    ComplexShape* shape = new ComplexShape( ptrWorld->getDictionary() );
    
    // For each complexShape, append shape dictionary
    while( !action.compare("draw") )
    {
        fileBuffer >> *shape;
        fileBuffer >> action;
    };
    
    // check definition contains done
    if ( action.compare("done")  )
    {
        std::string errorMessage = "Error with Shape Definition: ";
        errorMessage.append(name);
        throw InvalidDefineTerminationException(errorMessage);
    }
    
    // store shape
    ptrWorld->defineComplexShape(name, shape);
};


// check and store shape definitions.
void Definition::shapeDefinition(std::istream& fileBuffer)
{
    std::string name, action;
    
    // read file strings until definition or draw read.
    do
    {
        fileBuffer >> action >> std::skipws >> name;
        
        // If define, store the complex shape parameters. If draw, add basic shape to draw buffer
        if( !action.compare("define") )
            storeComplexShape(fileBuffer, name);
        else if( !action.compare("draw")  )
            renderShape(fileBuffer, name);
        else
            throw BadInputParameterException("Action must be draw or define");

    }
    while(fileBuffer.peek() != EOF);
}


// checks and stores image size
void Definition::check_imageHeader(std::istream& fileBuffer)
{
    std::string action, operation;
    Vec2 worldSize;
    
    // get World size action
    fileBuffer >> action;
    fileBuffer >> operation;
    fileBuffer >> worldSize.first >> worldSize.second;
    
    // world size parameter is correct
    if ( action.compare("size") || operation.compare("=") || fileBuffer.fail() )
        throw BadWorldFormatException("Invalid World Size Parameter");
    
    ptrWorld = new World(worldSize.first, worldSize.second);
}


// Returns line of failure based on the last char read
int Definition::getErrorLine(std::istream& fileBuffer)
{
    std::string str;
    
    // store char position of exception thrown
    int ptrLine = 0;
    int lastChar = (int) fileBuffer.tellg();
    
    // reset istream char ptr
    fileBuffer.clear();
    fileBuffer.seekg(std::ios::beg);
    
    // count lines to exception char position
    while( fileBuffer.tellg() < lastChar )
    {
        std::getline(fileBuffer,str);
        ptrLine++;
    };

    return ptrLine;
};


// reads and draws objects in file
void Definition::readFile()
{
    try
    {
        // Read world size definitions
        check_imageHeader(*file);
        
        // define and draw contents of file
        shapeDefinition(*file);
    }
    catch (Exception& e)
    {
        // store last char position in stream where error occurred. Find line char was on
        std::cout << e.show() << " | at line: "  << getErrorLine(*file) << std::endl;
        delete ptrWorld;
        std::exit(0);
    }
};
