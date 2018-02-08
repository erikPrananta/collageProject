#include "Candidate.h"

Candidate::Candidate(const string &n, const string &p)
{
	setName(n);
	setParty(p);
}
void Candidate::setName(const string &d)
{
	name = d;
}
void Candidate::setParty(const string &d)
{
	party = d;
}
string Candidate::getName()
{
	return name;
}
string Candidate::getParty()
{
	return party;
}