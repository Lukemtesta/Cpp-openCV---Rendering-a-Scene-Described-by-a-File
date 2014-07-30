//
//  Circle.cpp
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

#include "Circle.h"

/* default constructor */
Circle::Circle():radius(100){
#ifdef DEBUG
    std::cout << "[INFO] Circle Default Constructor" << std::endl;
#endif
    
}

/* Copy constructor */
Circle::Circle(Circle* source): BaseShape(source), radius(source->radius){
#ifdef DEBUG
    std::cout << "[INFO] Circle Copy Constructor" << std::endl;
#endif
}

/* Constructor with parameters */
Circle::Circle(int x, int y, int rad, int red, int green, int blue): BaseShape(x, y, red, green, blue),radius(rad){
#ifdef DEBUG
    std::cout << "[INFO] Circle Parameter Constructor" << std::endl;
#endif
}

/* Destructor */
Circle::~Circle(){
#ifdef DEBUG
    std::cout << "[INFO] Circle Destructor" << std::endl;
#endif
}

/* Circle draw function, takes display pointer and offset */
void Circle::draw(SceneDisplay::BaseDisplay* display, int xOff = 0, int yOff = 0){
    
    display->drawCircle(center[0]+xOff, center[1]+yOff, radius, color[0], color[1], color[2]);
    
}

/* function to check that parameters in the input stream are valid */
bool Circle::checkParameter(std::string check){
    
    return (!check.compare("position")) || (!check.compare("color")) || (!check.compare("radius"));
}

/*friend function for stream operation */
std::istream& operator>> (std::istream& in, Circle& s){
    std::string parameter, eq, p1, p2, p3;
    
    //take in parameter
    in >> parameter >> std::ws;
    
    // check that parameters are valid
    while(s.checkParameter(parameter)){
        
        // remove equals sign
        in >> eq >> std::ws;
        
        // check for equals sign and throw exception if missing.
        if(eq.compare("=")){
            std::string error = "Missing equals sign in Parameter: '";
            error.append(parameter);
            error.append("' of Circle.");
            
            throw MissingEqualsSignException(error);
        }
        
        // exceptions from stoi() function caught by try{}catch(){} block
        try{
            
            if(parameter == "position"){
                
                in >> p1 >> std::ws >> p2;
                // explicitally sets center to the given parameters
                
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
                
            }else if(parameter == "radius"){
                
                in >> p1;
                
                s.radius = stoi(p1);
            }
            
        }catch( std::invalid_argument& ia ){
            std::string error;
            error.append("Invalid value of: '");
            error.append(parameter);
            error.append("' in Circle draw.");
            
            throw BadParameterValueException(error);
        }
        
        //take in parameter for next loop
        in >> parameter >> std::ws;
        
    }
    
    // parameter should now be 'done'
    if(!parameter.compare("done")){
        
        //return the stream for further operations
        return in;
        
    }else if(!parameter.compare("draw")){
        
        // if parameter is 'draw' of next shape, the 'done' must be missing.
        throw MissingDoneException("Missing 'done' in Circle ");
        
    }else{
        
        // if parameter is anything else, it must be an invalid parameter
        std::string error = "'";
        error.append(parameter);
        error.append("' is not a valid parameter for Circle ");
        
        throw BadParameterException(error);
        
    }

}