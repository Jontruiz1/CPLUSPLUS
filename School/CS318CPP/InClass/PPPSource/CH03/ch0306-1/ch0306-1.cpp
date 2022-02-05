// ch0306-1

// Different than what is in the text

// read in up to the end of line and then token the strings in the line using istringstream

#include "..\libroot\std_lib_facilities.h" //location of header in CH03 Solution
#include <sstream>

int main()
{
    int number_of_words = 0;
    string stream;

    
    cout << "Enter a sequence of words followed by return"; 
    getline(cin, stream);

    istringstream iss(stream);

    string previous = " ";      // not a word
    string current;
    
    while (iss >> current) {
        ++number_of_words;      // increase word count
        if (previous == current)
            cout << "word number " << number_of_words
                 << " repeated: "<< current << '\n';
        previous = current;
    }

    cin.get();
    return 0;
}
