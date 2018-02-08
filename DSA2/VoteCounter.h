#pragma once
#include "Candidate.h"
#include "BallotPaper.h"
#include <string>
using namespace std;

class VoteCounter
{

public:
	string name;
	int voteCounter;

	VoteCounter(const string &c, const int v = 0);
	void addVote();
	int getVote();
};