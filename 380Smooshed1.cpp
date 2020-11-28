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
        toTranslate[i] = tolower(toTranslate[i]);
        countSpaces = toTranslate[i] - 97;
        index = 0;

        for (int k = 0; k < countSpaces;  k++)
        {
            index = smooshed.find(' ', index + 1);
        }

        for ( int j = index + bool(index) ; (smooshed[j] == '\0' || smooshed[j] != ' ') ; j++)
        {
            cout << smooshed[j];
        }

    }

}