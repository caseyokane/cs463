%CS463 Assignment 4 - Prolog 1
%Casey O'Kane

%%%Helper Rules used by primary methods

%Make sure that X and Y are within the confines of the maze
posValid(X,Y,Width,Height) :-
	%Check that X and Y are positive but contained within bounds
	(X >= 0, Y >= 0), 
	(X < Height, Y < Width).

%Make sure that you can move to the new coordinates
validMove(X,Y,Maze) :-
	%Make get the current position from the current row
	nth0(X,Maze,CurrRow),
	nth0(Y,CurrRow,CurrPos),	
	%If the proposed position contains a 0, then you can move there
	CurrPos == 0.

%%%

%%%Find if adjacent move will be valid or not 

%Base case: 
moveAdj(X,Y,X,Y,Maze,Result,Width,Height,Path) :-
	%Store the path of adjacent moves and calculate the length
	Path = [[X,Y]|Result], length(Path,Len), 
	%%Account for offset caused by initial point 
	Cost is Len-2, format('Cost to path: ~w', [Cost]).

%Recursive portion:
moveAdj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path) :-
	%Check that all possible adjacent moves from current position are valid

	%Done by updating X/Y coordinates and checking validity of new position 
	%Does this by checking that X/Y are valid coordinates, the move to new X/Y
	%values is valid and that they are not included in the Visited list 

	Xnew is X1, Ynew is Y1+1, 
	(posValid(Xnew,Ynew,Width,Height),
	\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze)),

	%Resulting path is found with current X/Y and the Visited coordinates 
	Result = [[X1,Y1]|Visited],
	%append(Result, [Visited, [X1,Y1]]),

	%Recursive call with new coordinates after confirming validity	
	moveAdj(Xnew,Ynew,X2,Y2,Maze,Result,Width,Height,Path).

%Repeat for other adjacent movement possibilities
moveAdj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path) :-
	Xnew is X1, Ynew is Y1-1, 
	posValid(Xnew,Ynew,Width,Height),\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze),
	Result = [[X1,Y1]|Visited],
	%append(Result, [Visited, [X1,Y1]]),
	moveAdj(Xnew,Ynew,X2,Y2,Maze,Result,Width,Height,Path).	

moveAdj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path) :-
	Xnew is X1+1, Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze),
	Result = [[X1,Y1]|Visited],
	%append(Result, [Visited, [X1,Y1]]),
	moveAdj(Xnew,Ynew,X2,Y2,Maze,Result,Width,Height,Path).	

moveAdj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path) :-
	Xnew is X1-1, Ynew is Y1, 
	posValid(Xnew,Ynew,Width,Height),\+ member([Xnew,Ynew],Visited),
	validMove(Xnew,Ynew,Maze),
	Result = [[X1,Y1]|Visited],
	%append(Result, [Visited, [X1,Y1]]),
	moveAdj(Xnew,Ynew,X2,Y2,Maze,Result,Width,Height,Path).	
%%%

%Find out if a citypath exists 
%%%
citypath(X1,Y1, X2, Y2, Maze, Path) :-
	%Get the first row in order to get maze dimension
	nth0(0,Maze,Row),

	%Store the Witdth and Length using r
	length(Row,Width),
	length(Maze,Height),

	%Check that the passed coordinates are valid with given Width/Height
	posValid(X1,Y1,Width,Height),
	posValid(X2,Y2,Width,Height),

	%Reinitialize Visited to empty list
	Visited = [[]],

	%Check sure that coordinates are adjacent
	moveAdj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path).
%%%
