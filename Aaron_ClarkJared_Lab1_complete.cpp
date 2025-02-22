#include <iostream>
#include <string>

using namespace std;

const int maxElem = 30;  
int myArray[maxElem];   
int numElem = 0;        


string traverseArray() {
    if (numElem == 0) {
        return "The array is empty.\n";
    }
    string result = "Array elements: ";
    for (int i = 0; i < numElem; i++) {
        result += to_string(myArray[i]) + " ";
    }
    return result + "\n";
}


string insertAtTheEnd(int num) {
    if (numElem != maxElem) {
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}


string insertAtTheBeginning(int num) {
    if (numElem != maxElem) {
        for (int i = numElem; i > 0; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}


string insertAtTheGivenPosition(int num, int elementAfter) {
    if (numElem != maxElem) {
        int position = -1;
        for (int i = 0; i < numElem; i++) {
            if (myArray[i] == elementAfter) {
                position = i + 1;
                break;
            }
        }
        if (position == -1) {
            return "Specified element not found.\n";
        }
        for (int i = numElem; i > position; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[position] = num;
        numElem++;
        return "An element is successfully inserted at the specified location!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

int main() {
    
    myArray[0] = 0;
    myArray[1] = 1;
    myArray[2] = 2;
    myArray[3] = 3;
    myArray[4] = 4;
    numElem = 5;

    cout << traverseArray();

    
    cout << insertAtTheBeginning(3);
    cout << insertAtTheEnd(7);
    cout << insertAtTheEnd(9);
    cout << insertAtTheBeginning(20);
    cout << insertAtTheGivenPosition(37, 7);
    cout << insertAtTheBeginning(256);
    cout << insertAtTheGivenPosition(128, 9);
    cout << insertAtTheBeginning(19);

    cout << traverseArray();

//Sorting Operations
void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i =0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(myArray[j], > myArray[j+1]){
                swap(myArray[j], myArray[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
    }
}  

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
            }
        }

        for(int 1 = numElem; i>=position; i--){ //Loop through the array
            myArray[i+1] = myArray[i]; // move each elements from left to right
        }

        myArray[position] = num; //insert new element at the appropriate position
        numElem++; //Increase number of elements in array
        return "An element is successfully inserted at a sorted array! \n";
    }

    //If array is full return this error message
    return "The array is full. Please remove elements before inserting new one. \n";
}

string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been deleted from the end!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromTheBeginning(){
    if(numElem != 0){
        for(int i = 0; i<= numElem; i++ ){
        myArray[i] = myArray[i+1];
        }
        numElem--;
        return "An element has been deleted from the beginning!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromGivenElement(int element){
    if(numElem != 0){
        int index;
        for(int i = 0; i <= numElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        }

        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return to_string(element) + "has been deleted!";

    }
    return "The array is underflow! Delete is not possible";
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + ((highest - 1) /2);

        if(myArray[middle] == num){
            return middle;
        }

        if(myArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
    return 0;
}