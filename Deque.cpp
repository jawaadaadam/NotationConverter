 #include "Deque.hpp"  

//This function is the constructor for the deque
Deque::Deque(){
    n = 0; //Size tracking variable intially assigned to 0
}

//This function is the destructor for the deque
Deque::~Deque(){
    while(!isEmpty())
        Deck.removeFront();
}

//This function returns the size of the deque
int Deque::size() const{
    return n;
}

//This function checks if the deque is empty
bool Deque::isEmpty() const{
    return Deck.isEmpty();
}

//This function returns the front of the deque
std::string Deque::front() const{
    return Deck.getFront();
}

//This function returns the back of the deque
std::string Deque::back() const{
    return Deck.getBack();
}

//This function adds the passed element to the beginning of the deque
void Deque::insertFront(std::string elem){
    Deck.addFront(elem);
    n++;
}

//This function adds the passed element to the back of the deque
void Deque::insertBack(std::string elem){
    Deck.addBack(elem);
    n++;
}

//This function removes the front element of the deque
void Deque::deleteFront(){
    Deck.removeFront();
    n--;
}

//This function removes the back element of the deque
void Deque::deleteBack(){
    Deck.removeBack();
    n--;
}

