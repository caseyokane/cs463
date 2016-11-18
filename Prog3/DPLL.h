#ifndef _DPLL_INCLUDED_
#define _DPLL_INCLUDED_


#include <vector>
#include <string>
#include <iterator>

using std::vector; 
using std::string;


//Notable variables:

//Vector to contain the possible pure literal 
vector<int> v_PureLits;
//Vector to contain the Unit Clauses
vector<int> v_UnitClause;

vector<vector<int>> unitPropagate(vector<vector<int>> v_currForm, int iLiteral);
vector<vector<int>> literalAssign(vector<vector<int>> v_currForm, int iLiteral);
bool DPLL(vector<vector<int>> v_currForm);

#endif
