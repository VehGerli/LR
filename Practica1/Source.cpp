//Калькулятор для перевода целых чисел из системы счисления с основанием А в систему счисления с основанием В.

//Входными данными являются число, исходная система счисления и конечная система счисления.
//Основания А и В могут принимать значения из отрезка[2, 16].
//Ввод и преобразование чисел продолжается до тех пор, пока пользователь не введет 0. 
//Предусмотреть возможность перевода дробных чисел.

//P.S. Без перевода дробных чисел

#include <iostream>
#include <math.h>
#include <string>
#include <locale.h>
#include <stdlib.h>


using namespace std;

string str = "";

int ToDec(char n[256], int a)    //перевод в 10 сс 
{
	int r = 0, m, p = 0;

	int k = strlen(n);

	for (int i = 0; i <= strlen(n) - 1; i++)
	{
		k--;

		switch (toupper(n[i]))
		{
		case '0': m = 0; break;
		case '1': m = 1; break;
		case '2': m = 2; break;
		case '3': m = 3; break;
		case '4': m = 4; break;
		case '5': m = 5; break;
		case '6': m = 6; break;
		case '7': m = 7; break;
		case '8': m = 8; break;
		case '9': m = 9; break;
		case 'A': m = 10; break;
		case 'B': m = 11; break;
		case 'C': m = 12; break;
		case 'D': m = 13; break;
		case 'E': m = 14; break;
		case 'F': m = 15; break;
		default: return r = 0; break;
		}
		if (m < a) //проверяем, чтобы все значения входили в алфавит сс
			r += m * pow(a, k);
		else r = 0;
	}

	return r;

}

void DecToB(int n, int b) //перевод из 10 в указанную пользователем сс
{
	int s;

	while (n > 0)
	{
		s = n % b;
		if (s <= 9) str = char('0' + s) + str;
		else str = char(s - 10 + 'A') + str;

		n /= b;
	}

}


int main()
{
	setlocale(0, "");

	char n[256];

	int a, b, n1;

	int ifnull;

	cout << "*КАЛЬКУЛЯТОР ПЕРЕВОДА СИСТЕМ СЧИСЛЕНИЯ*\n\n";

	do
	{
		ifnull = 0;

		cout << "Введите число (>0 или 0, если хотите завершить работу): "; cin >> n;

		for (int i = 0; i <= strlen(n) - 1; i++) //проверяет введение 0
			if (char(toupper(n[i])) == char('0'))
				ifnull += 1;

		if (ifnull != strlen(n))
		{
			cout << "Введите исходную систему счисления (2<=16): ";
			cin >> a;

			if (a >= 2 && a <= 16)
			{

				n1 = ToDec(n, a); //перевод в 10 сс

				if (n1 != 0)
				{
					cout << "Введите систему счисления, в которую хотите перевести число (2<=16): ";
					cin >> b;

					if (b >= 2 && b <= 16)
					{
						DecToB(n1, b);

						cout << str << "\n";
						str = "";
					}
					else cout << "Введенное значение системы счисления не входит в заданный промежуток\n";
				}
				else cout << "Ошибка! Есть символы не входящие в алфавит системы счисления!\n";
			}
			else cout << "Введенное значение системы счисления не входит в заданный промежуток\n";
		}


	} while (ifnull != strlen(n));


	system("pause");

	return 0;
}