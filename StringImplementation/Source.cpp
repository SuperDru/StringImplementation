#include "String.h"

int main() {
	String st1("1String1");
	String st2("    String2     ");

	cout << "String1 = " << st1 << endl;
	cout << "String2 = " << st2 << endl;

	cout << "FirstIndexOf 1 st1 - " << st1.firstIndexOf('1') << endl;
	cout << "LastIndexOf 1 st1 - " << st1.lastIndexOf('1') << endl;
	cout << "FirstIndexOf lo st1 - " << String("olololo").firstIndexOf("lo") << endl;
	cout << "LastIndexOf lo st1 - " << String("olololo").lastIndexOf("lo") << endl;
	cout << "TrimEnd st1 - " << st2.trimEnd() << endl;
	cout << "TrimStart st2 - " << st2.trimStart() << endl;
	cout << "Contains 'st' in st1 - " << st1.contains("st") << endl;
	cout << "Contains 'St' in st1 - " << st1.contains("St") << endl;
	cout << "Remove the second char st1 - " << st1.remove(1) << endl;
	cout << "Remove the second and the third chars st1 - " << st1.remove(1, 2) << endl;
	cout << "ToUpperCase st1 - " << st1.toUpperCase() << endl;
	cout << "ToLowerCase st1 - " << st1.toLowerCase() << endl;
	cout << "Char array + st1 - " + st1 << endl;
	cout << st1 + " st1 + Char array" + st2 << endl;
	cout << st1 + ' ' + st2 << endl;
	cout << st1 + st2;

	st1 = st2 + st1;

	cout << "st1 = st2 + st1   " << st1 << endl;

	_getch();
	return 0;
}