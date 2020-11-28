#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string get_valid_string(void);
void smorse(string toTranslate);

int main(void)
{
    string toTranslate = get_valid_string();
    smorse(toTranslate);
}

string get_valid_string(){

    string content;
    bool notValid = true;

    while(notValid)
    {
        // get user input
        cout << "What would you like to translate?";
        cin >> content;

        // string is too small
        if (content.length() < 1) {
            continue;
        }

        else {

            for (int i = 0; i < content.length(); i++)
            {
                // program does not work with numbers  
                if (isdigit(content[i]))
                {
                    break;
                }

                //string has no digits
                if (i == (content.length() -1 ))
                {
                    notValid = false;
                }
            }
        }

    } 

    return content;

}

void smorse(string toTranslate)
{
    string smooshed = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..";
    int countSpaces = 0;
    int index = 0;
    for (int i = 0; i < toTranslate.length(); i++)
    {
        // find how many spaces we need to skip to get to letter
        toTranslate[i] = tolower(toTranslate[i]);
        countSpaces = toTranslate[i] - 97;
        index = 0;

        //get index by skipping the amount of spaces we calculated above
        for (int k = 0; k < countSpaces;  k++)
        {
            index = smooshed.find(' ', index + 1);
        }

        //only print until end of string or next space is reached
        //adding bool(index) because if index is 0 we should start at beginning of string
        //otherwise start at position after space
        for ( int j = index + bool(index) ; (smooshed[j] == '\0' || smooshed[j] != ' ') ; j++)
        {
            cout << smooshed[j];
        }

    }

}