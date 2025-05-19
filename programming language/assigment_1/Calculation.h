#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
using namespace std;

class Calculator {
private:
    stack<int> num;
    stack<char> ope;

    int apply(int a, int b, char op);
    int priority(char op);

public:
    //복사 생성하는 것을 방지하기 위해 참조매개변수로 값 입력
    int cal(const string& s);
    int INPUT_ERROR = 4;
};

#endif 