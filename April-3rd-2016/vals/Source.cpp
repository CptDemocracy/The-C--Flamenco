/* "Programming Principles" by B.Stroustrup
    p.85 Exercise 4
    Write a program that prompts the user to enter two integer values. Store
    these values in int variables named vall and val2. Write your program to
    determine the smallest, largest, sum, difference, product, and ratio of
    these values and report them to the user.
*/

#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>

#include <crtdbg.h>

using std::cout;
using std::endl;
using std::cin;
using std::strtok;
using std::string;
using std::getline;
using std::unique_ptr;
using std::runtime_error;

bool tryParseLong(const char* cstr, long* OutResult);

int main(void) {

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    const char* INPUT_DELIMS = " ";
    const string INPUT_INVALID_MSG = "Input invalid.";

    long val1 = 0L;
    long val2 = 0L;
    string input;
    
    long smallest = 0L;
    long largest = 0L;
    long sum = 0L;
    long difference = 0L;
    long product = 0L;
    double ratio = 0.0;

    cout << "Please enter two integer numbers: ";

    while (1) {
        getline(cin, input);        

        // reserve an extra byte for the null terminating char
        // we will need this buffer to tokenize user input for validation
        unique_ptr<char> buffer((char*)calloc(input.length() + 1, sizeof(char)));

        // tokenize input, remember, we need to parse
        // two numbers on one line
        strcpy(buffer.get(), input.c_str());

        char* token = nullptr;
        token = strtok(buffer.get(), INPUT_DELIMS);

        // if not a number, prompt again
        if (!token || !tryParseLong(token, &val1)) {
            cout << INPUT_INVALID_MSG << endl;
            continue;
        }

        token = strtok(NULL, INPUT_DELIMS);

        // if not a number, prompt again
        if (!token || !tryParseLong(token, &val2)) {
            cout << INPUT_INVALID_MSG << endl;
            continue;
        }
        
        // if there is any trailing irrelevant input
        // token will NOT be a nullptr, - signal an error
        token = strtok(NULL, INPUT_DELIMS);
        if (token) {
            cout << INPUT_INVALID_MSG << endl;
            continue;
        }
        
        cout << "val1 = " << val1 << endl 
             << "val2 = " << val2 << endl;

        if (val1 == val2) {
            smallest = val1;
            largest = val1;
            cout << "val1 and val2 are both equal." << endl;
        }

        if (val1 < val2) {
            smallest = val1;
            largest = val2;
        }
        else if (val1 > val2) {
            smallest = val2;
            largest = val1;
        }
        cout << "smallest = " << smallest << endl
             << "largest  = " << largest  << endl;

        sum = val1 + val2;
        cout << "sum = " << sum << endl;

        difference = val1 - val2;
        cout << "difference = " << difference << endl;

        product = val1 * val2;
        cout << "product = " << product << endl;

        ratio = val1 / static_cast<double>(val2);
        cout << "ratio = " << ratio << endl;

        break;
    }    
    cin.get();

    return 0;
}

bool tryParseLong(const char* cstr, long* OutResult) {
    if (cstr == nullptr) {
        throw runtime_error("cstr cannot be a nullptr.");
    }
    if (OutResult == nullptr) {
        throw runtime_error("OutResult cannot be a nullptr.");
    }
    static const int RADIX = 10;

    // locate the end of the string
    const char* end = &cstr[0];
    while (*end) ++end;
    
    // skip whitespace at the end of the cstring
    while (end > cstr && isspace(*end)) --end;

    // parse
    long value = 0L;
    char* parseEnd = nullptr;
    value = strtol(cstr, &parseEnd, RADIX);
    
    // see if the number was indeed a number
    if (end == parseEnd) {
        *OutResult = value;
        return true;
    }
    return false;
}
