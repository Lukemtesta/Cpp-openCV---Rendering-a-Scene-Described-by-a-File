/*
 * CairoDisplay.h
 *
 *  Created on: 6 Nov 2013
 *      Author: nicolas
 */

#ifndef CAIRODISPLAY_H_
#define CAIRODISPLAY_H_


#include <X11/Xlib.h>
#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include "BaseDisplay.h"

namespace SceneDisplay {

/**
 * Class for drawing shapes on the screen using Cairo + Xlib. 
 */
class CairoDisplay: public BaseDisplay {
private:	
	// Xlib-related structures
	Display *display; 	// Xlib display 
	int screen; 		// Xlib screen id
	Window rootWindow; 	// Xlib window 
	Window window; 		// Xlib window 
	XEvent event; 		// Xlib event  

	// Cairo related structures
	cairo_surface_t *surface, *record;	// surfaces for drawing onto
	cairo_t *context;					// current context for drawing
	cairo_rectangle_t region;			// region to be drawn on (rectangle the same size as the window)

public:

	// default constructor does not initialize the drawing area (drawing operations will fail)
	//CairoDisplay();

	/*
	Constructor initializing the drawing area to a valid size.
	Raises an exception if the requested size is invalid.
	*/
	CairoDisplay(int width, int height) throw(DisplayException);

	// Destructor releases the current Xlib windows and Cairo context (if initialized)
	~CairoDisplay();

	/* 
		Changes the size of the drawing area. 
		Discards previous context and therefore all previous drawing operations.
		Raises an exception if the requested size is invalid.
	*/
	void resize( int width, int height ) throw(DisplayException);

	/* 
	Show the result on the screen.
	The created window will closed when clicked. 
	This will throw an exception if the display has not been initialized.
	*/
	void show() throw(DisplayException);


	/* 
	Draw a circle on the screen. 
	x,y are the coordinates of the circle's centre.
	radius is the circle's radius
	red,green.blue define the circle's color (each within [0,255])
	This will throw an exception if the display has not been initialized.
	*/
	void drawCircle( int x, int y, int radius, int red, int green, int blue ) throw(DisplayException);

	/* 
	Draw a rectangle on the screen. 
	x,y are the coordinates of the top-left corner.
	width,height are the rectangle's dimensions
	red,green.blue define the circle's color (each within [0,255])
	This will throw an exception if the display has not been initialized.
	*/
	virtual void drawRectangle( int x, int y, int width, int height, int red, int green, int blue ) throw(DisplayException);
};

} // SceneDisplay


#endif /* CAIRODISPLAY_H_ */
