#include<iostream>
#include<string>
#include<stack>
#include "Calculation.h"

using namespace std;

//함수를 통하여 각 연산자에 해당하는 연산 결과 반환
int Calculator::apply(int a, int b, char op) {
  switch (op) {
  case '+': return a + b;
  case '-': return a - b;
  case '*': return a * b;
  case '/': return a / b;
  }
  return 0;
}

//연산자의 우선 순위를 결정. +.-는 1을 반환하고 *,/는 2를 반환하여 우선 순위를 판단한다.
int Calculator::priority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

//연산 진행
int Calculator::cal(const string& s) {
  int startIndex = 0;
  string operators = "+-*/";

  //스택 초기화 하기
  while (!num.empty()) num.pop();
  while (!ope.empty()) ope.pop();

  while(true) {
    //연산자 찾기 -> find_first_of를 이용하여 +-*/를 한 번에 찾기
    int findex =s.find_first_of(operators, startIndex);

    //만약 더 이상 연산자를 찾지 못했다면 해당 startIndex부터 문자열의 끝까지 저장, 만약 부호로 끝나는데 그 뒤에 문자가 없다면
    //break로 끝내기, 그게 아니라면 num스택에 숫자 추가
    if(findex == -1){
      string part = s.substr(startIndex);
      //만약 연산자 부호 뒤에 값이 없다면(즉, 연산자 부호로 문자열이 끝난다면 INPUT_ERROR 반환)
      if(part == "") {
        return INPUT_ERROR;
      }
      num.push(stoi(part));
      break;
    }

    //count 변수에 findex와 startIndex를 뺸 값을 넣어 숫자의 자리수 파악하기
    int count = findex - startIndex;
    //substr을 이용하여 숫자 잘라서 part변수에 문자열로 저장
    string part = s.substr(startIndex, count);
    //문자열part를 stoi를 이용하여 정수형으로 num스택에 저장
    num.push(stoi(part));

    //op변수에 부호 저장
    char op = s[findex];

    //연산을 진행 하기위해 위에서 만들었던 함수를 통하여 연산자 스택의 top값과 방금 가져온 부호의 값을 비교하여 크거나 같다면
    //(1+2-3, 1*2/2, 1+2*2 등 등) 연산을 진행하도록 조건 설정
    while (!ope.empty() && priority(ope.top()) >= priority(op)) 
    {
      //변수 b에 스택 num에 마지막으로 들어간 값 할당, 그 후 스택에서 해당 값 삭제(그래야 그 다음 수를 가져오고 계산 결과를 추가 할 수 있기 때문)
      int b = num.top(); num.pop();
      //위와 같이 변수a에 스택 num에 b를 삭제한 후 최상위 값을 할당, 그 후 해당 값을 삭제
      int a = num.top(); num.pop();
      //연산자 스택에서 top값을 가져옴
      char ope_cal = ope.top(); ope.pop();
      //함수를 이용하여 연산 부호에 맞는 연산 진행하여 num스택에 추가하기
      //이렇게 하면 두 개의 정수와 하나의 부호가 연산 후 하나의 정수값으로 바뀌어 들어가기에 다음 연산도 자연스럽게 진행가능
      num.push(apply(a, b, ope_cal));
    }

    //비교에 사용하였던 연산자를 ope스택에 추가
    ope.push(s[findex]);
    //startIndex 다음 칸으로 이동
    startIndex = findex+1;
  }

  //위 while문은 연산이 끝나고 연산자 순위에 밀려 연산되지 않은 부호와 수에 대한 연산 진행
  while (!ope.empty()) 
  {
    //위 코드와 동일
    int b = num.top(); num.pop();
    //위 코드와 동일
    int a = num.top(); num.pop();
    //만약 우선 연산자(*, /)가 마지막 연산이어서 스택에 남아있더라도 가장 먼저 pop되기에 계산결과에 문제 X
    char op = ope.top(); ope.pop();
    //함수를 통하여 연산 진행
    num.push(apply(a, b, op));
  }
  //위 모든 과정이 끝나면 num스택에는 계산이 끝난 하나의 값만 있기에 그 값을 반환
  return  num.top();
}