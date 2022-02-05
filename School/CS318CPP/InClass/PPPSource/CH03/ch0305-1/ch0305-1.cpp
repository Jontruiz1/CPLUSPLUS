// ch0305-1

#include "..\libroot\std_lib_facilities.h" //location of header in CH03 Solution

int main()
{
    string previous = " ";       // not a word
    string current;
    cout << "Enter a sequence of words (to end stream enter end): ";
    while (cin>>current) {       // read a stream of words
        if (current != "end") {
            if (previous == current) // check if the word is the same as last
                cout << "repeated word: " << current << '\n';
            previous = current;
        }
        else
            break;
    }

    cin.get();

    return 0;
}
