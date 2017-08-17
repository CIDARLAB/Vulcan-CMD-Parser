#ifndef ParsingLibrary_h
#define ParsingLibrary_h

#include "Arduino.h"


class ParsingLibrary
{
  public:
	typedef unsigned char BYTE;
    ParsingLibrary();
	void ParseCode();
	void clearBuffer();
	int showCommand();
	void getdat(BYTE *pdata);
	void getParameters(int *output);
  private:
	int parameters[];
	BYTE newByteList[];
	BYTE byteList[200];
	String inputString;
	char inChar;
	char term;
	int bufPos;

};

#endif