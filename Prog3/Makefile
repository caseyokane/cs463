# A basic Makefile 
CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I.
LIBS = -lpthread
SRCS = csapp.c p3extra.c  
OBJS = csapp.o p3extra.o  

CSRCS = $(SRCS) rrshClient.c
SSRCS = $(SRCS) rrshServer.c
COBJS = $(OBJS) rrshClient.o
SOBJS = $(OBJS) rrshServer.o

RRSHSERVER = rrsh-server
RRSHCLIENT = rrsh-client
LDFLAGS = -ldl

all:	$(RRSHSERVER) $(RRSHCLIENT)

$(RRSHSERVER):$(SOBJS) 
	$(CC)  -o $(RRSHSERVER) $(CFLAGS) $(INCLUDES) $(SOBJS) $(LIBS) $(LDFLAGS) 

$(RRSHCLIENT):$(COBJS)
	$(CC)  -o $(RRSHCLIENT) $(CFLAGS) $(INCLUDES) $(COBJS) $(LIBS) $(LDFLAGS) 

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(RRSHSERVER) $(RRSHCLIENT)

