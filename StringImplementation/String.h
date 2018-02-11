#include <iostream>
#include <conio.h>


using namespace std;

#pragma once
class String
{
private:
	int length_;
	char* str_;
	String(int length);
	int computeLength(const char * str);
	int indexOf(int startLoop, int endLoop, const String& str);
public:
	//------------
	//Constructors
	//------------
	//Constructor copy
	String(const String &str);
	String(const char* str);
	String(int length, char ch);
	//Standart constructor, that doesn't assign value for {str_} 
	String();
	~String();
	//------
	//Methods
	//------
	//Returns first entrance of {char}, else return -1
	int firstIndexOf(char ch);
	//Returns first entrance of {str}, else return -1
	int firstIndexOf(const String& str);
	//Returns last entrance of {char}, else return -1
	int lastIndexOf(char ch); 
	//Returns last entrance of {str}, else return -1
	int lastIndexOf(const String& str);
	//Returns string length
	int getLength(); // It doesn't include zero symbol
	//Finds <str> in the string and if it exists returns true, else returns false
	bool contains(const String& str); 
	//Returns the string in upper case
	String& toUpperCase();
	//Returns the string in lower case
	String& toLowerCase();
	//Returns the string with removed {index} symbol
	String& remove(int index);
	//Returns the string with removed {length} symbols, starts with {startWith} 
	String& remove(int startWith, int length);
	//Returns the string with removed first spaces
	String& trimStart();
	//Returns the string with removed last spaces
	String& trimEnd();
	//Returns the string with {length} elements, start with {startWith} element
	String& substring(int startWith, int length);
	//---------------------
	//Oveload operators
	//---------------------
	String& operator+(const String& str);
	String& operator+(const char* str);
	String& operator+(char ch);
	String& operator=(const String& str);
	String& operator=(const char* str);
	String& operator=(char ch);
	bool operator==(const String& str);
	char operator[](int i);
	//--------------------------------
	//Overload of friend functions
	//--------------------------------
	friend ostream& operator<<(ostream& stream, const String& obj);
	friend String& operator+(const char* str, const String& obj);
	friend String& operator+(char ch, const String& obj);
	friend void* operator new[](size_t size);

};

