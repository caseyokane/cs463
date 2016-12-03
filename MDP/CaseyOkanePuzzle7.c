/*
	CS463 Puzzle 7: Markov Decision Processes
	Casey O'Kane
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Simple helper function to display both grids when desired
void displayGrids(char arrowGrid, double valueGrid);


void displayGrids(char arrowGrid, double valueGrid){

	int i,j;

	//First display the values
	for(i = 0; i<6; i++){
		for(j = 0; j<6; j++){
			printf(" %s ", valueGrid[i][j]);
		}
		//Finish each row with a newline 
		printf("\n");
	}

	//Then the arrows
	for(i = 0; i<6; i++){
		for(j = 0; j<6; j++){
			printf(" %s ", arrowGrid[i][j]);
		}
		//Finish each row with a newline 
		printf("\n");
	}
}

int main()
{

	//Initialize grid for the arrows
	char arrowGrid[6][6] = {
		{'-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', 'X', '-'},
		{'X', 'X', '-', '-', 'X', '-'},
		{'-', 'X', '-', '-', 'X', '-'},
		{'-', 'X', '-', '-', 'X', '-'},
		{'-', '-', '-', '-', '-', '-'}

	};

	//Initialize grid for the values
	double valueGrid[6][6] = {
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, -1.0, 0.0},
		{-1.0, -1.0, 0.0, 0.0, -1.0, 0.0},
		{0.0, -1.0, 0.0, 0.0, -1.0, 0.0},
		{0.0, -1.0, 0.0, 0.0, -1.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}

	};


	//initialize values for all actions
	double upProbs[36][36];
	double downProbs[36][36];
	double leftProbs[36][36];
	double rightProbs[36][36]; 

	//Then assign probability values based on table calculations
	//A0 Probabilities
	upProbs[0][0] = 0.8; upProbs[0][6] = 0.2; upProbs[1][1] = 0.8; upProbs[1][7] = 0.2;
	upProbs[2][2] = 0.8; upProbs[2][8] = 0.2; upProbs[3][3] = 0.8; upProbs[3][9] = 0.2;
	upProbs[4][4] = 1; upProbs[5][5] = 0.8; upProbs[5][11] = 0.8; 
	upProbs[6][0] = 0.7; upProbs[6][6] = 0.3; upProbs[7][1] = 0.7; upProbs[7][7] = 0.3; 
	upProbs[8][2] = 0.7; upProbs[8][8] = 0.1; upProbs[8][14] = 0.2;
	upProbs[9][3] = 0.7; upProbs[9][9] = 0.1; upProbs[9][15] = 0.2;
	upProbs[11][5] = 0.7; upProbs[11][11] = 0.1; upProbs[11][17] = 0.2;
	upProbs[14][8] = 0.7; upProbs[14][14] = 0.1; upProbs[14][20] = 0.2;
	upProbs[15][9] = 0.7; upProbs[15][15] = 0.1; upProbs[15][21] = 0.2;
	upProbs[17][11] = 0.7; upProbs[17][17] = 0.1; upProbs[17][23] = 0.2;							
	upProbs[18][18] = 0.8; upProbs[18][24] = 0.2;
	upProbs[20][W] = 0.7; upProbs[20][20] = 0.1; upProbs[20][Z] = 0.2;
	upProbs[21][W] = 0.7; upProbs[21][21] = 0.1; upProbs[21][Z] = 0.2;
	upProbs[23][W] = 0.7; upProbs[23][23] = 0.1; upProbs[23][Z] = 0.2;
	upProbs[24][W] = 0.7; upProbs[24][24] = 0.1; upProbs[24][Z] = 0.2;
	upProbs[26][W] = 0.7; upProbs[26][26] = 0.1; upProbs[26][Z] = 0.2;
	upProbs[27][W] = 0.7; upProbs[27][27] = 0.1; upProbs[27][Z] = 0.2;							
	upProbs[29][W] = 0.7; upProbs[29][29] = 0.1; upProbs[29][Z] = 0.2;
	upProbs[30][W] = 0.7; upProbs[30][30] = 0.1; upProbs[30][Z] = 0.2;
	upProbs[31][W] = 0.7; upProbs[31][31] = 0.1; upProbs[31][Z] = 0.2;
	upProbs[32][W] = 0.7; upProbs[32][32] = 0.1; upProbs[32][Z] = 0.2;
	upProbs[33][W] = 0.7; upProbs[33][33] = 0.1; upProbs[33][Z] = 0.2;
	upProbs[34][W] = 0.7; upProbs[34][34] = 0.1; upProbs[34][Z] = 0.2;
	upProbs[35][W] = 0.7; upProbs[35][35] = 0.1; upProbs[35][Z] = 0.2;


	//Associate rewards with states 10 (+10), 19 (+100), and 24 (+20)

	//Now find value iteration results for 7 horizon
	//V(s0) = currReward [0 unless 9,18,23] +  sum with maximized action

		//Sum for all attainable states for different actions(lookupprob  * prevVal)
		//if sum is greater than previous sum it is the maximized action so update the current state
		//based on the action and start again

	//update arrow grid so that arrow for current state points in direction of maximized action

	//Display grids 

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


	//Find results for infinite horizon


	//Display grids 



	return 0;
}
