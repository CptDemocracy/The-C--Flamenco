/* "Programming Principles" by B.Stroustrup
    p.85 Exercise 6
    Write a program that prompts the user to enter three integer values, and
    then outputs the values in numerical sequence separated by commas. So,
    if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
    values are the same, they should just be ordered together. So, the input 4
    54 should give 4, 4, 5.
*/

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::sort;
using std::string;
using std::vector;
using std::getline;
using std::unique_ptr;
using std::runtime_error;
using std::invalid_argument;

bool tryParseLong(const char* cstr, long* OutResult);

int main(void) {

    const string INPUT_INVALID_MSG = "Input invalid";
    const string QUIT_CMD = "q";
    const char* INPUT_DELIMS = " ";

    void(*ON_EXIT)(void) = [](void){ cout << "Quitting..." << endl; };

    string input;
    char* token = nullptr;

    vector<long> values;
    long value = 0L;

    cout << "Please enter integer numbers you would like sorted: " << endl;
    while (true) {
        try {
            getline(cin, input);
        
            if (input == QUIT_CMD) {
                (*ON_EXIT)();
                break;
            }

            // allocate an extra byte for the null-terminating character
            unique_ptr<char> buffer((char*)calloc(input.length() + 1, sizeof(char)));
            
            if (buffer.get() == nullptr) {
                throw runtime_error("Out of memory.");
            }

            strcpy(buffer.get(), input.c_str());
        
            token = strtok(buffer.get(), INPUT_DELIMS);
            while (token) {
                if (!tryParseLong(token, &value)) {
                    throw invalid_argument("argument invalid");
                }
                values.push_back(value);
                token = strtok(nullptr, INPUT_DELIMS);
            }

            sort(values.begin(), values.end());
            for (long value : values) {
                cout << value << ' ';
            }
            cout << endl;

            values.clear();
        } catch (const invalid_argument&) {
            cerr << INPUT_INVALID_MSG << endl;
            values.clear();
            continue;
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            abort();
        }
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
