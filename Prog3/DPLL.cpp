#include "DPLL.h"

int DPLL(vector<int> v_Clauses){

    //If a_Clauses  is a consistent set of literals
        //return true
    //If a_Clauses contains an empty clause
        //return false
    //For every unit clause l in a_Clauses 
        //aClauses = unit-popagate(l, a_Clauses);
    //For every pure literal in a_Clauses 
        //aClauses = pure-literal-assign(l, a_Clauses)
    //l = choose-literal(a_Clauses);
    //return (dpll(a_Clauses & l) & dpll(a_Clauses  & ~l));

    return 0;
}

//Used to set the l clause to True and remove clasues with literals with ~l
int unitPropagate(){

    
    return 0;
}

//If l occurs in clause, remove that clause
int literalAssign(){

    return 0;
}
