#ifndef _WALKSAT_INCLUDED_
#define _WALKSAT_INCLUDED_

#include <vector>
#include <string>
#include <time>
#include <stdlib>

using std::vector;
using std::string;

vector<int> v_varAssign;
vector<int> v_falseClauses;
vector<int> v_trueClauses;

void generateRandomModel(int iLargestVar);
int walkSAT();



#endif
