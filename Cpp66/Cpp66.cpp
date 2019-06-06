#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct shop {
	string name;
	int cost;
	string unit;
};

void Init(shop *arr, const int n) {
	for (int i = 0; i < n; i++) 
	{
		cout << "Input name: ";
		cin >> arr[i].name;
		cout << "Input cost: ";
		cin >> arr[i].cost; cin.ignore();
		cout << "Input unit: ";
		cin >> arr[i].unit; cin.ignore();
	}
}

void Print(shop *arr, const int n)
{
	cout << "\nList: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << " | " << arr[i].cost << " | " << arr[i].unit << " | "<< endl;
	}
}

void Write(shop *arr, const int n)
{
	ofstream file("file.txt", ios::binary | ios::in);
	for (int i = 0; i < n; i++)
	{
		
			file.write((char*)&arr[i].name, sizeof arr[i].name);
			file.write((char*)&arr[i].cost, sizeof arr[i].cost);
			file.write((char*)&arr[i].unit, sizeof arr[i].unit);
		
	}
	file.close();
}

int main()
{
	int n;
	cout << "How many: ";
	cin >> n;
	shop *arr = new shop[n];
	Init(arr, n);
	Print(arr, n);
	Write(arr, n);
	delete[] arr;
	return 0;
}

