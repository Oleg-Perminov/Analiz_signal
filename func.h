#pragma once
void welcome(); // функция заставки


void arrTime(int n, double t[]); //Формирование массива времени t 
double maximum(int n, double U[]); // функция нахождения максимального элемента массива
double minimum(int n, double U[]); // функция нахождения минимального элемента массива
double durationPulse(int n, double U[]); //функция расчета длины импульса
void arrUvx(int n, double t[], double Uvx[]); //функция формирования массива входного напряжения
void arrUvix(int n, double Uvx[], double Uvix[]); //функция формирования массива выходного напряжения
void output(int n, double t[], double Uvx[], double Uvix[]); // функция для форматного вывода в виде таблицы
bool outputFile(int n, double t[], double Uvx[], double Uvix[]); //вывод данных в файл