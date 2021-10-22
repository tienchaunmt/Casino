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

  drawLine(80,'%');
  wcout << "\n\n\n\t\t\t\tCASINO GAME\n\n\n\n";
  drawLine(80,'%');

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
    wcout << L"Số tiền (VND) hiện tại có trong tài khoản của bạn là: " << amount << endl;

    int bettingAmount;
    do {
      wcout << playerName << L", đặt cược số tiền (VND) khi bắt đầu ván game: ";
      wcin >> bettingAmount;
      if (bettingAmount > amount)
        wcout << L"Số tiền đặt cược của bạn lớn hơn số dư tài khoản mà bạn đang sở hữu\n"
              << L"Bạn vui lòng đặt lại số tiền đặt cược\n";
    } while (bettingAmount > amount);

    int guess;
    do {
      wcout << L"Số bạn dự đoán từ 1 đến 5 : ";
      wcin >> guess;
      if (guess <= 0 || guess > 5)
        wcout << L"Số của bạn nằm ngoài số cho phép của trò chơi! Số của bạn nên nằm trong khoảng từ 1 đến 5\n"
              << L"Bạn vui lòng chọn lại số dự đoán của bạn\n";
    } while (guess <= 0 || guess > 5);

    int dice = rand()%5 + 1;
    if(dice == guess) {
      wcout << L"\nQuá tuyệt!! Bạn đã đoán chính xác con số may mắn.\n Bạn được nhận " << bettingAmount * 10 << L" VND.";
      amount += bettingAmount * 10;
    } else {
      wcout << L"Chúc bạn may mắn lần sau!! Bạn đã cược thua với số tiền "<< bettingAmount << L" VND.";
      amount -= bettingAmount;
    }

    wcout << L"\nCon số chiến thắng của lượt chơi này là : " << dice << L"\n";
    wcout << L"\n" << playerName << L", Số tiền hiện tại của bạn là : " << amount << L"\n";

    if (amount == 0) {
      wcout << L"Số tiền trong tài khoản của bạn đã hết!\nXin người chơi nạp tiền để tiếp tục đặt cược." << endl;
      break;
    }
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
  drawLine(80,'&');
  wcout << L"\n\t\t\t\tQuy tắc trò chơi\n\n";
  drawLine(80,'&');
  wcout << L"\n\t1. Lựa chọn 1 số bất kì từ 1 đến 5\n";
  wcout << L"\t2. Nếu bạn đoán đúng thì sẽ nhận lại được gấp 10 lần số tiền đặt cược\n";
  wcout << L"\t3. Nếu bạn đoán sai thì sẽ bị mất hết số tiền đặt cược trước đó\n\n";
  drawLine(80,'&');
}