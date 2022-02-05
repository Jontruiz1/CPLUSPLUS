// Used with PR1511
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
		minPassingScore = 0.0;
	}

	// Constructor
	PassFailActivity(double mps) : GradedActivity()
	{
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
	// Member function PassFailActivity::getLetterGrade    *
	// This function returns 'P' if the score is passing,  *
	// otherwise it returns 'F'.                           *
	//******************************************************
	// Redefined in derived automatically become virtual 
	// Good practice to note this here although not required
	virtual char getLetterGrade() const
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
