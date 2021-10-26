#include <iostream>
#include <string>
#include "bleeper.h"

using namespace  std;

int main(int argc, char* argv[]) {
    if (argc < 3)
    {
        string word;
        string text;
        cout << "Please enter a word, followed by a phrase using that word.\n Word:";
        getline(cin, word);
        cout << "\nPhrase:";
        getline(cin,text);
        bleeper(word, text);
        cout << text << "\n";
        return 0;
    }
    string word (argv[1]);
    string text(argv[2]);

    bleeper(word, text);
    cout << word << "\n";
    cout << text;
    return 0;
}
