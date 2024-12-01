#include <iostream>
#include <iomanip> // formatting a double-precision number
#include <string>

using namespace std; // to avoid repeating std::

double extractNumeric(const string& str) { // function extracts numeric value from given string
    bool hasDecimal = false; // used to indicate if the given string has a decimal point in it
    bool hasSign = false; // used to indicate if the given string has a sign in it
    double result = 0.0; // stores integer value of the number
    double fractionalPosition = 0.0; // stores fractional value of the number
    int decimalPosition = 1; // used to scale fractional part

    int length = str.length(); // gets the length of the given string
    if (length > 20) { // returns invalid input if given string is longer than 20 characters
        return -999999.99;
    }

    int i = 0;
    if (str[i] == '+' || str[i] == '-') { // checks to see if there is a sign in the given string
        hasSign = true;
        i++;
    }

    for (; i < length; i++) { // loops through the characters in the given string
        if (str[i] >= '0' && str[i] <= '9') { // checks to see if the character is a digit
            if (!hasDecimal) {
                result = result*10 + (str[i] - '0'); // add to the integer part if there is not a decimal point
            }
            else {
                fractionalPosition = fractionalPosition*10 + (str[i] - '0'); // add to the fractional part if there is a decimal point
                decimalPosition *= 10; // scale
            }
        }
        else if (str[i] == '.') { // checks to see if the character is a decimal point
            if (hasDecimal) {
                return -999999.99; // returns -999999.99 if there already is a decimal point
            }
            hasDecimal = true;
        }
        else {
            return -999999.99; // returns -999999.99 if the character is not a digit or a decimal point
        }
    }
    if (hasDecimal) { // if there is a decimal point in the given string, adjust result to include fractional
        result += fractionalPosition/decimalPosition;
    }
    if (hasSign) { // if there is a sign in the given string
        if (str[0] == '-') { // if the sign in the given string is negative, apply it to the result
            result = -result;
        }
    }
    return result;
}

int main() { // function gets user input and calls extractNumeric
    string input; // stores user input
    
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") { // if the user inputs 'END', then it kills the program
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) { // if the number is valid, display the number with four decimal places
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
        else { // if the number is invalid, display a message that states so
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}
