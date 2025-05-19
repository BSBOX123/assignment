// 동적 생성 왜 하는가
  // -> 이 코드에서는 동적 생성구현 X
    // 수정: 동적 생성 구현. 단, 정말 동적생성만 했기에 그 특징을 이용한 코딩 X

// printedount 멤버 변수는 어디다가 사용하는가
  // -> 이 코드에서는 printedount 사용 X

// 위 두가지 사항 수정 필요.


#include<iostream>
#include<string>

using namespace std;

//부모 클래스 - 베이스프린터
class BasePrinter {
protected:
  string model;
  string manufacturer;
  int availableCount;
  int printedCount; // 이건 뭐지
public:
  //부모 클래스 생성자에서 두 프린트의 공통 부분 초기화
  BasePrinter(string model, string manufacturer, int availableCount) {
    this -> model = model;
    this -> manufacturer = manufacturer;
    this -> availableCount = availableCount;
  }
  ~BasePrinter() {}
  bool print(int pages);
  void Show();
};
// 두 프린트 공통으로 종이의 페이지를 조건으로 봐야하기에 부모 클래스에 조건 보기
bool BasePrinter::print(int pages) {
  if(availableCount < pages) {
    return false;
  } else return true;
}
// 공통으로 출력하는 model, manufacturer, availableCount는 부모 클래스에서 작성
void inline BasePrinter::Show() {
  cout << model << ", " << manufacturer << ", 남은 종이" << availableCount << "장"; 
}



//자식 클래스 - 잉크젯
class InkJetPrinter : public BasePrinter {
  int availableInk;
public:
//부모 클래스를 불러와 model과 manufacturer, availableCount를 초기화 하고 혼자만 가지는 availableInk는 따로 초기화
InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) 
  : BasePrinter(model, manufacturer, availableCount) {
  this -> availableInk = availableInk;
}
~InkJetPrinter() {}
  void printInkJet(int pages);
  void InkShow();
};
//부모 클래스의 출력 함수를 사용하고 추가적으로 필요한 부분 출력
void InkJetPrinter::InkShow() {
  Show();
  cout << ", 남은 잉크" << availableInk << endl;
}
//남은 종이는 부모 클래스의 멤버함수를 사용하고 개인이 가지는 availableInk를 확인하여 출력 여부 판단.
void InkJetPrinter::printInkJet(int pages) {
  if(this -> print(pages) == false) {
    cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
    return;
  } else if(availableInk < pages) {
    cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
    return;
  } 
  cout << "프린트 하였습니다." << endl;
  availableCount -= pages;
  availableInk -= pages;
}



//자식 클래스 - 레이저
class LaserPrinter : public BasePrinter {
  int availableToner;
public:
LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) 
  : BasePrinter(model, manufacturer, availableCount) {
  this -> availableToner = availableToner;
}
~LaserPrinter() {}
  void printLaser(int pages);
  void LasShow();
};

void LaserPrinter::LasShow() {
  Show();
  cout << ", 남은 토너" << availableToner << endl;
}

void LaserPrinter::printLaser(int pages) {
  if(this -> print(pages) == false) {
    cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
    return;
  } else if(availableToner < pages) {
    cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
    return;
  } 
  cout << "프린트 하였습니다." << endl;
  availableCount -= pages;
  availableToner -= pages;
}



int main() {
  int pt_num;
  int pg_num;
  char con;

  InkJetPrinter* Ink = new InkJetPrinter("Officejet v40", "HP", 5, 10);
  LaserPrinter* Las = new LaserPrinter("SCX-6X45", "삼성전자", 3, 20);

  cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
  cout << "잉크젯 : ";
  Ink -> InkShow();
  cout << "레이저 : ";
  Las -> LasShow();

  while(true) {
    cout << "\n" <<"프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
    cin >> pt_num >> pg_num;

    switch (pt_num)
    {
    case 1:
      Ink -> printInkJet(pg_num);
      Ink -> InkShow(); 
      Las -> LasShow();
      break;
    
    case 2:
      Las -> printLaser(pg_num);  
      Ink ->InkShow(); 
      Las ->LasShow();
      break;
    
    default:
     cout << "잘 못된 입력 입니다." << endl;
     break;
    }

    while(true) {
      cout << "계속 프린트 하시겠습니까(y/n)>>";
      cin >> con;
      if (con == 'y') {
        break;
      } else if(con == 'n') {
        return 0;
      } else {
        cout << "잘 못된 입력입니다." << endl;
        continue;
      }
    }

  }
}