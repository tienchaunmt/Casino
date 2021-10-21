#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

void drawLine(int n, char symbol);
void rules();

int main() {
  _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);

  system("cls");

  drawLine(80,'_');
  wcout << "\n\n\n\t\t\t\tCASINO GAME\n\n\n";
  drawLine(80,'_');

  wstring playerName;
  wcout << L"Nhập tên của bạn: ";
  getline(wcin, playerName);

  int amount;
  wcout << L"Số tiền (VND) bạn đăng ký sở hữu trong trò chơi: ";
  wcin >> amount;

  wchar_t choice;

  do {
    system("cls");
    rules();

    wcout << L"\n\n--> Bạn có muốn chơi tiếp không?\n Chọn (y) để tiếp tục, chọn (n) để kết thúc game? ";		
    wcin >> choice;
  } while (choice == 'Y' || choice == 'y');


  system("pause");
  return 0;
}

void drawLine(int n, char symbol) {
  for(int i = 0; i < n; i++)
    wcout << symbol;
  wcout << "\n";
}

void rules() {
  wcout << L"\n\n";
  drawLine(80,'-');
  wcout << L"\t\t\t\tQuy tắc trò chơi\n";
  drawLine(80,'-');
  wcout << L"\t1. Lựa chọn 1 số bất kì từ 1 đến 5\n";
  wcout << L"\t2. Nếu bạn đoán đúng thì sẽ nhận lại được gấp 10 lần số tiền đặt cược\n";
  wcout << L"\t3. Nếu bạn đoán sai thì sẽ bị mất hết số tiền đặt cược trước đó\n\n";
  drawLine(80,'-');
}