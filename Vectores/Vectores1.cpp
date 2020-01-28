#include <iostream>
#include <vector>

using namespace std;

//Format: vector<DataType> nameOfVector
//nameOfVector.push_back() fill de vector - Add an element to the end of the vector(also resizes it)
//nameOfVector.at(i) or nameOfVector[i] - return element at specified index number
//nameOfVector.size() - return an unsigned int equal to the number of elements
//nameOfVector.begin() - read vector from first element(index 0)
//nameOfVector.insert(nameOfVector.begin() + integer, new value) - adds elements BEFORE specified index number
//nameOfVector.erase(myVector.Begin()+ integer) - removes elements At specified index number
//nameOfVector.clear() - removes all elements in vector
//nameOfVector.empty() - returns boolean value if whether vector is empty



int main()
{
    vector<int> myVector; //Define vector

    //Filling the vector
    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(4);
    myVector.push_back(12);
    myVector.push_back(9);


//Print the vector
    cout << "Vector: ";

    for(unsigned int i{0}; i < myVector.size(); i++){
        cout << myVector.at(i) << " ";
        //myVector[i]
    }


    cout << endl;

     myVector.insert(myVector.begin() + 3 ,5); //Insert a 5 in the third position counting from the first element of the vector

     cout << "Vector: ";

    for(unsigned int i{0}; i < myVector.size(); i++){
        cout << myVector.at(i) << " ";
        //myVector[i]
    }

     cout << endl;

     myVector.erase(myVector.begin() + 4); //Erase the fourth element of the vector counting from the first element of the vector, in this case the number 12 because whe insert a 5 early.

     cout << "Vector: ";

    for(unsigned int i{0}; i < myVector.size(); i++){
        cout << myVector.at(i) << " ";
        //myVector[i]
    }

     cout << endl;

     if(myVector.empty()){
         cout << endl << "Is Empty!";

     }else{
         cout << endl << "Is Not Empty";
     }


     myVector.clear();

     if(myVector.empty()){
         cout << endl << "Is Empty!";

     }else{
         cout << endl << "Is Not Empty";
     }

    return 0;
}
