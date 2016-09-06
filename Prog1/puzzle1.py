#CS463 - Artificial Intelligence
#Puzzle 1 - Atomic Chaos
#Casey O'Kane - 8/30/16

from graphics import *

#Global list used to keep track of ball locations
currBallLocs = []
#Global List to contain tube locations
tubeLocs = []
#Dictionary to associate numbers with colors:
numColorDict = {1:'white', 2:'black',3:'blue',4:'yellow',5:'green',6:'red'}

def drawChaos(window):

    drawList = []
    lBallRow = []; rBallRow = [];
    lRectRow = []; rRectRow = [];
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

    gravMsg = Text(Point(390,400), 'Gravity = Right Side');
    gravMsg.draw(window)
    
    #Primary for loop used to do the initial ball printing and store the objects
    for i in range(6,0,-1):
        lBallCol = []; rBallCol = [];
        
        if i == 6:
            currLTLoc = leftT6CircleLoc; currRTLoc = rightT6CircleLoc;
        elif i == 5:
            currLTLoc = leftT5CircleLoc; currRTLoc = rightT5CircleLoc;
        elif i == 4:
            currLTLoc = leftT4CircleLoc; currRTLoc = rightT4CircleLoc;
        elif i == 3:
            currLTLoc = leftT3CircleLoc; currRTLoc = rightT3CircleLoc;
        elif i == 2:
            currLTLoc = leftT2CircleLoc; currRTLoc = rightT2CircleLoc;
        else:
            currLTLoc = leftT1CircleLoc; currRTLoc = rightT1CircleLoc;
            
        currColor = numColorDict[i]

        offset = 0    
        for j in range (6, 0 ,-1):
            lCircle = Circle(Point(currLTLoc.getX()+offset,currLTLoc.getY()),10)
            rCircle = Circle(Point(currRTLoc.getX()-offset,currRTLoc.getY()),10)
            offset += 60
            lCircle.setOutline('white');lCircle.setFill('white');
            if j>i:
                rCircle.setOutline('white');rCircle.setFill('white');
            else:
                rCircle.setOutline('black');rCircle.setFill(currColor);
            
            lCircle.draw(window); rCircle.draw(window);
            lBallCol.append(lCircle); rBallCol.append(rCircle);
            
        lBallRow.append(lBallCol); rBallRow.append(rBallCol);
            
    drawList.append(lBallRow);drawList.append(rBallRow);drawList.append(gravMsg)

    #Possible improvement here... Have UI buttons...
##    lCWrect = Rectangle(Point(50,300), Point(300,400)); lCWrect.draw(window);
##    lCCWrect = Rectangle(Point(50,400), Point(300,500)); lCCWrect.draw(window);
##    rCWrect = Rectangle(Point(400,300), Point(650,400)); rCWrect.draw(window);
##    rCCWrect = Rectangle(Point(400,400), Point(650,500)); rCCWrect.draw(window);
    
    return drawList

def redrawPuzzle(window, drawList):
    print('Left:', currBallLocs[0]); print('Right:',currBallLocs[1]);
    for tube in range(6):
        tubeNum = 6-tube
        circleColor = numColorDict[tubeNum]
        for lCtr in range(len(currBallLocs[0][tube])):
            if currBallLocs[0][tube][lCtr] == 0:
                drawList[0][tube][lCtr-tubeNum].setOutline('white')                
                drawList[0][tube][lCtr-tubeNum].setFill('white')
            else:
                drawList[0][tube][lCtr-tubeNum].setFill(circleColor)
                if circleColor == 'white':
                    drawList[0][tube][lCtr-tubeNum].setOutline('black')
                    
        for rCtr in range(len(currBallLocs[1][tube])):
            if currBallLocs[1][tube][rCtr] == 0:
                drawList[1][tube][rCtr-tubeNum].setOutline('white')
                drawList[1][tube][rCtr-tubeNum].setFill('white')
            else:
                drawList[1][tube][rCtr-tubeNum].setFill(circleColor)
                if circleColor == 'white':
                    drawList[1][tube][rCtr-tubeNum].setOutline('black')
               
    return 

def handleMovement(userMove, oriented, gravity):

    #First check that if gravity is on same side as rotation, don't flip
    if (userMove != 'f') & (oriented == gravity):
        return

    #Push and pull sides are used to determine which side of the puzzle the
    #balls are moving. Default is that the right side is bottom 

    #Flip motion is preformed based on the current state of gravity
    else:
        pullSide = 0; pushSide = 1
        #gravity is passed as oriented parameter
        if gravity == 'l':
            pullSide = 1; pushSide = 0
            
        for tube in range(0,6,1):
            #Position of where nonzero balls begin in the right tube
            pos = 0
            #Find the number of positions until a nonzero value occurs
            while currBallLocs[pushSide][tube][pos] == 0:
                pos+=1

            #variable used to keep track of the balls in a tube     
            remainingNonZeros = len(currBallLocs[pushSide][tube]) - pos
            for i in range(0, len(currBallLocs[pullSide][tube]), 1):
                if currBallLocs[pullSide][tube][i] == 0:
                    #For each element in the right, check that it can go in the left 
                    if pos < remainingNonZeros:
                        currBallLocs[pullSide][tube][i] = currBallLocs[pushSide][tube].pop(0)
                        #update push tube 
                        currBallLocs[pushSide][tube].append(0)
                        pos+=1

##    #If flip is not being preformed, then a rotation is
##    else:
##        #After tubes are rotated, check that gravity handles any balls that
##        #should fall
##        for tube in range(6):
##            for i in range(0, len(currBallLocs[pullSide][tube]), 1):
##                if currBallLocs[pullSide][tube][i] == 0:
                    
 

def accountforMovement(userMove, window, drawList, gravity):

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
        handleMovement('cw', 'l', gravity)
        
        
    elif userMove == 'lccw':
        tempRow = currBallLocs[0].pop(0)
        currBallLocs[0].append(tempRow)
        for i in range(1,6,1):
            tubeLocs[0][i].move(0,-50)
        tubeLocs[0][0].move(0,250)
        tempRow = tubeLocs[0].pop(0)
        tubeLocs[0].append(tempRow)
        handleMovement('ccw', 'l', gravity)

    #Movement for right tube
    elif userMove == 'rcw':
        tempRow = currBallLocs[1].pop()
        currBallLocs[1].insert(0,tempRow)
        for i in range(0,5,1):
            tubeLocs[1][i].move(0,50)
        tubeLocs[1][5].move(0,-250)
        tempRow = tubeLocs[1].pop()
        tubeLocs[1].insert(0,tempRow)
        handleMovement('cw', 'r', gravity)
        
    elif userMove == 'rccw':
        tempRow = currBallLocs[1].pop(0)
        currBallLocs[1].append(tempRow)
        for i in range(1,6,1):
            tubeLocs[1][i].move(0,-50)
        tubeLocs[1][0].move(0,250)
        tempRow = tubeLocs[1].pop(0)
        tubeLocs[1].append(tempRow)
        handleMovement('cw', 'r', gravity)
       
    #Flip Action - used to flip the puzzle from one side to the other
    elif userMove == 'f':
        #Determine movement based on which way gravity is acting
        if gravity == 'l':
            handleMovement(userMove, 'r', gravity)
            drawList[2].setText('Gravity = Right Side')
            gravity = 'r'
        else:
            handleMovement(userMove, 'l', gravity)
            drawList[2].setText('Gravity = Left Side')
            gravity = 'l'

    #Status move, for debugging purposes    
    elif userMove == 's':
        print("CurrBallLocs[0]: ", currBallLocs[0])
        print("CurrBallLocs[1]: ", currBallLocs[1])

    redrawPuzzle(window, drawList)
    return gravity       
            

def main():
    #Create a graphics window and set the initial conditions for the board
    window = GraphWin('Atomic Chaos Solution', 780, 500)
    drawList = drawChaos(window)

    #char used to determine if gravity is active towards right or left side
    gravity = 'r'
    
    #Initialize Ball Location List which keeps track of the balls in both tubes
    lPuzzleLocs = []
    rPuzzleLocs = []    
    for i in range (6,0,-1):
        lTemp = []
        rTemp = []
        for j in range(0,i,1):
            lTemp.append(0); rTemp.append(i)
        lPuzzleLocs.append(lTemp); rPuzzleLocs.append(rTemp)
    #Finally, when both sides of the puzzle are stored, append them to the list    
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
            gravity = accountforMovement(userInput, window, drawList,gravity)
            userInput = input('New Command? Select "q" to quit,"h" for help: ')

    #print("CurrBallLocs: ", currBallLocs)
    #accountforMovement('lcw', window, drawList)

    #window.getMouse()
    window.close()
    #Account for tube movement (left/right/up/down)
    #Implement randomizer function


main()
