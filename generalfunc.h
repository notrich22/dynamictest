#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include <random>
#define tab "\t"
void FillRand(double arr[], const int n);
template<typename T>void FillRand(T arr[], const int n);
void FillRand(double** arr, const int m, const int n);
template<typename T>void FillRand(T** arr, const int m, const int n);
template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);