#include "VoteCounter.h"

using namespace std;

VoteCounter::VoteCounter(const string &c, const int v)
{
	name = c;
	voteCounter = v;
}
void VoteCounter::addVote()
{
	voteCounter += 1;
}
int VoteCounter::getVote()
{
	return voteCounter;
}
