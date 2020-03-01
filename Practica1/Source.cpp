//����������� ��� �������� ����� ����� �� ������� ��������� � ���������� � � ������� ��������� � ���������� �.

//�������� ������� �������� �����, �������� ������� ��������� � �������� ������� ���������.
//��������� � � � ����� ��������� �������� �� �������[2, 16].
//���� � �������������� ����� ������������ �� ��� ���, ���� ������������ �� ������ 0. 
//������������� ����������� �������� ������� �����.

//P.S. ��� �������� ������� �����

#include <iostream>
#include <math.h>
#include <string>
#include <locale.h>
#include <stdlib.h>


using namespace std;

string str = "";

int ToDec(char n[256], int a)    //������� � 10 �� 
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
		if (m < a) //���������, ����� ��� �������� ������� � ������� ��
			r += m * pow(a, k);
		else r = 0;
	}

	return r;

}

void DecToB(int n, int b) //������� �� 10 � ��������� ������������� ��
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

	cout << "*����������� �������� ������ ���������*\n\n";

	do
	{
		ifnull = 0;

		cout << "������� ����� (>0 ��� 0, ���� ������ ��������� ������): "; cin >> n;

		for (int i = 0; i <= strlen(n) - 1; i++) //��������� �������� 0
			if (char(toupper(n[i])) == char('0'))
				ifnull += 1;

		if (ifnull != strlen(n))
		{
			cout << "������� �������� ������� ��������� (2<=16): ";
			cin >> a;

			if (a >= 2 && a <= 16)
			{

				n1 = ToDec(n, a); //������� � 10 ��

				if (n1 != 0)
				{
					cout << "������� ������� ���������, � ������� ������ ��������� ����� (2<=16): ";
					cin >> b;

					if (b >= 2 && b <= 16)
					{
						DecToB(n1, b);

						cout << str << "\n";
						str = "";
					}
					else cout << "��������� �������� ������� ��������� �� ������ � �������� ����������\n";
				}
				else cout << "������! ���� ������� �� �������� � ������� ������� ���������!\n";
			}
			else cout << "��������� �������� ������� ��������� �� ������ � �������� ����������\n";
		}


	} while (ifnull != strlen(n));


	system("pause");

	return 0;
}