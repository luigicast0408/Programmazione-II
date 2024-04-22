#ifndef QUESTION
#define QUESTION
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Question {
private:
    string text;
    string answers[4];
    bool correct;
    ofstream *out;
    string question1,question2,question3,question4;
    int index;
public:
    Question();
    Question(ifstream& out);
    Question(string text, string question1, string question2,string question3, string question4, int index);
    Question(string& t, string r[4], int c);
    void readText();
    bool guessAnswers(int answer);
};


#endif
