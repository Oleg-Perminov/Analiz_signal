#include <stdio.h>
#include <iostream> //std
#include <fstream> //работа с файлами std?
#include <string> // для чтения строк
#include <cassert>

#include "func.h" 

#define a1 12.0
#define b1 48.0
#define tn 10.0
#define tk 35.0
#define t1 30.0

#define a2 2.0
#define b2 -5.0
#define Uvx1 20.0


using namespace std;

void welcome() { //реализация считывания файла 
	ifstream file("Welcome.txt");
	if (!file) {
		cerr << "Не удалось открыть файл\n";
		return;
	}
	string line;
	while (getline(file, line)) {
		cout << line << '\n';
	}
	file.close();
}

void arrTime(int n, double t[])
{
	double dt = (tk - tn) / (n - 1);
	for (int i = 0; i < n; i++)
		t[i] = tn + i * dt;
}

double maximum(int n, double U[])
{
	double max = *U;
	for (int i = 1; i < n; i++)
		if (U[i] > max)
			max = U[i];
	return max;
}

double minimum(int n, double U[])
{
	double min = *U;
	for (int i = 1; i < n; i++)
		if (U[i] < min)
			min = U[i];
	return min;
}

double durationPulse(int n, double U[])
{
	double dt = (tk - tn) / (n - 1);
	double dlit, Uimp, Umax, Umin;
	dlit = 0;

	Umin = minimum(n, U);
	Umax = maximum(n, U);
	Uimp = Umin + 0.5 * (Umax - Umin);

	for (int i = 0; i < n; i++)
		if (U[i] > Uimp)
			dlit += dt;

	return dlit;
}

void arrUvx(int n, double t[], double Uvx[])
{
	for (int i = 0; i < n; i++)
	{
		if (t[i] <= t1)
			Uvx[i] = a1 * (t[i] - tn);
		else
			Uvx[i] = a1 * (t1 - tn) - b1 * (t[i] - t1);
	}

}

void arrUvix(int n, double Uvx[], double Uvix[])
{
	for (int i = 0; i < n; i++)
	{
		if (Uvx[i] <= Uvx1)
			Uvix[i] = a2 * Uvx[i] + b2;
		else
			Uvix[i] = a2 * Uvx1 + b2;
	}
}

void output(int n, double t[], double Uvx[], double Uvix[])
{
	printf("\n   N   |    t    |    Uvx     |    Uvix   ");
	printf("\n -------------------------------------------");
	for (int i = 0; i < n; i++)
		printf("\n %5d |%8.2f |%11.2f |%12.2f|", i, t[i], Uvx[i], Uvix[i]);
	printf("\n -------------------------------------------\n");
}

bool outputFile(int n, double t[], double Uvx[], double Uvix[])
{
	ofstream file1("t.txt");
	ofstream file2("Uvx.txt");
	ofstream file3("Uvix.txt");

	if (!file1 or !file2 or !file3) {
		return 0;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			file1 << t[i] << endl;
			file2 << Uvx[i] << endl;
			file3 << Uvix[i] << endl;
		}

		file1.close();
		file2.close();
		file3.close();
		
		return 1;
	}

}