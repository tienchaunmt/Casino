#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main() {
  _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);
  system("cls");
  wstring playerName;
  wcout << L"Nhập tên của bạn: ";
  getline(wcin, playerName);
  system("pause");
  return 0;
}
