// Same as in PR1501
// Used with PR1502
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
private:
    double score;   // To hold the numeric score
public:
    // Default constructor
    GradedActivity() { score = 0.0; }

    // Constructor
    GradedActivity(double s) { score = s; }

    // Mutator function
    void setScore(double s) { score = s; }

    // Accessor functions
    double getScore() const { return score; }

    // returns letter grade based on score
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