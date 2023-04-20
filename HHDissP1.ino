
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
  preferences.begin("my-app", false);//opens my-app preferences
  apMode = preferences.getBool("apmode", true);//loads apmode bool
  FTS = preferences.getBool("FirstSetup", true);//loads first time setup bool
  preferences.end();//closes preferences
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
  duckySetup(50);//performs startup activities within the duckyscript module
  //Serial.println("end of startup");
}

void wifiJoin(){
  preferences.begin("my-app", false);//opens my-app 
  String ssidString = preferences.getString("SSID", "AP");//loads ssid from preferences
  String pwdString = preferences.getString("PWD", "TestTest");//loads password from preferences
  char ssid[ssidString.length()+1];//creates correct length char array
  char pwd[pwdString.length()+1];//creates correct length char array
  ssidString.toCharArray(ssid, ssidString.length()+1);//loads string to char array
  pwdString.toCharArray(pwd, pwdString.length()+1);//loads string to char array
  //Serial.println("password is: " + String(pwd));


  WiFi.begin(ssid, pwd);//joins wifi
  addLog("Wifi connecting");
  delay(10000);//waits 10 seconds
  if (WiFi.status() != WL_CONNECTED){
    addLog("Wifi Couldnt connect, starting in AP mode");//adds to log
    WiFi.disconnect();//stops attempting to join
    backupapStart();//starts the backup ap
  }
  //Serial.println("end of wifijoin");
}

void apStart(){
  addLog("AP started");
  preferences.begin("my-app", false);//opens myapp namespace
  String ssidString = preferences.getString("SSID", "AP");//loads ssid from preferences
  String pwdString = preferences.getString("PWD", "TestTest");//loads password from preferences
  preferences.end();//closes the namespace
  char ssid[ssidString.length()+1];//creates correct length char array
  char pwd[pwdString.length()+1];//creates correct length char array
  ssidString.toCharArray(ssid, ssidString.length()+1);//loads string to char array
  pwdString.toCharArray(pwd, pwdString.length()+1);//loads string to char array
  //Serial.println("password is: " + String(pwd)); //test
  WiFi.softAP(ssid, pwd);//creates access point from the stored ssid and password
  Serial.println("end of apstart");//test code
}
backupapStart(){
  char* bakSSID = "AP";
  //char* bakpwd = "TestTest";
  WiFi.softAP(ssid);//creates access point with no password
  //Serial.println("end of backup apstart");//debug code
}
void handleStartup(){
  server.send(200, "text/html", startupSite);//pushes startup to client
}
void handleIndex(){
  server.send(200, "text/html", indexSite);//pushes index to client
}

void handleSave(){
  preferences.begin("my-app", false);
  preferences.putString("Script1", server.arg("text1"));//saves arg text 1 to script for in myapp
  preferences.putString("Script2", server.arg("text2"));//saves arg text 2 to script for in myapp
  preferences.putString("Script3", server.arg("text3"));//saves arg text 3 to script for in myapp
  preferences.putString("Script4", server.arg("text4"));//saves arg text 4 to script for in myapp
  server.send(200, "text/html", editSite + preferences.getString("Script1") + editMid1 + preferences.getString("Script2") + editMid2 + preferences.getString("Script3") + editMid3 + preferences.getString("Script4")  + editEnd);//loads scripts from mem, and pushes 
  preferences.end();
}
void handleEdit(){
  preferences.begin("my-app", false);
  server.send(200, "text/html", editSite + preferences.getString("Script1")  + editMid1 + preferences.getString("Script2")  + editMid2 + preferences.getString("Script3") + editMid3 + preferences.getString("Script4")  + editEnd);//loads scripts from mem, and pushes 
  preferences.end();
}
void handleLog(){
  //Serial.println(loadLog());//test code
  server.send(200, "text/html", logSiteBegin + loadLog() + logSiteEnd);//pushes logsite to client, with the logs loaded from debughandler

}
void handleAbout(){
  server.send(200, "text/html", aboutSite);//pushes aboutsite to client
}
void run1(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script1", "STRING script is empty"));//parses script 1 from memory
  preferences.end();
  server.send(200, "text/html", indexSite);//pushes index to client
}
void run2(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script2", "STRING script is empty"));//parses script 2 from memory
  preferences.end();
  server.send(200, "text/html", indexSite);//pushes index to client
}
void run3(){
  preferences.begin("my-app", false);
  parse(preferences.getString("Script3", "STRING script is empty"));//parses script 3 from memory
  preferences.end();
  server.send(200, "text/html", indexSite);//pushes index to client
}
void run4(){
  preferences.begin("my-app", false);//opens my-app namespace
  parse(preferences.getString("Script4", "STRING script is empty"));//loads script 4 from my-app namespace and parses it to duckyscipt executor
  preferences.end();//closes preferences
  server.send(200, "text/html", indexSite);//pushes index to client
}

void saveStart(){
  preferences.begin("my-app", false);//opens up namespace my-app
  preferences.putString("SSID", server.arg("SSID"));//saves arg ssid to ssid in namespace
  preferences.putString("PWD",server.arg("Password"));//saves arg pwd to pwd in namespace
  Serial.println("APMode: " + server.arg("APMode"));//saves arg apmode to apmode in namespace
  //writeSingle(firstStartAddr, 0xff);
  if(server.arg("APMode")=! ""){
    //writeSingle(apTestAddr, 0xff);
  }
  else{
    //writeSingle(apTestAddr, 0x21);
  }
  preferences.end();//closes preferences namespace
  server.send(200, "text/html", indexSite);//pushes index site
}

void setup() {
  // put your setup code here, to run once:
  startUp();// runs the startup code
  if(FTS){ //checks flash mem to see if this is first time startup
    server.on("/", handleStartup);//if its the first time setup root pushes startup
  }
  else{
    server.on("/", handleIndex);//if its not it pushes index
  }
  //vvvvv--sets what function should be performed when the client accesses the page--vvvvv
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

  server.begin();//begins server
  
}

void loop() {
  //put your main code here, to run repeatedly:
  server.handleClient();//handles client
  delay(50);//allows for cpu to perform other tasks
}

