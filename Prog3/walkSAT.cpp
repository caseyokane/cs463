#include "walkSAT.h"

//TODO: Make sure main returns largestVar
//Function use to fill in the v_VariableAssign vector which is used throughout
void generateRandomModel(int iLargestVar){
    
    //add offset element so that variable numbers will match index
    v_varAssign.push_back(0);

    //Using the largest variable number push all the variable assignments onto
    //v_trueClauses 
    for(int varCtr = 0; varCtr < iLargestVar; varCtr++){

        int iRandAssign = rand() % 2;
        v_varAssign.push_back(iRandAssign);

    }

}

//Will return a boolean value whether or not the model is valid or not
//Also keeps track of the false clauesse for selection in walkSAT
bool modelValid(vector<vector<int>> v_currForm){

    //Simple boundary integer
    int iNumClauses = v_trueClause.size();
    //Use iterators to traverse the current formula
    vector<vector<int>>::iterator it_Cl;
    vector<int>::iterator it_Lit; 
    //assume formula is satisfied until proven false
    bool satisfied = true;

    //Make sure that initially, that there are no true clauses 
    int iClauseCtr = 0;
    while(iClauseCtr < iNumClauses){
        v_trueClauses[iClauseCtr] = 0;
    }
   
    //For each variable, traverse each clause 
    for(int iVar = 1; iVar < v_varAssign.size(); iVar++){
        
        for(it_Cl = v_currForm.begin(); it_Cl != v_currForm.end(); it_Cl++){
            
            //keep track of clause index
            int iClauseIdx = 0

            //Iterate through each literal
            for(it_Lit = it_Cl->begin(); it_Lit != it_Cl->end();  it_Lit++){
                //If the variable is found within the clause determine if clause
                //is validated or not
                if(iVar == abs(*it_Lit){
    
                    //If the assignment is 0 (false), then the variable must be 
                    //negative. If 1, then the variable is positive 
                    if((v_varAssign[iVar] == 0) && (*it_Lit < 0)) ||
                        (v_varAssign[iVar]==1 && (*it_Lit > 0)){
                            //Record this clause as true and break out
                            v_trueClauses[iClauseIdx] = 1;
                            break;
                    }

                }
                //Increment clause index
                iClauseIdx++;
            }
        }
    }

    //Check if the clauses are false or not
    iClauseCtr = 0;
    while(iClauseCtr < iNumClauses){

        //If a clause is false, satisfied is false, and then that postion is 
        //store in the false clauses vector
        if(!v_trueClauses[iClauseCtr]){
            satisfied = false;
            v_falseClauses.push(iClauseCtr) 
        }
    } 
    return satisfied;
}

//TODO: Finish This
void flipRandLiteral(){
}

//TODO: Finish this
void flipMaxSATLiteral(){
}

//Take in all the clauses, the probability of a random walk, and max flips
//Return the satisfying model or an empty vector
vector<int> walkSAT(vector<vector<int>> v_currForm, double probWalk, 
                            int max_flips, int iLargestVar){
  
    //handle rand() related things
    srand(time(NULL));

    //Randomly assign True/False to all symbols in each clause
    generateRandomModel(int iLargestVar);

    //initialize true clauses
    int iNumClause =0 
    while(iNumClause < v_currForm.size()){
        v_trueClauses.push_back(0);
    }

    //iterate as long as ctr < max_flips
    for(int iCtr = 0; iCtr < max_flips; iCtr++){

        //if model satisfies clauses
        if(modelValid(v_currForm)){
            //return the model
            return v_varAssign;
        }
        
        //Select a random index for the false clause vector
        int iRandIdx = rand() % v_falseClauses.size();
        //Assign a randomly selected false clause to clause
        vector<int> currClause = v_falseClauses[iRandIdx];


        //generate random double value 
        double dRandInit = rand() % 100;
        double dRandProb = dRandInit / 100;

        //if randomVal <= probWalk flip value of model of symbol in clause
        if(dRandProb < probWalk){
            flipRandLiteral();
        }

        //else flip symbol that maximizes the number of satisfied clauses
        else{
            flipMaxSATLiteral();
        }
    }
    //return failure if solution not found for max flips, vector size 0
    vector<int> v_empty;
    return v_empty;
}
