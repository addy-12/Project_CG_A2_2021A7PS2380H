LIBS = -lglut -lGLU -lGL

all: run

run : main.o Control.o Mass.o Segment.o Spring.o Worm.o
	g++ -o run main.o Control.o Mass.o Segment.o Spring.o Worm.o $(LIBS) 

main : main.cpp
	g++ -c main.cpp

Control: Control.cpp
	g++ -c Control.cpp

Mass: Mass.cpp
	g++ -c Mass.cpp

Segment: Segment.cpp
	g++ -c Segment.cpp

Spring: Spring.cpp
	g++ -c Spring.cpp

Worm: Worm.cpp
	g++ -c Worm.cpp

clean:
	rm -f run main.o Control.o Spring.o Segment.o Mass.o Worm.o