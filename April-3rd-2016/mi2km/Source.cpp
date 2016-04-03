
/* "Programming Principles" by B.Stroustrup

    p.85 Exercise 1
    Write a program in C++ that converts from miles to kilometers. Your
    program should have a reasonable prompt for the user to enter a number
    of miles. Hint: There are 1.609 kilometers to the mile.
*/

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>

#include "Converter.h"

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

using std::getline;
using std::strtod;
using std::string;
using std::runtime_error;

bool tryParseDouble(const char* cstr, double* OutResult);

int main(void){
    
    constexpr double KM_TO_MI = 1.609;

    Converter milesToKm([](double miles) { return miles / 1.609; });

    double miles = 0.0;
    double km = 0.0;

    string input;

    cout << "Please enter the number of miles you would like to convert to km." << endl;
    while (true) {

        getline(cin, input);

        if (!tryParseDouble(input.c_str(), &miles)) {
            cerr << "Input invalid." << endl;
            continue;
        }
        km = milesToKm(miles);

        cout << "There are " << km << " km in " << miles << " miles." << endl;
        break;
    }
    cin.get();

    return 0;
}

bool tryParseDouble(const char* cstr, double* OutResult) {
    if (cstr == nullptr) {
        throw runtime_error("cstr cannot be a nullptr");
    }
    
    if (OutResult == nullptr) {
        throw runtime_error("OutResult cannot be a nullptr");
    }
    
    // skip whitespace at the end of the cstring
    const char* end = &cstr[0];
    while (*end) ++end;

    // parse
    double value = 0.0;
    char* parseEnd = nullptr;
    value = strtod(cstr, &parseEnd);
    
    // see if the number was indeed a number
    if (end == parseEnd) {
        *OutResult = value;
        return true;
    }
    return false;
}
