#pragma once
#include <string>
#include <iostream>
using namespace std;

class Candidate
{

public:
	string name;
	string party;

	Candidate(const string &n, const string &p);
	void setName(const string &d);
	void setParty(const string &d);
	string getName();
	string getParty();
}; 