ex: data.o node.o  list.o main.o
	g++  data.o node.o  list.o main.o


main.o: main.cpp
	g++ -c main.cpp


list.o:
	g++ -c List.cpp

node.o:
	g++ -c Node.cpp
data.o:
	g++ -c Data.cpp
clean:
	rm -rf *o ex


