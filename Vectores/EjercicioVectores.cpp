#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void fillVector(vector<int>& myNewVector){
    int howManyNums{0}, newNumOfVector;
    cout << "Cuantos numeros tiene tu vector?: ";
    cin >> howManyNums;

    for(int i{0}; i < howManyNums; i++){
        cout << "Cual es el nuevo numero que quiere añadir?: ";
        cin >> newNumOfVector;

        myNewVector.push_back(newNumOfVector);
    }

}

void meanAndComprobationOfNumbers(vector<int>& myNewVector){
   auto mean = accumulate(myNewVector.begin(), myNewVector.end(), 0.0) / myNewVector.size();
   vector<int> biggerThanMean;
   vector<int> smallerThanMean;

   cout << "La media es: " << mean << endl;

   for(int i{0}; i < myNewVector.size(); i++){
       if(myNewVector.at(i) < mean){
           smallerThanMean.push_back(i);
       }else{
           biggerThanMean.push_back(i);
       }
   }

   cout << "Los números que son más pequeños que la media son: ";

   for(int j{0}; j < smallerThanMean.size(); j++){
       cout << smallerThanMean.at(j) << " ";

   }
   cout << endl;

   cout << "Los números que son más grandes que la media son: ";

   for(int k{0}; k < biggerThanMean.size(); k++){
       cout << biggerThanMean.at(k) << " ";
   }

   cout << endl;

}


void printVector(const vector<int>& myNewVector){
    cout << "Tu vector es: ";
    for(int i{0}; i < myNewVector.size(); i++){
        cout << myNewVector.at(i) << " ";
    }

    cout << endl;

}


int main()
{
    vector<int> myVector;

    fillVector(myVector);
    printVector(myVector);
    meanAndComprobationOfNumbers(myVector);



    return 0;
}
