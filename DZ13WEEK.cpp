#include <iostream>
#include"header.h"
const int s = 10;
using namespace std;
void func1() {
	int arr1[s] = { 0 };
	int arr2[s] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr1[i] = rand() % 50 - 20;
	}
	int* arr1ptr = arr1;
	int* arr2ptr = arr2;
	for (int i = 0; i < s; i++) {
		*arr2ptr = *arr1ptr;
		cout << "Arr 2: " << *arr2ptr << " ";
		arr1ptr++; arr2ptr++;
	}
	cout << endl << endl;
}
void func2() {
	int arr1[s] = { 0 };
	int temp;
	int* last = &arr1[9];
	int* frst = &arr1[0];
	for (int i = 0; i < s; i++) {
		arr1[i] = rand() % 50 - 20;
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < s / 2; i++) {
		temp = *frst;
		*frst = *last;
		*last = temp;

		frst++;
		last--;
	}
	for (int i = 0; i < s; i++)
		cout << arr1[i] << " ";
	cout << endl << endl;
}
void func3() {
	int arr1[s] = { 0 };
	int arr2[s] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr1[i] = rand() % 50 - 20;
	}
	int* arr1ptr = arr1;
	int* arr2ptr = &arr2[s - 1];
	for (int i = 0; i < s; i++) {
		*arr2ptr = *arr1ptr;
		arr1ptr++; arr2ptr--;
	}
	for (int i = 0; i < s; i++) {
		cout << "Arr 1: " << arr1[i] << "\t" << "Arr 2: " << arr2[i];
		cout << endl;
	}
	cout << endl << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int ch = 0;
	cout << "Выберите функцию: " << endl;
	cout << "1. Копирование одного массива в другой" << endl;
	cout << "2. Обратный порядок массива" << endl;
	cout << "3. Копирование одного массива в другой в обратном порядке" << endl;
	cout << "4. Пятнашки" << endl;
	cout << "5. Крестики-нолики" << endl;
	cout << "6. Задача с конем" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1: func1(); break;
	case 2: func2(); break;
	case 3: func3(); break;
	case 4: moving(); break;
	case 5: xxx(); break;
	case 6: konb(); break;
	default:
		main();
	}
	main();
}