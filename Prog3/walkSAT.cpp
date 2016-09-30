#include "walkSAT.h"


//Very short helper function that is used to flip a variable in v_varAssign
void flipLiteral(int index){

    //Flip the value of that random variable in the assignment vector 
    if(vars[index] == 0){
        v_varAssign[index] = 1;
    }
    else{
        v_varAssign[index] = 0;
    }

}

//Function use to fill in the v_VariableAssign vector which is used throughout
void generateRandomModel(int iLargestVar){
    
    //add offset element so that variable numbers will match index
    v_varAssign.push_back(0);

    //Using the largest variable number push all the variable assignments onto
    //v_varAssign 
    for(int varCtr = 0; varCtr < iLargestVar; varCtr++){

        int iRandAssign = rand() % 2;
        v_varAssign.push_back(iRandAssign);

    }

}

//Keeps track of the false claueses for selection in walkSAT and returns the 
//number of true clauses 
int  modelValid(vector<vector<int>> v_currForm){

    //Simple boundary integer
    int iNumClauses = v_trueClause.size();
    //Use iterators to traverse the current formula
    vector<vector<int>>::iterator it_Cl;
    vector<int>::iterator it_Lit; 
    
    int iTrueClauses = 0;

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
                            iTrueClauses++;
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

        //If a clause is false then that postion is 
        //stored in the false clauses vector
        if(!v_trueClauses[iClauseCtr]){
            v_falseClauses.push(iClauseCtr) 
        }
    } 
    return iTrueClauses;
}

//Function that flips literal in a clause at random
void flipRandLiteral(vector<int> currClause){

    //Select a random index variable in a clause
    int iLitIdx = rand() % currClause.size() + 1;
    //Store the actual variable given the index
    int iLit = v_varAssign[iLitIdx];

    //Flip the value of that random variable in the assignment vector 
    flipLiteral(iLit);
}

//Function that makes a flip based on the max number of true clauses 
void flipMaxSATLiteral(vector<int> currClause, vector<vector<int>> v_currForm){

    //Have variables to store the current literal and the number of true clauses 
    //per literal
    int iCurrLit = 0;
    vector<int> trueClausesPerLit;   

    //Iterate through each literal starting from 1
    for(int iLit = 0; iLit < currClause.size(); iLit++){

        //Set variable to the flipped version and test the model (yes/no)
        flipLiteral(iLit+1);
        trueClausesPerLit.push_back(modelValid(v_currForm)); 
        //reset variable to original vector
        flipLiteral(iLit+1);
    }
    //find max value of vector
    iCurrLit= *max_element(trueClausesPerLit, trueClausesPerLit+currClause.size());
    //flip that variable in v_varAssign
    flipLiteral(iCurrLit); 
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
    int iNumClause, iNumTrueClauses = 0; 
    while(iNumClause < v_currForm.size()){
        v_trueClauses.push_back(0);
    }

    //iterate as long as ctr < max_flips
    for(int iCtr = 0; iCtr < max_flips; iCtr++){

        //if model satisfies clauses, meaning the number of true clauses is
        //the same as the formula size
        iNumTrueClauses = modelValid(v_currForm);
        if(iNumTrueClauses == v_currForm.size()){
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
            flipRandLiteral(currClause);
        }

        //else flip symbol that maximizes the number of satisfied clauses from clause
        else{
            flipMaxSATLiteral(currClause);
        }
    }
    //return failure if solution not found for max flips, vector size 0
    vector<int> v_empty;
    return v_empty;
}
