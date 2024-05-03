ex: main.o rectangle.o
	g++ main.o rectangle.o -o ex

main.o: main.cpp
	g++ -c main.cpp

rectangle.o: Rectangle.cpp
	g++ -c Rectangle.cpp

clean:
	rm -rf *o ex
