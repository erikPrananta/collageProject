#include "BallotPaper.h"

void BallotPaper::setPreference(const int &n, const string &c)
{
	Pref temp(c, n);
	candidatePref.push_back(temp);
}
string BallotPaper::getPreference(const int &n)
{
	vector<Pref>::iterator iter = candidatePref.begin();
	for (iter = candidatePref.begin(); iter != candidatePref.end(); iter++)
	{
		if ((iter)->pref == n)
		{
			return (iter)->canName;
		}		
	}
}