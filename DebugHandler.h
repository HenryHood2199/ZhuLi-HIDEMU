#include "WString.h"

String Dlog[100];

void startLog(){
    for(int j =0; j < 100; j++){
      Dlog[j]= "";
  }
}

String loadLog(){
  String rLog ="";

  for(int i = 0; i < 99; i++){
    rLog += "<div class=\"logItem\">";
    rLog += Dlog[i];
    rLog += "</div>\n"; 
  }

  
  return rLog;
}

void addLog(String inLog){
  for(int j =99; j > -1; j--){
    Dlog[j+1]= Dlog[j];
  }
  Dlog[0] = inLog;
}