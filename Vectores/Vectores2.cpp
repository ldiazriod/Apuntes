#include <iostream>
#include <vector>

using namespace std;

//Function Declarations
void fillVector(vector<int>& newMyVector){
    int input;
    cout << "Type in a list of numbers (-1 top stop): ";
    cin >> input;

    while(input != -1){
        newMyVector.push_back(input);
        cin >> input;
    }
    cout << endl;
}

void printVector(const vector<int>& newMyVector){

    cout << "Vector: ";

    for(unsigned int i{0}; i < newMyVector.size(); i++){
        cout << newMyVector.at(i) << " ";
    }

    cout << endl;
}

void reverse(const vector<int>& newMyVector){

    cout << "Vector reverse: ";

    for(unsigned int i{newMyVector.size()}; i > 0; i--){
        cout << newMyVector[i - 1] << " ";
    }
    cout << endl;
}

void printEvens(const vector<int>& newMyVector){

    for(unsigned int i{0}; i < newMyVector.size(); i++){
        if((newMyVector.at(i)%2) == 0){
         cout << newMyVector.at(i) << " ";
        }
    }
}

void replace(vector<int>& newMyVector){

    int old, replace;

    cout << "Type in a number to be replaced with another number: ";
    cin >> old >> replace;

    for(unsigned int i{0}; i < newMyVector.size(); i++){
        if(newMyVector.at(i)== old){
            newMyVector.at(i) = replace;
        }
    }

    printVector(newMyVector);
    cout << endl;
}

//Main Function

int main()
{
    vector<int> myVector;

    fillVector(myVector);
    printVector(myVector);

    return 0;
}


