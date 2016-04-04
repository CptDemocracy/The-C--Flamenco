
/*
    "Programming Principles" by B.Stroustrup
     p.86 Exercise 10

    Write a program that takes an operation followed by two operands and
    outputs the result. For example:
    + 100 3.14
    * 45
*/

#include <iostream>
#include <memory>
#include <string>
#include <map>

using std::invalid_argument;
using std::numeric_limits;
using std::domain_error;
using std::streamsize;
using std::unique_ptr;
using std::string;
using std::stod;
using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::map;

typedef double (*MathBinaryOpFuncPtr) (double, double);

int main(void) {

    constexpr size_t BUFFER_CAPACITY = 8;
    
    map<string, MathBinaryOpFuncPtr> mathOps;

    mathOps["+"] = []( double val1, double val2) { 
            return val1 + val2; 
        };

    mathOps["-"] = []( double val1, double val2) { 
            return val1 - val2; 
        };

    mathOps["*"] = []( double val1, double val2) { 
            return val1 * val2; 
        };

    mathOps["/"] = []( double val1, double val2) { 
            if (val2 == 0.0) { 
                throw domain_error(""); 
            }
            return val1 / val2; 
        };

    string optor;
    string oprnd1;
    string oprnd2;

    double value1 = 0.0;
    double value2 = 0.0;
    double result = 0.0;

    unique_ptr<char> buffer((char*)calloc(BUFFER_CAPACITY, sizeof(char)));
    if (buffer.get() == nullptr) {
        cerr << "Out of memory." << endl;
        return 1;
    }
    while (true) {
        try {
            cout << ">>> ";
            cin >> optor >> oprnd1 >> oprnd2;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            value1 = stod(oprnd1);
            value2 = stod(oprnd2);

            strncpy(buffer.get(), optor.c_str(), BUFFER_CAPACITY - 1);
            
            // trim whitespace
            char* pBegin = &buffer.get()[0];
            char* pEnd = pBegin;
            while (*pEnd) ++pEnd;
            while (pBegin < pEnd && isspace(*pBegin)) {
                *pBegin = '\0';
                ++pBegin;
            }
            while (pEnd > pBegin && isspace(*pEnd)) {
                *pEnd = '\0';
                --pEnd;
            }

            auto exppair = mathOps.find(optor);
            if (exppair != mathOps.end()) {
                result = exppair->second(value1, value2);
            }
            
            cout << result << endl;
            
        } catch (const domain_error&) {
            cerr << "Domain error has occured during calculation." << endl;
        } catch (const invalid_argument&) {
            cerr << "Please enter an operator followed by two values." << endl;
            continue;
        }        
    }

    return 0;
}
