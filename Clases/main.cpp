#include <iostream>

#include "bmi.h"

using namespace std;



int main()
{
    string name;
    double weight;
    int height;
    
    cout << "Mete tu nombre: ";    
    cin >> name;
    
    cout << "mete tu altura: ";
    cin >> height;
    
    cout << "Mete tu peso: ";
    cin >> weight;
    
    //Overloaded Constructor
    BMI Student_1(name, height, weight);
    
    cout << endl;
    cout << "Patient Name: " << Student_1.getName() << endl;
    cout << "Patient height: " << Student_1.getHeight() << endl;
    cout << "Patient weight: " << Student_1.getWeight() << endl;
    
    //Default Constructor
    BMI Student_2;
    
    Student_2.setName(name);
    Student_2.setHeight(height);
    Student_2.setWeight(weight);
    
    cout << endl;
    cout << "Patient Name: " << Student_2.getName() << endl;
    cout << "Patient height: " << Student_2.getHeight() << endl;
    cout << "Patient weight: " << Student_2.getWeight() << endl;
    cout << "Patient BMI: " << Student_2.calculateBMI() << endl;
    
    
    return 0;
}
