#include "CairoDisplay.h"

#include <math.h>
#include <iostream>

namespace SceneDisplay {

using namespace std;

	//CairoDisplay::CairoDisplay() : display(NULL), surface(NULL), record(NULL), context(NULL) {}

	CairoDisplay::CairoDisplay(int width, int height) throw(DisplayException) : display(XOpenDisplay(NULL)), surface(NULL), record(NULL), context(NULL) {
		resize(width,height);
	}

	CairoDisplay::~CairoDisplay(){
		if(context) cairo_destroy(context);	
		if(surface) cairo_surface_destroy(surface);
		if(record) cairo_surface_destroy(record);
		if(display) XCloseDisplay(display);	
	}

	void CairoDisplay::resize( int width, int height ) throw(DisplayException) {
		BaseDisplay::resize(width,height);

		// clear up previous canvas
		if(context) cairo_destroy(context);
		if(surface) cairo_surface_destroy(surface);
		if(record) cairo_surface_destroy(record);
		if(display)	XCloseDisplay(display);	

		// open xlib display & window
		display = XOpenDisplay(NULL);
		if(!display)
			throw DisplayException("Could not open display (Xlib error)");

		screen = DefaultScreen(display);
		rootWindow = RootWindow(display, screen);

		window = XCreateSimpleWindow(display, 
				rootWindow, 1, 1, width, height, 0, 
				BlackPixel(display, screen), 
				BlackPixel(display, screen)
			);

		XStoreName(display, window, "CairoDisplay");
		XSelectInput(display, window, ExposureMask|ButtonPressMask);
		XMapWindow(display, window);

		// create Cairo surface 
		region.x = region.y = 0.0;
		region.width = (float)width;
		region.height = (float)height; 
		record =  cairo_recording_surface_create(CAIRO_CONTENT_COLOR, &region);
		surface = cairo_xlib_surface_create( display, window, DefaultVisual(display,0), width, height);

		if(!surface)
			throw DisplayException("Could not Cairo surface (Xlib front-end)!");

		// initialize Cairo context for drawing
		context = cairo_create(record);
		cairo_rectangle(context, 0.0, 0.0, width, height);
		cairo_set_source_rgb(context, 0.0, 0.0, 0.0);
		cairo_fill(context);
	}

	void CairoDisplay::show() throw(DisplayException) {
		if( display && surface ){
			cairo_show_page(context);
			do {
				XNextEvent(display, &event);
				if(event.type==Expose && event.xexpose.count<1){
					if(context) cairo_destroy(context);
					context = cairo_create(surface);
					cairo_set_source_surface(context, record, 0.0, 0.0);
					cairo_paint(context);
					cairo_show_page(context);
				}
			} while( event.type != ButtonPress );
		} else 
			throw DisplayException("Display front-end (Cairo+Xlib) needs to be initialised to a correct size before calling the show() method!");

		if(context) cairo_destroy(context);
		context = cairo_create(record);
	}

	void CairoDisplay::drawCircle( int x, int y, int radius, int red, int green, int blue ) throw(DisplayException) {
		if( display && context ){
			cairo_set_line_width( context, 0.0 );
			cairo_set_source_rgb( context, (float)red/255.0, (float)green/255.0, (float)blue/255.0 );
			cairo_translate(context, (float)x, (float)y);
			cairo_arc(context, 0.0, 0.0, radius, 0, 2 * M_PI);
			cairo_fill(context);
			cairo_stroke(context);
			cairo_identity_matrix(context);
		} else 
			throw DisplayException("Display front-end (Cairo+Xlib) needs to be initialised to a correct size before drawing!");
	}

	void CairoDisplay::drawRectangle( int x, int y, int width, int height, int red, int green, int blue ) throw(DisplayException) {
		if( display && context ){
			cairo_set_line_width( context, 0.0 );
			cairo_set_source_rgb( context, (float)red/255.0, (float)green/255.0, (float)blue/255.0 );
			cairo_translate(context, (float)x, (float)y);
			cairo_rectangle(context, 0.0, 0.0, width, height);
			cairo_fill(context);
			cairo_stroke(context);
			cairo_identity_matrix(context);
		} else 
			throw DisplayException("Display front-end (Cairo+Xlib) needs to be initialised to a correct size before drawing!");		
	}

} // SceneDisplay
