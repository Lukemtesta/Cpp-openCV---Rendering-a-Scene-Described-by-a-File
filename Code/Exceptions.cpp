//
//  Exceptions.cpp
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

#include "Exceptions.h"


Exception::Exception(): errorMessage("Exception string not initialised."){};
Exception::Exception(std::string input): errorMessage(input){};
Exception::~Exception(){};

////

BadParameterException::BadParameterException(std::string input): Exception(input){};
BadParameterValueException::BadParameterValueException(std::string input): Exception(input){};
MissingDoneException::MissingDoneException(std::string input): Exception(input){};
MissingEqualsSignException::MissingEqualsSignException(std::string input): Exception(input){};

////

BadFileException::BadFileException(std::string input): Exception(input){};
BadInputParameterException::BadInputParameterException(std::string input): Exception(input){};
BadWorldSizeException::BadWorldSizeException(std::string input): Exception(input){};
BadDefineFormatException::BadDefineFormatException(std::string input): Exception(input){};

////

BadDrawSceneException::BadDrawSceneException(std::string input): Exception(input){};
BadColorValueException::BadColorValueException(std::string input): Exception(input){};
ShapeAlreadyExistsException::ShapeAlreadyExistsException(std::string input): Exception(input){};
ShapeDoesNotExistException::ShapeDoesNotExistException(std::string input): Exception(input){};

////

CommandLineInputException::CommandLineInputException() : Exception() {};
CommandLineInputException::~CommandLineInputException() {};
CommandLineInputException::CommandLineInputException(std::string str) : Exception()
{
    errorMessage = str;
};

FileNotExistException::FileNotExistException() : Exception() {};
FileNotExistException::~FileNotExistException() {};
FileNotExistException::FileNotExistException(std::string str) : Exception()
{
    errorMessage = str;
};

InvalidDefineTerminationException::InvalidDefineTerminationException() : Exception() {};
InvalidDefineTerminationException::~InvalidDefineTerminationException() {};
InvalidDefineTerminationException::InvalidDefineTerminationException(std::string str) : Exception()
{
    errorMessage = str;
};


BadFileHandledException::BadFileHandledException() : Exception() {};
BadFileHandledException::~BadFileHandledException() {};
BadFileHandledException::BadFileHandledException(std::string str) : Exception()
{
    errorMessage = str;
};


BadWorldFormatException::BadWorldFormatException() : Exception() {};
BadWorldFormatException::~BadWorldFormatException() {};
BadWorldFormatException::BadWorldFormatException(std::string str) : Exception()
{
    errorMessage = str;
};










