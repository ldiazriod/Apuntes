#ifndef LIST_H
#define LIST_H

#endif // LIST_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class list{
public:
    list(){}
    ~list(){}
    void push_back(T const &d);
    void push_front(T const &d);
    void insert(T const &d, int pos);
    void erase(int pos);
    int devolverReferencia(int pos);
    T search(T const &d);
    list<T> filter();
    vector<T> getData() const;
    void setData(const vector<T> &value);

private:

    vector<T> data;


};
template<class T>
void list<T>::push_back(const T &d){
    data.push_back(d);
}
template<class T>
void list<T>::push_front(const T &d){
    data.insert(data.begin(), d);
}
template<class T>
void list<T>::insert(const T &d, int pos){
    if(pos >= data.size() || pos < 0 ){
        throw string {"No existen tantas posiciones"};
    }

    data.insert(data.begin() + pos, d);
}
template<class T>
void list<T>::erase(int pos){
    if(pos >= data.size() || pos < 0){
        throw string {"No existen tantas posiciones"};
    }
    data.erase(data.begin() + pos);
}
template<class T>
int list<T>::devolverReferencia(int pos){
    T *n;
    for(int i{0}; i < data.size(); i++){
        if(i == pos){
            n = &data.at(i);
            cout << n << endl;
        }
    }
}
template<class T>
T list<T>::search(const T &d){
    for(int i{0}; i < data.size(); i++){
        if(data.at(i) == d){
            cout << "Aqui esta lo que buscabas: " << i << endl;
        }
    }
}
template<class T>
list<T> list<T>::filter(){

}
template<class T>
vector<T> list<T>::getData() const
{
    return data;
}
template<class T>
void list<T>::setData(const vector<T> &value)
{
    data = value;
}

template <class T>
ostream & operator<<(ostream &os, list<T> p){
    auto data = p.getData();
    for(auto elem: data){
        os << elem << "  --  ";
    }
    return os;
}
