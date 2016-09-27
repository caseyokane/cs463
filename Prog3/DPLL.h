#ifndef _DPLL_INCLUDED_
#define _DPLL_INCLUDED_


#include <vector>
#include <string>

using std::vector; 
using std::string;


//Notable variables:

//clause container, received from command line args
vector<vector<int>> v_clContainer;



int DPLL(vector<int> v_Clauses);
int unitPropagate();
int literalAssign();
bool locatePureLit();

#endif
