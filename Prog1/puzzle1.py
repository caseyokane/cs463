#CS463 - Artificial Intelligence
#Puzzle 1 - Atomic Chaos
#Casey O'Kane - 8/30/16

from graphics import *

def drawChaos(window):

    #Still need to account for making some rectangles smaller, change up corner
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

    leftT6CircleLoc = Point(60,75); leftT5CircleLoc = Point(60, 125);
    leftT4CircleLoc = Point(60,175); leftT3CircleLoc = Point(60, 225);
    leftT2CircleLoc = Point(60,275); leftT1CircleLoc = Point(60, 325);

    rightT6CircleLoc = Point(720,75); rightT5CircleLoc = Point(720, 125);
    rightT4CircleLoc = Point(720,175); rightT3CircleLoc = Point(720, 225);
    rightT2CircleLoc = Point(720,275); rightT1CircleLoc = Point(720, 325);

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
    currColor = 'black'

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
                lCircle.setOutline('white'); rCircle.setOutline('white');
                lCircle.setFill('white'); rCircle.setFill('white');
            else:
                lCircle.setOutline('black'); rCircle.setOutline('black');
                lCircle.setFill(currColor); rCircle.setFill(currColor);
            lCircle.draw(window); rCircle.draw(window);
            lBallRow.append(lCircle); rBallRow.append(rCircle);
            
        ChaosBallList.append(lBallRow); ChaosBallList.append(rBallRow);    

def main():
    #Currently just a dummy program that creates a small window with a circle
    window = GraphWin('Atomic Chaos Solution', 780, 500)
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
