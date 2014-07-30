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

#ifndef __CPP_Coursework__Dictionary__
#define __CPP_Coursework__Dictionary__

#include <iostream>
#include <string>
#include <map>
#include "Exceptions.h"

// uncomment for debug
//#define DEBUG

class ComplexShape;

class Dictionary{
public:
    Dictionary();
    virtual ~Dictionary();
    
    void defineComplexShape(std::string name, ComplexShape* complexShape);
    ComplexShape* getComplexShape(std::string name);
    
private:
    typedef std::map <std::string, ComplexShape*> CShapeMap;
    CShapeMap shapeMap;
};

#endif /* defined(__CPP_Coursework__World__) */
