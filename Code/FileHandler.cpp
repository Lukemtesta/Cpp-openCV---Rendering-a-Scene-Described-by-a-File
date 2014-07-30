//
//  FileHandler.cpp
//  OOBcoursework
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

#include "FileHandler.h"

// Constructors

FileHandler::FileHandler() : fileName(NULL), file(NULL) {};

// Takes command line parameters and checks whether input file exists and contains information
FileHandler::FileHandler(int argc, char** argv) : file(NULL), fileName(NULL)
{
    try
    {
        // Check command line parameters
        switch (argc)
        {
            case 1:
                throw CommandLineInputException("Not Enough Input Parameters");
            case 2:
                break;
            default:
                std::cout << "Warning: Too many command line parameters. Assuming input parameter [1] is " << argv[1] << std::endl;
            break;
        }
        
        // send warning, will assume second cmd line argument is the input file
        fileName = new std::string(argv[1]);
        
        // initialize filePtr and check if file exists
        openFile();
    }
    catch ( Exception& e)
    {
        std::cout << e.show() << std::endl;
        delete file;
        delete fileName;
        std::exit(0);
    };
    
};


// Destructors

// Clsoes file if open. Destroys file pointers safely
FileHandler::~FileHandler()
{
    if( file )
    {
        if( file->is_open() )
        {
            file->close();
        }
    }
    
    delete file;
    delete fileName;
    
    //std::cout << "Deleting [FileHandler Class] containing: " << fileName << std::endl;
};


// Methods

// check if the file is contained in the current directory
void FileHandler::fileExist()
{
        if( !file->good() )
            throw FileNotExistException( "Input File Does Not Exist" );
};


// IGNORE NOT EXECUTED IN RUN-TIME: print file contents for debugging
void FileHandler::print_fileContents()
{
    std::istream& fileBuffer = *file;
    
    std::string fileLine;

    while(fileBuffer)
    {
        std::getline(fileBuffer,fileLine);
        std::cout << fileLine << std::endl;
    }
};


// check if the contents of the file is empty
void FileHandler::fileEmpty()
{
    std::istream& ptrFile(*file);
    
    if(ptrFile.peek() == EOF)
        throw BadFileHandledException("Input File Is Empty");
}

void FileHandler::openFile()
{
    file = new std::ifstream(*fileName, std::ios::in);
    
    // Does file exist?
    fileExist();
    
    // Is file empty?
    fileEmpty();
    
};

