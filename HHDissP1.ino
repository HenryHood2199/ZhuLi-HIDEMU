
#include "SiteFiles.h"
#include "Ducky.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>  
#include "DebugHandler.h"
#include <Preferences.h>



WebServer server(80);
Preferences preferences;
String ssidString = "";
String pwdString = "";
bool apMode = true;
bool FTS = true;


void loadPrefs(){
  preferences.begin("my-app", false);
  apMode = preferences.getBool("apmode", true);
  FTS = preferences.getBool("FirstSetup", true);
  preferences.end();
}

void startUp(){
  startLog();//starts logging
  Serial.begin(115200);//starts serial
  addLog("starting serial");//adds string to log
  delay(5000);//5 second delay to let the pc catch up for debug
  //setupFlash();//sets up flash mem
  //addLog("INIT FlashMem module");//adds to log

  duckySetup(50);
  addLog("INIT Ducky module");
  if(apMode){//0xff means access point mode is off(checks to see if running in AP mode)
    apStart();//starts local access point
  }
  else{
    wifiJoin();//joins wifi if not in ap mode
  }
  duckySetup(50);
  Serial.println("end of startup");
}

void wifiJoin(){
  
  
  preferences.begin("my-app", false);
  String ssidString = preferences.getString("SSID", "AP");
  String pwdString = preferences.getString("PWD", "TestTest");
  char ssid[ssidString.length()+1];
  char pwd[pwdString.length()+1];
  ssidString.toCharArray(ssid, ssidString.length()+1);
  pwdString.toCharArray(pwd, pwdString.length()+1);
  Serial.println("password is: " + String(pwd));


  WiFi.begin(ssid, pwd);
  addLog("Wifi connecting");
  delay(10000);
  if (WiFi.status() != WL_CONNECTED){
    addLog("Wifi Couldnt connect, starting in AP mode");
    WiFi.disconnect();
    backupapStart();
  }
  Serial.println("end of wifijoin");
}

void apStart(){
  addLog("AP started");
  preferences.begin("my-app", false);
  String ssidString = preferences.getString("SSID", "AP");
  String pwdString = preferences.getString("PWD", "TestTest");
  char ssid[ssidString.length()+1];
  char pwd[pwdString.length()+1];
  ssidString.toCharArray(ssid, ssidString.length()+1);
  pwdString.toCharArray(pwd, pwdString.length()+1);
  Serial.println("password is: " + String(pwd));
  WiFi.softAP(ssid, pwd);
  Serial.println("end of apstart");
}
backupapStart(){
  char* bakSSID = "AP";
  char* bakpwd = "TestTest";
  WiFi.softAP(ssid, pwd);
  Serial.println("end of backup apstart");
}
void handleStartup(){
  server.send(200, "text/html", startupSite);
}
void handleIndex(){
  server.send(200, "text/html", indexSite);
}

void handleSave(){
  preferences.begin("my-app", false);
  preferences.putString("Script1", server.arg("text1"));
  preferences.putString("Script2", server.arg("text2"));
  preferences.putString("Script3", server.arg("text3"));
  preferences.putString("Script4", server.arg("text4"));
  server.send(200, "text/html", editSite + preferences.getString("Script1") + editMid1 + preferences.getString("Script2") + editMid2 + preferences.getString("Script3") + editMid3 + preferences.getString("Script4")  + editEnd);
  preferences.end();
}
void handleEdit(){
  preferences.begin("my-app", false);
  server.send(200, "text/html", editSite + preferences.getString("Script1")  + editMid1 + preferences.getString("Script2")  + editMid2 + preferences.getString("Script3") + editMid3 + preferences.getString("Script4")  + editEnd);
  preferences.end();
}
void handleLog(){
  Serial.println(loadLog());
  server.send(200, "text/html", logSiteBegin + loadLog() + logSiteEnd);

}
void handleAbout(){
  server.send(200, "text/html", aboutSite);
}
void run1(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script1", "STRING script is empty"));
  preferences.end();
  server.send(200, "text/html", indexSite);
}
void run2(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script2", "STRING script is empty"));
  preferences.end();
  server.send(200, "text/html", indexSite);
}
void run3(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script3", "STRING script is empty"));
  preferences.end();
  server.send(200, "text/html", indexSite);
}
void run4(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script4", "STRING script is empty"));
  preferences.end();
  server.send(200, "text/html", indexSite);
}
void saveStart(){
  preferences.begin("my-app", false);
  preferences.putString("SSID", server.arg("SSID"));
  preferences.putString("PWD",server.arg("Password"));
  Serial.println("APMode: " + server.arg("APMode"));
  //writeSingle(firstStartAddr, 0xff);
  if(server.arg("APMode")=! ""){
    //writeSingle(apTestAddr, 0xff);
  }
  else{
    //writeSingle(apTestAddr, 0x21);
  }
  preferences.end();
  server.send(200, "text/html", indexSite);
}

void setup() {
  // put your setup code here, to run once:
  startUp();// runs the startup code
  if(FTS){ //checks flash mem to see if this is first time startup(0xff means it isnt)
    server.on("/", handleStartup);
  }
  else{
    server.on("/", handleIndex);
  }
  
  server.on("/About", handleAbout);
  server.on("/Logs", handleLog);
  server.on("/index", handleIndex);
  server.on("/Edit", handleEdit);
  server.on("/Save", handleSave);
  server.on("/Run1", run1);
  server.on("/Run2", run2);
  server.on("/Run3", run3);
  server.on("/Run4", run4);
  server.on("/SaveStart", saveStart);
  server.begin();
  
}

void loop() {
  //put your main code here, to run repeatedly:
  server.handleClient();
}

