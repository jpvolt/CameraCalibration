CC = g++
CFLAGS = 
SRCS = main.cpp
PROG = SimpleUndistort

PKGCONF = `pkg-config opencv camcalib --cflags --libs`
LIBS = $(PKGCONF)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)