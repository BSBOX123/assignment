#include<iostream>
#include<string>
#include "Dept.h"

using namespace std;

Dept::Dept(const Dept &dept) {
  this -> size = dept.size;
  this -> scores = new int[size];
  for (int i=0; i < size; i++) {
    this -> scores[i] = dept.scores[i];
  }
} 


void Dept::read() {
  cout << size <<" 개 정수 입력 : ";
  for(int i=0; i < size; i++) {
    cin >> scores[i];
  }
}
bool Dept::isOver60(int index) {
  if(scores[index] > 60) {
    return true;
  } else {
    return false;
  }
}
Dept::~Dept() {
  if(scores != nullptr) {
    delete[] scores;
  }
}

//5장 3번 에 2번은 참조를 사용하여 복사 생성자 없이 값 출력