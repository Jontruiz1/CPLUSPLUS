// Used with PR1510
#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H
#include "PassFailActivity.h"
#include <iostream>
using namespace std;


class PassFailExam : public PassFailActivity
{
private:
    int numQuestions;    // Number of questions
    double pointsEach;   // Points for each question
    int numMissed;       // Number of questions missed
public:
    // Default constructor
    PassFailExam() : PassFailActivity()
    {
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }

    // Constructor
    PassFailExam(int questions, int missed, double mps) :
        PassFailActivity(mps)
    {
        set(questions, missed);
    }


    // Mutator function
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
