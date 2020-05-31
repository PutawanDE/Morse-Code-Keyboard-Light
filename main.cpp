#define WINVER 0x0500
#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

INPUT ip;

void light(const int time)
{
  ip.ki.dwFlags = 0; // 0 for key press
  SendInput(1, &ip, sizeof(INPUT));
  ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
  SendInput(1, &ip, sizeof(INPUT));
  Sleep(time); // Wait time to press again
  ip.ki.dwFlags = 0; // 0 for key press
  SendInput(1, &ip, sizeof(INPUT));
  ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
  SendInput(1, &ip, sizeof(INPUT));
}

int main(int argc, char *argv[])
{   
	const int unit = 750; 
    const int dit = unit;
    const int dah = unit * 3;
    
    string message;
    getline(cin, message);
    
    
    // Setting up input
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VK_SCROLL; // Scroll Lock

	Sleep(unit * 2);
    for(int i = 0; i < message.length(); i++) 
    {
	    if(message[i] == ' ')
	    {
          Sleep(4 * unit);
          continue;              
	    }
	    message[i] = toupper(message[i]);
	    string morse;
		switch(message[i]) 
		{
		 case 'A':
		        morse = ".-";
		        break;
		 case 'B':
		        morse = "-...";
		        break;
		 case 'C':
		        morse = "-.-.";
		        break;
		 case 'D':
		        morse = "-..";
		        break;
		 case 'E':
		        morse = ".";
		        break;
		 case 'F':
		        morse = "..-.";
		        break;
		 case 'G':
		        morse = "--.";
		        break;
		 case 'H':
		        morse = "....";
		        break;
		 case 'I':
		        morse = "..";
		        break;
		 case 'J':
		        morse = ".---";
		        break;
		 case 'K':
		        morse = "-.-";
		        break;
		 case 'L':
		        morse = ".-..";
		        break;
		 case 'M':
		        morse = "--";
		        break;
		 case 'N':
		        morse = "-.";
		        break;
		 case 'O':
		        morse = "---";
		        break;
		 case 'P':
		        morse = ".--.";
		        break;
		 case 'Q':
		        morse = "--.-";
		        break;
		 case 'R':
		        morse = ".-.";
		        break;
		 case 'S':
		        morse = "...";
		        break;
		 case 'T':
		        morse = "-";
		        break;	
		 case 'U':
		        morse = "..-";
		        break;	
		 case 'V':
		        morse = "...-";
		        break;	
		 case 'W':
		        morse = ".--";
		        break;	
		 case 'X':
		        morse = "-..-";
		        break;	
		 case 'Y':
		        morse = "-.--";
		        break;	
		 case 'Z':
		        morse = "--..";
		        break;
		 default :
		 		continue;					        
		}
		
		for(int j = 0; j < morse.length(); j++)
		{
	      if(morse[j] == '.')
	      {
	       light(dit);
	      }
	      if(morse[j] == '-')
	      {
	       light(dah);
	      }
	      Sleep(dit);
		}
		Sleep(dah);
    }
    
	//End of transmition, Caplock light up
    ip.ki.wVk = VK_CAPITAL;
    ip.ki.dwFlags = 0; // 0 for key press
  	SendInput(1, &ip, sizeof(INPUT));
  	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
  	SendInput(1, &ip, sizeof(INPUT));
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
