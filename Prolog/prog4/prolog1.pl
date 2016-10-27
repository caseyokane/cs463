%CS463 Assignment 4 - Prolog 1
%Casey O'Kane

%%%Helper Rules used by primary methods

%posValid checks that given coordinates are valid
posValid(X) :- 
	X==0.

%Make sure that X and Y are within the confines of the maze
posValid(X,Y,Width,Height) :-
	X >= 0, Y >= 0, X < Height, Y < Width.

%Make sure that you can move to the new coordinates
movable(X,Y,Maze) :-
	nth0(X,Maze,Position,_),
	nth0(Y,Position,InnerPos,_),
	%posValid(InnerPos).
	InnerPos == 0.

%%%

%%%Find if adjacent move will be valid or not 

%Base case: 
findadj(X,Y,X,Y,Maze,Result,Width,Height,Path) :-
	%Store the path of adjacent moves and calculate the length
	Path = [[X,Y]|Result], length(Path,Len), write(Len).

%Recursive portion:
findadj(X,Y,X2,Y2,Maze,Visited,Width,Height,Path) :-
	%Check that all possible adjacent moves from current position are valid

	%Done by updating X/Y coordinates and checking validity of new position 
	%Does this by checking that X/Y are not included in the Visited and that 
	%the move to new X/Y values is valid.

	Xprime is X, Yprime is Y+1, 
	(posValid(Xprime,Yprime,Width,Height),\+ member([Xprime,Yprime],Visited),
	movable(Xprime,Yprime,Maze)),
	Result = [[X,Y]|Visited],
	findadj(Xprime,Yprime,X2,Y2,Maze,Result,Width,Height,Path).

findadj(X,Y,X2,Y2,Maze,Visited,Width,Height,Path) :-
	Xprime is X, Yprime is Y-1, 
	posValid(Xprime,Yprime,Width,Height),\+ member([Xprime,Yprime],Visited),
	movable(Xprime,Yprime,Maze),
	Result = [[X,Y]|Visited],
	findadj(Xprime,Yprime,X2,Y2,Maze,Result,Width,Height,Path).	

findadj(X,Y,X2,Y2,Maze,Visited,Width,Height,Path) :-
	(Xprime is X+1, Yprime is Y, 
	posValid(Xprime,Yprime,Width,Height),\+ member([Xprime,Yprime],Visited),
	movable(Xprime,Yprime,Maze)),

	%Resulting path is found with current X/Y and the Visited coordinates 
	Result = [[X,Y]|Visited],

	%Recursive call with new coordinates after confirming validity
	findadj(Xprime,Yprime,X2,Y2,Maze,Result,Width,Height,Path).

%Repeat for other adjacent movement possibilities
findadj(X,Y,X2,Y2,Maze,Visited,Width,Height,Path) :-
	(Xprime is X-1, Yprime is Y, 
	posValid(Xprime,Yprime,Width,Height),\+ member([Xprime,Yprime],Visited),
	movable(Xprime,Yprime,Maze)),
	Result = [[X,Y]|Visited],
	findadj(Xprime,Yprime,X2,Y2,Maze,Result,Width,Height,Path).
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
	findadj(X1,Y1,X2,Y2,Maze,Visited,Width,Height,Path).
