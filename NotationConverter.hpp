/*
Name: Jawaad Ramcharitar
UID: 10335787
Description: This is the header file for the notation converter system using a deque.
*/
#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Deque.hpp"
#include "NotationConverterInterface.hpp"

class NotationConverter: public NotationConverterInterface{
public:

    std::string postfixToInfix(std::string inStr); //Converts postfix notation to infix
    std::string postfixToPrefix(std::string inStr); //Converts postfix notation to prefix

    std::string infixToPostfix(std::string inStr); //Converts infix notation to postfix
    std::string infixToPrefix(std::string inStr); //Converts infix notation to prefix

    std::string prefixToInfix(std::string inStr); //Converts prefix notation to infix
    std::string prefixToPostfix(std::string inStr); //Converts prefix notation to postfix

    bool isValid(std::string test); //Tests if input is valid
    
private:
    Deque a; //Implemented using deque
};

#endif