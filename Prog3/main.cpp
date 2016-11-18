/*
    CS463 AI Puzzle 3 - Fall 2016
    Casey O'Kane

    main.cpp - Primary driver function that also handles SAT arguments
*/


#include <iostream>
#include <ifstream>
#include <string>
#include <ctime>


using namespace std;

int iHighestVar = 0;

vector<vector<int>> fileToForm(string fileName);


//Helper function used to read create a 2d vector using SAT forms 
vector<vector<int>> fileToForm(string fileName){

    ifstream inputFile(fileName);
    string currLine = "";
    vector<vector<int>> v_currForm;
    char currVariable = '';
    int numClauses = 0;

    //Ignore all the comments
    inputFile >> currVariable;
    while(currVariable != 'p'){
        inputFile >> currVariable;
    }

    //ignore 'cnf'
    inputFile >> currVariable;
    
    //Store number of variables 
    inputFile >> iHighestVar;

    //Store number of clauses 
    inputFile >> numClauses

    //Start filling out the vector
    for(int iCurrCl = 0; iCurrCl < numClauses; iCurrCl++){

        vector<int> rowLits;
        char currChar = inputFile.get();

        //While we endl hasn't been reached, get numbers 
        while(currChar != '\n'){
            //get numbers not whitespace
            if(currChar != ' '){
                rowLits.push_back((int)currChar);
            }
        }

        //For each clause, push back the number of literals
        v_currForm.push_back(rowLits)
    }

}


int main(int argc, char* argv[]){

    //Initialize variables that will be used in the lower loops
    bool isSAT = false;
    vector<vector<int>> v_currForm; 
    vector<int> v_varAssign;
    string fileName = "";
    
    //timer related variables
    clock_t startTime;
    double execTime;

    //Work on the easy sets
    cout << "Using SAT algorithms for easy sets" << endl;
    string easyFiles = "/SATinstances/easy/";
    for(int i =1; i <101; i++){

        fileName = easyFiles + i + ".cnf";

        //Convert information to a vector<vector<ints>>
        v_currForm = fileToForm(fileName);

        //create a timer call DPLL
        startTime = clock();

        isSAT = false;
        isSAT = DPLL(vector<vector<int> v_currForm);

        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;

        cout << "Using DPLL, is the formula satisfiable? " << isSAT;
        cout << " in " << execTime  " seconds." << endl;

        //reset the timer, call walkSAT
        startTime = clock();
        v_varAssign = walkSAT(v_currForm, 0.5, 1000, iHighestVar);
        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;       
        //Output assignment 
        if(v_varAssign.size() != 0){
            cout << "walkSAT result is satisfiable. Results: "
            for(int varCtr = 1; varCtr < v_varAssign.size(); varCtr++){
                cout << '\t' << varCtr " = " << v_varAssign[varCtr];
            }
        }
        else{
            cout << "walkSAT result for formula " + i + " is unsatsifiable";
        }
        cout << "walkSAT completed in " + execTime " seconds" << endl;

        //reset the timer, call hillClimb
        startTime = clock();
        v_varAssign = hillClimb(v_currForm, 1000)
        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;       
        //Output assignment 
        if(v_varAssign.size() != 0){
            cout << "hillClimb result is satisfiable. Results: "
            for(int varCtr = 1; varCtr < v_varAssign.size(); varCtr++){
                cout << '\t' << varCtr " = " << v_varAssign[varCtr];
            }
        }
        else{
            cout << "hillClimb result for formula " + i + " is unsatsifiable";
        }
        cout << "hillClimb completed in " + execTime " seconds" << endl;
    }

    cout << endl;

    cout << "Using SAT algorithms on hard sets" << endl;
    string hardFiles = "/SATinstances/hard/";
    for(int i =1; i <101; i++){

        fileName = hardFiles + i + ".cnf";

        //Convert information to a vector<vector<ints>>
        v_currForm = fileToForm(fileName);

        //create a timer call DPLL
        startTime = clock();

        isSAT = false;
        isSAT = DPLL(vector<vector<int> v_currForm);

        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;

        cout << "Using DPLL, is the formula satisfiable? " << isSAT;
        cout << " in " << execTime  " seconds." << endl;

        //reset the timer, call walkSAT
        startTime = clock();
        v_varAssign = walkSAT(v_currForm, 0.5, 1000, iHighestVar);
        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;       
        //Output assignment 
        if(v_varAssign.size() != 0){
            cout << "walkSAT result is satisfiable. Results: "
            for(int varCtr = 1; varCtr < v_varAssign.size(); varCtr++){
                cout << '\t' << varCtr " = " << v_varAssign[varCtr];
            }
        }
        else{
            cout << "walkSAT result for formula " + i + " is unsatsifiable";
        }
        cout << "walkSAT completed in " + execTime " seconds" << endl;

        //reset the timer, call hillClimb
        startTime = clock();
        v_varAssign = hillClimb(v_currForm, 1000)
        execTime = (clock() - startTime)/(double) CLOCKS_PER_SEC;       
        //Output assignment 
        if(v_varAssign.size() != 0){
            cout << "hillClimb result is satisfiable. Results: "
            for(int varCtr = 1; varCtr < v_varAssign.size(); varCtr++){
                cout << '\t' << varCtr " = " << v_varAssign[varCtr];
            }
        }
        else{
            cout << "hillClimb result for formula " + i + " is unsatsifiable";
        }
        cout << "hillClimb completed in " + execTime " seconds" << endl;

    }

    return 0;
}
