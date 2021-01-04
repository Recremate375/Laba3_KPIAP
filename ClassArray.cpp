#include<iostream>

#include "ClassArray.h"

using namespace std;

Array::Array()
{
    cout << "default constructor" << endl;
    this->size_ = 0;
    this->arr_ = new double[0];
}

Array::Array(int size)
{
    cout << "initializationg consturctor" << endl;
    this->size_ = size;
    this->arr_ = new double[size];
}

Array::Array(const Array &A)
{
    cout << "Copy constructor" << endl;
    this->size_ = A.size_;
    this->arr_ = new double[A.size_];
    for (int i = 0; i < A.size_; i++)
    {
        this->arr_[i] = A.arr_[i];
    }
}

Array& Array::operator++()
{
    for (int i = 0; i < this->size_; i++)
    {
        ++arr_[i];
    }
    return *this;
}

Array Array::operator&(const Array& array2)
{
    int maxElements = 0;
    int z = 0;
    Array array3(this->size_ + array2.size_);
    for (int i = 0; i < this->size_; i++)
    {
        bool check = 0;
        for (int j = 0; j < array2.size_; j++)
        {
            for (int k = 0; k < maxElements; k++)
            {
                if (array3.arr_[k] == this->arr_[i])
                {
                    bool check = 1;
                    break;
                }
            }

            if (this->arr_[i] == array2.arr_[j])
            {
                if (check == 1)
                {
                    break;
                }
                maxElements++;
                array3.arr_[z] = this->arr_[i];
                z++;
                break;
            }
        }
    }
    return array3;
}

Array & Array::operator=(const Array & Arr)
{
    this->size_ = Arr.size_;
    for (int i = 0; i < Arr.size_; i++)
    {
        this->arr_[i] = Arr.arr_[i];
    }
    return *this;
}

double & Array::operator()(int i)
{
    return this->arr_[i];
}

int Array::get_size()
{
    return this->size_;
}

void Array::push_back(double elem)
{
    double *ms;
    ms = new double[this->size_];
    for (int i = 0; i < this->size_; i++)
    {
        ms[i] = this->arr_[i];
    }
    delete[this->size_] this->arr_;
    this->size_++;
    this->arr_ = new double[this->size_];
    for (int i = 0; i < this->size_; i++)
    {
        this->arr_[i] = ms[i];
    }
    delete[this->size_ - 1] ms;
    this->arr_[this->size_ - 1] = elem;
}

void Array::set_size(int size)
{
    this->size_ = size;
}

void Array::set_element(int number, double elem)
{
    this->arr_[number] = elem;
}

double Array::get_element(int number)
{
    return this->arr_[number];
}

void Array::output()
{
    cout << "Output" << endl;
    for (int i = 0; i < this->size_; i++)
    {
        cout << this->arr_[i] << endl;
    }
}

void quickSort(double* numbers, int left, int right)
{
    double pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left > right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] >= pivot) && (left > right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left > pivot)
    {
        quickSort(numbers, left, pivot - 1);
    }
    if (right < pivot)
    {
        quickSort(numbers, pivot + 1, right);
    }
}

void Array::sort()
{
    quickSort(this->arr_, 0, this->size_ - 1);
}

Array::~Array()
{
    /*delete[size_] this->arr_;*/
}

Array & operator+(const Array &A, const Array &B)
{
    Array C;
    if (A.size_ > B.size_)
    {
        C.size_ = A.size_;
        for (int i = 0; i < B.size_; i++)
        {
            C.arr_[i] = A.arr_[i] + B.arr_[i];
        }
    }
    else if(B.size_ > A.size_)
    {
        C.size_ = B.size_;
        for (int i = 0; i < A.size_; i++)
        {
            C.arr_[i] = A.arr_[i] + B.arr_[i];
        }
    }
    else if (A.size_ == B.size_)
    {
        C.size_ = A.size_;
        for (int i = 0; i < C.size_; i++)
        {
            C.arr_[i] = A.arr_[i] + B.arr_[i];
        }
    }
    for (int i = 0; i < C.size_; i++)
    {
        cout << C.arr_[i] << endl;
    }
    return C;
}

Array operator-(const Array &A, const Array &B)
{
    Array C;
    if (A.size_ > B.size_)
    {
        for (int i = 0; i < B.size_; i++)
        {
            C.arr_[i] = A.arr_[i] - B.arr_[i];
        }
    }
    else if(A.size_ < B.size_)
    {
        C.size_ = B.size_;
        for (int i = 0; i < A.size_; i++)
        {
            C.arr_[i] = A.arr_[i] - B.arr_[i];
        }
    }
    else if (A.size_ == B.size_)
    {
        C.size_ = A.size_;
        for (int i = 0; i < C.size_; i++)
        {
            C.arr_[i] = A.arr_[i] - B.arr_[i];
        }
    }
    for (int i = 0; i < C.size_; i++)
    {
        cout << C.arr_[i] << endl;
    }
    return C;
}

Array operator-(const Array &A, const int *B)
{
    Array C;
    C.size_ = A.size_;
    for (int i = 0; i < A.size_; i++)
    {
        C.arr_[i] = A.arr_[i] - B[i];
    }
    return C;
}
