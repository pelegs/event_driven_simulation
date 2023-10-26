# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O1

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
TESTDIR = tests

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TESTSRCS = $(wildcard $(TESTDIR)/*.cpp)
TESTOBJS = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TESTSRCS))

# Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS += -I$(SRCDIR)

# Targets
TARGET = $(BINDIR)/ball_wall_collision_time_run

all: $(TARGET)

$(TARGET): $(OBJS) $(TESTOBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean

