%CS463 Assignment 4 - Prolog 2
%Casey O'Kane

%%%Helper Rules used by primary predicates 

%Simple incrementor to keep track of the score
calcScore(Val1,Val2, Result) :-
	Result is Val1 + Val2.

%Simple predicate to count the elements in a list 
%TODO: Explain in greater detail
%Base Case
countElements([],X,0).
%Check that Y iz the succeding element compared to Z
countElements([X|Tail],X,Y):- 
	countElements(Tail,X,Z), 
	succ(Z, Y).
%Check that the start of the array isnt the same as 
countElements([X1|Tail],X,Z):- 
	X1 \= X,
	countElements(Tail,X,Z).


%predicate that updates score if pikachu is found
%foundPik(CurrPos,Score,UpdScore) :-
%	CurrPos == p, !,
	%Pass the old score and the point value of 1 to incrementor
%	calcScore(Score,1,UpdScore).

%predicate that updates score if egg is hatched 



%Make sure that X and Y are within the confines of the maze
posValid(X,Y,Xmax,Ymax) :-
	%Check that X and Y are positive but contained within bounds
	X > 0, 
	Y > 0, 
	X =< Xmax, 
	Y =< Ymax.

%Make sure that you can move to the new coordinates
validMove(X,Y,Maze,CurrPos) :-
	%Get the current position from the current row
	nth1(Y,Maze,CurrRow),
	nth1(X,CurrRow,CurrPos),	
	%If the proposed position contains a j, then you can not move there
	%Also account for eggs and Pikachus to increase the score
	%calcScore(Score,1,UpdScore),
	CurrPos \= j.
	%foundPik(CurrPos,Score,UpdScore).

%See if win condition has been met 
checkWin(X,Y,Maze,ResultItems) :-
	nth1(Y,Maze,CurrRow),
	nth1(X,CurrRow,CurrPos),	

	%If a Pikachu found and eggHatched, then only mewtwo needs to be found
	member(p, ResultItems),
	%TODO: Handle the egg hatching here...

	member(mb, ResultItems),
	%If mewtwo found then final path is found 
	
	CurrPos == mt, 
	%calculate the final score by checking appearances of values
	countElements(ResultItems, p, NumPikas),
	Score is NumPikas,
	%Inform the user of the final score
	format('Final Score: ~w', [Score]).

%%%

%%%Find if adjacent move will be valid or not 

%Base case: 
moveAdj(X,Y,Maze,Result,ResultItems,Width,Height,Path) :-
	%Store the path of adjacent moves and calculate the length
	Path = [[X,Y]|Result],
	checkWin(X,Y,Maze,ResultItems).


%Recursive portion:
moveAdj(X1,Y1,Maze,Visited,VisitedItems,Width,Height,Path) :-
	%Check that all possible adjacent moves from current position are valid

	%Done by updating X/Y coordinates and checking validity of new position 
	%Does this by checking that X/Y are valid coordinates, the move to new X/Y
	%values is valid and that they are not included in the Visited list 

	Xnew is X1, 
	Ynew is Y1+1, 
	posValid(Xnew,Ynew,Width,Height),
	\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze,CurrPos),

	%Resulting path is found with current X/Y and the Visited coordinates 
	Result = [[X1,Y1]|Visited],
	%Append found values here to determine if condition was reached  
	ResultItems = [CurrPos|VisitedItems],
	%Recursive call with new coordinates after confirming validity	
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,Width,Height,Path).

%Repeat for other adjacent movement possibilities
moveAdj(X1,Y1,Maze,Visited,VisitedItems,Width,Height,Path) :-
	Xnew is X1, 
	Ynew is Y1-1, 
	posValid(Xnew,Ynew,Width,Height),
	\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	ResultItems = [CurrPos|VisitedItems],
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,Width,Height,Path).	

moveAdj(X1,Y1,Maze,Visited,VisitedItems,Width,Height,Path) :-
	Xnew is X1+1, 
	Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),
	\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	ResultItems = [CurrPos|VisitedItems],
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,Width,Height,Path).	

moveAdj(X1,Y1,Maze,Visited,VisitedItems,Width,Height,Path) :-
	Xnew is X1-1, 
	Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),
	\+ member([Xnew,Ynew],Visited),
	%validMove(Xnew,Ynew,Maze,Score,UpdScore,CurrPos),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	ResultItems = [CurrPos|VisitedItems],
	%moveAdj(Xnew,Ynew,Maze,Result,ResultItems,UpdScore,Width,Height,Path).	
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,Width,Height,Path).	
%%%

%Find out if a mazepath exists 
%%%
mazepath(X,Y, Maze, Path) :-
	%Get the first row in order to get maze dimension
	nth0(0,Maze,Row),

	%Store the Witdth and Length using r
	length(Row,Width),
	length(Maze,Height),

	%Check that the passed coordinates are valid with given Width/Height
	posValid(X,Y,Width,Height),

	%Initialize Visited to empty list
	Visited = [[]],
	%Initialize list of seen items as empty at first
	VisitedItems = [],
	%Initialize score 
	%Score = 0,

	%Check sure that coordinates are adjacent
	moveAdj(X,Y,Maze,Visited,VisitedItems,Width,Height,Path).
	%moveAdj(X,Y,Maze,Visited,VisitedItems,Score,Width,Height,Path).

%%%
