// World Object
//  - contains vector of shapes for drawing
//
// Exceptions:
//  - std::bad_alloc for errors in vector memory allocation

#ifndef __CPP_Coursework__World__
#define __CPP_Coursework__World__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "OpenCVDisplay.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ComplexShape.h"
#include "Dictionary.h"

// uncomment for debug output
//#define DEBUG

class Dictionary;

class World : public Dictionary {
private:
    int width;
    int height;
    
    SceneDisplay::OpenCVDisplay display;
    std::vector <BaseShape*> drawVector;
    
public:
    World();
    World(int w, int h);
    virtual ~World();
    
    void drawShape(BaseShape* shape);
    void drawComplexShape(std::string name, int xOffset, int yOffset);
    void drawWorld();
    inline Dictionary* getDictionary() {return this;};
};

#endif /* defined(__CPP_Coursework__World__) */
