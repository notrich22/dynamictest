#include "generalfunc.h"

template<typename T>void FillRand(T arr[], const int n)
{
	if (typeid(T) == typeid(double)){
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 1000;
			arr[i] /= 100;
		}
	}
	else {
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;
		}
	}
}
template<typename T>void FillRand(T** arr, const int m, const int n)
{
	if (typeid(T) == typeid(double)) {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = double(rand() % 10000) / 100;
			}
		}
	}
	else {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = rand() % 100;
			}
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int m, const int n)
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