#ifndef _DPLL_INCLUDED_
#define _DPLL_INCLUDED_


#include <vector>
#include <string>
#include <iterator>

using std::vector; 
using std::string;


//Notable variables:

//clause container, received from command line args
vector<vector<int>> v_clauses;
//clause results, contain integer (-1/1) if clause is true or false
vector<int> v_clRslts;
vector<int> v_clVars;
vector<int> v_UnitClause;


bool DPLL();
vector<int> DPLLhandle();
int unitPropagate();
int literalAssign();
bool locPureLit(vector<int>::iterator it_Lit);
int verifyDPLL();

#endif
