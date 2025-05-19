#include<iostream>
#include<string>
#include "Dept.h"

using namespace std;

int countPass(Dept dept) {
  int count = 0;
  for (int i = 0; i < dept.getSize(); i++) {
    if (dept.isOver60(i)) count++;
  }
  return count;
}

int main() {
  Dept com(10);
  com.read();
  int n = countPass(com);
  cout << "60점 이상은 " << n << "명" << endl;
}