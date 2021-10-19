#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main() {
  _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);
  wcout << L"Tiếng việt có dấu" << endl;
  system("pause");
  return 0;
}
