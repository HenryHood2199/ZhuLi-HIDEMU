#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;
int stdDelay;

void executeSpec(String inCommandArr[]) {
  char charArr[100];
  
  for (int i = 0; i < 20; i++) {
    if( inCommandArr[i] == "ENTER"){Keyboard.press(KEY_RETURN);}
    else if (inCommandArr[i] == "ESCAPE") {Keyboard.press(KEY_ESC);}
    else if (inCommandArr[i] == "PAUSE" || inCommandArr[i] == "BREAK") {/*Keyboard.press(0x48 );*/Serial.println("pause break not available");}
    else if (inCommandArr[i] == "PRINTSCREEN") {/*Keyboard.press(0x46);*/Serial.println("Printscreen not available");}
    else if (inCommandArr[i] == "MENU" || inCommandArr[i] == "APP") {/*Keyboard.press(0x65);*/Serial.println("app key not availabe");}
    else if (inCommandArr[i] == "F1") {Keyboard.press(KEY_F1);}
    else if (inCommandArr[i] == "F2") {Keyboard.press(KEY_F2);}
    else if (inCommandArr[i] == "F3") {Keyboard.press(KEY_F3);}
    else if (inCommandArr[i] == "F4") {Keyboard.press(KEY_F4);}
    else if (inCommandArr[i] == "F5") {Keyboard.press(KEY_F5);}
    else if (inCommandArr[i] == "F6") {Keyboard.press(KEY_F6);}
    else if (inCommandArr[i] == "F7") {Keyboard.press(KEY_F7);}
    else if (inCommandArr[i] == "F8") {Keyboard.press(KEY_F8);}
    else if (inCommandArr[i] == "F9") {Keyboard.press(KEY_F9);}
    else if (inCommandArr[i] == "F10") {Keyboard.press(KEY_F10);}
    else if (inCommandArr[i] == "F11") {Keyboard.press(KEY_F11);}
    else if (inCommandArr[i] == "F12") {Keyboard.press(KEY_F12);}
    else if (inCommandArr[i] == "F13") {Keyboard.press(KEY_F13);}
    else if (inCommandArr[i] == "F14") {Keyboard.press(KEY_F14);}
    else if (inCommandArr[i] == "F15") {Keyboard.press(KEY_F15);}
    else if (inCommandArr[i] == "F16") {Keyboard.press(KEY_F16);}
    else if (inCommandArr[i] == "F17") {Keyboard.press(KEY_F17);}
    else if (inCommandArr[i] == "F18") {Keyboard.press(KEY_F18);}
    else if (inCommandArr[i] == "F19") {Keyboard.press(KEY_F19);}
    else if (inCommandArr[i] == "F20") {Keyboard.press(KEY_F20);}
    else if (inCommandArr[i] == "F21") {Keyboard.press(KEY_F21);}
    else if (inCommandArr[i] == "F22") {Keyboard.press(KEY_F22);}
    else if (inCommandArr[i] == "F23") {Keyboard.press(KEY_F23);}
    else if (inCommandArr[i] == "F24") {Keyboard.press(KEY_F24);}
    else if (inCommandArr[i] == "UPARROW") {Keyboard.press(KEY_UP_ARROW);}
    else if (inCommandArr[i] == "DOWNARROW") {Keyboard.press(KEY_DOWN_ARROW);}
    else if (inCommandArr[i] == "LEFTARROW") {Keyboard.press(KEY_LEFT_ARROW);}
    else if (inCommandArr[i] == "RIGHTARROW") {Keyboard.press(KEY_RIGHT_ARROW);}
    else if (inCommandArr[i] == "PAGEUP") {Keyboard.press(KEY_PAGE_UP);}
    else if (inCommandArr[i] == "PAGEDOWN") {Keyboard.press(KEY_PAGE_DOWN);}
    else if (inCommandArr[i] == "HOME") {Keyboard.press(KEY_HOME);}
    else if (inCommandArr[i] == "END") {Keyboard.press(KEY_END);}
    else if (inCommandArr[i] == "INSERT") {Keyboard.press(KEY_INSERT);}
    else if (inCommandArr[i] == "DELETE") {Keyboard.press(KEY_DELETE);}
    else if (inCommandArr[i] == "BACKSPACE") {Keyboard.press(KEY_BACKSPACE);}
    else if (inCommandArr[i] == "TAB") {Keyboard.press(KEY_TAB);}
    else if (inCommandArr[i] == "SPACE") {Keyboard.press(' ');}
    else if (inCommandArr[i] == "SHIFT") {Keyboard.press(KEY_LEFT_SHIFT);}
    else if (inCommandArr[i] == "ALT") {Keyboard.press(KEY_LEFT_ALT);}
    else if (inCommandArr[i] == "CONTROL" || inCommandArr[i] =="CTRL") {Keyboard.press(KEY_LEFT_CTRL);}
    else if (inCommandArr[i] == "COMMAND") {Keyboard.press(KEY_LEFT_GUI);}
    else if (inCommandArr[i] == "WINDOWS"||inCommandArr[i] =="GUI") {Keyboard.press(KEY_LEFT_GUI);}
    else if (inCommandArr[i].length() == 1){inCommandArr[i].toCharArray(charArr, 100); Keyboard.press(charArr[0]);}
    else {Serial.println("notfound in elif for spec");}
    }
  delay(stdDelay);
  Keyboard.releaseAll();
  //Serial.println("exspec done");
}
void splitSpec(String inputCommand) {
  //inputCommand = "test asadasd adats";
  inputCommand += " ";
  //Serial.println("splitSpec called");
  //Serial.println("command is still: " + inputCommand);

  String commandsSpec[20];
  int num_commands = 0;
  int start_pos = 0;
  int end_pos = inputCommand.indexOf(' ');
  while (end_pos != -1) {
    commandsSpec[num_commands] = inputCommand.substring(start_pos, end_pos);
    start_pos = end_pos + 1;
    end_pos = inputCommand.indexOf(' ', start_pos);
    num_commands++;
  }
  executeSpec(commandsSpec);
}




void duckySetup(int delay) {
  // initialize the keyboard and mouse
  Keyboard.begin();
  stdDelay = delay; 
}


void parse(String input) {
  // read the input string from a text file or user input
  //String input = "STRING Hello World!\nGUI r\nDELAY 1000\nALT F4\n";
  input += "\n";
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!https://studylib.net/doc/8551536/the-usb-rubber-ducky---ducky !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // split the input string into individual commands
  String commands[100];
  int num_commands = 0;
  int start_pos = 0;
  int end_pos = input.indexOf('\n');
  while (end_pos != -1) {
    commands[num_commands] = input.substring(start_pos, end_pos);
    start_pos = end_pos + 1;
    end_pos = input.indexOf('\n', start_pos);
    num_commands++;
  }

  // loop through each command and execute the corresponding input
  for (int i = 0; i < num_commands; i++) {
    String command = commands[i];
    Serial.println("command is: " + command);
    
    if (command.startsWith("STRING ")) {  //if string
      Keyboard.print(command.substring(7));
      //Serial.println("string is: "+ command.substring(7));  //print string
      delay(10);
    } else if (command.startsWith("DELAY ")) {
      //Serial.println("delay called");                                                                                                                                                                                                                                                                                                                                                                                                                  //if delay
      delay(command.substring(6).toInt());                                                                                                                                                                                                                                                                                                                                                                                                             //delay
    } else if (command.startsWith("UPARROW") || command.startsWith("DOWNARROW") || command.startsWith("LEFTARROW") || command.startsWith("RIGHTARROW") || command.startsWith("PAGEUP") || command.startsWith("PAGEDOWN") || command.startsWith("HOME") || command.startsWith("END") || command.startsWith("INSERT") || command.startsWith("DELETE") || command.startsWith("BACKSPACE") || command.startsWith("TAB") || command.startsWith("SPACE")) {  //starts with CURSOR key or mod key perform do the special key script
      //Serial.println("cursor called");
      
      splitSpec(command);
    } else if (command.startsWith("ENTER") || command.startsWith("ESCAPE") || command.startsWith("PRINTSCREEN") || command.startsWith("MENU") || command.startsWith("APP") || command.startsWith("F1") || command.startsWith("F2") || command.startsWith("F3") || command.startsWith("F4") || command.startsWith("F5") || command.startsWith("F6") || command.startsWith("F7") || command.startsWith("F8") || command.startsWith("F9") || command.startsWith("F10") || command.startsWith("F11") || command.startsWith("F12")|| command.startsWith("F13")|| command.startsWith("F14")|| command.startsWith("F15")|| command.startsWith("F16")|| command.startsWith("F17")|| command.startsWith("F18")|| command.startsWith("F19")|| command.startsWith("F20")|| command.startsWith("F21")|| command.startsWith("F22")|| command.startsWith("F23")|| command.startsWith("F24")) {  //starts with SYSTEM key or mod key perform do the special key script
      //Serial.println("system called");

      splitSpec(command);
    } else if (command.startsWith("SHIFT") || command.startsWith("ALT") || command.startsWith("CONTROL") || command.startsWith("CTRL") || command.startsWith("COMMAND") || command.startsWith("WINDOWS") || command.startsWith("GUI")) {  //starts with MODIFIER key or mod key perform do the special key script
      //Serial.println("mod called");

      splitSpec(command);
    }
     else if (command.startsWith("REM")){
       Serial.println("comment: " + command.substring(4));
     }
  }
}
