#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::sort;

int main()
{
    ifstream wordslist;
    string x;
    string given_letters;
    char anchor_letter;
    int anchor_letter_position;
    int n;
    int counter;
    cin >> given_letters;
    bool anchor_present;
    n = given_letters.size();
    cout << "Enter the position of the letter in the word which is to be always considered (first letter indexed as 1): "<<endl;
    cin >> anchor_letter_position;
    if(anchor_letter_position > n)
    {
        cout<<("Invalid Input")<<endl;
        exit(1);
    }
    anchor_letter = given_letters[anchor_letter_position - 1];
    sort(given_letters.begin(), given_letters.end());

    wordslist.open("listofwords.txt");
    if(wordslist.is_open())
    {
        while(wordslist.good())
        {
            wordslist >> x;
            counter = 0;
            anchor_present = false;
            for(int i = 0; i < x.size(); i++)
            {
                for(char j : given_letters)
                {
                    if(x[i] == j)
                    {
                        counter++;
                    }
                }
            }
            for(char i : x)
            {
                if(i == anchor_letter)
                {
                    anchor_present = true;
                }
            }
            if(counter == x.size() && anchor_present)
            {
                cout<<x<<" is a valid word for the given combination of letters"<<endl;
            }
        }
    }    
    return 0;
}
