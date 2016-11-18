#ifndef _HILLCLIMB_INCLUDED_
#define _HILLCLIMB_INCLUDED_

//Basic node structure used throughout hill climbing
struct hillNode{
    int fitVal;
    vector<int> v_varAssign;
    vector<vector<int>> v_currFormState;
    hillNode v_fittestNeighbor;
};

int randRestartCtr = 0;

hillNode findNeighbors(hillNode currNode);
vector<int> hillClimb(vector<vector<int>> v_currForm, int limit);


#endif
