#include "functions.h"

//Open input file

//Create an array that contains the data

//prompt user for actions

//call corresponding function

//loop back to user prompt

int* array1 = new int[100];

int main(){ // Tried to factor out methods as best I could, main just handles the user input via switch and calls the corresponding func.

    ReadInputFile(array1);

    int size1 = 100;
    string input = "";
    int value;
    int index;

    while (toupper(input[0]) != 'Q'){
        UserMenu();
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
        try{
        switch (stoi(input)){
        case 1:
            if (IntegerExists(array1, size1))
                cout << "\nExists in array" << endl << endl;
            else{
                cout << "\nDoes not exist in the array" << endl << endl;
            }
            break;
        case 2:
            ModifyFromIndex(array1, size1);
            break;
        case 3:
            array1 = Append(array1, size1);
            size1++;
            break;
        case 4:
            Remove(array1, size1);
            break;
        default:
            cout << "Enter a valid menu option" << endl;
            break;
        }
    }
       catch(std::invalid_argument e){
        cout << "Quitting..." << endl;
       } 
    }

    return 0;
}