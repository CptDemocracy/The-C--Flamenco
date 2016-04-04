#include <iostream>
#include <cctype>
#include <memory>
#include <string>
#include <map>

/*
    "Programming Principles" by B.Stroustrup
     p.86 Exercise 9

     Write a program that converts spelled·out numbers such as "zero" and
     "two" into digits, such as 0 and 2. Then the user inputs a number, the
     program should print out the corresponding digit.
*/

using std::unique_ptr;
using std::getline;
using std::string;
using std::cout;
using std::endl;
using std::map;
using std::cin;

int main(void) {

    constexpr int BUFFER_INIT_CAPACITY = 16;
    constexpr char* INPUT_DELIMS = " ";

    map<string, int> wordsToDigits;

    wordsToDigits["zero"]  = 0;
    wordsToDigits["one"]   = 1;
    wordsToDigits["two"]   = 2;
    wordsToDigits["three"] = 3;
    wordsToDigits["four"]  = 4;
    wordsToDigits["five"]  = 5;
    wordsToDigits["six"]   = 6;
    wordsToDigits["seven"] = 7;
    wordsToDigits["eight"] = 8;
    wordsToDigits["nine"]  = 9;

    string input;
    size_t inputLen = 0;

    unique_ptr<char> buffer((char*)calloc(BUFFER_INIT_CAPACITY, sizeof(char)));
    if (buffer.get() == nullptr) {
        return 1;
    }
    size_t bufferCapacity = BUFFER_INIT_CAPACITY;

    char* token = nullptr;
    char* tokenBeginPtr = nullptr;
    char* tokenEndPtr = nullptr;
    char* tokenCharPtr = nullptr;

    while (true) {
        getline(cin, input);    

        // allocate more memory only when absolutely required
        // mem alloc calls are expensive, we need to use them
        // wisely
        inputLen = input.length();
        if (inputLen + 1 > bufferCapacity) {
            size_t newBufferCapacity 
                = (inputLen + 1 > bufferCapacity * 2) ? inputLen + 1 : bufferCapacity * 2;
            buffer.reset((char*)calloc(newBufferCapacity, sizeof(char)));
            if (buffer.get() == nullptr) {
                return 1;
            }
            bufferCapacity = newBufferCapacity;
        }

        strcpy(buffer.get(), input.c_str());
        token = strtok(buffer.get(), INPUT_DELIMS);

        while (token) {    
            
            // convert token to lowercase            
            tokenBeginPtr = &token[0];
            tokenEndPtr = tokenBeginPtr;
            while (*tokenEndPtr) ++tokenEndPtr;
            tokenCharPtr = tokenBeginPtr;
            while (tokenCharPtr < tokenEndPtr) {
                *tokenCharPtr = tolower(*tokenCharPtr);
                ++tokenCharPtr;
            }
            
            // map token to a digit if in the dictionary
            auto iterval = wordsToDigits.find(string(token));
            if (iterval != wordsToDigits.end()) {
                cout << iterval->second << ' ';
            } else {
                cout << token << ' ';
            }

            // alternative exception-based method for mapping
            // it is slower, but in some cases, more readable
            /*try {
                int digit = wordsToDigits.at(string(token));
                cout << digit << ' ';
            } catch (std::invalid_argument) {
                cout << token << ' ';
            }*/

            token = strtok(nullptr, INPUT_DELIMS);
        }
        cout << endl;
    }

    return 0;
}
