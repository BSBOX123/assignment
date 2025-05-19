#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
  string s;

  stack<int> num;
  stack<char> op;

  cout << "문자열 입력: "<< endl;
  getline(cin, s);

  int start = 0;

  while(true) {
    int findex = s.find_first_of("+-*/", start);
    if(findex == -1) {
      string part = s.substr(start);
      if(part == "") {
        break;
      }
      cout << part << endl;
    }
    int count = findex - start;
    string part = s.substr(start, count);
    cout << part << endl;
    num.push(stoi(part));
  }
}
