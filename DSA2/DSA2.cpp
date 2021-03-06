// Author
// Erik Prananta
// C00209974
// Implement vote-counting for a simple electoral system.


#include "Candidate.h"
#include "BallotPaper.h"
#include "VoteCounter.h"
#include "Pref.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	ifstream file("candidateList.txt");
	string str;
	vector<Candidate> listCandidate;
	int candidateNumber = 0;
	while (std::getline(file, str) && str != "")
	{
		string name = str.substr(0, str.find("("));
		string party = str.substr(0, str.find(")"));
		party = party.substr(party.find("(") + 1);
		Candidate can(name, party);
		listCandidate.push_back(can);
		candidateNumber += 1;
	}
	vector<Candidate>::iterator iter = listCandidate.begin();
	for (iter = listCandidate.begin(); iter != listCandidate.end(); iter++)
	{
		cout << (iter)->name << " of " << (iter)->party << " party has been added to the candidate list!" << endl;
	}

	cout << endl;
	ifstream file2("candidateList.txt");
	int counter = 1;
	vector<BallotPaper> ballotList;
	while (str != "end")
	{
		BallotPaper singleBallot;
		while (std::getline(file2, str))
		{
			if (str == "")
			{
				ballotList.push_back(singleBallot);
				counter += 1;
				cout << endl;
				break;
			}
			else if (str == "end")
			{
				break;
			}
			else
			{
				string name = str.substr(0, str.find("("));
				int prefer = atoi((str.substr(str.find(":") + 1)).c_str());
				singleBallot.setPreference(prefer, name);
				cout << name << " has been set as the number " << prefer << " preference in the ballot" << endl;
			}
		}
		
	}
	string highName;
	string toppos;
	string lowName;
	int stage = 0;
	vector<string> canOut;
	vector<BallotPaper>::iterator iter2 = ballotList.begin();
	//do each stage
	while (stage < candidateNumber - 1)
	{
		vector<VoteCounter> vote;
		vector<Candidate>::iterator iter3 = listCandidate.begin();
		for (iter3 = listCandidate.begin(); iter3 != listCandidate.end(); iter3++)
		{
			if (!(std::find(canOut.begin(), canOut.end(), (iter3)->name) != canOut.end()))
			{
				string tempName = (iter3)->name;
				VoteCounter canVote(tempName);
				vote.push_back(canVote);
			}
		}
		int lowVote = -1;
		cout << endl;
		cout << "Stage " << stage + 1 << endl;
		//read each ballot 1 by 1
		for (iter2 = ballotList.begin(); iter2 != ballotList.end(); iter2++)
		{
			//get the higest pref and check if the can still running or not
			for (int i = 0; i < candidateNumber; i++)
			{
				highName = (iter2)->getPreference(i + 1);
				if (!(std::find(canOut.begin(), canOut.end(), highName) != canOut.end()))
				{
					break;
				}
			}
			//add vote to the candidate
			vector<VoteCounter>::iterator iter4 = vote.begin();
			for (iter4 = vote.begin(); iter4 != vote.end(); iter4++)
			{
				if ((iter4)->name == highName)
				{
					iter4->addVote();
					break;
				}
			}
		}
		//kick candidate with the lowest vote out
		vector<VoteCounter>::iterator iter4 = vote.begin();
		for (iter4 = vote.begin(); iter4 != vote.end(); iter4++)
		{
			if (lowVote == -1)
			{
				lowName = (iter4)->name;
				lowVote = (iter4)->voteCounter;
			}
			else if (lowVote > (iter4)->voteCounter && !(std::find(canOut.begin(), canOut.end(), (iter4)->name) != canOut.end()))
			{
				lowName = (iter4)->name;
				lowVote = (iter4)->voteCounter;
			}
			cout << (iter4)->name << " : " << (iter4)->voteCounter << endl;
		}
		canOut.push_back(lowName);
		cout << lowName << " is eliminated at stage " << stage + 1 << endl;
		stage += 1;
	}
	vector<Candidate>::iterator iter3 = listCandidate.begin();
	{
		for (iter3 = listCandidate.begin(); iter3 != listCandidate.end(); iter3++)
		{
			if (!(std::find(canOut.begin(), canOut.end(), (iter3)->name) != canOut.end()))
			{
				toppos = iter3->name;
			}
		}
	}
	cout << endl;;
	cout << "the winner of the election is " << toppos << endl;
	system("pause");
    return 0;
}

