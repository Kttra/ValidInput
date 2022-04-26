using System;
using System.Collections.Generic; //List
using System.Text.RegularExpressions; //regex
using System.Linq; //any
/*  Program created by Kttra
 
    The purpose of the program is to show different ways to validate
    input. This is inspired by my C++ program that does the same thing.
*/

namespace cSharpTesting
{
    class Program
    {
        public static void Main(string[] args)
        {
            //Ask user for integer input
            int num = getInt();
            Console.WriteLine($"Your integer is: {num}");

            //Ask user for double input
            double decimalNum = getDecimal();
            Console.WriteLine($"Your decimal number is: {decimalNum}");

            //Unwanted characters, string does not contain specific characters [whitespace, 0-9, +, -, /, *, (, )]
            string myString = getSpecificString();
            Console.WriteLine($"Your string is {myString}");

            //Wanted characters, string does contain specific characters [whitespace, 0-9, +, -, /, *, (, )]
            myString = getSpecificString2();
            Console.WriteLine($"Your string is {myString}");

            //Remove specific Characters, remove numbers
            myString = editString();
            Console.WriteLine("Your string with removed numbers is: " + myString);

            //Faster removal method, remove numbers
            Console.WriteLine("Enter a string (faster removal, removes numbers): ");
            myString = Console.ReadLine();
            //var unwantedChars = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //Can also pass unwantedChars
            myString = myString.RemoveCharacters('0', '1', '2', '3', '4', '5', '6', '7', '8', '9');
            Console.WriteLine($"Your string is: {myString}");


        }
        //Get an integer input, can rewrite for double, bool, float, char
        public static int getInt()
        {
            Console.Write("Input a number: ");
            string input = Console.ReadLine();

            int num;
            while (!int.TryParse(input, out num))
            {
                Console.Write("Invalid! Try again: ");
                input = Console.ReadLine();
            }

            return num;
        }
        //Get a decimal input
        public static double getDecimal()
        {
            Console.Write("Input a decimal: ");
            string input = Console.ReadLine();

            double decimalNum;
            while (!double.TryParse(input, out decimalNum))
            {
                Console.Write("Invalid! Try again: ");
                input = Console.ReadLine();
            }

            return decimalNum;
        }
        //Get a specific string with only specific characters (checks for unwanted characters)
        public static string getSpecificString()
        {
            Console.Write("Input a string (cannot contain spaces, 0-9, +, -, /, *, (, ), ,): ");
            string userInput = Console.ReadLine();

            for (; ; )
            {
                //Can change the unwanted characters here
                Regex Validator = new Regex(@"[0-9+\-/*(),]");

                //If there are no unwanted characters, exit and return the string
                //If we want whitespace specifically, userInput.Any(x => Char.IsWhiteSpace(x))
                if (!Validator.IsMatch(userInput) && !userInput.Contains(" "))
                {
                    break;
                }
                Console.Write("Invalid! Try again: ");
                userInput = Console.ReadLine();
            }

            return userInput;
        }
        //Get a specific string allowing only specific characters (wanted characters)
        public static string getSpecificString2()
        {
            Console.Write("Input a string (spaces, 0-9, +, -, /, *, (, ), , are allowed): ");
            string userInput = Console.ReadLine();

            for (; ; )
            {
                //Can change the wanted characters here
                Regex Validator = new Regex(@"^[0-9+\-/*(), ]+$");

                //If there are no unwanted characters, exit and return the string
                if (Validator.IsMatch(userInput))
                {
                    break;
                }
                Console.Write("Invalid! Try again: ");
                userInput = Console.ReadLine();
            }

            return userInput;
        }
        public bool FormatValid(string format)
        {
            string allowableLetters = "yYmMdDsShH";

            foreach (char c in format)
            {
                if (!allowableLetters.Contains(c.ToString()))
                {
                    return false;
                }
            }

            return true;
        }
        //Get a string while removing specific characters
        public static string editString()
        {
            Console.Write("Input a string (numbers will be removed): ");
            string userInput = Console.ReadLine();

            //Add or remove elements from the array to change what will be removed
            var charsToRemove = new string[] { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
            foreach (var c in charsToRemove)
            {
                userInput = userInput.Replace(c, string.Empty);
            }

            return userInput;
        }
        //Functions below aren't used in this program, but are good example of how to use regex
        public bool IsAlpha(string input)
        {
            return Regex.IsMatch(input, "^[a-zA-Z]+$");
        }
        public bool IsAlphaNumeric(string input)
        {
            return Regex.IsMatch(input, "^[a-zA-Z0-9]+$");
        }
        public bool IsAlphaNumericWithUnderscore(string input)
        {
            return Regex.IsMatch(input, "^[a-zA-Z0-9_]+$");
        }
    }
    //Faster character removal from a string
    public static class StringEx
    {
        public static string RemoveCharacters(this string s, params char[] unwantedCharacters)
            => s == null ? null : string.Join(string.Empty, s.Split(unwantedCharacters));
    }
}
