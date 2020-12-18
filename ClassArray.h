#include<iostream>

class Array
{
private:
    double *arr_;
    int size_;
public:
    Array();
    Array(int);
    Array(Array&);
    Array& operator ++();
    Array operator &(const Array&);
    int get_size();
    void push_back(double);
    void set_size(int);
    void set_element(int, double);
    double get_element(int);
    void output();
    friend Array & operator + (const Array&, const Array&);
    friend Array operator - (const Array&, const Array&);
    friend Array operator - (const Array&, const int*);
    void sort();
    ~Array();

};