#ifndef _DPLL_INCLUDED_
#define _DPLL_INCLUDED_


#include <vector>
#include <string>

using std::vector; 
using std::string;


//Notable variables:

//clause container, received from command line args
vector<vector<int>> v_clContainer;
//clause results, contain integer (-1/1) if clause is true or false
vector<int> v_clRslts;


bool DPLL(vector<int> v_Clauses);
int unitPropagate();
int literalAssign();
bool locPureLit(vector<int>::iterator it_Lit);
int verifyDPLL();

#endif
