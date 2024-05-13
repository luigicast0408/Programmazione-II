ex: students.o Scholarship.o ScholarshipStudents.o Node.o List.o main.o
	g++ students.o Scholarship.o ScholarshipStudents.o Node.o List.o main.o -o ex

students.o: Students.cpp
	g++ -c Students.cpp

Scholarship.o: Scholarship.cpp
	g++ -c Scholarship.cpp

ScholarshipStudents.o: ScholarshipStudents.cpp
	g++ -c ScholarshipStudents.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

List.o: List.cpp
	g++ -c List.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o ex
