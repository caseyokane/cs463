#include "DPLL.h"

bool DPLL(vector<int> v_Clauses){

    //Use an iterator to iterate through the literals of each clause 
    vector<int>::iterator it_Lit; 
    int iCl; 
    

    //If a_Clauses  is a consistent set of literals
        //return true
    //If a_Clauses contains an empty clause
        //return false
    //For every unit clause l in a_Clauses 
        //aClauses = unitPropagate(l, a_Clauses);
        //TODO: Set up return value here
        unitPropagate(it_Lit, numClauses);
    //For every pure literal in a_Clauses 
        //aClauses = literalSssign(l, a_Clauses)
    //l = choose-literal(a_Clauses);
    //return (dpll(a_Clauses & l) & dpll(a_Clauses  & ~l));

    //Receieve minimized index from a set of literals
    iCl = unitPropagate(it_Lit, numClauses);

    //check for a consistent set of literals
    if(v_clRslts[iCl] == 1){
        return true;
    }

    //Check for empty clause
    else if(v_clRslts[iCl] < 0){
        return false;
    }

    //Find pure literals 
    else if(locPureLit(it_Lit)){

    }


    return true;
}

//Used to set the l clause to True and remove clasues with literals with ~l
//Counts T literals for each clause and stores values. Fills pure vector with 
//literals
int unitPropagate(vector<int>::iterator &it_Lit, numClauses){

    int iClause;
    bool isSat = false;
    vector<int>::iterator it_Prop;

    //Iterate through each of the clauses 
    for(iClause = 0; iClause < numClauses; iClause++){
        
        //iterate over each of the vars in the clause 
        while( (it_Prop != v_clContainer[iClause].end() ) && (isSat != true) ){
        
        }

         
    }
    
    return 0;
}

bool locPureLit(vector<int>::iterator & li_it){
    return true;
}

//If l occurs in clause, remove that clause
int literalAssign(){

    return 0;
}

int verifyDPLL(){
    return 0;
}
