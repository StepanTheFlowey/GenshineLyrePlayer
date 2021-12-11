#include <Windows.h>
#include <iostream>

void pressButton(char button) {
  INPUT ip;
  
  ip.type = INPUT_KEYBOARD;
  ip.ki.wScan = button; // hardware scan code for key
  ip.ki.time = 0;
  ip.ki.dwExtraInfo = 0;

  // Press the "A" key
  ip.ki.wVk = button; // virtual-key code for the "a" key
  ip.ki.dwFlags = 0; // 0 for key press

  UINT i = 0;
  do {
    i = SendInput(1, &ip, sizeof(INPUT));
  } while(i == 0);
  ip.ki.dwFlags=KEYEVENTF_KEYUP;
  do {
    i = SendInput(1, &ip, sizeof(INPUT));
  } while(i == 0);
}

const char arr[] = "GQ GHJ DDH GFG AAS SDF FGH JQW G E WQW JGQ JHJ DDH GFG AAQ JHG E WQJQW GG Q JHGHJ DD Q HJQ HJQ HQR R EWQWE QQ W QJHJQ HH Q JHG AAQ JHG";
//const char arr[] = "GW JJHG GQ JJHHG GW JHG GDS GHGW GHG GQ JJHHG GW JHG GDS";
//const char arr[] = "HJQWQJWQJWQJH HJQQJHFGJGH HJQWQJWQJJQWW QQJQJHFFJGH";

int main() {
	FreeConsole();
  for(int i = 0; i < sizeof(arr); i++) {
    pressButton(arr[i]);
    Sleep(250);
  }
}
