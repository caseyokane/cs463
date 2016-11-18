#include "hillClimb.h"

//determine the fit (or number of correct clauses)
int findFit(hillNode currNode){
	int iTrueClauses = 0;
	//iterate through the current formula

	//check for number of correct clauses 

	return	iTrueClauses;
}

//determine the best nieghbor for a given node by changing evaluations
hillNode findNeighbors(hillNode currNode){
	hillNode v_fittestNeighbor;

	//For each variable in each clause, create a new node that contains the 
	//formula with that changed variable 

	//set v_varAssign equal to the variable assignment and associate that with 
	//the node

	//for each node find the  highest fit by calling find fit for every node
	//if the node has the highest fit, set it to v_HighestNeighbor

	//Eventually after all iterations occur the highest fit node will be returned

	return v_fittestNeighbor;
}

vector<int> hillClimb(vector<vector<int>> v_currForm, int limit){

    //set the current node to that of the initial state 
   	hillNode currNode;
   	currNode.v_currFormState = v_currForm;
   	currNode.fitVal = findFit(currNode);
   	currNode.v_fittestNeighbor = findNeighbors(currNode);

   	int i = 0;
    //enter primary loop of the algorithm
    while(i < limit)
        //Set the neighbor node to the successor with hightest fit 
   		hillNode neighbor = currNode.v_fittestNeighbor;
        //if neighbor.fit < = current.fit
        if(neighbor.fitVal <= currNode.fitVal)
            //return current.formula
            return current.v_varAssign;
        //current = neighbor if value greater
        currNode = neighbor;


   	}
 
 	//If it doesn't solve past the limit, return an empty vector for not satisfied
 	vector<int> empty;
    return empty;
}
