//
// Created by jdwil on 25/10/2021.
//

#include "bleeper.h"
#include <iostream>
#include <cctype>

void bleeper(std::string word, std::string &sentence)
{
    if (sentence.size() < word.size()) return;
    for (int a = 0; a < sentence.size() - word.size(); a++)
    {
        char check_char = tolower(sentence[a]);
        if (check_char == tolower(word[0]))
        {
            bool ismatch = true;
            for (int b = a; b < a + word.size(); b++)
            {

                if (tolower(sentence[b]) != tolower(word[b-a])) ismatch = false;

            }
            if (ismatch)
            {
                for (int b = a; b < ((a + word.size())); b++)
                {
                    sentence[b] = '*';
                }
            }
            a = a + word.size();
        }
    }
}