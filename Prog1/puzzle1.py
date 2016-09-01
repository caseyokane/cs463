#CS463 - Artificial Intelligence
#Puzzle 1 - Atomic Chaos
#Casey O'Kane - 8/30/16

from graphics import *

def drawChaos(window):

    #The below idea is to draw individual tubes and then move them around
    #Maybe look into QGraphicsItemGroup

    #Still need to account for making some rectangles smaller, change up corner
    leftT6upCorner = Point(50,50); leftT6lowCorner = Point(200,100);
    leftT5upCorner = Point(75,100); leftT5lowCorner = Point(200,150);
    leftT4upCorner = Point(100,150); leftT4lowCorner = Point(200,200);
    leftT3upCorner = Point(125,200); leftT3lowCorner = Point(200,250);
    leftT2upCorner = Point(150,250); leftT2lowCorner = Point(200,300);
    leftT1upCorner = Point(175,300); leftT1lowCorner = Point(200,350);

    leftT6CircleLoc = Point(60,75); leftT5CircleLoc = Point(60, 125);
    leftT4CircleLoc = Point(60,175); leftT3CircleLoc = Point(60, 225);
    leftT2CircleLoc = Point(60,275); leftT1CircleLoc = Point(60, 325);

    rightT6CircleLoc = Point(340,75); rightT5CircleLoc = Point(340, 125);
    rightT4CircleLoc = Point(340,175); rightT3CircleLoc = Point(340, 225);
    rightT2CircleLoc = Point(340,275); rightT1CircleLoc = Point(340, 325);


    rightT6upCorner = Point(200,50); rightT6lowCorner = Point(350,100);
    rightT5upCorner = Point(200,100); rightT5lowCorner = Point(325,150);
    rightT4upCorner = Point(200,150); rightT4lowCorner = Point(300,200);
    rightT3upCorner = Point(200,200); rightT3lowCorner = Point(275,250);
    rightT2upCorner = Point(200,250); rightT2lowCorner = Point(250,300);
    rightT1upCorner = Point(200,300); rightT1lowCorner = Point(225,350);

    leftT6 = Rectangle(leftT6upCorner, leftT6lowCorner)
    leftT6.draw(window)
    leftT5 = Rectangle(leftT5upCorner, leftT5lowCorner)
    leftT5.draw(window)
    leftT4 = Rectangle(leftT4upCorner, leftT4lowCorner)
    leftT4.draw(window)
    leftT3 = Rectangle(leftT3upCorner, leftT3lowCorner)
    leftT3.draw(window)
    leftT2 = Rectangle(leftT2upCorner, leftT2lowCorner)
    leftT2.draw(window)
    leftT1 = Rectangle(leftT1upCorner, leftT1lowCorner)
    leftT1.draw(window)

    rightT6 = Rectangle(rightT6upCorner, rightT6lowCorner)
    rightT6.draw(window)
    rightT5 = Rectangle(rightT5upCorner, rightT5lowCorner)
    rightT5.draw(window)
    rightT4 = Rectangle(rightT4upCorner, rightT4lowCorner)
    rightT4.draw(window)
    rightT3 = Rectangle(rightT3upCorner, rightT3lowCorner)
    rightT3.draw(window)
    rightT2 = Rectangle(rightT2upCorner, rightT2lowCorner)
    rightT2.draw(window)
    rightT1 = Rectangle(rightT1upCorner, rightT1lowCorner)
    rightT1.draw(window)

    ChaosBallList = []
    lBallRow = []
    rBallRow = []
    currLTLoc = 0
    currRTLoc = 0

    #Primary for loop used to do the initial ball printing and store the obects
    for i in range(6,0,-1):
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

        BallOffset = 0    
        for j in range (0,6,1):
            lCircle = Circle(currLTLoc, 10)
            rCircle = Circle(currRTLoc, 10)
            BallOffset += 30
            lCircle.setOutline('black'); rCircle.setOutline('black');
            lCircle.setFill('black'); rCircle.setOutline('black');
            lCircle.draw(window); rCircle.draw(window);
            lBallRow.append(lCircle); rBallRow.append(rCircle);
            
        ChaosBallList.append(lBallRow); ChaosBallList.append(rBallRow);    

def main():
    #Currently just a dummy program that creates a small window with a circle
    window = GraphWin('Atomic Chaos Solution', 400, 400)
    drawChaos(window)
    window.getMouse()
    window.close()
    #Create 2D array to keep track of the tubes 
    #Draw the initial state of the tubes 
    #Account for tube movement (left/right/up/down)
    #Implement user interraction with UI
    #Implement solver function
    #Implement randomizer function


main()
