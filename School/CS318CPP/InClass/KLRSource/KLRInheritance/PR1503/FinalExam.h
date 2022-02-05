// Used with PR1503
#ifndef FINALEXAM_H
#define FINALEXAM_H
#include <iostream>
#include "GradedActivity.h"
using namespace std;

class FinalExam : public GradedActivity
{
private:
    int numQuestions;    // Number of questions
    double pointsEach;   // Points for each question
    int numMissed;       // Number of questions missed
public:
    // Default constructor
    FinalExam()
    {
        cout << "\tFinalExam no-arg constructor " << endl;
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }

    // Constructor
    FinalExam(int questions, int missed)
    {
        cout << "\tFinalExam 2-arg constructor " << endl; 
        set(questions, missed);
    }

    // Mutator functions
   //********************************************************
 // set function                                          *
 // The parameters are the number of questions and the    *
 // number of questions missed.                           *
 //********************************************************

    void set(int questions, int missed)
    {
        double numericScore;  // To hold the numeric score

        // Set the number of questions and number missed.
        numQuestions = questions;
        numMissed = missed;

        // Calculate the points for each question.
        pointsEach = 100.0 / numQuestions;

        // Calculate the numeric score for this exam.
        numericScore = 100.0 - (missed * pointsEach);

        // Call the inherited setScore function to set
        // the numeric score.
        setScore(numericScore);

        // Call the adjustScore function to adjust
        // the score.
        adjustScore();
    }

    //*****************************************************************
    // Definition of Test::adjustScore. If score is within 0.5 points *
    // of the next whole point, it rounds the score up and            *
    // recalculates the letter grade.                                 *
    //*****************************************************************

    void adjustScore()
    {
        double fraction = score - static_cast<int>(score);

        if (fraction >= 0.5)
        {
            // Adjust the score variable in the GradedActivity class.
            score += (1.0 - fraction);
        }
    }

    // Accessor functions
    double getNumQuestions() const
    {
        return numQuestions;
    }

    double getPointsEach() const
    {
        return pointsEach;
    }

    int getNumMissed() const
    {
        return numMissed;
    }
};
#endif 
