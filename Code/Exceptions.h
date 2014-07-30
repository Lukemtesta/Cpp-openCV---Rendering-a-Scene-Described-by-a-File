//
//  Exceptions.h
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

#ifndef __CPP_Coursework__Exceptions__
#define __CPP_Coursework__Exceptions__

#include <iostream>
#include <string>
#include <stdexcept>

class Exception{
public:
    Exception();
    Exception(std::string);
    virtual ~Exception();
    std::string errorMessage;
    std::string show(){
        std::string header = "[EXCEPTION] ";
        return header.append(errorMessage);
    };
};

////

class BadParameterException: public Exception{
    public: BadParameterException(std::string input);};

class BadParameterValueException: public Exception{
    public: BadParameterValueException(std::string input);};

class MissingDoneException: public Exception{
    public: MissingDoneException(std::string);};

class MissingEqualsSignException: public Exception{
    public: MissingEqualsSignException(std::string);};

//////

class BadFileException: public Exception{
    public: BadFileException(std::string);};

class BadInputParameterException: public Exception{
    public: BadInputParameterException(std::string);};

class BadWorldSizeException: public Exception{
    public: BadWorldSizeException(std::string);};

class BadDefineFormatException: public Exception{
    public: BadDefineFormatException(std::string);};

/////

class BadDrawSceneException: public Exception{
    public: BadDrawSceneException(std::string);};

class BadColorValueException: public Exception{
    public: BadColorValueException(std::string);};

class ShapeAlreadyExistsException: public Exception{
    public: ShapeAlreadyExistsException(std::string);};

class ShapeDoesNotExistException: public Exception{
    public: ShapeDoesNotExistException(std::string);};

////

class CommandLineInputException : public Exception
{
public:
    CommandLineInputException();
    CommandLineInputException(std::string str);
    
    ~CommandLineInputException();
};

class FileNotExistException : public Exception
{
public:
    FileNotExistException();
    FileNotExistException(std::string str);
    
    ~FileNotExistException();
};

class InvalidDefineTerminationException : public Exception
{
public:
    InvalidDefineTerminationException();
    InvalidDefineTerminationException(std::string str);
    
    ~InvalidDefineTerminationException();
};

class BadFileHandledException : public Exception
{
public:
    BadFileHandledException();
    BadFileHandledException(std::string str);
    
    ~BadFileHandledException();
};

class BadWorldFormatException : public Exception
{
public:
    BadWorldFormatException();
    BadWorldFormatException(std::string str);
    
    ~BadWorldFormatException();
};



#endif /* defined(__CPP_Coursework__Exceptions__) */
