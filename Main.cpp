#include<iostream>
#include"generalfunc.h"
#include"generalfunc.cpp"
#include"arrays1.h"
#include"arrays1.cpp"
#include"arrays2.h"
#include"arrays2.cpp"
#define GENERALFUNC
//#define ARRAYS1
#define ARRAYS2
using namespace std;


void main()
{
	setlocale(LC_ALL, "");
#ifdef ARRAYS1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
#ifdef GENERALFUNC
	FillRand(arr, n);
	Print(arr, n);
#endif // GENERALFUNC

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента:\n";
	pop_back(arr, n);
	Print(arr, n);
	cout << "Введите индекс удавляемого элемента: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // ARRAYS1


#ifdef ARRAYS2
	int m = 0;
	int n = 0;
	int index = 0;
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr2[i] = new int [n] {};
	}
	FillRand(arr2, m, n);
	Print(arr2, m, n);
	cout << "Удаление строки по индексу: " << endl;
	cout << "Введите индекс: "; cin >> index;
	erase_row(arr2, m, n, index);
	Print(arr2, m, n);
	cout << "Удаление нулевой строки: " << endl;
	pop_row_front(arr2, m, n);
	Print(arr2, m, n);
	cout << "Добавление строки по указанному индексу: " << endl;
	cout << "Введите индекс: "; cin >> index;
	insert_row(arr2, m, n, index);
	Print(arr2, m, n);

	cout << "Добавление строки в конец массива:\n";
	push_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "Добавление строки в начало массива:\n";
	push_row_front(arr2, m, n);
	Print(arr2, m, n);



	cout << "Добавление столбца в конец:" << endl;
	push_col_back(arr2, m, n);
	Print(arr2, m, n);
	for (int i = 0; i < m; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
#endif // ARRAYS2

	
}