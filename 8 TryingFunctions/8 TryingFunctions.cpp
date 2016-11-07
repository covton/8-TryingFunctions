// 8 TryingFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

int max(signed long slNum1, signed long slNum2);
signed long fnRetNum(std::string strPrompt);

int max(signed long slNum1, signed long slNum2) {

	signed long result;

	if (slNum1 > slNum2) {
		result = slNum1;
	}
	else {
		result = slNum2;
	}
	return result;
}

signed long fnRetNum(std::string strPrompt) {
	 
	signed long result = 0;

	while (true) {
		
		std::string strinput = "";
		//use getline to avoid errors with inputs
		std::cout << strPrompt;
		std::getline(std::cin, strinput);

		// this line defines a stringstream called 'mystream' and gives it the value of strinput
		std::stringstream myStream(strinput);
		//this line looks for result (i.e. a signed long) and stores it. If it can't, it returns false
		if (myStream >> result) {
			break;
		}
		std::cout << "That's not a number. Please enter a number.\n";
	}
	return result;
}

int main()
{
	//set up integers, we need a string to accept inputs from cin
	//find this is better because we can then test that we do actually get an int
	signed long slFN;
	signed long slSN;
	signed long ret;

	slFN = fnRetNum("Please enter your first number.\n");
	slSN = fnRetNum("Please enter your second number.\n");

	ret = max(slFN, slSN);
	std::cout << "The max number is " << ret << ".\n";

	system("PAUSE");
    return 0;
}

