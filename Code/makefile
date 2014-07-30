# Skeleton makefile for using OpenCV front-end
# (doesn't seem to be installed on the labs' computers, you can install it on your own machine though)

# use the following to indicate the location of OpenCV libraries and header files
OPENCV_INC_DIR = /usr/include
OPENCV_LIB_DIR = /usr/lib

CXX = g++ -std=c++11

# for optimised build comment the first line and uncomment the second
# for debugging, comment the second line and uncomment the first
CXXFLAGS =	-ggdb -g3 -O0 -DUSE_OPENCV
#CXXFLAGS =	-O3 -Wall


# compilation flags, you won't need to change this
CPPFLAGS = -Wall -fmessage-length=0 -I$(OPENCV_INC_DIR)
LDFLAGS = -L$(OPENCV_LIB_DIR)

# (CHANGE THIS!) add here any additional module you have written
MAIN_OBJS = main.o BaseShape.o Circle.o Rectangle.o ComplexShape.o World.o OpenCVDisplay.o Dictionary.o Definition.o FileHandler.o Exceptions.o 

OBJS = $(MAIN_OBJS) $(EXCEPT_OBJS_1) $(EXCEPT_OBJS_2) $(EXCEPT_OBJS_3) $(EXCEPT_OBJS_4) $(EXCEPT_OBJS_5)

# libraries to be linked, these ones are required for the OpenCV display
LIBS =	-lopencv_highgui -lopencv_core

# name of the program to build
TARGET = DrawScene

# main linking
$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS) $(LDFLAGS)

# Note: the makefile is using an implicit rule in this case for building 
# all the .o files 

# build everything
all:	$(TARGET)

# cleanup source by removing .o files
clean:
	rm $(OBJS) $(TARGET)
