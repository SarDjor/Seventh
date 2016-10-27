#pragma once
#include <iostream>
class mainException {
protected:
	char name[15];
	int errorCode;
public:
	mainException(char [15]);
	mainException(int);
	mainException(char [15], int);

	void showError();
};
////////////CONSTRUCTORS-----------------------------------------------------------------------------------
mainException::mainException(char buf[15]){
	strcpy(name, buf);
}
mainException::mainException(int buf) : errorCode(buf){};
mainException::mainException(char buf[15], int k) : errorCode(k){
	strcpy(name, buf);
}
//////////////----------------------------------------------------------------------------------------------

void mainException::showError(){
	std::cout << "Error name: " << name <<std::endl
		<< "Error type: " << errorCode << std::endl;
}