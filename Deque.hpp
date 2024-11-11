/*
Name: Jawaad Ramcharitar
UID: 10335787
Description: This is the header file for my deque.
*/
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include "Dlinkedlist.hpp"

class Deque{ //Class to manage deque
public:

    Deque(); //Constructor 
    ~Deque(); //Destructor

    int size() const; //Returns size of deque
    bool isEmpty() const; //Returns if deque is empty
    std::string front() const; //Returns front 
    std::string back() const; //Returns back

    void insertFront(std::string elem); //Adds element to the front 
    void insertBack(std::string elem); //Adds element to the back
    void deleteFront(); //Removes element from the front
    void deleteBack(); //Removes element from the back

private:
    Dlinkedlist Deck; //Doubly linked list implementation of deque
    int n; //Tracks number of elements in the deque
};

#endif