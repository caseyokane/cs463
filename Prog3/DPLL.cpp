#include "DPLL.h"

//remove clauses that contain the literal but also remove literals when a 
//negation is found.
vector<vector<int>> =unitPropagate(vector<vector<int>> v_currForm,int iLiteral){

    //Use an iterator to iterate through each clause of the container
    vector<vector<int>>::iterator it_Cl;
    //iterate through the literals of each clause and Unit Clauses
    vector<int>::iterator it_Lit; 

    //Iterate through each element in the current formula
    for(it_Cl == v_currForm.begin(); it_Cl != v_currForm.end(); it_Cl++){

        for(it_Lit = it_Cl->begin(); it_Lit != it_Cl->end(); it_Lit++){

            //If the literal shows up in the clause remove the clause
            if(*it_Lit == iLiteral){
                //ISSUES MIGHT HAPPEN HERE 
                v_currForm.erase(it_Cl);
                break;
            }
            //if the complement of the literal shows up, remove the literal
            else if(*it_Lit == -iLiteral){
                v_currForm.erase(it_Lit);
            }
        }
    }
    
    //After updating the formula, return it
    return v_currForm; 
}

//If l occurs in clause, remove that clause
vector<vector<int>> literalAssign(vector<vector<int>> v_currForm, int iLiteral){
    
    //Use an iterator to iterate through each clause of the container
    vector<vector<int>>::iterator it_Cl;
    //iterate through the literals of each clause and Unit Clauses
    vector<int>::iterator it_Lit; 

    //Iterate through each element in the current formula
    for(it_Cl == v_currForm.begin(); it_Cl != v_currForm.end(); it_Cl++){

        for(it_Lit = it_Cl->begin(); it_Lit != it_Cl->end(); it_Lit++){

            //If the literal shows up in the clause remove the clause
            if(*it_Lit == iLiteral){
                //ISSUES MIGHT HAPPEN HERE 
                v_currForm.erase(it_Cl);
                break;
            }
        }
    }
    
    //After updating the formula, return it
    return v_currForm; 
}

bool DPLL(vector<vector<int> v_currForm){

    //Use an iterator to iterate through each clause of the container
    vector<vector<int>>::iterator it_Cl;
    //iterate through the literals of each clause, pure literals and Unit Clauses
    vector<int>::iterator it_Lit, it_Pures; it_Unit; 

    //set formula as consistent until negation is present
    bool isConsistent = true;

    for(it_Cl == v_currForm.begin(); it_Cl != v_currForm.end(); it_Cl++){


        //TODO: Is this really the best method?
        //vector to keep track of consistent literals
        //vector<int> v_PureLits; vector<int>::iterator it_Consist;


        //For every literal in each clause, check that currLit is negated prev
        for(it_Lit = it_Cl->begin(); it_Lit != it_Cl->end(); it_Lit++){

            //If the vector of pure literals is empty, append current literal
            if(v_PureLits.empty()){
                v_PureLits.push_back(*it_Lit);
            }

            //If the pure vector isn't empty, start comparing values
            else{

                //Used to to determine if current literal is pure or not
                bool isPure = true;
 
                //For every current pure literal, check that literals don't negate 
                for(it_Pures = v_PureLits.begin(); 
                    it_Pures = v_PureLits.end(); it_Pures++){
                    
                    //If the current literal is a negated version of  pure
                    //remove it from pure, and set isConsistent/isPure to false    
                    if((*it_Pures == -(*it_Lit)){
                        v_PureLits.erase(itPures);
                        isConsistent = false;
                        isPure = false;
                    }

                }
                //If the literal doesn't show up in v_PureLits and isn't negation
                //of a pure literal, then append it to the pure literal list
                if(isPure){
                    v_PureLits.push_back(*it_Lit);
                }
            }
        }

    
        //ALG: If v_currForm contains an empty clause return false
        if((*it_Cl).size() == 0){
            return false
        }

        //If unit clause (clause size 1 is found, push the position onto the 
        //unit clause position vector
        if((*it_Cl).size() == 1){
            //index found as distance from list begin to iterator pos
            v_UnitClause.push_back(std::distance(v_currForm.begin(), it_Cl));
        }

    }

    //ALG: If v_currForm  is a consistent set of literals return true
    if(isConsistent){
        return true;
    }    

    //For every unit clause l in v_currForm,v_currForm = unitPropagate(l, v_currForm);
    for(it_Unit = v_UnitClause.begin(); it_Unit != v_UnitClause.end(); it_Unit++){
        v_currForm = unitPropagate(v_currForm[*it_Unit]);
    }
    
    //For every pure literal in v_currForm use literalSssign(l, v_currForm)
    for(it_Pures - v_PureLits.begin(); it_Pures = v_PureLits.end(); it_Pures++){
        v_currForm = literalAssign(v_currForm, *it_Pures)
    }

    //Select one of the remaining literals and recurse with two versions of the 
    //formula, one where the literal is true and the other where it is false
        //Literal selection will be arbitrary at first, can be improved later
    int literal = v_currForm[0][0];


    //Use propagation to create the new versions of formulas
    vector<vector<int>> v_posLitForm = unitPropagate(v_currForm, literal);
    vector<vector<int>> v_negLitForm = unitPropagate(v_currForm, -(literal));

    //return (dpll(v_currForm & l) & dpll(v_currForm  & ~l));
    //recurse with these formulas 
    bool posDPLL = DPLL(v_posLitForm);
    bool negDPLL = DPLL(v_negLitForm);

    //return if both are true or not
    return posDPLL && negDPLL;

    //TODO: v_Clauses so that it isn't global anywmore, to handle asynchronus
    //recursion? Interesting question for Greg

}


//MAY NOT BE NEEDED IF ASSIGNMENT DOESN'T NEED TO RETURN!
bool DPLLhandle(vector<vector<int>> SATform){

    //convert SATform to a vector of clauses (vector of ints)

    //if the DPLL call returns true return assignment 
    if(DPLL()){
        return v_currForm;
    }
    
    //Return NULL for failure otherwise
    return NULL; 
}
