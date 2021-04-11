#include<algorithm>
#include<iostream>
#include<conio.h>
#include"header.h"
using namespace std;
const int s = 3;
char pole[s][s]{ 
		{'1','2','3'},
		{'6','5','4'},
		{'7','8',' '}};
int x = 2;
int y = 2;
void check() {
	char ideal[s][s] = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8',' '} };
	int flag = 0;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (pole[i][j] == ideal[i][j])
				flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	if (flag == 1) {
		system("cls");
		cout << "You have won!!! Congratulations!" << endl;
		system("pause");
		main();
	}
}
void output() {
	system("cls");
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++)
			cout << pole[i][j] << " ";
		cout << endl;
	}
}
void moving() {
	check();
	long int temp = 0;
	char ch;
	output();
	ch = _getch();
	switch (ch)
	{
	case 'w': {
		if (y > 0) {
			temp = pole[y-1][x];
			pole[y-1][x] = pole[y][x];
			pole[y][x] = temp;
			y--;
		}
		break;
	}
	case 's': {
		if (y < 2) {
			temp = pole[y + 1][x];
			pole[y + 1][x] = pole[y][x];
			pole[y][x] = temp;
			y++;
		}
		break; 
	}
	case 'a': {
		if (x > 0) {
			temp = pole[y][x - 1];
			pole[y][x - 1] = pole[y][x];
			pole[y][x] = temp;
			x--;
		}
		break;
	}
	case 'd': {
		if (x < 2) {
			temp = pole[y][x + 1];
			pole[y][x + 1] = pole[y][x];
			pole[y][x] = temp;
			x++;
		}
		break;
	}
	case 'e': main();
	default:
		moving;
	}
	moving();
}