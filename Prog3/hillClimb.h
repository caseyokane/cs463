#ifndef _HILLCLIMB_INCLUDED_
#define _HILLCLIMB_INCLUDED_

//Basic node structure used throughout hill climbing
struct hillNode{
    int fitVal;
    vector<vector<int>> v_currFormState;
    vector<hillNode*> v_neighbors;
};

int hillClimb(vector<vector<int>> v_currForm);


#endif
