/*
    CS463 AI Puzzle 3 - Fall 2016
    Casey O'Kane

    main.cpp - Primary driver function that also handles SAT arguments
*/


#include <iostream>
int hillClimb();
int dpll();
int walkSAT();

//Driver for dpll, which uses the dpll class  
int dpll(){

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

//Driver for walkSAT algorithm
int walkSAT(){
    return 0;
}

//Driver for hillClimb algorithm
int hillClimb(){
    return 0; 
}



int main(int argc, char* argv[]){

    std::cout << "Hello World" << std::endl;
    return 0;
}
