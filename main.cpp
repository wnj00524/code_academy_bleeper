#include <iostream>
#include <fstream>
#include <string>
#include "bleeper.h"

using namespace  std;

int main(int argc, char* argv[]) {
    string word, text;
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
    if (argc == 4)
    {
        //cout << "Got four...\nNum 1 = " << argv[1] << "\nArg 2 = " << argv[2] << "\nArg 3 = " << argv[3] << "\n";
        if (strcmp(argv[1],"-f") == 0)
        {
            //cout << "Got to the -f check...\n";
           std::ifstream  ifs(argv[2]);
           string text((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
           string word = argv[3];
            bleeper(word, text);
           cout << "Word = " << word << "\n";
           cout << "Data saved in out.txt\n";
           ofstream out("out.txt");
           out << text;
           out.close();
            return 0;

        }
    }
    else {
        string word(argv[1]);
        string text(argv[2]);
    }
    bleeper(word, text);
    cout << "Word = " << word << "\n";
    cout << "Text = " << text << "\n";
    return 0;
}
