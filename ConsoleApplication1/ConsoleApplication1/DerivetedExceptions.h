#pragma once
#include "ExceptionScheme.h"
#include <iostream>


//FUNC EXCEPTION----------------------------------------------------
class funcException : mainException{
private:
	char fname[15];
public:
	funcException(char a[15], int b, char t[15]) :
		mainException(a, b){
		strcpy(fname,t);
	};
	void showError(){
		mainException::showError();
		std::cout << "Function with error: " << fname << std::endl;
	}
};
//-------------------------------------------------------------------

//INT EXCEPTION------------------------------------------------------
class intException : mainException{
private: 
	int errorVariable;
public:
	intException( int b, int k) : mainException(b){
		strcpy(name, "int");
		errorVariable = k;}

	void showError(){
		mainException::showError();
		std::cout << "Int with error: " << &errorVariable << std::endl;
	}
};
//-------------------------------------------------------------------

//CHAR EXCEPTION------------------------------------------------------
class charException : mainException{
private:
	char errorVariable[15];
public:
	charException(int b, char k[15]) : mainException(b){
		strcpy(name, "char");
		strcpy(errorVariable,k);
	}

	void showError(){
		mainException::showError();
		std::cout << "Char with error: " << &errorVariable << std::endl;
	}
};
//-------------------------------------------------------------------

//PTR EXCEPTION------------------------------------------------------
class NullptrException : mainException{
private:
	int errorVariable;
public:
	NullptrException( int b, int &k) : mainException(b){
		strcpy(name, "Null ptr");
		errorVariable = k;
	}

	void showError(){
		mainException::showError();
		std::cout << "Ptr with error: " << &errorVariable << std::endl;
	}
};
//-------------------------------------------------------------------
