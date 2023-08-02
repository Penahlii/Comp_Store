#include<iostream>
#include<cassert>
#include<Windows.h>
#include<string.h>
using namespace std;
typedef unsigned short int ushort;
char* error = new char[5] {"NULL"};
#include"Computer.h"
#include"Computer_functions.h"
#include"CompStore.h"
#include"CompStore_functions.h"
int main()
{
	Computer** computers = new Computer*[3];
	computers[0] = new Computer("Asus tuf dash f15", "Black", 2023, 16, 1024);
	computers[1] = new Computer("Asus tuf f17", "Italic", 2022, 16, 2048);
	computers[2] = new Computer("Hp model 1", "White", 2021, 8, 1024);

	CompStore* cmp1 = new CompStore("Ibrahim", computers, 3);

	cmp1->print();
	return 0;
}