# NotationConverter
Converts between popular mathematical notations: prefix, infix, and postfix, using a double ended queue.

The three notations are:

Postfix (Reverse Polish) Notation:
Operators are written after operands A B - C + == (A - B) + C

Infix Notation:
The standard notation we use where the operator is between the operands.

Prefix (Polish) Notation:
Operators are written before operands: * - A B C == (A - B) * C

The converter will is able to convert from one of those three to any other. 
The input must be a string written in a single notation, and the output will be the conversion to the specified notation.

The input string for the functions will only ever contain the standard four arithmetic operators (* / + -), an operand denoted by a letter (upper or lower case), a left or right parentheses (only round), or spaces. Whitespace (one or more characters of space) separate all operand and operators, while parentheses must have whitespace on the outside (between operators), and inside parentheses whitespace is optional. Parentheses are only used in infix strings. Parentheses must have operators between them, as all operations must be binary and not implied.

For example:

Valid Postfix: c d / a b * r r * / *
Valid Prefix: * + A B - C D
Valid Infix: ( ( X + B ) * ( Y - D ) )

Invalid Postfix: c d a b * r r * / * (Operators don’t match up with operands)
Invalid Prefix: * ^ A B & C D (Invalid Characters)
Invalid Infix: ( ( a / f ) ( ( a * b) / ( r * r ) ) ) (No operator between parentheses)

The output string always separates all operand and operators by ONLY one space. The interior of a parenthesis has no whitespace between the letter and the parenthesis or another parenthesis, while the exterior of a parenthesis is separated by ONLY one space from an operator and none for another parenthesis. 

For example:

Valid Output: ( ( x / y ) - g)
Valid Output: ( ( x / y ) - (a * b ) )
Valid Output: x y * g / h +

Abstract Class Methods:

std::string postfixToInfix(std::string inStr)
This method takes in a string of postfix notation and returns a string in the infix notation

std::string postfixToPrefix(std::string inStr)
This method takes in a string of postfix notation and returns a string in the prefix notation

std::string infixToPostfix(std::string inStr)
This method takes in a string of infix notation and returns a string in the postfix notation

std::string infixToPrefix(std::string inStr)
This method takes in a string of infix notation and returns a string in the prefix notation

std::string prefixToInfix(std::string inStr)
This method takes in a string of prefix notation and returns a string in the postfix notation

std::string prefixToPostfix(std::string inStr)
This method takes in a string of prefix notation and returns a string in the postfix notation
