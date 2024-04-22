#include "Question.h"
using namespace std;
Question::Question() {
    text="";
    correct= false;
    out=nullptr;
    question1="";
    question2="";
    question3="";
    question4="";
    index=0;
}
Question::Question(ifstream& out) {
    getline(out,text);
    for (int i = 0; i < 3; ++i) {
        getline(out, answers[i]);
    }
    out >> index;
}

Question::Question(string& t, string r[4], int c) {
    this->text=t;
    for (int i = 0; i < 4; ++i)
        answers[i] = r[i];
    correct = c;
}

Question::Question(string text, string question1, string question2, string question3,string question4, int index) {
    this->text= text;
    answers[0]=question1;
    answers[1]=question2;
    answers[2]=question3;
    answers[3]=question4;
    this->index=index;
}

void Question::readText() {
    cout<<"_______Question________"<<endl;
    cout<<"TEXT:"<<text<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<i<<")"<<answers[i]<<endl;
    }
    cout<<"_____END QUESTION________"<<endl;
}

bool Question::guessAnswers(int answer) {
    return (answer-1)==index ? true: false;
}