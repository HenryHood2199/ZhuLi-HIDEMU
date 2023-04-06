#include "WString.h"

String Dlog[100];

void startLog(){
    for(int j =0; j < 100; j++){
      Dlog[j]= "";
  }
}

String loadLog(){
  String rLog ="";
  for(int j =0; j < 100; j++){
      Dlog[j]= "";


  }
  for(int i = 0; i < 100; i++){
    rLog += "<div class=\"logItem\">";
    rLog += Dlog[i];
    rLog += "</div>"; 
  }

  
  return rLog;
}

void addLog(String inLog){
  for(int j =99; j > 0; j--){
    Dlog[j+1]= Dlog[j];
  }
  Dlog[0] = inLog;
}