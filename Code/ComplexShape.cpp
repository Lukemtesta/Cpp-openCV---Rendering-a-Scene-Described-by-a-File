//
//  ComplexShape.cpp
//  CPP-Coursework
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


#include "ComplexShape.h"

/* Constructor takes reference to dictionary object */
ComplexShape::ComplexShape(Dictionary* dicRef): BaseShape(0, 0, 0, 0, 0), dictionaryReference(dicRef){
#ifdef DEBUG
    std::cout << "[INFO] Default ComplexShape Constructor" << std::endl;
#endif
}

/* Copy constructor */
ComplexShape::ComplexShape(ComplexShape* source, int xTrans, int yTrans): BaseShape(xTrans, yTrans, 0, 0, 0){
#ifdef DEBUG
    std::cout << "[INFO] Constructing ComplexShape with offset" << std::endl;
#endif
    dictionaryReference = source->dictionaryReference;
    for(unsigned int i = 0; i<source->shapeArray.size(); i++){
        //std::cout << "Copy shapes across" << std::endl;

        shapeArray.push_back(source->shapeArray[i]);
        
    }
    
}

/* Destructor */
ComplexShape::~ComplexShape(){
#ifdef DEBUG
    std::cout << "[INFO] ComplexShape Destructor" << std::endl;
#endif   
    shapeArray.clear();
    
}

/* Function for adding shapes intot the array of shapes */
void ComplexShape::addShape(BaseShape* source){
    // inserts the BaseShape pointer into the shapeArray object;
    shapeArray.push_back(source);
    
}

/* draw function takes pointer to display and offset */
void ComplexShape::draw(SceneDisplay::BaseDisplay* display, int xOff, int yOff){
    //std::cout << "in ComplexShape Draw" << std::endl;

    for(unsigned int i = 0; i<shapeArray.size(); i++){

        shapeArray[i]->draw(display, center[0]+xOff, center[1]+yOff);
    }

}

/* Friend function for stream operations */
std::istream& operator>> (std::istream& in, ComplexShape& s){
    /* initialise the ComplexShape from the parameters */
    /* on each draw line, pass the stream on to the circle or rectangle shape */
    std::string action, name, position, eq, p1, p2, done;

    // take in name of the shape to be added to the complex shape
    in >> name;
    
        // if name is Circle or Rectangle, create and pass stream to shape
        if(name == "Circle"){
            Circle* c = new Circle();
            in >> *c;
            s.addShape(c);
        }else if(name == "Rectangle"){
            Rectangle* r = new Rectangle();
            in >> *r;
            s.addShape(r);
        }else{
            // if name is anything other than Circle, it must be a pre defined complex shape.
            // take in parameters
            in >> position >> eq >> p1 >> p2;
            
            // check that equals sign is present
            if(eq != "=") {
                
                std::string error = "Missing equals sign in complex shape definition.";
                
                throw MissingEqualsSignException(error);
                
            }
        #ifdef DEBUG
            std::cout << "[INFO] Using definition: " << name << std::endl;
        #endif
            

            try{
                // Attempt to retrieve the definition from the dictionary
                // This function throws exceptions which are caught below
                ComplexShape* definition = s.dictionaryReference->getComplexShape(name);
                
                //if program reaches here without exception make a copy of the shape with the offset and add to complex shape
                ComplexShape* com = new ComplexShape(definition, stoi(p1), stoi(p2));
                s.addShape(com);
                
            }catch( ShapeAlreadyExistsException& e){
                std::cerr << "[WARNING] Shape with name " << name << "is already defined...." << std::endl;
                std::cerr << "[WARNING] Previous definition of" << name << "will be used." << std::endl;
            }
            
            // pass stream back for further operations
            in >> done;
            
           
        }
    
    return in;
};