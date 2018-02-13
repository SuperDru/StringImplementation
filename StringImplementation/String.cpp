#include "String.h"


//Private methods
int String::computeLength(const char * str)
{
	int i = -1;
	while (str[++i] != 0); 
	return i;
}
int String::indexOf(bool leftToRight, const String& str)
{
	if (length_ < str.length_)
		return -1;

	int startLoop = !leftToRight ? length_ - str.length_ : 0,
		endLoop = leftToRight ? length_ - str.length_ : -1,
		shift = leftToRight ? 1 : -1;

	bool flag;
	for (int i = startLoop; i != endLoop; i += shift) {
		flag = true;
		for (int j = 0; j < str.length_ && flag; j++) {
			if (str_[i + j] != str.str_[j])
				flag = false;
		}
		if (flag) return i;
	}
	return -1;
}

//-----------------------------------------------------------------

//Constructors
String::String(const String & obj): length_(obj.length_)
{
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_+1; i++) {
		str_[i] = obj.str_[i];
	}
}
String::String(const char * str)
{
	length_ = computeLength(str);
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_+1; i++) {
		str_[i] = str[i];
	}
}
String::String(int length, char ch) : length_(length)
{
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_; i++) {
		str_[i] = ch;
	}
	str_[length_] = 0;
}
String::String(int length): length_(length)
{
	if (length < 0)
		throw "IndexOutOfBoundsException";
	str_ = new char[length + 1];
	str_[length] = 0;
}
String::String(): length_(0){
	str_ = new char[1];
	str_[0] = 0;
}

//Desctructor
String::~String()
{
	if (str_ != NULL)
		delete[]str_;
}

//-------------------------------------------------------------------

//Getters
int String::getLength()
{
	return length_;
}

//IndexOf methods
int String::firstIndexOf(char ch)
{
	for (int i = 0; i < length_; i++) {
		if (str_[i] == ch)
			return i;
	}
	return -1;
}
int String::firstIndexOf(const String& str)
{
	return indexOf(true, str);
}
int String::lastIndexOf(char ch)
{
	for (int i = length_-1; i >= 0; i--) {
		if (str_[i] == ch)
			return i;
	}
	return -1;
}
int String::lastIndexOf(const String& str)
{
	return indexOf(false, str);
}

bool String::contains(const String & str)
{
	return firstIndexOf(str) == -1 ? false : true;
}

//Changing case methods
String& String::toUpperCase()
{
	String* result = new String(length_);
	for (int i = 0; i < length_; i++) {
		(*result).str_[i] = toupper(str_[i]);
	}
	return *result;
}
String& String::toLowerCase()
{
	String* result = new String(length_);
	for (int i = 0; i < length_; i++) {
		(*result).str_[i] = tolower(str_[i]);
	}
	return *result;

}

//Removing methods
String& String::remove(int index)
{
	return remove(index, 1);
}
String& String::remove(int startWith, int removingLength)
{
	if (startWith + removingLength > length_ || startWith < 0 || removingLength < 1)
		throw "LogicException";

	String* result = new String(length_ - removingLength);

	int i = 0;
	for (i; i < startWith; i++) {
		(*result).str_[i] = str_[i];
	}

	for (i += removingLength; i < length_; i++) {
		(*result).str_[i - removingLength] = str_[i];
	}

	return *result;
}

//Methods, removed excessive spaces
String& String::trimStart()
{
	int i = 0;
	while (str_[i++] == ' ');
	return substring(--i, length_ - i);
}
String& String::trimEnd()
{
	int i = length_;
	while (str_[--i] == ' ');
	return substring(0, i + 1);
}

//Method returns substring from the string
String & String::substring(int startWith, int length)
{
	if (startWith + length > length_ || startWith < 0 || length < 1)
		throw "LogicException";

	String* result = new String(length);

	for (int i = 0; i < length; i++) {
		(*result).str_[i] = str_[i + startWith];
	}
	return *result;
}

//-----------------------------------------------------------------------

//Overloading operators
String& String::operator+(const String & str)
{
	int endLength = str.length_ + length_;
	String* result = new String(endLength);

	int i = 0;
	for (i; i < length_; i++) {
		(*result).str_[i] = str_[i];
	}

	for (i; i < endLength; i++) {
		(*result).str_[i] = str.str_[i - length_];
	}
	return *result;
}
String& String::operator+(const char * str)
{
	String* result = new String(*this + String(str)); 
	return *result;
}
String & String::operator+(char ch)
{
	String* result = new String(*this + String(1, ch));
	return *result;
}
String & operator+(const char * str, const String & obj)
{
	String* result = new String(String(str) + obj);
	return *result;
}
String & operator+(char ch, const String & obj)
{
	String* result = new String(String(1, ch) + obj);
	return *result;
}

bool String::operator==(const String & str)
{
	if (length_ != str.length_)
		return false;
	for (int i = 0; i < length_; i++) {
		if (str_[i] != str.str_[i])
			return false;
	}
	return true;
}

String& String::operator=(const String & obj)
{
	if (this != &obj) {
		delete[]str_;
		str_ = new char[obj.length_ + 1];
		for (int i = 0; i < obj.length_ + 1; i++) {
			str_[i] = obj.str_[i];
		}
		length_ = obj.length_;
	}
	return *this;
}
String& String::operator=(const char* str)
{
	*this = String(str);	
	return *this;
}
String & String::operator=(char ch)
{
	*this = String(1, ch);
	return *this;
}

void* operator new[](size_t const size)
{
	void* result = malloc( size);
	if (result == NULL) {
		throw "MemoryException";
	}
	return result;
}

char String::operator[](int i)
{
	if (i < 0 || i > length_)
		throw "IndexOutOfArrayException";
	return str_[i];
}

ostream & operator<<(ostream& stream, const String & obj)
{
	stream << obj.str_;
	return stream;
}
