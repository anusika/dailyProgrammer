#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;
void getRoll(string entry);

int main(int argc, char *argv[])
{


    if (argc == 1)
    {
        cout << "no command line arguments given\n";
        exit(1);
    }
    //add entrys to global vector of strings
    for (int i = 1; i < argc; i++)
    {
        getRoll(argv[i]);
    }
}

/*entry in form NdM
The first number is the number of dice to roll, the d just means "dice",
 it's just used to split up the two numbers, and the second number is how many sides the dice have. 
 --from https://www.reddit.com/r/dailyprogrammer/comments/8s0cy1/20180618_challenge_364_easy_create_a_dice_roller/
prints numbers rolled and total sum
*/
void getRoll(string entry){
    int sum = 0;
    int randNum = 0;
    int indexD = entry.find('d');

    //reinatialize random seed
    srand (time(NULL));

    //invalid string found if d is not in string
    if (indexD == -1)
    {
        cout << "invalid entry: " << entry << "\n"; 
        return;
    }

    int diceNumber = stoi(entry.substr(0, indexD));
    int diceSide = stoi(entry.substr(indexD + 1));

    for (int i = 0; i < diceNumber; i++)
    {
        randNum =  rand() % diceSide + 1; //number in range 1:diceSide
        sum += randNum;
        cout << randNum << " ";
    }

    cout << ": " << sum << "\n";
}