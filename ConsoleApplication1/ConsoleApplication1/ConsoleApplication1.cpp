// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include "ExceptionScheme.h"
#include "DerivetedExceptions.h"

#define NDEBUG
#include <assert.h>
using namespace std;

class myException : public exception{
public:
	myException(const char * const & buf) : exception(buf){}
};


void ptrCheck(int *a){
	assert(*a == NULL);
	cout << "All good\n";
}


int _tmain(int argc, _TCHAR* argv[])
{
	try{
		//zero divided------------------------------------
		try{
			int b = 0;
			cout << "Vvedite zna4enie: ";
			cin >> b;
			if (b == 0) throw mainException("Divided zero", 5);
		}
		catch (mainException &p) {
			p.showError();
		}
		cout << "\n\n";
		//ptr-------------------------------------------
		try{
			int *a = new int(NULL);
			if (*a == NULL) throw NullptrException(1, *a);
		}
		catch (NullptrException &b){
			b.showError();
		}
		cout << "\n\n";
		//char------------------------------------------
		try{
			char qwe[15] = "asdfghjk";
			if (qwe[0] == 'a') throw charException(5, qwe);
		}
		catch (charException &n){
			n.showError();
		}
		cout << "\n\n";
		//int--------------------------------------------
		try{
			int buf = -5;
			if (buf < 0) throw intException(9, buf);
		}
		catch (intException &g){
			g.showError();
		}
		cout << "\n\n";
		/*function exception-----------------------------*/

		try{
			cout << "\n\nThis function try to log(x)\n";
			int a;
			cout << "Enter positive int: ";
			cin >> a;
			if (a < 0) throw funcException("Negative parametr", 23, "log");	
			
		}
		catch (funcException &f){
			f.showError();
		}

		throw 7;                                                                 //unknow exception 
	}
	catch (...){
		cout << "Unknow error!!! Check all your variables!!!\n";
	}

	//accert
	int *a = new int(7);
	int *b = new int(NULL);
	ptrCheck(a);
	ptrCheck(b);
	return 0;
}



