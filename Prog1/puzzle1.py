#CS463 - Artificial Intelligence
#Puzzle 1 - Atomic Chaos
#Casey O'Kane - 8/30/16

from graphics import *

def drawChaos(window):
    #current plan, draw a large rectangle and redraw tubes as click occurs
    lCorner = Point(50,50)
    rCorner = Point(350,350)
    tubeContainer = Rectangle(lCorner, rCorner)
    tubeContainer.setOutline('white')
    tubeContainer.draw(window)

    topLine = Line(Point(50,50),Point(350,50))
    t6Line = Line(Point(50,100),Point(350,100))
    t5Line = Line(Point(50,150),Point(350,150))
    t4Line = Line(Point(50,200),Point(350,200))
    t3Line = Line(Point(50,250),Point(350,250))
    t2Line = Line(Point(50,300),Point(350,300))
    t1Line = Line(Point(50,350),Point(350,350))
    topLine.draw(window)
    t6Line.draw(window)
    t5Line.draw(window)
    t4Line.draw(window)
    t3Line.draw(window)
    t2Line.draw(window)
    t1Line.draw(window)

def main():
    #Currently just a dummy program that creates a small window with a circle
    window = GraphWin('Atomic Chaos Solution', 400, 400)
    drawChaos(window)
    rBall = Circle(Point(200,200),25)
    rBall.setFill('red')
    rBall.draw(window)
    window.getMouse()
    window.close()
    #Create 2D array to keep track of the tubes 
    #Draw the initial state of the tubes 
    #Account for tube movement (left/right/up/down)
    #Implement user interraction with UI
    #Implement solver function
    #Implement randomizer function


main()
