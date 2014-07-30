/*
 * OpenCVDisplay.h
 *
 *  Created on: 5 Nov 2013
 *      Author: nicolas
 */

#ifndef OPENCVDISPLAY_H_
#define OPENCVDISPLAY_H_


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "BaseDisplay.h"


namespace SceneDisplay {


/**
 * Class for drawing shapes on the screen using OpenCV. 
 */
class OpenCVDisplay: public BaseDisplay {
private:
	// opencv related methods and structures
	IplImage* image; 		// opencv image format
	void releaseImage();	// called to release the opencv image
	void initializeImage( int width, int height ) throw(DisplayException);

public:
	/*
	Constructor initializing the drawing area to a valid size.
	Raises an exception if the requested size is invalid.
	*/
	OpenCVDisplay(int w, int h) throw(DisplayException);

	// Destructor releases the current OpenCV image (if initialized)
	~OpenCVDisplay();

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
	void drawRectangle( int x, int y, int width, int height, int red, int green, int blue ) throw(DisplayException);
};

} //SceneDisplay

#endif /* OPENCVDISPLAY_H_ */
