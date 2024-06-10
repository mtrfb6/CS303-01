#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#pragma once

using namespace std;

bool isDigit(string str1);
//Helper function to verify input file

int getArraySize(unsigned u, size_t t);
//Helper function to get array size, unused

void UserMenu();

void ReadInputFile(int arr[]);
//open 'A1input.txt' and set the array values

bool IntegerExists(int arr[], int size); 
//Check if a certain integer exists in the array if the number is present return the index where the number is present.

void ModifyFromIndex(int arr[], int size);
//modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user

int* Append(int* arr, int size);
//adds a new integer to the end of the array

void Remove(int arr[], int size);
//intakes an index of an array and replaces the value with either 0 or removes the integer altogether.