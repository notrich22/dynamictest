#include<iostream>
#include"Fillrand.h"
#include"Print.h"
#include"arrays1.h"
#include"arrays2.h"
using namespace std;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	pop_front(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "�������� ���������� ��������:\n";
	pop_back(arr, n);
	Print(arr, n);
	cout << "������� ������ ����������� ��������: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int m;	
	int n;
	int index;
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "�������� ������ �� �������: " << endl;
	cout << "������� ������: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "�������� ������� ������: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "���������� ������ �� ���������� �������: " << endl;
	cout << "������� ������: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);
	//cout << "������ ��������" << endl;
	system("PAUSE");

	cout << "���������� ������ � ����� �������:\n";
	push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "���������� ������ � ������ �������:\n";
	push_row_front(arr, m, n);
	Print(arr, m, n);



	cout << "���������� ������� � �����:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	//cout << "������ ���������" << endl;
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // DYNAMIC_MEMORY_2
}
