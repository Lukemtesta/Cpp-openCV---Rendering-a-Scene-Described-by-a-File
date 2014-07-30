//
//  Rectangle.h
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

#ifndef __CPP_Coursework__Rectangle__
#define __CPP_Coursework__Rectangle__

#include <iostream>
#include "BaseShape.h"

class Rectangle: public BaseShape{
private:
    int width;
    int height;
    bool checkParameter(std::string check);
    
public:
    Rectangle();
    Rectangle(Rectangle* source);
    Rectangle(int x, int y, int w, int h, int red, int green, int blue);
    virtual ~Rectangle();
    
    void draw(SceneDisplay::BaseDisplay* display, int xOff, int yOff);
    friend std::istream& operator>> (std::istream& in, Rectangle& s);
    
};

#endif /* defined(__CPP_Coursework__Rectangle__) */
