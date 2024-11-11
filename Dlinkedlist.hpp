/*
Name: Jawaad Ramcharitar
UID: 10335787
Description: This is the header file for my doubly linked list.
*/
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H


#include<iostream>
#include<string>

class Dnode{ //Node class
private:
    std::string data;
    Dnode* prev;
    Dnode* next;
    friend class Dlinkedlist;
};

class Dlinkedlist{ //Class to handle list
public:
    Dlinkedlist(); //Constructor
    ~Dlinkedlist(); //Destructor
    bool isEmpty() const; //Checks if empty
    std::string getFront() const; //Returns front
    std::string getBack() const; //Returns back
    void add(Dnode* elem, std::string new_data); //Adds element after element passed
    void addFront(std::string data); //Adds element to front
    void addBack(std::string data); //Adds element to the back
    void remove(Dnode* elem); //Removes element passed
    void removeFront(); //Removes element from the front
    void removeBack(); //Removes element from the back
private:
    Dnode* head; //Tracks front
    Dnode* tail; //Tracks back
};

#endif