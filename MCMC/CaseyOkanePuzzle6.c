/*
	CS463 Puzzle 6: MCMC and Bayes Net 
	Casey O'Kane
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{

 	//Initialize variables to keep track of current variable evaluation
 	int nodeA = 0;
 	int nodeD = 0;
 	int nodeE = 0;
 	int nodeF = 0;
	
 	//Initialize probabilities found with markov blanket calculations
 	//Where node probability is found where node value is true
 	//Node A
 	double probAwCtrDtr = 0.5283018868;
 	double probAwCtrDfa = 1;

 	//Node D
 	double probDwCtrAtrFtrEtr = 0.6;
 	double probDwCtrAfaFtrEtr = 1;
 	double probDwCtrAtrFfaEtr = 0.9333333333;
 	double probDwCtrAfaFfaEtr = 1;
 	double probDwCtrAtrFtrEfa = 0.9411764706;
 	double probDwCtrAfaFtrEfa = 1;
 	double probDwCtrAtrFfaEfa = 0.7272727273;
 	double probDwCtrAfaFfaEfa = 1;

 	//Node E
 	double probEwBfaDtrFtr = 0.5294117647;
 	double probEwBfaDtrFfa = 0.6363636364;
 	double probEwBfaDfaFtr = 0.9230769231;
 	double probEwBfaDfaFfa = 0.25;

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

		//Create random initial values for ADEF

 		//Complete 10000 instances 
		for(int i = 1; i <= 10000; i++){

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
	 					if(nodeA && nodeF && nodeE){
	 						//DOCUMENTATION
	 						//If the flip value is greater than the 
	 						//probability, then we say that node is true for that configuration 
	 						if(biasFlip < probDwCtrAtrFtrEtr){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(!nodeA && nodeF && nodeE){
	 						if(biasFlip < probDwCtrAfaFtrEtr){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(nodeA && !nodeF && nodeE){
	 						if(biasFlip < probDwCtrAtrFfaEtr){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(!nodeA && !nodeF && nodeE){
	 						if(biasFlip < probDwCtrAfaFfaEtr){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(nodeA && nodeF && !nodeE){
	 						if(biasFlip < probDwCtrAtrFtrEfa){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(!nodeA && nodeF && !nodeE){
	 						if(biasFlip < probDwCtrAfaFtrEfa){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(nodeA && !nodeF && !nodeE){
	 						if(biasFlip < probDwCtrAtrFfaEfa){
	 							nodeD = 1;
	 						}
	 					}
	 					else if(!nodeA && !nodeF && !nodeE){
	 						if(biasFlip < probDwCtrAfaFfaEfa){
	 							nodeD = 1;
	 						}
	 					}
	 					//If the probability doesn't match for the given 
	 					//configuration, then that node is false
	 					else{
	 						nodeD = 0;
	 					}		 							 							 					
	 					break;

	 				//work with node E
	 				case 1:
	 					//Account for all permutations of D, F, and B = !b
	 					if(nodeD && nodeF){
	 						if(biasFlip < probEwBfaDtrFtr){
	 							nodeE = 1; 
	 						}
	 					}
	 					else if(nodeD && !nodeF){
	 						if(biasFlip < probEwBfaDtrFfa){
	 							nodeE = 1;
	 						}
	 					}
	 					else if(!nodeD && nodeF){
	 						if(biasFlip < probEwBfaDtrFfa){
	 							nodeE = 1; 
	 						}
	 					}
	 					else if(!nodeD && !nodeF){
	 						if(biasFlip < probEwBfaDfaFfa){
	 							nodeE = 1; 
	 						}
	 					}
	 					//If the permutation isn't relevant, E = False
	 					else{
	 						nodeE = 0;
	 					}

	 					break;

	 				//work with F
	 				case 2:
	 					//Account for all permutations of D and E
	 					if(nodeD && nodeE){
	 						if(biasFlip < probFwDtrEtr){
	 							nodeE = 1; 
	 						}
	 					}
	 					else if(nodeD && !nodeE){
	 						if(biasFlip < probFwDtrEfa){
	 							nodeE = 1;
	 						}
	 					}
	 					else if(!nodeD && nodeE){
	 						if(biasFlip < probFwDfaEtr){
	 							nodeE = 1; 
	 						}
	 					}
	 					else if(!nodeD && !nodeE){
	 						if(biasFlip < probFwDfaEfa){
	 							nodeE = 1; 
	 						}
	 					}
	 					//If the permutation isn't relevant, E = False
	 					else{
	 						nodeE = 0;
	 					}

	 					break;

	 				//Finally work with node A after figuring out the
	 				//other variable evaluations
	 				default:
	 					//Account for all permutations of D with C = c
	 					if(nodeD){
	 						if(biasFlip < probAwCtrDtr){
	 							nodeA = 1;
	 							//DOC: Incremement the number of times A is true 
	 							nodeAcntr++;
	 						}
	 					}
	 					else if(!nodeD){
	 						if(biasFlip < probAwCtrDfa){
	 							nodeA = 1;
	 							nodeAcntr++;
	 						}
	 					}

	 					else{
	 						nodeA = 0;
	 					}
	 			}

	 			
	 		}

	 		//Enter branch if 40 iterations have occurred
	 		if(i % 1000 == 0){
	 			//Find where to store value in the array
	 			int RatioValsPos = (i / 1000) - 1;
	 			//Calculate actual ratio 
	 			double currRatio = (double) nodeAcntr / i; 
	 			//store resulting ratio in array for graphing 
	 			dRatioVals[RatioValsPos] = currRatio;

	 		}

	 	}

	 	//Display actual results for that iteration
 		printf("Run #%d: Ratio Values (per 1000 iterations) shown below\n", runNum);
	 	for(int arrCntr = 0; arrCntr < 10; arrCntr++){
	 		printf("x = %d, y = %f\n", (arrCntr*1000), dRatioVals[arrCntr]);
	 	}
	 	printf("\n");

 	}

	return 0;
}
