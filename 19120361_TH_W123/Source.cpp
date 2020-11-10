#include <iostream>
#include <fstream>
#include<math.h>
#include <vector>
#include "Source.h"
#include "string"
#include<sstream>

//#include "pointer.h"
using namespace std;

void inputArray(int*& a, int& n)
{
	cout << "enter n ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "enter a[" << i << "]";
		cin >> a[i];
	}
}

void dellocateArray(int*& a)
{
	delete[] a;
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
}

int findMin(int* a, int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i]) min = a[i];
	}
	return min;
}

int findMaxModulus(int* a, int n)
{
	int maxMod = abs(a[0]);
	for (int i = 0; i < n; i++)
	{
		if (maxMod < abs(a[i])) maxMod = abs(a[i]);
	}
	return maxMod;
}

bool isAcending(int* a, int n)
{
	bool ascending = true;
	for (int i = 0; i < n-1 ; i++)
	{
		if (a[i] > a[i + 1]) ascending = false;
	}
	return ascending;
}

int sumArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

bool isPrime(int n)
{
	int prime = 0;
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) prime++;
	}
	if (prime > 0) return false;
	else return true;
}

int countPrime(int* a, int n)
{
	int prime = 0;
	for (int i = 0; i < n; i++)
	{
		if (isPrime(a[i]))prime++;
	}
	return prime;
}

void reverseArray(int* a, int n)
{
	for (int i = 0; i <= n / 2; i++)
	{
		int temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}

int linearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int sentineLinearSearch(int* a, int n, int key)
{
	a[n] = key;
	int i;
	for (i = 0; ; i++)
	{
		if (a[i] == key)
			break;
	}

	if (i == n) return -1;
	else return i;
}

void insertionSort(int* a, int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		key = a[i];
		while (j > -1 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int binarySearch(int* a, int n, int left, int right, int key)
{
	while (left < right)
	{
		int mid = left + (right - left);
		if (a[mid] < key) left = mid + 1;
		if (a[mid] > key)right = mid - 1;
		if (a[mid] == key) return mid;
	}
	return -1;
}

int recursiveBinarySearch(int* a, int n, int left, int right, int key)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] > key)
		{
			return recursiveBinarySearch(a, n, left, mid, key);
		}
		else if (a[mid] < key)
		{
			return recursiveBinarySearch(a, n, mid + 1, right, key);
		}
		else return mid;
	}
	return -1;
}

//`````````````````````RECURSION```````````````````````````
int sumOfSquare(int n)
{
	if (n == 0) return n;
	else return (pow(n, 2) + sumOfSquare(n-1));
}

int gcd(int a, int b)
{
	if (a == 0 || b == 0) return a + b;
	if (a > b) return gcd(a -= b, b);
	if (a < b) return gcd(a, b -= a);
	if (a == b)return a;
	
}

bool isPalindrome(int* a, int n)
{
	return true;
}

int countDigit(int n) // bug so 0 co o chu so
{
	if (n == 0) return n;
	else return 1 + countDigit(n / 10);
}

int factorial(int n)
{
	if (n == 1) return n;
	else return n * factorial(n - 1);
}

int FIB(int n)
{
	if (n == 1 || n == 2)return 1;
	else return FIB(n - 1) + FIB(n - 2);
}

//struct Examinee
//{
//	string id;
//	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
//};

void readCSV(Examinee& sv)
{
	fstream fs;
	fs.open("data.txt", ios::in);
	vector<string> row;
	string temp, line, word;
	int roll, j = 0, i = 0;
	cout << "Enter number of row to see details: ";
	cin >> roll;
	getline(fs, temp);
	while (fs >> line)
	{
		row.clear();
		//getline(fs, line);
		stringstream s(line);
		while (getline(s, word, ','))
		{
			row.push_back(word);
		}
		j++;
		if (roll == j)
		{
			//sv.id = row[0];
			sv.math = stof(row[1]);
			sv.literature = stof(row[2]);
			sv.physic = stof(row[3]);
			sv.chemistry = stof(row[4]);
			sv.biology = stof(row[5]);
			sv.history = stof(row[6]);
			sv.geography = stof(row[7]);
			sv.civic_education = stof(row[8]);
			sv.natural_science = stof(row[9]);
			sv.social_science = stof(row[10]);
			sv.foreign_language = stof(row[11]);
		}
		if (roll < 1) cout << "roll not found" << endl;
	}

}

void countWord(string str)
{
	string word;
	stringstream s(str);
	int count = 0;
	while (s>>word)
	{
		count++;
		cout << word << ' ' << count << endl;
		
	}
	string S, T;

	getline(cin, S);

	stringstream X(S);

	while (getline(X, T, ' ')) {
		cout << T << endl;
	}
}
void main()
{
	Examinee sv = {};
	readCSV(sv);
	cout << sv.math;
}