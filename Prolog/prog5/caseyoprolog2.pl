%CS463 Assignment 4 - Prolog 2
%Casey O'Kane

%%%Helper Rules used by primary predicates 


%Simple predicate to count the elements in a list and calculate score 
%Result of Intuition of users sumx and Boris of stack overflow (detailed in documentation)
%Base Case
countElements([],_,0).
%Check that Y iz the succeding element compared to Z
countElements([X|Tail],X,Y):- 
	countElements(Tail,X,Z), 
	succ(Z, Y).
%Check that the start of the array isnt the same as 
countElements([X1|Tail],X,Z):- 
	X1 \= X,
	countElements(Tail,X,Z).


%Make sure that X and Y are within the confines of the maze
posValid(X,Y,Xmax,Ymax) :-
	%Check that X and Y are positive but contained within bounds
	X > 0, 
	Y > 0, 
	X =< Xmax, 
	Y =< Ymax.

%Make sure that the initial coordinate value is valid before moving
validStart(X,Y,Maze,VisitedItems,VisitedOccur) :-
	%Get the current position from the current row
	nth1(Y,Maze,CurrRow),
	nth1(X,CurrRow,CurrPos),

	%If the proposed position contains a j, then you can't move there
	CurrPos \= j,
	%If the prposed position isn't a j, then append it to visited items.
	VisitedItems = [[CurrPos,X,Y]], 
	VisitedOccur = [CurrPos].


%Make sure that you can move to the new coordinates
validMove(X,Y,Maze,CurrPos) :-
	%Get the current position from the current row
	nth1(Y,Maze,CurrRow),
	nth1(X,CurrRow,CurrPos),	
	%If the proposed position contains a j, then you can't move there
	CurrPos \= j.


%See if win condition has been met 
checkWin(X,Y,Maze,ResultItems,ResultOccur) :-
	%Get current location value as CurrPos
	nth1(Y,Maze,CurrRow),
	nth1(X,CurrRow,CurrPos),	

	%Check that at least one Pikachu is found 
	member([p,_,_], ResultItems),
	%Check that at least one egg Hatched 
	member([e,_,_], ResultItems),
	%Check that the masterball has been found 
	member([mb,_,_], ResultItems),
	%If mewtwo found then final path is found 
	CurrPos == mt, 

	%calculate the final score by checking appearances of values
	countElements(ResultOccur, p, NumPikas),
	countElements(ResultOccur, e, NumEggs),

	%Final score is number of pikachus + number of eggs hatched *10
	Score is NumPikas + (NumEggs * 10),

	%Inform the user of the final score
	format('Final Score: ~w', [Score]).

%Currently I check that the maze is unwinnable if you have visited twice as many locations as the dimension of the maze
checkFail(Width,Height,Visited) :-
	%Get the length
	length(Visited, VisitedLen),
	%If visited length is less than 2*dimension continue. Else, fail.
	VisitedLen < 2 * (Width * Height).

%%%

%%%Find if adjacent move will be valid or not 

%Base case: 
moveAdj(X,Y,Maze,Result,ResultItems,ResultOccur,Width,Height,Path) :-

	%Store the path of adjacent moves
	Path = [[X,Y]|Result],

	%Check if the maze is unwinnable, if checkFail returns false, then we say it is.
	(checkFail(Width,Height,Result) -> 0=0; !,fail),

	%Finally, check if the maze was won
	checkWin(X,Y,Maze,ResultItems,ResultOccur).


%Recursive portion:
moveAdj(X1,Y1,Maze,Visited,VisitedItems,VisitedOccur,Width,Height,Path) :-
	%Check that all possible adjacent moves from current position are valid

	%Done by updating X/Y coordinates and checking validity of new position 
	%Does this by checking that X/Y are valid coordinates and that the move to new X/Y
	%values is valid 

	Xnew is X1, 
	Ynew is Y1+1, 
	posValid(Xnew,Ynew,Width,Height),
	validMove(Xnew,Ynew,Maze,CurrPos),

	%Resulting path is found with current X/Y and the Visited coordinates 
	Result = [[X1,Y1]|Visited],

	%Append found values here to determine if condition was reached and not visited prior 
	(\+member([CurrPos,X1,Y1], VisitedItems) -> 

		%If current location is not a member, store itself along with the coordinates in ResultedItems
		%and the location item itself in ResultOccur. Otherwise, keep those variables the same
		ResultItems = [[CurrPos,X1,Y1]|VisitedItems], ResultOccur = [CurrPos|VisitedOccur]; 
		ResultItems = VisitedItems, ResultOccur = VisitedOccur),

	%Recursive call with new coordinates after confirming validity	
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,ResultOccur,Width,Height,Path).

%Repeat for other adjacent movement possibilities
moveAdj(X1,Y1,Maze,Visited,VisitedItems,VisitedOccur,Width,Height,Path) :-
	Xnew is X1, 
	Ynew is Y1-1, 
	posValid(Xnew,Ynew,Width,Height),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	(\+member([CurrPos,X1,Y1], VisitedItems) -> 
		ResultItems = [[CurrPos,X1,Y1]|VisitedItems], ResultOccur = [CurrPos|VisitedOccur]; 
		ResultItems = VisitedItems, ResultOccur = VisitedOccur),
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,ResultOccur,Width,Height,Path).	

moveAdj(X1,Y1,Maze,Visited,VisitedItems,VisitedOccur,Width,Height,Path) :-
	Xnew is X1+1, 
	Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	(\+member([CurrPos,X1,Y1], VisitedItems) -> 
		ResultItems = [[CurrPos,X1,Y1]|VisitedItems], ResultOccur = [CurrPos|VisitedOccur]; 
		ResultItems = VisitedItems, ResultOccur = VisitedOccur),
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,ResultOccur,Width,Height,Path).	

moveAdj(X1,Y1,Maze,Visited,VisitedItems,VisitedOccur,Width,Height,Path) :-
	Xnew is X1-1, 
	Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),
	%\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze,CurrPos),
	Result = [[X1,Y1]|Visited],
	(\+member([CurrPos,X1,Y1], VisitedItems) -> 
		ResultItems = [[CurrPos,X1,Y1]|VisitedItems], ResultOccur = [CurrPos|VisitedOccur]; 
		ResultItems = VisitedItems, ResultOccur = VisitedOccur),
	moveAdj(Xnew,Ynew,Maze,Result,ResultItems,ResultOccur,Width,Height,Path).	
%%%

%Find out if a mazepath exists 
%%%
mazepath(X,Y, Maze, Path) :-
	%Get the first row in order to get maze dimension
	nth0(0,Maze,Row),

	%Store the Width and Length using the row
	length(Row,Width),
	length(Maze,Height),

	%Check that the passed coordinates are valid with given Width/Height
	posValid(X,Y,Width,Height),

	%Initialize Visited to empty list
	Visited = [[]],

	%Check that starting in a valid location and initialize list of items seen with (Items) and without (Occur) coordinates
	validStart(X,Y,Maze,VisitedItems,VisitedOccur),

	%Check sure that coordinates are adjacent
	moveAdj(X,Y,Maze,Visited,VisitedItems,VisitedOccur,Width,Height,Path).

%%%
