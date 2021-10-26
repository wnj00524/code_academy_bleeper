#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bleeper.h"

using namespace std;

using std::string;
using std::cout;
using std::cin;

int main(int argc, char* argv[]) {
    string word, text;
    if (argc == 2  && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1],"-H") == 0))
    {
        cout << "Handy censor tool! Use without parameters to be prompted to provide text and a watch word. \n-f filename1 word = run the word against filename1. Saves output in output.txt\n-c datafile wordfile outputfile = Run the words in wordfile against datafile and save in outputfile.\n";
        return 0;
    }
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
    if (argc == 5)
    {

        if (strcmp(argv[1],"-c") == 0)
        {

            std::ifstream  ifs(argv[2]);
            if (ifs.good())
            {

                std::vector<std::string> words;
                std::ifstream wfs(argv[3]);
                std::string line;
                if (wfs.good())
                {
                    string text((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
                    while (getline(wfs,line))
                    {
                        words.push_back(line);
                    }
                    for (int a = 0; a < words.size(); a++)
                    {
                        bleeper(words[a],text);
                    }
                    ofstream out(argv[4]);
                    if (out.good()) {
                        out << text;
                        out.close();
                        std::cout << "Ran the words in " << argv[4] << " against " << argv[3] << " and saved in "
                                  << argv[4] << "\n";
                    }
                    else {
                        std::cout << "Unable to save to " << argv[4] << "\n";
                    }
                    return 0;

                }
                else
                {
                    cout << "Word list file  not found.\n";
                    return 0;
                }
            }
            else
            {
                std::cout << "Data file not found.\n";
            }
            return 0;

        }
        //cout << "Got four...\nNum 1 = " << argv[1] << "\nArg 2 = " << argv[2] << "\nArg 3 = " << argv[3] << "\n";
        else if (strcmp(argv[1],"-f") == 0)
        {
            //cout << "Got to the -f check...\n";
           std::ifstream  ifs(argv[2]);
           if (ifs.good())
           {
               string text((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
               string word = argv[3];
               ofstream out("out.txt");
               bleeper(word, text);
               out << text;
               out.close();
               cout << "Word = " << word << "\n";
               cout << "Data saved in out.txt\n";
           }
           else
           {
               cout << "File " << argv[2] << " could not be found.\n";
           }





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
