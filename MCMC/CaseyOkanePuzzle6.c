/*

	CS463 Puzzle 6: MCMC and Bayes Net 
	Casey O'Kane

*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char[] argv)
{

 	//Initialize variables to keep track of current variable evaluation
 	// const bool nodeB = false;
 	// const bool nodeC = true;
 	bool nodeA = false;
 	bool nodeD = false;
 	bool nodeE = false;
 	bool nodeF = false;
	
 	//Initialize probabilities found with markov blanket calculations
 	//Where node probability is found where node value is true
 	//Node A
 	double probAwCtrDtr = 0.528;
 	double probAwCtrDfa = 1;

 	//Node D
 	double probDwCtrAtrFtrEtr = 0;
 	double probDwCtrAfaFtrEtr = 0;
 	double probDwCtrAtrFfaEtr = 0;
 	double probDwCtrAfaFfaEtr = 0;
 	double probDwCtrAtrFtrEfa = 0;
 	double probDwCtrAfaFtrEfa = 0;
 	double probDwCtrAtrFfaEfa = 0;
 	double probDwCtrAfaFfaEfa = 0;

 	//Node E
 	double probEwBfaDtrFtr = 0;
 	double probEwBfaDtrFfa = 0;
 	double probEwBfaDfaFtr = 0;
 	double probEwBfaDfaFfa = 0;

 	//Node F - Given in bayesnet.pdf
 	double probFwDtrEtr = 0.3;
 	double probFwDtrEfa = 0.4;
 	double probFwDfaEtr = 0.8;
 	double probFwDfaEfa = 0.1;

 	//Seed the RNG
 	srand(time(NULL));

 	//Complete 5 runs of the sampler code 
 	for(int runNum = 0; runNum < 5; runNum++){

 		//Initialize array to store ratios for graphing
 		double dRatioVals [9] = {};

		//Initialize counter to keep track of instances where A = true 
		int nodeAcntr = 0;

 		//Complete 400 instances 
		for(int i = 1; i <= 400; i++){

	 		//Iterate through each of the nonevidence nodes  
	 		for(int j = 0; j < 3; j++){

	 			//Update the j node according to a biased flip

	 			//Find the biased flip value using RNG
	 			double biasFlip = ((double) rand() / (RAND_MAX));

	 			//The j node is treated as one of the nonevidence values 
	 			//0 = nodeD, 1 = nodeE, 2 = nodeF, nodeA otherwise
	 			switch(j){


	 				//work with node D
	 				case 0:
	 					//Account for all permuations of A, F, E, and C = c

	 					//First, check for the particular configuration of node values
	 					if(nodeA && nodeF && NodeE){
	 						//DOCUMENTATION
	 						//If the flip value is greater than the 
	 						//probability, then we say that node is true for that configuration 
	 						if(biasFlip > probDwCtrAtrFtrEtr){
	 							nodeD = true;
	 						}
	 					}
	 					else if(!nodeA && nodeF && NodeE){
	 						if(biasFlip > probDwCtrAfaFtrEtr){
	 							nodeD = true;
	 						}
	 					}
	 					else if(nodeA && !nodeF && NodeE){
	 						if(biasFlip > probDwCtrAtrFfaEtr){
	 							nodeD = true;
	 						}
	 					}
	 					else if(!nodeA && !nodeF && NodeE){
	 						if(biasFlip > probDwCtrAfaFfaEtr){
	 							nodeD = true;
	 						}
	 					}
	 					else if(nodeA && nodeF && !NodeE){
	 						if(biasFlip > probDwCtrAtrFtrEfa){
	 							nodeD = true;
	 						}
	 					}
	 					else if(!nodeA && nodeF && !NodeE){
	 						if(biasFlip > probDwCtrAfaFtrEfa){
	 							nodeD = true;
	 						}
	 					}
	 					else if(nodeA && !nodeF && !NodeE){
	 						if(biasFlip > probDwCtrAtrFfaEfa){
	 							nodeD = true;
	 						}
	 					}
	 					else if(!nodeA && !nodeF && !NodeE){
	 						if(biasFlip > probDwCtrAfaFfaEfa){
	 							nodeD = true;
	 						}
	 					}
	 					//If the probability doesn't match for the given 
	 					//configuration, then that node is false
	 					else{
	 						nodeD = false;
	 					}		 							 							 					
	 					break;

	 				//work with node E
	 				case 1:
	 					//Account for all permutations of D, F, and B = !b
	 					if(nodeD && nodeF){
	 						if(biasFlip > probEwBfaDtrFtr){
	 							nodeE = true; 
	 						}
	 					}
	 					else if(nodeD && !nodeF){
	 						if(biasFlip > probEwBfaDtrFfa){
	 							nodeE = true;
	 						}
	 					}
	 					else if(!nodeD && nodeF){
	 						if(biasFlip > probEwBfaDtrFfa){
	 							nodeE = true; 
	 						}
	 					}
	 					else if(!nodeD && !nodeF){
	 						if(biasFlip > probEwBfaDfaFfa){
	 							nodeE = true; 
	 						}
	 					}
	 					//If the permutation isn't relevant, E = False
	 					else{
	 						nodeE = false;
	 					}

	 					break;

	 				//work with F
	 				case 2:
	 					//Account for all permutations of D and E
	 					if(nodeD && nodeE){
	 						if(biasFlip < probFwBfaDtrEtr){
	 							nodeE = true; 
	 						}
	 					}
	 					else if(nodeD && !nodeE){
	 						if(biasFlip < probFwBfaDtrEfa){
	 							nodeE = true;
	 						}
	 					}
	 					else if(!nodeD && nodeE){
	 						if(biasFlip < probFwBfaDtrEfa){
	 							nodeE = true; 
	 						}
	 					}
	 					else if(!nodeD && !nodeE){
	 						if(biasFlip < probFwBfaDfaEfa){
	 							nodeE = true; 
	 						}
	 					}
	 					//If the permutation isn't relevant, E = False
	 					else{
	 						nodeE = false;
	 					}

	 					break;

	 				//Finally work with node A after figuring out the
	 				//other variable evaluations
	 				default:
	 					//Account for all permutations of D with C = c
	 					if(nodeD){
	 						if(biasFlip < probAwCtrDtr){
	 							nodeA = true;
	 							//DOC: Incremement the number of times A is true 
	 							nodeAcntr++;
	 						}
	 					}
	 					else if(!nodeD){
	 						if(biasFlip < probAwCtrDfa){
	 							nodeA = true;
	 							nodeAcntr++;
	 						}
	 					}

	 					else{
	 						nodeA = false;
	 					}
	 			}

	 			
	 		}

	 		//Enter branch if 40 iterations have occurred
	 		if(i % 40 == 0){
	 			//Find where to store value in the array
	 			int RatioValsPos = (i / 40) - 1;
	 			//Calculate actual ratio 
	 			double currRatio = (double) nodeAcntr / i; 
	 			//store resulting ratio in array for graphing 
	 			dRatioVals[RatioValsPos] = currRatio;

	 		}

	 	}

	 	//Display actual results for that iteration
 		printf("Run #%d: Ratio Values (per 40 iterations) shown below\n", runNum);
	 	for(int arrCntr = 0; arrCntr < 10; arrCntr++){
	 		printf("x = %d, y = %f\n", (arrCntr*40), dRatioVals[arrCntr]);
	 	}
	 	printf("\n");

 	}

	return 0;
}