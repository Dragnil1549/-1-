#pragma once
#include <string>
#include "Windows.h"
#include <iostream>
#define INT_MAX 32767
#define NUM 13

using namespace std;
struct arr
{
	string str = "\0";
	int TelNumber = 0;
	arr* next = NULL;
};
int hash_f(string);
void output(arr*, int);
void input(arr*, int, string, int);
void search(arr*, int, int);
void dlt(arr*, int, int);