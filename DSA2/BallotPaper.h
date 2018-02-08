#pragma once
#include "Candidate.h"
#include "Pref.h"
#include <string>
#include <vector>
using namespace std;

class BallotPaper
{

public:
	vector<Pref>candidatePref;

	void setPreference(const int &n, const string &c);
	string getPreference(const int &n);
};