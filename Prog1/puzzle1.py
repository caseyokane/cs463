#CS463 - Artificial Intelligence
#Puzzle 1 - Atomic Chaos
#Casey O'Kane - 8/30/16

from graphics import *

#Global list used to keep track of ball locations
currBallLocs = []
#Global List to contain tube locations
tubeLocs = []
#Global char used to determine if gravity is active towards right or left side
gravity = 'r'

def drawChaos(window):

    ChaosBallList = []
    lBallRow = []
    rBallRow = []
    lRectRow = []
    rRectRow = []
    currLTLoc = 0
    currRTLoc = 0
    currColor = 'black'

    #Coordinates for rectangles
    leftT6upCorner = Point(30,50); leftT6lowCorner = Point(390,100);
    leftT5upCorner = Point(90,100); leftT5lowCorner = Point(390,150);
    leftT4upCorner = Point(150,150); leftT4lowCorner = Point(390,200);
    leftT3upCorner = Point(210,200); leftT3lowCorner = Point(390,250);
    leftT2upCorner = Point(270,250); leftT2lowCorner = Point(390,300);
    leftT1upCorner = Point(330,300); leftT1lowCorner = Point(390,350);

    rightT6upCorner = Point(390,50); rightT6lowCorner = Point(750,100);
    rightT5upCorner = Point(390,100); rightT5lowCorner = Point(690,150);
    rightT4upCorner = Point(390,150); rightT4lowCorner = Point(630,200);
    rightT3upCorner = Point(390,200); rightT3lowCorner = Point(570,250);
    rightT2upCorner = Point(390,250); rightT2lowCorner = Point(510,300);
    rightT1upCorner = Point(390,300); rightT1lowCorner = Point(450,350);

    #Coordinates for circles
    leftT6CircleLoc = Point(60,75); leftT5CircleLoc = Point(60, 125);
    leftT4CircleLoc = Point(60,175); leftT3CircleLoc = Point(60, 225);
    leftT2CircleLoc = Point(60,275); leftT1CircleLoc = Point(60, 325);

    rightT6CircleLoc = Point(720,75); rightT5CircleLoc = Point(720, 125);
    rightT4CircleLoc = Point(720,175); rightT3CircleLoc = Point(720, 225);
    rightT2CircleLoc = Point(720,275); rightT1CircleLoc = Point(720, 325);

    #Create Rectangular objects
    leftT6 = Rectangle(leftT6upCorner, leftT6lowCorner)
    leftT5 = Rectangle(leftT5upCorner, leftT5lowCorner)
    leftT4 = Rectangle(leftT4upCorner, leftT4lowCorner)
    leftT3 = Rectangle(leftT3upCorner, leftT3lowCorner)
    leftT2 = Rectangle(leftT2upCorner, leftT2lowCorner)
    leftT1 = Rectangle(leftT1upCorner, leftT1lowCorner)

    rightT6 = Rectangle(rightT6upCorner, rightT6lowCorner)
    rightT5 = Rectangle(rightT5upCorner, rightT5lowCorner)
    rightT4 = Rectangle(rightT4upCorner, rightT4lowCorner)
    rightT3 = Rectangle(rightT3upCorner, rightT3lowCorner)
    rightT2 = Rectangle(rightT2upCorner, rightT2lowCorner)
    rightT1 = Rectangle(rightT1upCorner, rightT1lowCorner)

    lRectRow.append(leftT6); lRectRow.append(leftT5); lRectRow.append(leftT4);
    lRectRow.append(leftT3); lRectRow.append(leftT2); lRectRow.append(leftT1);

    rRectRow.append(rightT6); rRectRow.append(rightT5); rRectRow.append(rightT4);
    rRectRow.append(rightT3); rRectRow.append(rightT2); rRectRow.append(rightT1);

    #Append the rectangle objects to global array
    tubeLocs.append(lRectRow); tubeLocs.append(rRectRow);

    leftT6.draw(window); leftT5.draw(window);leftT4.draw(window)
    leftT3.draw(window); leftT2.draw(window);leftT1.draw(window)
    
    rightT6.draw(window); rightT5.draw(window); rightT4.draw(window);
    rightT3.draw(window); rightT2.draw(window); rightT1.draw(window);
    

    #Primary for loop used to do the initial ball printing and store the obects
    for i in range(6,0,-1):
        if i == 6:
            currLTLoc = leftT6CircleLoc; currRTLoc = rightT6CircleLoc;
            currColor = 'red'
        elif i == 5:
            currLTLoc = leftT5CircleLoc; currRTLoc = rightT5CircleLoc;
            currColor = 'green'
        elif i == 4:
            currLTLoc = leftT4CircleLoc; currRTLoc = rightT4CircleLoc;
            currColor = 'yellow'
        elif i == 3:
            currLTLoc = leftT3CircleLoc; currRTLoc = rightT3CircleLoc;
            currColor = 'blue'
        elif i == 2:
            currLTLoc = leftT2CircleLoc; currRTLoc = rightT2CircleLoc;
            currColor = 'black'
        else:
            currLTLoc = leftT1CircleLoc; currRTLoc = rightT1CircleLoc;
            currColor = 'white'

        offset = 0    
        for j in range (6,0,-1):
            lCircle = Circle(Point(currLTLoc.getX()+offset,currLTLoc.getY()),10)
            rCircle = Circle(Point(currRTLoc.getX()-offset,currRTLoc.getY()),10)
            offset += 60
            if j>i:
                lCircle.setOutline('white');lCircle.setFill('white');
                rCircle.setOutline('white');rCircle.setFill('white');
            else:
                lCircle.setOutline('white');lCircle.setFill('white'); 
                rCircle.setOutline('black');rCircle.setFill(currColor);
                rCircle.draw(window);
            #lCircle.draw(window); rCircle.draw(window);
            lBallRow.append(lCircle); rBallRow.append(rCircle);
            
        ChaosBallList.append(lBallRow); ChaosBallList.append(rBallRow);

    #Possible improvement here... Have UI buttons...
##    lCWrect = Rectangle(Point(50,300), Point(300,400)); lCWrect.draw(window);
##    lCCWrect = Rectangle(Point(50,400), Point(300,500)); lCCWrect.draw(window);
##    rCWrect = Rectangle(Point(400,300), Point(650,400)); rCWrect.draw(window);
##    rCCWrect = Rectangle(Point(400,400), Point(650,500)); rCCWrect.draw(window);
    
    
    return ChaosBallList

def redrawPuzzle(userMove, window, drawList):
    #user
    return    

def accountforMovement(userMove, window, drawList):

    #Clockwise = Down, Counter Clockwise = Up

    #TODO: Consider collections.deque here...
    #TODO: Rewrite functionality with helper method (split left/right)
    #Movement for left tube
    if userMove == 'lcw':
        tempRow = currBallLocs[0].pop()
        currBallLocs[0].insert(0,tempRow)
        #Actually move the rectangle drawings
        for i in range(0,5,1):
            tubeLocs[0][i].move(0,50)
        tubeLocs[0][5].move(0,-250)
        #Adjust rectangle object arrays 
        tempRow = tubeLocs[0].pop()
        tubeLocs[0].insert(0,tempRow)
        #TODO: HANDLE BALL MOVEMENT
        
    elif userMove == 'lccw':
        tempRow = currBallLocs[0].pop(0)
        currBallLocs[0].append(tempRow)
        for i in range(1,6,1):
            tubeLocs[0][i].move(0,-50)
        tubeLocs[0][0].move(0,250)
        tempRow = tubeLocs[0].pop(0)
        tubeLocs[0].append(tempRow)

    #Movement for right tube
    elif userMove == 'rcw':
        tempRow = currBallLocs[1].pop()
        currBallLocs[1].insert(0,tempRow)
        for i in range(0,5,1):
            tubeLocs[1][i].move(0,50)
        tubeLocs[1][5].move(0,-250)
        tempRow = tubeLocs[1].pop()
        tubeLocs[1].insert(0,tempRow)        
        
    elif userMove == 'rccw':
        tempRow = currBallLocs[1].pop(0)
        currBallLocs[1].append(tempRow)
        for i in range(1,6,1):
            tubeLocs[1][i].move(0,-50)
        tubeLocs[1][0].move(0,250)
        tempRow = tubeLocs[1].pop(0)
        tubeLocs[1].append(tempRow)        
        
    #Flip Action
    elif userMove == 'f':
        return

    return

def main():
    #Create a graphics window and set the initial conditions for the board
    window = GraphWin('Atomic Chaos Solution', 780, 500)
    drawList = drawChaos(window)
    
    #Initialize Ball Location List which keeps track of the balls in both tubes
    #First make sure that the left puzzle is blank
    lPuzzleLocs = [[0] * 6 for i in range(6)]
    #Then make sure right side matches with initial state
    rPuzzleLocs = []
    for i in range (6,0,-1):
        rTemp = []
        for j in range(0,6,1):
            if j<i:
                rTemp.append(i)
            else:
                rTemp.append(0)
        rPuzzleLocs.append(rTemp)
    #Finally, when both sides of the puzzle are stored,     
    currBallLocs.append(lPuzzleLocs); currBallLocs.append(rPuzzleLocs);

    #Start User interraction loop
    userInput = input('What would you like to do? Select "q" to quit,"h" for help: ')
    while(userInput != 'q'):
        if userInput == 'h':
            print('lcw = left clockwise, rcw = right clockwise')
            print('lccw = left counterclockwise, rccw = right counterclockwise')
            print('f = flip, q= quit')
            userInput = input('New command?')
        else:
            accountforMovement(userInput, window, drawList)
            userInput = input('New Command? Select "q" to quit,"h" for help: ')

    #print("CurrBallLocs: ", currBallLocs)
    #print("CurrBallLocs[0]: ", currBallLocs[0])
    #accountforMovement('lcw', window, drawList)

    #window.getMouse()
    window.close()
    #Create 2D array to keep track of the tubes 
    #Account for tube movement (left/right/up/down)
    #Implement solver function
    #Implement randomizer function


main()
