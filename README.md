# Valid Input
Specific valid input methods in C++ and C# for different datatypes. Below I'll cover the C++ version. The C# version is similar.

The purpose of the program is to validate input from the user as user input is unpredicable, so it is important to make sure we have accounted for input that may break our programs. It will cover string, int, double, and character validation. This program is made so that one can avoid using a ton of if/else if/or/and/switch statements.

In addition, the program will go over removing specific characters from a string. Input will be primarily received through the getline command. However, I have provided an example of how to use scanf to continuously read input (to make it function like getline) at the end of the program.

**Specific Character Validation**
-----
Below is the getStr function where the function will continue looping until we receive a string without any numbers and spaces. The code can easily be altered to only accept specific characters by adding or removing characters in the allowedChars variable. Included in the code is an integer and character version.

```cpp
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
```

**Type Only Validation**
-----
Below is a portion of the code used to only validate if we are receiving the right data type from the user. To call this function we have defined it using a preprocessor macro called GETVAL. An example of calling it to validate a double input would be like so: ```double ourDouble = GETVAL(double)```. We can replace the double type with any other type making this function very flexible. However, it does not check for specific input like our previous function does.

```cpp
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
```

**Other Functions**
-----
There are more functions included in the file, but the two above are the main types. One of the other functions uses scanf to emulate the getline function while the last function shows how we can remove specific characters from a string.

**Code in Action**
-----
Below is an example of what the console would output given input:

```
Type in a number: 12
Your number is: 12
Type in a string without any numbers or spaces: reg
Your string is: reg
Type in a char: j
Your character is: j
Enter an input of type int: 23
Enter an input of type double: 24.4
Enter an input of type std::string: A string
Invalid Input. Try again: Enter an input of type std::string: string  
Enter an input of type char: h
Enter a number (1 - 2): 1
Your number is: 1
Type in a string (spaces, parentheses, numbers, and dashes will be removed): B(12r3)-3456r 7890A 
Your string is: BrrA
```
