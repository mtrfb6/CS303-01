#include "functions.h"

bool isDigit(string str1) {
	return str1.find_first_not_of("0123456789") == string::npos;
}

int getArraySize(unsigned u, size_t t){
    return u/t;
}

void UserMenu(){
        cout << "==========Array Manipulator==========" << endl;
        cout << "1. Check for Integer" << endl <<
         "2. Modify via Index" << endl <<
         "3. Append" << endl <<
         "4. Remove" << endl <<
         "Q. Quit" << endl <<
         "Enter a selection 1-4: ";
}

void ReadInputFile(int arr[]){
    ifstream inFile;
    inFile.open("A1input.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        return;
    }

    string line;
    int tempindex = 0;

    //Read line by line
    while (getline(inFile, line)) {
        stringstream iss(line);
        string value;
        
        while (iss >> value) {
            if (isDigit(value)) {
                arr[tempindex++] = stoi(value);
            }
        }
    }
    inFile.close();
}

bool IntegerExists(int arr[], int size){
    int value;
    cout << "Enter a number to check: ";
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    for(int i = 0; i < size; i++){
        if (arr[i] == value)
            return true;
    }
    return false;
}


void ModifyFromIndex(int arr[], int size){
    int index;
    int value;
    cout << "Enter the index to modify: ";
    cin >> index;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Enter the new value: ";
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    try {
        if (index < 0) {
            throw out_of_range("Index cannot be negative");
        }

        if (index >= size) {
            throw out_of_range("Index is out of bounds");
        }

        int old = arr[index]; //Keep old value to output and then reassign to the new value
        arr[index] = value;
        cout << "Old Value:" << setw(14) << "New Value:" << endl;
        cout << old << setw(15) << arr[index] << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return;
}

int* Append(int* arr, int size){
    int value;
    cout << "Enter a number to append: ";
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    try {
        int* arr2 = new int[size + 1]; //Creating a new array to be returned, keeping old values and adding the appended value at the end
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        arr2[size] = value;
        delete[] arr; //since were making a new array, clear the old one from memory
        return arr2;
    } catch (...) { //wasn't sure what to catch here so just using ...
        cerr << "An unknown error occurred." << endl;
        return arr; 
    }
}

void Remove(int arr[], int size){
    int index;
    cout << "Enter the index to be removed: ";
    cin >> index;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    for (int i = index; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    if (index == size - 1){
        arr[index] = 0;
    }
    return;
}

