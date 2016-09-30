#ifndef _WALKSAT_INCLUDED_
#define _WALKSAT_INCLUDED_

#include <vector>
#include <string>
#include <time>
#include <stdlib>
#include <algorithm>

using std::vector;
using std::string;

vector<int> v_varAssign;
vector<int> v_falseClauses;
vector<int> v_trueClauses;

void flipLiteral(int index);
void generateRandomModel(int iLargestVar);
int  modelValid(vector<vector<int>> v_currForm);
void flipRandLiteral(vector<int> currClause);
void flipMaxSATLiteral(vector<int> currClause, vector<vector<int>> v_currForm);
vector<int> walkSAT(vector<vector<int>> v_currForm, double probWalk,int max_flips, int iLargestVar);



#endif
