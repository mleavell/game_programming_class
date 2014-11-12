#include <iostream>
#include <string>
using namespace std;

string remove (string input, char character) {
    string result;
    if (input.find(character) != string::npos) {
        int loc = input.find(character);
        int numOfLetters = input.length() - loc;
        string begin = input.substr(0, loc);
        string end = input.substr(loc+1, numOfLetters);
        result = begin + end;
    } else {
        result = input;
    }
    return result;
}

int main(void) {
    string blah = "Hello World";
    char ball = 'e';
    cout << remove(blah, ball) + "\n";
    return 0;
}