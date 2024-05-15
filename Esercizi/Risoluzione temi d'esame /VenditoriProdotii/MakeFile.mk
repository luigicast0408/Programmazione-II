ex: Date.o  Product.o FoodProduct.o ProductChildren.o Node.o Queue.o Seller.o main.o
	g++ Date.o  Product.o FoodProduct.o ProductChildren.o Node.o Queue.o Seller.o main.o

Date.o: Date.cpp
	g++ -c Date.cpp

Product.o: Product.cpp
	g++ -c Product.cpp

FoodProduct.o: FoodProduct.cpp
	g++ -c FoodProduct.cpp

ProductChildren.o: ProductChildren.cpp
	g++ -c ProductChildren.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp

Seller.o: Seller.cpp
	g++ -c  Seller.cpp

main.o: main.cpp
	g++ -c main.cpp












