//
//  FileHandler.h
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

#ifndef __OOBcoursework__FileHandler__
#define __OOBcoursework__FileHandler__

#include "Exceptions.h"

#include <iostream>
#include <string>
#include <fstream>

#endif /* defined(__OOBcoursework__FileHandler__) */

class FileHandler
{
    public:
                // constructors
                FileHandler();
                FileHandler(int argc, char** argv);
    
                // destructors
                virtual ~FileHandler();
    
                // methods
                void print_fileContents();
    
    protected:
                //members
                std::ifstream* file;
    
                //methods
                // open file temporarily and check the file has at least a character
                void openFile();
    
    private:
                // methods
                // does file exist in current directory
                inline void fileExist();
                // check if the file contains no content
                inline void fileEmpty();
    
                // members
                std::string* fileName;

};