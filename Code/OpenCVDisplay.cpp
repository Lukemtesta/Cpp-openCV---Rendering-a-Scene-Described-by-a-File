/*
 * OpenCVDisplay.cpp
 *
 *  Created on: 5 Nov 2013
 *      Author: nicolas
 */

#include "OpenCVDisplay.h"

namespace SceneDisplay {

OpenCVDisplay::OpenCVDisplay(int w, int h) throw(DisplayException) : image(NULL) {
	initializeImage(w,h);
}

OpenCVDisplay::~OpenCVDisplay() {
	releaseImage();
}

void OpenCVDisplay::resize( int width, int height ) throw(DisplayException) {
	BaseDisplay::resize(width,height);
	initializeImage(width,height);
}

void OpenCVDisplay::releaseImage() {
	if(image)
		cvReleaseImage(&image);
	cvDestroyWindow("image");
}

void OpenCVDisplay::initializeImage( int width, int height ) throw(DisplayException) {
	releaseImage();
	image = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	if(!image)
		throw DisplayException("Could not create an OpenCV image!");
}

void OpenCVDisplay::show() throw(DisplayException) {
	if( image ){
		cvShowImage("image", image);
		cvWaitKey();
	} else
		throw DisplayException("Display front-end (OpenCV) needs to be initialised to a correct size before calling the show() method!");		
}

void OpenCVDisplay::drawCircle( int x, int y, int radius, int red, int green, int blue ) throw(DisplayException) {
	if( image )
		cvCircle(image, cvPoint(x,y), radius, CV_RGB(red, green, blue), CV_FILLED);
	else 
		throw DisplayException("Display front-end (OpenCV) needs to be initialised to a correct size before drawing!");		

}

void OpenCVDisplay::drawRectangle( int x, int y, int width, int height, int red, int green, int blue ) throw(DisplayException) {
	if( image )
		cvRectangle(image, cvPoint(x,y), cvPoint(x+width,y+height), CV_RGB(red, green, blue), CV_FILLED);
	else 
		throw DisplayException("Display front-end (OpenCV) needs to be initialised to a correct size before drawing!");		
}

} // SceneDisplay



