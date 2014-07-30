
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

#ifndef BASEDISPLAY_H_
#define BASEDISPLAY_H_

#include <string>
#include "noncopyable.h"

namespace SceneDisplay {

using std::string;

/*
Basic class for display exceptions. 
*/
class DisplayException{
	const string errorMessage;

public:
	DisplayException( const string & msg ) : errorMessage(msg) {}

	~DisplayException(){}

	const string& show() const{
		return errorMessage;
	}
};

/*
Base class for display objects, allowing to draw shapes on the screen. 
Provides declaration of basic drawing functions that need to be implemented by all front-ends.
*/
class BaseDisplay : noncopyable {
public:
	virtual ~BaseDisplay(){}

	// used for resizing the drawing area, sends an exception if the requested size is invalid
	virtual void resize( int width, int height ) throw(DisplayException) {
		if( width < 1 || height < 1 )
			throw( DisplayException("Invalid display size provided!" ) );
	}

	/* 
	Show the result on the screen.
	This will throw an exception if the display has not been initialized.
	*/
	virtual void show() throw(DisplayException) = 0;

	/* 
	Draw a circle on the screen. 
	x,y are the coordinates of the circle's centre.
	radius is the circle's radius
	red,green.blue define the circle's color (each within [0,255])
	This will throw an exception if the display has not been initialized.
	*/
	virtual void drawCircle( int x, int y, int radius, int red, int green, int blue ) throw(DisplayException) = 0;

	/* 
	Draw a rectangle on the screen. 
	x,y are the coordinates of the top-left corner.
	width,height are the rectangle's dimensions
	red,green.blue define the circle's color (each within [0,255])
	This will throw an exception if the display has not been initialized.
	*/
	virtual void drawRectangle( int x, int y, int width, int height, int red, int green, int blue ) throw(DisplayException) = 0;
};

} // SceneDisplay

#endif /* BASEDISPLAY_H_ */
