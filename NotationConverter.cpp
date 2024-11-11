#include "NotationConverter.hpp"

//This function converts and inputted string from postfix notation to infix notation
std::string NotationConverter::postfixToInfix(std::string inStr){

    if(!isValid(inStr)) //Checks input validity 
        throw "Invalid entry";

    std::string infix; //String variable used for storage and pushing to the list

    for(int i = 0; i < inStr.size(); i++){ //Loops through input

        if(isalpha(inStr[i])){ //If character is a letter

            infix = inStr[i]; 
            a.insertFront(infix); //Push to front of deque

        }
        if((inStr[i] == '+') || (inStr[i] == '-') || (inStr[i] == '*') || (inStr[i] == '/')){ //If character is an operator 

            std::string temp_a;
            std::string temp_b;

            temp_a = a.front(); //Pop front 
            a.deleteFront();
            temp_b = a.front(); //Pop front
            a.deleteFront(); 

            infix = "(" + temp_b + " " + inStr[i] + " " + temp_a + ")";
            a.insertFront(infix); //Push converted section to front

        }

    }

    return a.front(); //Return front of deque
}

//This function converts and inputted string from postfix notation to prefix notation
std::string NotationConverter::postfixToPrefix(std::string inStr){

    if(!isValid(inStr)) //Checks input validity 
        throw "Invalid entry";

    std::string prefix; //String variable used for storage and pushing to the list

    for(int i = 0; i < inStr.size(); i++){ //Loops through input

        if(isalpha(inStr[i])){ //If character is a letter

            prefix = inStr[i];
            a.insertBack(prefix); //Push to back of deque

        }
        if((inStr[i] == '+') || (inStr[i] == '-') || (inStr[i] == '*') || (inStr[i] == '/')){ //If character is an operator

            std::string temp_a;
            std::string temp_b;

            temp_a = a.back(); //Pop back
            a.deleteBack();
            temp_b = a.back(); //Pop back
            a.deleteBack(); 

            prefix = inStr[i];
            prefix += " " + temp_b + " " + temp_a;
            a.insertBack(prefix); //Push converted section to back of deque

        }

    }
    
    return a.back(); //Return back of deque
}

//This function converts and inputted string from infix notation to postfix notation
std::string NotationConverter::infixToPostfix(std::string inStr){

    if(!isValid(inStr)) //Checks input validity
        throw "Invalid entry";

    std::string postfix = ""; //String variable used for storage and pushing to the list


    for(int i = 0; i < inStr.size(); i++){ //Loops through input

        if(isalpha(inStr[i])){ //If character is a letter

            postfix = inStr[i];
            a.insertBack(postfix); //Push to back of deque

        }   
        if((inStr[i] == '+') || (inStr[i] == '-') || (inStr[i] == '*') || (inStr[i] == '/')){ //If character is an operator

            postfix = inStr[i];
            a.insertFront(postfix); //Push to front of deque

        }
        if(inStr[i] == ')'){ //If character is a closing bracket

            std::string temp_a;
            std::string temp_b;

            temp_a = a.back(); //Pop back
            a.deleteBack();
            temp_b = a.back(); //Pop back
            a.deleteBack(); 

            postfix = temp_b + " " + temp_a + " " + a.front();
            a.insertBack(postfix); //Push converted section to back of deque
            a.deleteFront(); //Pop front of deque

        }       

    }

    return a.back(); //Return back of deque
}

//This function converts and inputted string from infix notation to prefix notation
std::string NotationConverter::infixToPrefix(std::string inStr){

    if(!isValid(inStr)) //Checks input validity 
        throw "Invalid entry";

    return NotationConverter::postfixToPrefix(NotationConverter::infixToPostfix(inStr)); //Converts from infix to postfix and then from postfix to prefix using existing functions

}

//This function converts and inputted string from prefix notation to infix notation
std::string NotationConverter::prefixToInfix(std::string inStr){

    if(!isValid(inStr)) //Checks input valditiy
        throw "Invalid entry";

    return NotationConverter::postfixToInfix(NotationConverter::prefixToPostfix(inStr)); //Converts from prefix to postfix and then from postfix to infix using existing functions

}

//This function converts and inputted string from prefix notation to postfix notation
std::string NotationConverter::prefixToPostfix(std::string inStr){

    if(!isValid(inStr)) //Checks input valditiy
        throw "Invalid entry";

    std::string postfix; //String variable used for storage and pushing to the list

    for(int i = inStr.size() - 1; i >= 0; i--){ //Loops through input

        if(isalpha(inStr[i])){ //If character is a letter

            postfix = inStr[i];
            a.insertFront(postfix); //Push to front of deque 

        }
        if((inStr[i] == '+') || (inStr[i] == '-') || (inStr[i] == '*') || (inStr[i] == '/')){ //If character is an operator
            
            std::string temp_a;
            std::string temp_b;

            temp_a = a.front(); //Pop front
            a.deleteFront();
            temp_b = a.front(); //Pop front
            a.deleteFront(); 

            postfix = temp_a + " " + temp_b + " " + inStr[i];
            a.insertFront(postfix); //Push converted section to front 
        
        }       

    }

    return a.front(); //Return front of deque
}

//This function checks if input is valid 
bool NotationConverter::isValid(std::string test){

    int flag = 1; //tracks validity of the input

    for(int i = 0; i < test.size(); i++){

        //Check if the input contains any invalid characters
        if((!isalpha(test[i])) && (test[i] != '(') && (test[i] != ')') && (test[i] != '+') && (test[i] != '-') && (test[i] != '*') && (test[i] != '/') && (test[i] != ' ')){
            flag = 0; //If true then set flag to false
            break;
        }

    }

    return flag; //returns the validity of the input
}
