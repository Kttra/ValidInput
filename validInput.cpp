/*  Program made by Kttra

    The purpose of the program is to validate input from the user. It will cover   
    string, int, double, and character validation. This program is made so that
    one can avoid using a ton of if/else if/or/and/switch statements.
    
    In addition, the program will go over removing specific characters from a 
    string. Input will be received through the getline command.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstring> //strlen
#include <algorithm> //std::remove

//Preprocessor macro, stringifies the name of the type and forwards it to our function
#define GETVAL(type) getVal<type>(#type)
using std::cout;
using std::cin;
using std::endl;
using std::string;

int getNumber();
string getStr();
char getChar();
template<typename TYPE> TYPE getVal(const char* type_str);
bool isValid(int ourNum, int numArgsRead);
void removeCharsFromString(string &str);

int main()
{
    //Int validation
    cout << "Type in a number: ";
    int number = getNumber();
    cout << "Your number is: " << number << endl;
    
    //String validation
    cout << "Type in a string without any numbers or spaces: ";
    string str = getStr();
    cout << "Your string is: " << str << endl;
    
    //Character validation
    cout << "Type in a char: ";
    char aChar = getChar();
    cout << "Your character is: " << aChar << endl;
    
    //Type validation only, doesn't look for specific characters
    int i = GETVAL(int);
    double d = GETVAL(double);
    str = GETVAL(std::string) ;
    aChar = GETVAL(char);

    //Normal validation, Scanf method
    int ourInt;
    int numArgsRead;
    //Checking for valid input
    /*  %c = character
        %d = integer
        %s = string
        %lf = double
    */
    do{
        std::cout << "Enter a number (1 - 2): ";
        numArgsRead = scanf("%d", &ourInt);
    }while(isValid(ourInt, numArgsRead));
    cout << "Your number is: " << ourInt << endl;

    //Removing specific characters from a string
    cout << "Type in a string (spaces, parentheses, numbers, and dashes will be removed): ";
    getline(cin, str);
    removeCharsFromString(str);
    cout << "Your string is: " << str << endl;

    return 0;
}

//Get a number
int getNumber(){
    string theInput;
    int inputAsInt;

    getline(cin, theInput);
    string allowedChars = "0123456789"; //Specific characters we allow

    //If we don't get the correct input, repeat
    while(cin.fail() || cin.eof() || theInput.find_first_not_of(allowedChars) != string::npos) {
        cout << "Invalid Input. Try again: ";

        //Searches the string for the first character that does not match any of the characters
        //specified in its arguments.
        if(theInput.find_first_not_of(allowedChars) == string::npos) {
            cin.clear();
            cin.ignore(256,'\n');
        }
        getline(cin, theInput);
    }

    //Convert to integer
    string::size_type st;
    inputAsInt = stoi(theInput,&st);

    return inputAsInt;
}

//Get a string
string getStr(){
    string theInput;
    int inputAsInt;

    getline(cin, theInput);
    string allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //Specific characters we allow

    //If we don't get the correct input, repeat
    while(cin.fail() || cin.eof() || theInput.find_first_not_of(allowedChars) != string::npos) {
        cout << "Invalid Input. Try again: ";

        //Searches the string for the first character that does not match any of the characters
        //specified in its arguments.
        if(theInput.find_first_not_of(allowedChars) == string::npos) {
            cin.clear();
            cin.ignore(256,'\n');
        }
        getline(cin, theInput);
    }

    return theInput;
}

//Get a single character
char getChar(){
    string theInput;
    int inputAsInt;

    getline(cin, theInput);
    string allowedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 "; //Specific characters we allow

    //If we don't get the correct input, repeat
    while(cin.fail() || cin.eof() || theInput.find_first_not_of(allowedChars) != string::npos || theInput.length() != 1) {
        cout << "Invalid Input. Try again: ";

        //Searches the string for the first character that does not match any of the characters
        //specified in its arguments.
        if(theInput.find_first_not_of(allowedChars) == string::npos && theInput.length() == 1) {
            cin.clear();
            cin.ignore(256,'\n');
        }
        getline(cin, theInput);
    }

    //Since the input is saved as a string, we can just return the 1st index as the string will be length 1
    return theInput[0];
}

//Get valid input of different types, int, double, string
template<typename TYPE> TYPE getVal(const char* type_str){
    std::cout << "Enter an input of type " << type_str << ": ";

    TYPE value ;
    // return valid input of the correct type, immediately followed by a new line
    if(std::cin >> value && std::cin.get() == '\n') return value;

    // return not executed; input error
    std::cout << "Invalid Input. Try again: " ;
    std::cin.clear() ;
    std::cin.ignore(1000, '\n') ;
    return getVal<TYPE>(type_str) ;
}

//Scanf validation
bool isValid(int ourNum, int numArgsRead){
    bool valid = (numArgsRead == 1);
	char lastChar;

    //Reads any other inputs in the event user input had spaces
	do{
		scanf("%c", &lastChar);
		if(!isspace(lastChar)){
		}
	}while(lastChar != '\n');

    switch(ourNum){
        case 1:
            return false;
            break;
        case 2:
            return false;
            break;
        default:
            std::cout << "Invalid! Try again." << std::endl;
            return true;
            break;
    }

	return valid;
}

//Remove specific characters from a string, pass by reference
void removeCharsFromString(string &str){
//Array of characters to remove from the string	
    char charsToRemove[] = "1234567890()- ";

   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}
