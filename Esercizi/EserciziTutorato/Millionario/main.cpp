#include <iostream>
#include "Question.h"
void readAllQuestions(int numberOfQuestion, Question *question);
using namespace std;
int main(){
    ifstream in("input.txt");
    if (!in){
        cerr<<"Error in open file "<<endl;
        return -1;
    }
    int numberOfquestions;

    in>>numberOfquestions;
    in.ignore(); // \n igonrato

    Question question[numberOfquestions];

    for (int i = 0; i <numberOfquestions ; ++i) {
        question[i]=Question(in);
    }
    in.close();
    readAllQuestions(numberOfquestions,question);
    return 0;
}

void readAllQuestions(int numberOfQuestion, Question *question){
    int answersUser,countA=0;
    for (int i = 0; i <numberOfQuestion ; ++i) {
       question[i].readText();
       cout<<"Inseer the answer"<<endl;
       cin>>answersUser;
        if (question[i].guessAnswers(answersUser)){  //==true
            cout<<"The answer is correct"<<endl;
            countA++;
        } else{
            cout<<"The answer is incorrect"<<endl;
        }
    }
    cout<<"Rate: "<<((countA/numberOfQuestion)*100)<< endl;
}