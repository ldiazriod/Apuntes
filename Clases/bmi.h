#ifndef BMI_H
#define BMI_H

#include <iostream>

using namespace std;

class BMI
{
public:
    
    //Default Constructor
    BMI();
    
    //Overload Constructor
    BMI(string _name, int _height, double _weight);
    
    //Destructor
    ~BMI();
    
    //Accesor Functions
    string getName() const;   //Return name of patient
    int getHeight() const;    //Return height of patient
    double getWeight() const; //Return weight of patient
    
    //Mutator Functions
    void setName(const string &value);
    void setHeight(int value);
    void setWeight(double value);
    
    //Class Functions
    double calculateBMI();
    
private:
    //Member Varables   
    string name;
    int height;
    double weight;
    
};

#endif // BMI_H
