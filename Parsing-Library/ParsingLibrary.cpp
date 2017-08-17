#include "Arduino.h"
#include "ParsingLibrary.h"
#include "HardwareSerial.h"


typedef unsigned char BYTE;
BYTE byteList[200];



ParsingLibrary::ParsingLibrary()
{
	

}

void ParsingLibrary::ParseCode() {

	int i;
	//clear the buffer
	for (int i=0; i< sizeof(byteList); i++) 
	{
		byteList[i]='\0';
	}
	

	
	//BYTE b;

 inputString = "";
	while (!Serial.available()) {} // wait for data to arrive
  //serial read section
	while (Serial.available())
	{
   // continue as before
    delay(30);  //delay to allow buffer to fill 
   if (Serial.available() >0)
   {
     
     //char c = Serial.read();  //gets one byte from serial buffer
     //inputString += c; //makes the string readString
     Serial.readBytes(byteList, 200);
   } 
	}

 } 
 

 
int ParsingLibrary::showCommand() {

	int j = 0;
  
  while(j < sizeof(byteList)-4) {
	if(memcmp(byteList[j],0,sizeof(byteList[j])) == 0){
		Serial.print(byteList[j]);
		Serial.print(" ");
		if(memcmp(byteList[j+1],0,sizeof(byteList[j+1])) == 0){
			Serial.print(byteList[j+1]);
			Serial.print(" ");
			if(memcmp(byteList[j+2],0,sizeof(byteList[j+2])) == 0){
				Serial.print(byteList[j+2]);
				Serial.print(" ");
				if(memcmp(byteList[j+3],0,sizeof(byteList[j+3])) == 0){
					Serial.print(byteList[j+3]);
					Serial.print(" ");
					Serial.println("four zeros!");
					Serial.println(j);
					break;
				}
			}
		}
	}
	j++;
  }
  
  BYTE newByteList[j];
  for(int a = 0; a < sizeof(newByteList); a++){
	  newByteList[a] = byteList[a];
  }
  
  
	int i = 0;
   while(i < sizeof(newByteList)) {
	Serial.print(newByteList[i]);
	Serial.print(" ");
	i++;
  }
	return newByteList[1];
	
 }
 
 int ParsingLibrary::showVersion() {

	int j = 0;
  
  while(j < sizeof(byteList)-4) {
	if(memcmp(byteList[j],0,sizeof(byteList[j])) == 0){
		Serial.print(byteList[j]);
		Serial.print(" ");
		if(memcmp(byteList[j+1],0,sizeof(byteList[j+1])) == 0){
			Serial.print(byteList[j+1]);
			Serial.print(" ");
			if(memcmp(byteList[j+2],0,sizeof(byteList[j+2])) == 0){
				Serial.print(byteList[j+2]);
				Serial.print(" ");
				if(memcmp(byteList[j+3],0,sizeof(byteList[j+3])) == 0){
					Serial.print(byteList[j+3]);
					Serial.print(" ");
					Serial.println("four zeros!");
					Serial.println(j);
					break;
				}
			}
		}
	}
	j++;
  }
  
  BYTE newByteList[j];
  for(int a = 0; a < sizeof(newByteList); a++){
	  newByteList[a] = byteList[a];
  }
  
  
	int i = 0;
   while(i < sizeof(newByteList)) {
	Serial.print(newByteList[i]);
	Serial.print(" ");
	i++;
  }
	return newByteList[0];
	
 }
 
 void ParsingLibrary::getParameters(int *output){
		int j = 0;
  
  while(j < sizeof(byteList)-4) {
	if(memcmp(byteList[j],0,sizeof(byteList[j])) == 0){
		Serial.print(byteList[j]);
		Serial.print(" ");
		if(memcmp(byteList[j+1],0,sizeof(byteList[j+1])) == 0){
			Serial.print(byteList[j+1]);
			Serial.print(" ");
			if(memcmp(byteList[j+2],0,sizeof(byteList[j+2])) == 0){
				Serial.print(byteList[j+2]);
				Serial.print(" ");
				if(memcmp(byteList[j+3],0,sizeof(byteList[j+3])) == 0){
					Serial.print(byteList[j+3]);
					Serial.print(" ");
					Serial.println("four zeros!");
					Serial.println(j);
					break;
				}
			}
		}
	}
	j++;
  }
  
  BYTE newByteList[j];
  for(int a = 0; a < sizeof(newByteList); a++){
	  newByteList[a] = byteList[a];
  }
  
  
	int i = 0;
   while(i < sizeof(newByteList)) {
	Serial.print(newByteList[i]);
	Serial.print(" ");
	i++;
  }
  
  
   Serial.println("");

 
	bool iterating = true;
	int commandIndex = 2;
	int outputIndex = 0;
	while(iterating) {
		int k = commandIndex;
		if(newByteList[k] == 1) {
			output[outputIndex] = newByteList[k + 1];
			commandIndex += 2;
			outputIndex++;
		}
		else if(newByteList[k] == 2) {
			output[outputIndex] = newByteList[k+1] << 8 | newByteList[k+2];
			commandIndex += 3;
			outputIndex++;
		}
		else if(newByteList[k] == 3) {
			output[outputIndex] = newByteList[k+1] << 16 | newByteList[k+2] << 8 | newByteList[k+3];
			commandIndex += 4;
			outputIndex++;
		}
		else {
			Serial.println("We can only concatenate 3 bytes right now.");
		}
		if(commandIndex >= sizeof(newByteList)) {
			iterating = false;
		}
	}

  
 }
 
 
