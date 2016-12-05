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
	upProbs[4][4] = 1; upProbs[5][5] = 0.8; upProbs[5][11] = 0.2; 
	upProbs[6][0] = 0.7; upProbs[6][6] = 0.3; upProbs[7][1] = 0.7; upProbs[7][7] = 0.3; 
	upProbs[8][2] = 0.7; upProbs[8][8] = 0.1; upProbs[8][14] = 0.2;
	upProbs[9][3] = 0.7; upProbs[9][9] = 0.1; upProbs[9][15] = 0.2;
	upProbs[11][5] = 0.7; upProbs[11][11] = 0.1; upProbs[11][17] = 0.2;
	upProbs[14][8] = 0.7; upProbs[14][14] = 0.1; upProbs[14][20] = 0.2;
	upProbs[15][9] = 0.7; upProbs[15][15] = 0.1; upProbs[15][21] = 0.2;
	upProbs[17][11] = 0.7; upProbs[17][17] = 0.1; upProbs[17][23] = 0.2;							
	upProbs[18][18] = 0.8; upProbs[18][24] = 0.2;
	upProbs[20][14] = 0.7; upProbs[20][20] = 0.1; upProbs[20][26] = 0.2;
	upProbs[21][15] = 0.7; upProbs[21][21] = 0.1; upProbs[21][27] = 0.2;
	upProbs[23][17] = 0.7; upProbs[23][23] = 0.1; upProbs[23][29] = 0.2;
	upProbs[24][18] = 0.7; upProbs[24][24] = 0.1; upProbs[24][30] = 0.2;
	upProbs[26][20] = 0.7; upProbs[26][26] = 0.1; upProbs[26][31] = 0.2;
	upProbs[27][21] = 0.7; upProbs[27][27] = 0.1; upProbs[27][33] = 0.2;							
	upProbs[29][23] = 0.7; upProbs[29][29] = 0.1; upProbs[29][35] = 0.2;
	upProbs[30][24] = 0.7; upProbs[30][30] = 0.3; 
	upProbs[31][31] = 1; upProbs[32][26] = 0.7; upProbs[32][32] = 0.3; 
	upProbs[33][27] = 0.7; upProbs[33][33] = 0.3; 
	upProbs[34][34] = 1; upProbs[35][29] = 0.7; upProbs[35][35] = 0.3; 

	//A1 Probs
	downProbs[0][0] = 0.3; downProbs[0][6] = 0.3; downProbs[1][1] = 0.3; downProbs[1][7] = 0.7;
	downProbs[2][2] = 0.3; downProbs[2][8] = 0.7; downProbs[3][3] = 0.3; downProbs[3][9] = 0.7;
	downProbs[4][4] = 1; downProbs[5][5] = 0.3; downProbs[5][11] = 0.7; 
	downProbs[6][0] = 0.2; downProbs[6][6] = 0.8; downProbs[7][1] = 0.2; downProbs[7][7] = 0.8; 
	downProbs[8][2] = 0.2; downProbs[8][8] = 0.1; downProbs[8][14] = 0.7;
	downProbs[9][3] = 0.2; downProbs[9][9] = 0.1; downProbs[9][15] = 0.7;
	downProbs[11][5] = 0.2; downProbs[11][11] = 0.1; downProbs[11][17] = 0.7;
	downProbs[14][8] = 0.2; downProbs[14][14] = 0.1; downProbs[14][20] = 0.7;
	downProbs[15][9] = 0.2; downProbs[15][15] = 0.1; downProbs[15][21] = 0.7;
	downProbs[17][11] = 0.2; downProbs[17][17] = 0.1; downProbs[17][23] = 0.7;							
	downProbs[18][18] = 0.3; downProbs[18][24] = 0.7;
	downProbs[20][14] = 0.2; downProbs[20][20] = 0.1; downProbs[20][26] = 0.7;
	downProbs[21][15] = 0.2; downProbs[21][21] = 0.1; downProbs[21][27] = 0.7;
	downProbs[23][17] = 0.2; downProbs[23][23] = 0.1; downProbs[23][29] = 0.7;
	downProbs[24][18] = 0.2; downProbs[24][24] = 0.1; downProbs[24][30] = 0.7;
	downProbs[26][20] = 0.2; downProbs[26][26] = 0.1; downProbs[26][31] = 0.7;
	downProbs[27][21] = 0.2; downProbs[27][27] = 0.1; downProbs[27][33] = 0.7;
	downProbs[29][23] = 0.2; downProbs[29][29] = 0.1; downProbs[29][35] = 0.7;
	downProbs[30][24] = 0.2; downProbs[30][30] = 0.8; 
	downProbs[31][31] = 1; downProbs[32][26] = 0.2; downProbs[32][32] = 0.8; 
	downProbs[33][27] = 0.2; downProbs[33][33] = 0.8; 
	downProbs[34][34] = 1; downProbs[35][29] = 0.2; downProbs[35][35] = 0.8; 	

	//A2 Probs
	leftProbs[0][0] = 0.8; leftProbs[0][1] = 0.2; 
	leftProbs[1][0] = 0.7; leftProbs[1][1] = 0.1; leftProbs[1][2] = 0.2;
	leftProbs[2][1] = 0.7; leftProbs[2][2] = 0.1; leftProbs[2][3] = 0.2; 
	leftProbs[3][2] = 0.7; leftProbs[3][3] = 0.1; leftProbs[3][4] = 0.2; 
	leftProbs[4][3] = 0.7; leftProbs[4][4] = 0.1; leftProbs[4][5] = 0.2; 
	leftProbs[5][4] = 0.7; leftProbs[5][5] = 0.3;
	leftProbs[6][6] = 0.8; leftProbs[6][7] = 0.2;
	leftProbs[7][6] = 0.7; leftProbs[7][7] = 0.1; leftProbs[7][8] = 0.2; 
	leftProbs[8][7] = 0.7; leftProbs[8][8] = 0.1; leftProbs[8][9] = 0.2; 
	leftProbs[9][8] = 0.7; leftProbs[9][9] = 0.3;
	leftProbs[11][11] = 1;
	leftProbs[14][14] = 0.8; leftProbs[14][15] = 0.2;	
	leftProbs[15][14] = 0.7; leftProbs[15][15] = 0.3;
	leftProbs[17][17] = 1;		
	leftProbs[18][18] = 1;	
	leftProbs[20][20] = 0.8; leftProbs[20][21] = 0.2;
	leftProbs[21][20] = 0.7; leftProbs[21][21] = 0.3;
	leftProbs[23][23] = 1;		
	leftProbs[24][24] = 1;	
	leftProbs[26][26] = 0.8; leftProbs[26][27] = 0.2;
	leftProbs[27][26] = 0.7; leftProbs[27][27] = 0.3;
	leftProbs[29][29] = 1;	
	leftProbs[30][30] = 0.8; leftProbs[30][31] = 0.2;	
	leftProbs[31][30] = 0.7; leftProbs[31][31] = 0.1; leftProbs[31][32] = 0.2;
	leftProbs[32][31] = 0.7; leftProbs[32][32] = 0.1; leftProbs[32][33] = 0.2; 
	leftProbs[33][32] = 0.7; leftProbs[33][33] = 0.1; leftProbs[33][34] = 0.2; 
	leftProbs[34][33] = 0.7; leftProbs[34][34] = 0.1; leftProbs[34][35] = 0.2; 				
	leftProbs[35][34] = 0.7; leftProbs[35][35] = 0.3;


	//A3 Probs
	rightProbs[0][0] = 0.3; rightProbs[0][1] = 0.7; 
	rightProbs[1][0] = 0.2; rightProbs[1][1] = 0.1; rightProbs[1][2] = 0.7;
	rightProbs[2][1] = 0.2; rightProbs[2][2] = 0.1; rightProbs[2][3] = 0.7; 
	rightProbs[3][2] = 0.2; rightProbs[3][3] = 0.1; rightProbs[3][4] = 0.7; 
	rightProbs[4][3] = 0.2; rightProbs[4][4] = 0.1; rightProbs[4][5] = 0.7; 
	rightProbs[5][4] = 0.2; rightProbs[5][5] = 0.8;
	rightProbs[6][6] = 0.3; rightProbs[6][7] = 0.7;
	rightProbs[7][6] = 0.2; rightProbs[7][7] = 0.1; rightProbs[7][8] = 0.7; 
	rightProbs[8][7] = 0.2; rightProbs[8][8] = 0.1; rightProbs[8][9] = 0.7; 
	rightProbs[9][8] = 0.2; rightProbs[9][9] = 0.8;
	rightProbs[11][11] = 1;
	rightProbs[14][14] = 0.3; rightProbs[14][15] = 0.7;	
	rightProbs[15][14] = 0.2; rightProbs[15][15] = 0.8;
	rightProbs[17][17] = 1;		
	rightProbs[18][18] = 1;	
	rightProbs[20][20] = 0.3; rightProbs[20][21] = 0.7;
	rightProbs[21][20] = 0.2; rightProbs[21][21] = 0.8;
	rightProbs[23][23] = 1;		
	rightProbs[24][24] = 1;	
	rightProbs[26][26] = 0.3; rightProbs[26][27] = 0.7;
	rightProbs[27][26] = 0.2; rightProbs[27][27] = 0.8;
	rightProbs[29][29] = 1;	
	rightProbs[30][30] = 0.3; rightProbs[30][31] = 0.7;	
	rightProbs[31][30] = 0.2; rightProbs[31][31] = 0.1; rightProbs[31][32] = 0.7;
	rightProbs[32][31] = 0.2; rightProbs[32][32] = 0.1; rightProbs[32][33] = 0.7; 
	rightProbs[33][32] = 0.2; rightProbs[33][33] = 0.1; rightProbs[33][34] = 0.7; 
	rightProbs[34][33] = 0.2; rightProbs[34][34] = 0.1; rightProbs[34][35] = 0.7; 				
	rightProbs[35][34] = 0.2; rightProbs[35][35] = 0.7;	

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
