//
//  BaseShape.cpp
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

#include "BaseShape.h"

/* Default Constructor */
BaseShape::BaseShape(){
    
    // set center to (0,0)
    center.push_back(0);
    center.push_back(0);
    
    // set color to gray
    color.push_back(127);
    color.push_back(127);
    color.push_back(127);
}

/* copy constructor */
BaseShape::BaseShape(BaseShape* source){
    
    center.push_back(source->center[0]);
    center.push_back(source->center[1]);
    
    color.push_back(source->color[0]);
    color.push_back(source->color[1]);
    color.push_back(source->color[2]);
    
}

/* Constructor with parameters */
BaseShape::BaseShape(int x, int y, int red, int green, int blue){

    
    center.push_back(x);
    center.push_back(y);
    
    color.push_back(red);
    color.push_back(green);
    color.push_back(blue);
    
    
}

/* BaseShape destructor */
BaseShape::~BaseShape(){
    center.clear();
    color.clear();
    
}


