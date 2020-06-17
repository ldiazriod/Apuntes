#include "bmi.h"

//Constructor and destructor
BMI::BMI()
{

}

BMI::BMI(string _name, int _height, double _weight){
    name = _name;
    height = _height;
    weight = _weight;
}

BMI::~BMI(){
    
}

//Accessor Functions
string BMI::getName() const
{
    return name;
}

int BMI::getHeight() const
{
    return height;
}

double BMI::getWeight() const
{
    return weight;
}

//Mutator Functions
void BMI::setName(const string &value)
{
    name = value;
}

void BMI::setHeight(int value)
{
    height = value;
}

void BMI::setWeight(double value)
{
    weight = value;
}

//Class Functions
double BMI::calculateBMI()
{
    return ((weight * 703)/ (height * height));
}
