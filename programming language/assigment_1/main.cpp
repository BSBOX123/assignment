#include<iostream>
#include<string>
#include<stack>
#include "Calculation.h"

using namespace std;

int main() {
  string s;
  Calculator a;

  while (true) {
    cout << "입력식 >> ";
    getline(cin, s, '\n');
    
    if(s == "end") {
      cout << "종료합니다." << endl;
      break;
    }
    int result = a.cal(s);
    //만약 함수의 결과 값이 문자열이 부호로 끝날 때 반환하는 특정 값이라면 잘못된 입력이라는 문구 출력
    if(result == a.INPUT_ERROR) {
      cout << "입력식이 잘못되었습니다." << endl;
      continue;
    }
    cout << "결과: " << result << endl;
  }
}
