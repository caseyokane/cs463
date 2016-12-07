/*
	CS463 Puzzle 7: Markov Decision Processes
	Casey O'Kane
*/

#include <stdio.h>
#include <stdlib.h>


//Simple helper function to display both grids when desired
void displayGrids(char arrowGrid[], double valueGrid[]);
//Helper function to intialize probabilities to the action table 
void initActionProbs();
//Function used to determine the action that maximizes movement
double findMaxActionVal(int currState, double valueGrid[]);


//Simple integer to determine arrow movement. 
//0 = up, 1 = down, 2 = left, 3 = right
int usedState = 0;

//Initialize grid for the arrows
char initArrowGrid[] = {
	'-', '-', '-', '-', '-', '-',
	'-', '-', '-', '-', 'X', '-',
	'X', 'X', '-', '-', 'X', '-',
	'-', 'X', '-', '-', 'X', '-',
	'-', 'X', '-', '-', 'X', '-',
	'-', '-', '-', '-', '-', '-'
};


//Initialize grid for the values
double initValueGrid[] = {
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
	0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
	1.0, 0.0, 1.0, 1.0, 0.0, 1.0,
	1.0, 0.0, 1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};


//initialize values for all actions
double upProbs[36][36] = {0};
double downProbs[36][36] = {0};
double leftProbs[36][36] = {0};
double rightProbs[36][36] = {0}; 



int main()
{
	//Call method that associates table probabilities shown in excel document
	initActionProbs();

	//Associate rewards with states 10 (+10), 19 (+100), and 24 (+20)
	double stateRewards[36];
	stateRewards[9] = 10; stateRewards[18] = 100; stateRewards[23] = 20; stateRewards[26] = 5;

	//simple counter variables for current horizon and current state
	int horizCtr = 0; int stateCtr = 0;

	//Simple variable used to store current value for action that maximizes MDP
	double maxActionVal = 0;

	//Initialize vectors to store results from value iteration
	double v_Vvals[36] = {0}; char v_currArrows[36];

	//PSUEDOCODE FROM TEXT/LECTURE
	//Loop
	//U = Uprime; double sigma = 0;
		//for every state
			//Uprime[s] = r(s) + discount * maxSum
			//if abs(Uprime[s] - U[s]) > sigma
				//sigma = abs(Uprime[s] - U[s])


	//Initialize the values that are being edited by setting them to the initial grid
	//Do same for arrow grid
    for(stateCtr = 0; stateCtr < 36; stateCtr++){
        v_Vvals[stateCtr] = initValueGrid[stateCtr];
        v_currArrows[stateCtr] = initArrowGrid[stateCtr];
    }

	printf("Outputting Finite Horizon 7 Solution\n");
	//Now find value iteration results for 7 horizon
	for (horizCtr = 0; horizCtr < 8; horizCtr++){

		//Iterate through each possible state s0-s35
		for(stateCtr = 0; stateCtr < 36; stateCtr++){

            //Account for internal walls
            if(stateCtr == 10 || stateCtr == 12 || stateCtr == 13 || stateCtr == 16 
                || stateCtr == 19 || stateCtr == 22 || stateCtr == 25 || stateCtr == 28){
                continue;
            }     

			maxActionVal = findMaxActionVal(stateCtr, v_Vvals);
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


	}

	//Display grid 
	displayGrids(v_currArrows, v_Vvals);
	printf("\n");
	



    //Find results for infinite horizon using same methods as 7 horizon but with
    //sigma.
	printf("Outputting Infinite Horizon Results\n");
	//Initialize discount value as defined in the prompt
	double discount = 0.95;
	//Initialize value for sigma which keeps value-iteration operating 
	double sigma = 0;
	//Initialize variable to represent maximum error for iteration
	double maxErr = 0.000001;
	//Double used to contain the temporary Vval value to calculate sigma.
	double tempVval = 0;

	//Initialize the values that are being edited by setting them to the initial grid
	//Do same for arrow grid
    for(stateCtr = 0; stateCtr < 36; stateCtr++){
        v_Vvals[stateCtr] = initValueGrid[stateCtr];
        v_currArrows[stateCtr] = initArrowGrid[stateCtr];
     }

	//Now find value iteration results for infinite horizon case
	while (sigma < (maxErr*(1 - discount))/discount ){


		//Iterate through each possible state s0-s35
		for(stateCtr = 0; stateCtr < 36; stateCtr++){
			
            //Account for internal walls
            if(stateCtr == 10 || stateCtr == 12 || stateCtr == 13 || stateCtr == 16 
                || stateCtr == 19 || stateCtr == 22 || stateCtr == 25 || stateCtr == 28){
                continue;
            }     

            maxActionVal = findMaxActionVal(stateCtr, v_Vvals);
			tempVval = v_Vvals[stateCtr];
			//Include discount this time 
			v_Vvals[stateCtr] = stateRewards[stateCtr] + (discount * maxActionVal);

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


            //Check that different between old values and new is not greater than sigma
            double currErr = abs(v_Vvals[stateCtr] - tempVval);
            if(currErr > sigma){
            	//Update the sigma value to the absolute difference
            	sigma = currErr;
            }
		}

	}

	//Display grids 
	displayGrids(v_currArrows, v_Vvals);
	printf("\n");
	return 0;
}

void displayGrids(char arrowGrid[], double valueGrid[]){

	//Simple counter variable
	int i;

    printf("Value function of the grid:\n");
	//First display the values
	for(i = 0; i<36; i++){

		printf("%lf\t", valueGrid[i]);

		if((i+1)%6 == 0){
			//Finish each row with a newline 
			printf("\n");
		}
	}

    printf("Policy function of the grid:\n");
	//Then the arrows
	for(i = 0; i<36; i++){

		printf("%c\t ", arrowGrid[i]);

		if((i+1)%6 == 0){
			//Finish each row with a newline 
			printf("\n");
		}
	}
}

double findMaxActionVal(int currState, double valueGrid[]){

	//Array of ints to store values for every action
	double actionVals[4] = {0};
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
	for(actionValsCtr = 1; actionValsCtr < 4; actionValsCtr++){
	
		//If the new value is the new maximum then enter this branch
		if(actionVals[actionValsCtr] > maxActionProb){
		
			//Set new maximum and  directional movment for current state.
			maxActionProb = actionVals[actionValsCtr];
			usedState = actionValsCtr;
		}
	}

    //printf("UpProb: %f value: %f result: %f", upProbs[0][0], valueGrid[0], (upProbs[0][0]* valueGrid[0]));
    

	//Finally, return the probability for the action that maximizes reward 
	return maxActionProb;

}


void initActionProbs(){
	//Then assign probability values based on table calculations
	//A0 Probabilities
	upProbs[0][0] = 0.8; upProbs[0][6] = 0.2; upProbs[1][1] = 0.8; upProbs[1][7] = 0.2;
	upProbs[2][2] = 0.8; upProbs[2][8] = 0.2; upProbs[3][3] = 0.8; upProbs[3][9] = 0.2;
	upProbs[4][4] = 1.0; upProbs[5][5] = 0.8; upProbs[5][11] = 0.2; 
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
	upProbs[31][31] = 1.0; upProbs[32][26] = 0.7; upProbs[32][32] = 0.3; 
	upProbs[33][27] = 0.7; upProbs[33][33] = 0.3; 
	upProbs[34][34] = 1.0; upProbs[35][29] = 0.7; upProbs[35][35] = 0.3; 

	//A1 Probs
	downProbs[0][0] = 0.3; downProbs[0][6] = 0.3; downProbs[1][1] = 0.3; downProbs[1][7] = 0.7;
	downProbs[2][2] = 0.3; downProbs[2][8] = 0.7; downProbs[3][3] = 0.3; downProbs[3][9] = 0.7;
	downProbs[4][4] = 1.0; downProbs[5][5] = 0.3; downProbs[5][11] = 0.7; 
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
	downProbs[31][31] = 1.0; downProbs[32][26] = 0.2; downProbs[32][32] = 0.8; 
	downProbs[33][27] = 0.2; downProbs[33][33] = 0.8; 
	downProbs[34][34] = 1.0; downProbs[35][29] = 0.2; downProbs[35][35] = 0.8; 	

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
	leftProbs[11][11] = 1.0;
	leftProbs[14][14] = 0.8; leftProbs[14][15] = 0.2;	
	leftProbs[15][14] = 0.7; leftProbs[15][15] = 0.3;
	leftProbs[17][17] = 1.0;		
	leftProbs[18][18] = 1.0;	
	leftProbs[20][20] = 0.8; leftProbs[20][21] = 0.2;
	leftProbs[21][20] = 0.7; leftProbs[21][21] = 0.3;
	leftProbs[23][23] = 1.0;		
	leftProbs[24][24] = 1.0;	
	leftProbs[26][26] = 0.8; leftProbs[26][27] = 0.2;
	leftProbs[27][26] = 0.7; leftProbs[27][27] = 0.3;
	leftProbs[29][29] = 1.0;	
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
	rightProbs[17][17] = 1.0;		
	rightProbs[18][18] = 1.0;	
	rightProbs[20][20] = 0.3; rightProbs[20][21] = 0.7;
	rightProbs[21][20] = 0.2; rightProbs[21][21] = 0.8;
	rightProbs[23][23] = 1.0;		
	rightProbs[24][24] = 1.0;	
	rightProbs[26][26] = 0.3; rightProbs[26][27] = 0.7;
	rightProbs[27][26] = 0.2; rightProbs[27][27] = 0.8;
	rightProbs[29][29] = 1.0;	
	rightProbs[30][30] = 0.3; rightProbs[30][31] = 0.7;	
	rightProbs[31][30] = 0.2; rightProbs[31][31] = 0.1; rightProbs[31][32] = 0.7;
	rightProbs[32][31] = 0.2; rightProbs[32][32] = 0.1; rightProbs[32][33] = 0.7; 
	rightProbs[33][32] = 0.2; rightProbs[33][33] = 0.1; rightProbs[33][34] = 0.7; 
	rightProbs[34][33] = 0.2; rightProbs[34][34] = 0.1; rightProbs[34][35] = 0.7; 				
	rightProbs[35][34] = 0.2; rightProbs[35][35] = 0.7;	
	
}

