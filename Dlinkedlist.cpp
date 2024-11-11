#include "Dlinkedlist.hpp"

//This function is the constructor for the linked list
Dlinkedlist::Dlinkedlist(){
    head = new Dnode;
    tail = new Dnode;
    head->next = tail; //Head intitially points to tail
    tail->prev = head; //Tail intially points to head
}

//This function is the destructor for the linked list
Dlinkedlist::~Dlinkedlist(){
    while(!isEmpty())
        removeFront();
    delete head;
    delete tail;
}

//This function returns true if the list is empty 
bool Dlinkedlist::isEmpty() const{
    return (head->next == tail);
}

//This function returns the data from the front element of the list 
std::string Dlinkedlist::getFront() const{
    return head->next->data;
}

//This function returns the data from the back element of the list
std::string Dlinkedlist::getBack() const{
    return tail->prev->data;
}

//This function adds a new node before the node passed as an argument
void Dlinkedlist::add(Dnode* elem, std::string new_data){
    Dnode* temp = new Dnode;
    temp->data = new_data;
    temp->next = elem; //New node points to passed node
    temp->prev = elem->prev; //New nodes points to prev of passed node
    elem->prev->next = temp; //prev node points to new node
    elem->prev = temp; //Old node points back to new node
}

//This function removes the node passed as an argument
void Dlinkedlist::remove(Dnode* elem){
        Dnode* prev = elem->prev;
        Dnode* next = elem->next;
        prev->next = next; //Node before node passed points to node after node passed
        next->prev = prev; //Node after node passed points to node before node passed
        delete elem;
}

//This function adds a node to the front of the list
void Dlinkedlist::addFront(std::string data){
    add(head->next, data);
}

//This function adds a node to the back of the list 
void Dlinkedlist::addBack(std::string data){
    add(tail, data);
}

//This function removes the node at the front of the list
void Dlinkedlist::removeFront(){
    if(isEmpty())
        return;
    remove(head->next);
}

//This function removes the node at the back of the list
void Dlinkedlist::removeBack(){
    if(isEmpty())
        return;
    remove(tail->prev);
}
