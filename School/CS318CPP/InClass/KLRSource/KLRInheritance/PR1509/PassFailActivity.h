// Used with PR1509
#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H
#include "GradedActivity.h"
#include <iostream>
using namespace std;

class PassFailActivity : public GradedActivity
{
protected:
    double minPassingScore;    // Minimum passing score.
public:
    // Default constructor
    PassFailActivity() : GradedActivity()
    {
        cout << "\tPassFailActivity: no arg constructor\n"; 
        minPassingScore = 0.0;
    }

    // Constructor
    PassFailActivity(double mps) : GradedActivity()
    {
        cout << "\tPassFailActivity: 1 arg constructor\n";
        minPassingScore = mps;
    }

    // Mutator
    void setMinPassingScore(double mps)
    {
        minPassingScore = mps;
    }

    // Accessors
    double getMinPassingScore() const
    {
        return minPassingScore;
    }

    //******************************************************
    // This function returns 'P' if the score is passing,  *
    // otherwise it returns 'F'.                           *
    //******************************************************

    char getLetterGrade() const
    {
        char letterGrade;

        if (score >= minPassingScore)
            letterGrade = 'P';
        else
            letterGrade = 'F';

        return letterGrade;
    }

};
#endif
