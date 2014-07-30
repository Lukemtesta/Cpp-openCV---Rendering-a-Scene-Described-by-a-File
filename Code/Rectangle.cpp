//
//  Rectangle.cpp
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

#include "Rectangle.h"

/* Default constructor */
Rectangle::Rectangle(): BaseShape(0, 0, 127, 127, 127), width(100), height(100){
#ifdef DEBUG
    std::cout << "[INFO] Default Rectangle Constructor" << std::endl;
#endif
}

/* Copy constructor */
Rectangle::Rectangle(Rectangle* source): BaseShape(source), width(source->width), height(source->height){
#ifdef DEBUG
    std::cout << "[INFO] Circle Copy Constructor" << std::endl;
#endif
}

/* Constructor with parameters */
Rectangle::Rectangle(int x, int y, int w, int h, int red, int green, int blue): BaseShape(x,y,red,green,blue), width(w), height(h){
#ifdef DEBUG
    std::cout << "[INFO] Rectangle Parameter Destructor" << std::endl;
#endif
}

/* Destructor */
Rectangle::~Rectangle(){
#ifdef DEBUG
    std::cout << "[INFO] Rectangle Destructor" << std::endl;
#endif
}

void Rectangle::draw(SceneDisplay::BaseDisplay* display, int xOff = 0, int yOff = 0){
    
    display->drawRectangle(center[0]+xOff, center[1]+yOff, width, height, color[0], color[1], color[2]);
    
}

bool Rectangle::checkParameter(std::string check){
    
    return (!check.compare("position")) || (!check.compare("color")) || (!check.compare("size"));
}

std::istream& operator>> (std::istream& in, Rectangle& s){
    std::string parameter, eq, p1, p2, p3;
    
    in >> parameter >> std::ws;
    
    while(s.checkParameter(parameter)){
        
        in >> eq >> std::ws;
        
        if(eq.compare("=")){
            std::string error = "Missing equals sign in Parameter: '";
            error.append(parameter);
            error.append("' of Rectangle ");
            
            throw MissingEqualsSignException(error);
        }
        
        // try is to catch invalid arguments from stoi() function
        try{
            if(parameter == "position"){
                
                in >> p1 >> std::ws >> p2;
                
                s.center[0] = stoi(p1);
                s.center[1] = stoi(p2);
            }else if(parameter == "color"){
                
                in >> p1 >> std::ws >> p2 >> std::ws >> p3;
                
                s.color[0] = stoi(p1);
                s.color[1] = stoi(p2);
                s.color[2] = stoi(p3);
                
                for(unsigned int i = 0; i<3; i++){
                    if(s.color[i]<0 || s.color[i]>255){
                        throw std::invalid_argument("");
                    }
                }
                
            }else if(parameter == "size"){
                
                in >> p1 >> std::ws >> p2;
                
                s.width = stoi(p1);
                s.height = stoi(p2);
            }
            
            
        }catch( std::invalid_argument& ia ){
            std::string error;
            error.append("Invalid value of: '");
            error.append(parameter);
            error.append("' for Rectangle ");
            
            throw BadParameterValueException(error);
        }
        
        //take in parameter for next loop
        in >> parameter >> std::ws;
    }
    
    // parameter should now be 'done'
    if(!parameter.compare("done")){
        
        return in;
        
    }else if(!parameter.compare("draw")){
        // if parameter is 'draw' of next shape, done must be missing
        throw MissingDoneException("Missing 'done' in Rectangle ");
        
    }else{
        // if parameter is anything else, it must be an invalid parameter
        std::string error = "'";
        error.append(parameter);
        error.append("' is not a valid parameter for Rectangle ");
        
        throw BadParameterException(error);
        
    }

}