// lab_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#define _USE_MATH_DEFINES

#include "pch.h"
#include <cmath>
#include <iostream>


using namespace std;

void loopTask(void(*task)(void)) {
	char userInput;

	do {
		task();
		cout << "Enter 'y' to continue any other kay to exit.\n";
		cin >> userInput;
	} while (userInput == 'y' || userInput == 'Y');
}

void lab() {
	//(2n+1/n!)*x^2n = 1 + (3x^2)/1! + (5x^4)/2! +...
	//(1+2x^2)*e^x^2; 0.1 <= x <= 1) 
	double y, x, a, e, fact;
	int n;

	do {
		cout << "x = ";
		cin >> x;
	} while (0.1 > x || x > 1);

	cout << "e = ";
	cin >> e;
	y = 1;
	n = 1;
	a = 1;//sum
	fact = 1;


	do
	{
		fact = fact * n;
		a = ((2 * n + 1) / fact) * pow(x, 2 * n);
		cout << "\n a = ((2 * " << n << " + 1) / "<< fact << ") * pow("<< x << ", 2 * "<< n << ") = " << a;
		y = y + a;
		n++;
	} while (fabs(a) >= e);

	cout << "\n sum = " << y;
	cout << "\n exp(x) = " << (1 + 2 * x*x)*pow(M_E, x*x); //(1+2x^2)*e^x^2;
	cout << endl;
}

int main()
{
	loopTask(lab);
}
