.PHONY: build clean

OBJS = CompilerDynamic.o ArgsParser.o bfc.o

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++14 -Wall -Wpedantic $(DEBUG)
OUT = bfc

build: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

bfc.cpp:
	sh generate_bfc_source.sh

clean:
	rm -f bfc.cpp $(OUT) $(OBJS)
