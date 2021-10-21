#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

void drawLine(int n, char symbol);

int main() {
  _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);

  system("cls");

  drawLine(60,'_');
  wcout << "\n\n\n\t\t\tCASINO GAME\n\n\n";
  drawLine(60,'_');

  wstring playerName;
  wcout << L"Nhập tên của bạn: ";
  getline(wcin, playerName);

  int amount;
  wcout << L"Số tiền (VND) bạn đăng ký sở hữu trong trò chơi: ";
  wcin >> amount;

  system("pause");
  return 0;
}

void drawLine(int n, char symbol) {
  for(int i = 0; i < n; i++)
    wcout << symbol;
  wcout << "\n";
}