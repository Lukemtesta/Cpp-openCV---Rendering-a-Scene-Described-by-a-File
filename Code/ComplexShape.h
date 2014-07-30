//
//  ComplexShape.h
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

#ifndef __CPP_Coursework__ComplexShape__
#define __CPP_Coursework__ComplexShape__

#include <iostream>
#include "BaseShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "World.h"
#include "Dictionary.h"


class ComplexShape: public BaseShape{
private:
    std::vector<BaseShape*> shapeArray;
    Dictionary* dictionaryReference;
    
public:
    ComplexShape(Dictionary* dicRef);
    ComplexShape(ComplexShape* source, int xTrans, int yTrans);
    virtual ~ComplexShape();
    
    void addShape(BaseShape* shape);
    void draw(SceneDisplay::BaseDisplay* display, int xOff, int yOff);
    friend std::istream& operator>> (std::istream& in, ComplexShape& s);
    
};

#endif /* defined(__CPP_Coursework__ComplexShape__) */
