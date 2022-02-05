// Same as in PR1501
// Used with PR1502
#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradedActivity.h"

// Inherits from GradedActivity
class FinalExam : public GradedActivity
{
private:
    int numQuestions;    // Number of questions
    double pointsEach;   // Points for each question
    int numMissed;       // Number of questions missed
public:
    // Default constructor
    FinalExam() : numQuestions{ 0 }, pointsEach{ 0.0 }, numMissed{ 0 } {}

    // Constructor
    FinalExam(int questions, int missed)
    {
        set(questions, missed);
    }


    // Mutator function
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
