#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);

template<typename T>
void Print(T arr[], const int n);
template<typename T>
void Print(T** arr, const int m, const int n);
template<typename T>
void push_back(T*& arr, int& n, T value);
template<typename T>
void push_front(T*& arr, int& n, T value);
template<typename T>
void insert(T*& arr, int& n, T value, int index);
template<typename T>
void pop_back(T*& arr, int& n);
template<typename T>
void erase(T*& arr, int& n, int index);
template<typename T>
void push_row_back(T**& arr, int& m, const int n);
template<typename T>
void push_row_front(T**& arr, int& m, const int n);
template<typename T>
void insert_row(T**& arr, int& m, const int n, const int index);
template<typename T>
void pop_row_back(T**& arr, int& m, const int n);
template<typename T>
void pop_row_front(T**& arr, int& m, const int n);
template<typename T>
void erase_row(T**& arr, int& m, const int n, const int index);
template<typename T>
void push_col_back(T** arr, const int m, int& n);

#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
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
	int m = 0;	
	n = 0;
	index = 0;
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
	//cout << "Память выделена" << endl;
	system("PAUSE");

	cout << "Добавление строки в конец массива:\n";
	push_row_back(arr2, m, n);
	Print(arr2, m, n);

	cout << "Добавление строки в начало массива:\n";
	push_row_front(arr2, m, n);
	Print(arr2, m, n);



	cout << "Добавление столбца в конец:" << endl;
	push_col_back(arr2, m, n);
	Print(arr2, m, n);
	//cout << "Строка добавлена" << endl;
	for (int i = 0; i < m; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
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


template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>
void Print(T** arr, const int m, const int n)
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


template<typename T>
void push_back(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>
void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>
void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
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
template<typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n]{};	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>
void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n]{};
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
template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1]{};
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
	arr[m] = new T[n] {};
	m++;
}
template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n] {};
	m++;
}
template<typename T>
void insert_row(T**& arr, int& m, const int n, const int index) {
	T** buffer = new T*[m + 1]{};
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T [n] {};
	m++;
}
template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T>
void pop_row_front(T**& arr, int& m, const int n) {
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>
void erase_row(T**& arr, int& m, const int n, const int index) {
	T** buffer = new T*[--m];
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i] = arr[i + 1];
	}
}
template<typename T>
void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}