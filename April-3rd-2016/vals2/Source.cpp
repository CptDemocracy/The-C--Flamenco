/* "Programming Principles" by B.Stroustrup
    p.85 Exercise 5
    Modify the program above (p.85 Exercise 4) to ask the user 
    to enter floating point values and store them in double variables. 
    Compare the outputs of the two programs for some inputs of your choice.
*/

#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::strtok;
using std::string;
using std::getline;
using std::unique_ptr;
using std::runtime_error;

bool tryParseDouble(const char* cstr, double* OutResult);

int main(void) {

    const char* INPUT_DELIMS = " ";
    const string INPUT_INVALID_MSG = "Input invalid.";

    double val1 =  0.0;
    double val2 =  0.0;
    string input;
    
    double smallest =  0.0;
    double largest =  0.0;
    double sum =  0.0;
    double difference =  0.0;
    double product =  0.0;
    double ratio = 0.0;

    cout << "Please enter two floating point numbers: ";

    try {
        while (1) {
            getline(cin, input);        
    
            // reserve an extra byte for the null terminating char
            // we will need this buffer to tokenize user input for validation
            unique_ptr<char> buffer((char*)calloc(input.length() + 1, sizeof(char)));
            
            if (buffer.get() == nullptr) {
                throw runtime_error("Out of memory.");
            }
    
            // tokenize input, remember, we need to parse
            // two numbers on one line
            strcpy(buffer.get(), input.c_str());
    
            char* token = nullptr;
            token = strtok(buffer.get(), INPUT_DELIMS);
    
            // if not a number, prompt again
            if (!token || !tryParseDouble(token, &val1)) {
                cout << INPUT_INVALID_MSG << endl;
                continue;
            }
    
            token = strtok(NULL, INPUT_DELIMS);
    
            // if not a number, prompt again
            if (!token || !tryParseDouble(token, &val2)) {
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
    
            ratio = val1 / val2;
            cout << "ratio = " << ratio << endl;
    
            break;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        abort();
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
    
    // locate the end of the string
    const char* end = &cstr[0];
    while (*end) ++end;
    
    // skip whitespace at the end of the cstring
    while (end > cstr && isspace(*end)) --end;

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
