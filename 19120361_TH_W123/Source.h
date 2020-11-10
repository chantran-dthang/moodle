#pragma once

void inputArray(int*& a, int& n);

void dellocateArray(int*& a);

void printArray(int* a, int n);

int findMin(int* a, int n);

int findMaxModulus(int* a, int n);

bool isAcending(int* a, int n);

int sumArray(int* a, int n);

bool isPrime(int n);

int countPrime(int* a, int n);

void reverseArray(int* a, int n);

int linearSearch(int* a, int n, int key);

int sentineLinearSearch(int* a, int n, int key);

void insertionSort(int* a, int n);

int binarySearch(int* a, int n, int left, int right, int key);

int recursiveBinarySearch(int* a, int n, int left, int right, int key);

int sumOfSquare(int n);

int gcd(int a, int b);

bool isPalindrome(int* a, int n);

int countDigit(int n);

int factorial(int n);

int FIB(int n);

void readCSV();
