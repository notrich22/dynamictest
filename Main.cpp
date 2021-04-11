#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);	
void erase(int*& arr, int& n, int index);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
void insert_row(int**& arr, int& m, const int n, const int index);
void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);
void erase_row(int**& arr, int& m, const int n, const int index);

void push_col_back(int** arr, const int m, int& n);

//#define PUSH_BACK
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
#ifdef PUSH_BACK
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
#endif // PUSH_BACK
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

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	Print(arr, n);
#endif // DEBUG_ARRAYS

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

void push_back(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	/*for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];*/
	for (int i = 0; i < n; i++)
	{
		true;
		if (i < index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}*/
	for (int i = 0; i < n; i++)
	{
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];	
	}

	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
}
void insert_row(int**& arr, int& m, const int n, const int index) {
	int** buffer = new int*[m + 1]{};
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int [n] {};
	m++;
}
void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
void pop_row_front(int**& arr, int& m, const int n) {
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void erase_row(int**& arr, int& m, const int n, const int index) {
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i] = arr[i + 1];
	}
}
void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}