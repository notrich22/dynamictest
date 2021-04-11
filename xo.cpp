#include<iostream>
#include "Header.h"
using namespace std;
const int s = 3;
int times = 0;
char xo[s][s] = {
	{'-','-','-'},
	{'-','-','-'},
	{'-','-','-'}
};
bool allcheck() {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) 
			if (xo[i][j] == '-')
				return false;
	}
	return true;
}
bool xwin() {
	for (int i = 0; i < s; i++) {
		if (xo[i][0] == 'x' && xo[i][1] == 'x' && xo[i][2] == 'x') {
			return true;
		}
	}
	for (int i = 0; i < s; i++) {
		if (xo[0][i] == 'x' && xo[1][i] == 'x' && xo[2][i] == 'x') {
			return true;
		}
	}
	if (xo[0][0] == 'x' && xo[1][1] == 'x' && xo[2][2] == 'x') {
			return true;}
	if (xo[2][0] == 'x' && xo[1][1] == 'x' && xo[0][2] == 'x') {
			return true;}
	return false;
}
bool owin() {
	for (int i = 0; i < s; i++) {
		if (xo[i][0] == 'o' && xo[i][1] == 'o' && xo[i][2] == 'o') {
			return true;
		}
	}
	for (int i = 0; i < s; i++) {
		if (xo[0][i] == 'o' && xo[1][i] == 'o' && xo[2][i] == 'o') {
			return true;
		}
	}
	if (xo[0][0] == 'o' && xo[1][1] == 'o' && xo[2][2] == 'o') {
		return true;
	}
	if (xo[2][0] == 'o' && xo[1][1] == 'o' && xo[0][2] == 'o') {
		return true;
	}
	return false;
}
void vivod() {
	system("cls");
	//cout << "  ";
	cout << "  ";
	for (int i = 0; i < s + 1; i++)
		if(i >= 1)
			cout << i - 1 << " ";
	cout << endl;
	for (int i = 0; i < s; i++) {
		cout << i << " ";
		for (int j = 0; j < s; j++) {
			cout << xo[i][j] << " ";
		}
		cout << endl;
	}
}
void x() {
	int x1, y;
	cout << "Введите y x:";
	cin >> x1 >> y;
	if (xo[x1][y] == '-')
		xo[x1][y] = 'x';
	else
		x();
}
void o() {
	int x, y;
	cout << "Введите y x:";
	cin >> x >> y;
	if (xo[x][y] == '-')
		xo[x][y] = 'o';
	else
		o();
}
void xxx() {
	vivod();
	if (xwin()) {
		cout << "Выиграл игрок с крестиками!" << endl;
		main();
	}
	if (allcheck()) {
		cout << "Ничья!" << endl;
		main();
	}
	if (owin()) {
		cout << "Выиграл игрок с ноликами!" << endl;
		main();
	}
	if (times % 2 == 0) {
		cout << "Куда хотите поставить крестик?" << endl;
		x();
	}
	else {
		cout << "Куда хотите поставить нолик?" << endl;
		o();
	}
	times++;
	xxx();
}