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
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	pop_front(arr, n);
	Print(arr, n);
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
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int m;	
	int n;
	int index;
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление строки по индексу: " << endl;
	cout << "Введите индекс: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "Удаление нулевой строки: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление строки по указанному индексу: " << endl;
	cout << "Введите индекс: "; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);
	//cout << "Память выделена" << endl;
	system("PAUSE");

	cout << "Добавление строки в конец массива:\n";
	push_row_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление строки в начало массива:\n";
	push_row_front(arr, m, n);
	Print(arr, m, n);



	cout << "Добавление столбца в конец:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	//cout << "Строка добавлена" << endl;
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // DYNAMIC_MEMORY_2
}
