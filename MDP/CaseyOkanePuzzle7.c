/*
	CS463 Puzzle 7: Markov Decision Processes
	Casey O'Kane
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Include the file that contains all the probabiltiies and initial grids
#include <puzzle7consts.c>


//Simple helper function to display both grids when desired
void displayGrids(char arrowGrid, double valueGrid);
//Function used to determine the action that maximizes movement
double findMaxActionVal(int currState);

void displayGrids(char arrowGrid, double valueGrid){

	//Simple counter variable
	int i;

	//First display the values
	for(i = 0; i<36; i++){

		printf(" %d ", valueGrid[i];

		if((i+1)%6 == 0){
			//Finish each row with a newline 
			printf("\n");
		}
	}

	//Then the arrows
	for(i = 0; i<36; i++){

		printf(" %d ", arrowGrid[i];

		if((i+1)%6 == 0){
			//Finish each row with a newline 
			printf("\n");
		}
	}
}

double findMaxActionVal(int currState){

	//Array of ints to store values for every action
	int actionVals[4] = {0};
	//Counter used to represent next possible state
	int nxtStCtr = 0; 
	int actionValsCtr = 0;

	for(nxtStCtr = 0; nxtStCtr < 36; nxtStCtr++){
		//Iterate through up probabilities
		//Determine if it is possible to move up
		if(upProbs[currState][nxtStCtr] != 0){
			//find value using up action probabilities
			actionVals[0] += (upProbs[currState][nxtStCtr] * valueGrid[currState]);
		}

		//Iterate through down probabilities
		//Determine if it is possible to move down
		if(downProbs[currState][nxtStCtr] != 0){
			//find value using down action probabilities
			actionVals[1] += (downProbs[currState][nxtStCtr] * valueGrid[currState]);
		}

		//Iterate through left probabilities
		//Determine if it is possible to move left
		if(leftProbs[currState][nxtStCtr] != 0){
			//find value using left action probabilities
			actionVals[2] += (leftProbs[currState][nxtStCtr] * valueGrid[currState]);
		}

		//Determine if it is possible to move right
		if(rightProbs[currState][nxtStCtr] != 0){
			//find value using right action probabilities
			actionVals[3] += (rightProbs[currState][nxtStCtr] * valueGrid[currState]);
		}

	}

	//Initialize up action as maximum 
	double maxActionProb = actionVals[0]; usedState = 0;
	//Iterate through the collected probabilties
	for(actionValsCtr = 1; actionValsCtr <4; actionValsCtr++){
		
		//If the new value is the new maximum then enter this branch
		if(actionVals[actionValsCtr] > maxActionProb){
		
			//Set new maximum and  directional movment for current state.
			maxActionProb = actionVals[actionValsCtr];
			usedState = actionValsCtr;
		}
	}

	//Finally, return the probability for the action that maximizes reward 
	return maxActionProb;

}

int main()
{

	//Associate rewards with states 10 (+10), 19 (+100), and 24 (+20)
	double stateRewards[36];
	stateRewards[9] = 10; stateRewards[18] = 100; stateRewards[23] = 20;

	//simple counter variables for current horizon and current state
	int horizCtr = 0; int stateCtr = 0;

	//Simple variable used to store current value for action that maximizes MDP
	double maxActionVal = 0;

	//Initialize vectors to store results from value iteration
	double v_Vvals[36] = {0}; char v_currArrows[36];


	printf("Outputting Finite Horizon Results\n");
	//Now find value iteration results for 7 horizon
	for (horizCtr = 0; horizCtr < 8; horizCtr++){

		printf("Finite Horizon %d\n", horizCtr);
		//Initialize the values that are being edited by setting them to the initial grid
		initValueGrid
		memcpy(v_Vvals, initValueGrid, sizeof(v_Vvals));
		//Do same for arrow grid
		memcpy(v_currArrows, initArrowGrid, sizeof(v_currArrows));

		//Iterate through each possible state s0-s35
		for(stateCtr = 0; stateCtr < 36; stateCtr++){
			maxActionVal = findMaxActionVal(stateCtr);
			v_Vvals[stateCtr] = stateRewards[stateCtr] + maxActionVal;

			//Update arrow grid
			if(!usedState){
				v_currArrows[stateCtr] = '^';
			}

			else if(usedState){
				v_currArrows[stateCtr] = 'v';
			}

			else if(usedState == 2){
				v_currArrows[stateCtr] = '<';
			}

			else{
				v_currArrows[stateCtr] = '>';
			}
		}

		//Display grids 
		displayGrids(v_currArrows, v_Vvals);
		printf("\n");

	}

	//Find results for infinite horizon


	//Display grids 
	printf('\n')

	//Loop
	//U = Uprime; double sigma = 0;
		//for every state
			//Uprime[s] = r(s) + discount * maxSum
			//if abs(Uprime[s] - U[s]) > sigma
				//sigma = abs(Uprime[s] - U[s])


	//Find the max sum by using the current state and seeing which states can be reached

	//MDP Class: Initializes a list of actions, terminal states (rewards), gamma
		//R(class, state) returns a reward for a given state
		//T(class, state, action) returns probabilities
		//actions(class, state) returns actions that can be preformed in a given state 

	//MDP Grid: intilizes a gid, num rows/cols and a gamma 
		//T(class, state, action) returns probability and new state using go()
		//go(class, state, direction) returns state if move can be made
		//to_grid convert mapping to grid
		//to_arrows convert mapping to arrow grid




	return 0;
}
