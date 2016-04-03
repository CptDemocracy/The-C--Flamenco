/* "Programming Principles" by B.Stroustrup
    p.85 Exercise 6
    Write a program that prompts the user to enter three integer values, and
    then outputs the values in numerical sequence separated by commas. So,
    if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
    values are the same, they should just be ordered together. So, the input 4
    54 should give 4, 4, 5.
*/

#include <algorithm>
#include <iostream>
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

int main(void) {

    const string QUIT_CMD = "<q>";
    const string SORT_CMD = "<done>";

    void(*ON_EXIT)(void) = [](void){ cout << "Quitting..." << endl; };

    string input;

    vector<string> lines;

    cout << "Please enter lines of text you would like sorted, "
         << "\"<done>\" when ready to sort, \"<q>\" to quit the program." << endl;

    while (true) {

        getline(cin, input);
        
        if (input == QUIT_CMD) {
            (*ON_EXIT)();
            break;
        }

        if (input != SORT_CMD) {
            lines.push_back(input);
            continue;
        }

        sort(lines.begin(), lines.end());
        for (string value : lines) {
            cout << value << ' ';
        }
        cout << endl;

        lines.clear();
    }

    cin.get();
    return 0;
}
