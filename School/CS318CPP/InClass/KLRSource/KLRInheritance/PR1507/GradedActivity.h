// Used with PR1507
// Specification file for the GradedActivity class
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H
#include <iostream>
using namespace std;

class GradedActivity
{
protected:
    char letter;            // To hold the letter grade
    double score;           // To hold the numeric score

    void determineGrade() //Member function that determines letter grade
    {
        if (score > 89)
            letter = 'A';
        else if (score > 79)
            letter = 'B';
        else if (score > 69)
            letter = 'C';
        else if (score > 59)
            letter = 'D';
        else
            letter = 'F';
    }
public:
    // Default constructor
    GradedActivity()
    {
        letter = ' '; score = 0.0;
    }

    // Mutator function
    void setScore(double s)
    {
        cout << "\tGradedActivity -- setScore" << endl; 
        score = s;
        determineGrade();
    }

    // Accessor functions
    double getScore() const
    {
        return score;
    }

    char getLetterGrade() const
    {
        return letter;
    }
};

#endif
