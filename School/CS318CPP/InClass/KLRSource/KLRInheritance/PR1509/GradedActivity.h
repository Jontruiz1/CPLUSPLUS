// Used with PR1509
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H
#include <iostream>
using namespace std;

// GradedActivity class declaration

class GradedActivity
{
protected:
    double score;   // To hold the numeric score
public:
    // Default constructor
    GradedActivity()
    {
        cout << "\tGradedActivity: no arg constructor\n";
        score = 0.0;
    }

    // Constructor
    GradedActivity(double s)
    {
        cout << "\tGradedActivity: 1 arg constructor\n"; 
        score = s;
    }

    // Mutator function
    void setScore(double s)
    {
        score = s;
    }

    // Accessor functions
    double getScore() const
    {
        return score;
    }

    char getLetterGrade() const
    {
        char letterGrade; // To hold the letter grade

        if (score > 89)
            letterGrade = 'A';
        else if (score > 79)
            letterGrade = 'B';
        else if (score > 69)
            letterGrade = 'C';
        else if (score > 59)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        return letterGrade;
    }

};
#endif