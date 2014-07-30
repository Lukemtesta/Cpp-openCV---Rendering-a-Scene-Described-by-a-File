
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
#include "Exceptions.h"

typedef SceneDisplay::OpenCVDisplay ValidDisplay;


// imports stream objects from std namespace
using std::cerr;
using std::endl;


/*
Main function draws a red circle and a green rectangle on the screen. 
*/
int main(int argc, char** argv) {
	try{
        
        Definition F( argc, argv );
        
        
	} 
	catch( SceneDisplay::DisplayException & e ){
			cerr << "ERROR: A display error occured: \n" << e.show() << endl;
	}
    catch(Exception e){
        cerr << e.show() << endl;
    }
     
     
}
