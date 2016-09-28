#include "DPLL.h"


//Used to set the l clause to True and remove clasues with literals with ~l
//Counts T literals for each clause and stores values. Fills pure vector with 
//literals

//TODO: Fill out these functions`
int unitPropagate(vector<int>::iterator &it_Lit, numClauses){
    return 0;
}


bool locPureLit(vector<int>::iterator & li_it){
    return true;
}

//If l occurs in clause, remove that clause
int literalAssign(){

    return 0;
}

bool DPLL(){

    //Use an iterator to iterate through each clause of the container
    vector<vector<int>>::iterator it_Cl;
    //iterate through the literals of each clause and Unit Clauses
    vector<int>::iterator it_Lit, it_Unit; 

    bool isConsistent = true;
    //int iCl, iVar, iSign; 
    

    for(it_Cl == v_clauses.begin(); it_Cl != v_clauses.end(); it_Cl++){

        //vector to keep track of consistent literals
        vector<int> v_consistLits;

        for(it_Lit = it_Cl->begin(); it_Lit != it_Cl->end(); it_Lit++){

            //TODO: Stuff with consistent literals here

        }
    
        //ALG: If a_Clauses contains an empty clause return false
        if(*it_Cl.size() == 0){
            return false
        }

        //If unit clause (clause size 1 is found, push the position onto the 
        //unit clause position vector
        if(*it_Cl.size() == 1){
            //index found as distance from list begin to iterator pos
            v_UnitClause.push_back(std::distance(v_clauses,begin(), it_Cl));
        }

    }

    //ALG: If a_Clauses  is a consistent set of literals return true
    if(isConsistent){
        return true;
    }    

    //For every unit clause l in a_Clauses,aClauses = unitPropagate(l, a_Clauses);
    for(it_Unit = v_UnitClause.begin(); it_Unit != v_UnitClause.end(); it_Unit++){
        v_clauses = unitPropagate(v_clauses[*it_Unit]);
    }
    
    //For every pure literal in a_Clauses use literalSssign(l, a_Clauses)
    while(locPureFit){
        //TODO: Create pureLiteralAssign function
        v_clauses = pureLiteralAssign()
    }

    //l = choose-literal(a_Clauses);
    //TODO: Create method that will randomly select one of the remaining literals
    //return (dpll(a_Clauses & l) & dpll(a_Clauses  & ~l));
    //TODO: v_Clauses so that it isn't global anywmore, to handle asynchronus
    //recursion? Interesting question for Greg

}

vector<int> DPLLhandle(vector<vector<int>> SATform){

    //convert SATform to a vector of clauses (vector of ints)

    //if the DPLL call returns true return assignment 
    if(DPLL()){
        return v_clauses;
    }
    
    //Return NULL for failure otherwise
    return NULL; 
}
