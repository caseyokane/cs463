# A basic Makefile 
CC = g++
CFLAGS = -Wall -g
INCLUDES = -I.
LIBS = -lpthread
SRCS = DPLL.cpp   
OBJS = DPLL.o   

SATassign = SATassignment
LDFLAGS = -ldl

all:	$(SATassign)

$(SATassign):$(OBJS) 
	$(CC)  -o $(SATassign) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(LDFLAGS) 

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(SATassign)

