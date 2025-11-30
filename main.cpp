#include <iostream> // std
#include <locale.h> // язык консоли
#include <cstdlib> // работа с консолью windows
#include <fstream> // работа с файлами

#include "func.h"
#define N 1000

using namespace std;

int main()
{
    try {
        setlocale(LC_ALL, "ru_RU.UTF-8");
    }
    catch (...) {}

    char choice;

    while (true)
    {
        system("cls");

        double t[N], Uvx[N], Uvix[N];
        int n = 0;

        welcome();

        cout << "\n";
        cout << "1) Контрольный расчет для n точек\n";
        cout << "2) Расчет параметра с заданной точностью\n";
        cout << "3) Запись данных в файл\n";

        cout << "0) Выход\n";
        cout << "Введите номер меню -> ";
        cin >> choice;
        cout << "\n";
        
        switch (choice) {
            case '1':
                cout << "Введите количество точек n = ";
                cin >> n;
                cout << endl;
                if (n > N) {
                    cout << "Количество точек превышает " << N << ", выход.";
                    break;
                }

                arrTime(n, t);
                arrUvx(n, t, Uvx);
                arrUvix(n, Uvx, Uvix);
                output(n, t, Uvx, Uvix);

                printf("\nДлительность импульса сигнала Uvx(t): %.2f\n", durationPulse(n, Uvx));
                printf("\nДлительность импульса сигнала Uvix(t): %.2f\n\n", durationPulse(n, Uvix));

                break;
            case '2': {
                double p = 1, 
                eps = 0.01, 
                par = 1e10, 
                par1;

                n = 11;
                
                while (p > eps) {
                    arrTime(n, t);
                    arrUvx(n, t, Uvx);
                    arrUvix(n, Uvx, Uvix);

                    par1 = durationPulse(n, Uvix);
                    if (par1 == 0) // защита от деления на 0
                        printf("\nn= %3d параметр = %.3f погрешность = %.6f\n\n", n, par, p);
                    else
                    {
                        p = fabs(par - par1) / par1;
                        printf("n = %3d, параметр = %.3f, погрешность = %.6f\n", n, par1, p);
                    }
                    
                    par = par1;
                    n = 2 * n;
                }

            }
                break;
            case '3':

                if(n == 0){
                    cout << "Введите количество точек n = ";
                    cin >> n;
                    cout << endl;
                    if (n > N) {
                        cout << "Количество точек превышает " << N << ", выход.";
                        break;
                    }
                }

                arrTime(n, t);
                arrUvx(n, t, Uvx);
                arrUvix(n, Uvx, Uvix);

                if (outputFile(n, t, Uvx, Uvix)) {
                    cout << "Произведена запись в файлы t.txt, Uvx.txt, Uvix.txt\n";
                }
                else {
                    cout << "Не получилось записать в файлы\n";
                }
                break;
            case '0': // выход
                cout << "0\n";
                return 0;
                break;
            default:
                cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }

        cout << "\nНажмите Enter, чтобы вернуться в меню...";
        cin.ignore();
        cin.get();
    }
}


