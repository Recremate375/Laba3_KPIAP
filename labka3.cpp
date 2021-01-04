#include <iostream>

#include "ClassArray.h"
#include "Function.h"

using namespace std;

int main()
{
    int choice_1 = 1;
    Array arr1;
    Array arr2(3);
    int choice;
    while (choice_1)
    {
        cout << "Enter the element of the array." << endl;
        double element;
        element = input_double();
        arr1.push_back(element);
        cout << "Do you want to add one more element? \n 1 - yes; \n 0 - no;" << endl;
        choice_1 = input_int();
    }
    cout << "The first array: " << endl;
    arr1.output();
    choice_1 = 1;
    cout << "Enter the element's of the second array: " << endl;
    for (int i = 0; i < arr2.get_size(); i++)
    {
        double element;
        element = input_double();
        arr2.set_element(i, element);
    }
    arr2.output();
    Array arr3(arr2);
    arr3.output();
    do
    {
        cout << "Enter the number of operation do you want to do. \n 1 - Output; \n 2 - Enter the element to the end of the array; " <<
            "\n 3 - increment operation; \n 4 - Subtraction; \n 5 - Addition; \n 6 - Get element of array; \n 7 - change the element of array" <<
            "\n 8 - crossing operation (&);\n 9 - Create the array of object's; \n 10 - Create the dinam copy of object; \n 0 - exit;" << endl;
        choice = input_int();
        switch (choice)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            int choice_3;
            cout << "What array do you want to see?" << endl;
            choice_3 = input_int();
            switch (choice_3)
            {
            case 1:
            {
                arr1.output();
                break;
            }
            case 2:
            {
                arr2.output();
            }
            case 3:
            {
                arr3.output();
            }
            }
            break;
        }
        case 2:
        {
            cout << "What object do you want to add the element to?" << endl;
            int choice_3;
            choice_3 = input_int();
            switch (choice_3) {
                double element;
            case 1:
            {
                cout << "Enter the element of the first array: " << endl;
                element = input_double();
                arr1.push_back(element);
                break;
            }
            case 2:
            {
                cout << "Enter the element of the second array: " << endl;
                element = input_double();
                arr2.push_back(element);
                break;
            }
            case 3:
            {
                cout << "Enter the element of the third array: " << endl;
                element = input_double();
                arr3.push_back(element);
                break;
            }
            break;
            }
            break;
        }
        case 3:
        {
            cout << "What array do you want to incremate?" << endl;
            int choice_2;
            choice_2 = input_int();
            switch (choice_2)
            {
            case 1:
            {
                arr1.output();
                ++arr1;
                cout << "Incremating" << endl;
                arr1.output();
                break;
            }
            case 2:
            {
                arr2.output();
                ++arr2;
                cout << "Incremating" << endl;
                arr2.output();
                break;
            }
            case 3:
            {
                arr3.output();
                ++arr3;
                cout << "Incremating" << endl;
                arr3.output();
                break;
            }
            }
            break;
        }
        case 4:
        {
            Array A;
            A = arr1 - arr2;
            break;
        }
        case 5:
        {
            Array A;
            A = arr1 + arr2;
            break;
        }
        case 6:
        {
            cout << "Choose the array." << endl;
            int choice_2;
            int element;
            choice_2 = input_int();
            switch (choice_2)
            {
            case 1:
            {
                cout << "What element from the first array do you want to get?" << endl;
                element = input_int();
                arr1.get_element(element);
                break;
            }
            case 2:
            {
                cout << "What element from the second array do you want to get?" << endl;
                element = input_int();
                arr2.get_element(element);
                break;
            }
            case 3:
            {
                cout << "What element from the third array do you want to get?" << endl;
                element = input_int();
                arr3.get_element(element);
                break;
            }
            }
            break;
        }
        case 7:
        {
            cout << "Choose the array " << endl;
            int choice_2;
            double element;
            choice_2 = input_int();
            switch (choice_2)
            {
            case 1:
            {
                cout << "What element do you want to change?" << endl;
                int change;
                change = input_int();
                cout << "Enter the element" << endl;
                element = input_double();
                arr1.set_element(change, element);
                break;
            }
            case 2:
            {
                cout << "What element do you want to change?" << endl;
                int change;
                change = input_int();
                cout << "Enter the element" << endl;
                element = input_double();
                arr2.set_element(change, element);
                break;
            }
            case 3:
            {
                cout << "What element do you want to change?" << endl;
                int change;
                change = input_int();
                cout << "Enter the element" << endl;
                element = input_double();
                arr3.set_element(change, element);
                break;
            }
            }
            break;
        }
        case 8:
        {
            Array A;
            A = arr1 & arr2;
            A.output();
            break;
        }
        case 9:
        {
             Array* arr4 = new Array[1];
             while (choice_1)
             {
                 cout << "Enter the element of the array." << endl;
                 double element;
                 element = input_double();
                 arr4->push_back(element);
                 cout << "Do you want to add one more element? \n 1 - yes; \n 2 - no;" << endl;
                 choice_1 = input_int();
             }
             arr4->output();
             Array arr5(*arr4);
             arr5.output();
             arr4->operator++();
             arr4->output();
             arr5.output();
             cout << "Destructor" << endl;
             arr4->~Array();
             cout << "Destructor" << endl;
             arr5.~Array();
             delete[1] arr4;
             break;
        }
         case 10:
          {
              cout << "Enter the size of array: ";
              int size;
              size = input_int();
              Array *arr5 = new Array[size];
              cout << endl;
              int choice_2 = 1;
              for (int i = 0; i < size; i++)
              {
                  do
                  {
                      cout << "Enter the element of the array." << endl;
                      double element;
                      element = input_double();
                      arr5[i].push_back(element);
                      cout << "Do you want to add one more element? \n 1 - yes; \n 0 - no;" << endl;
                      choice_2 = input_int();
                  } while (choice_2 != 0);
              }
              cout << "Choose the element, which you want to receive." << endl;
              cout << ">>";
              int choose;
              choose = input_int();
              choose--;
              arr5[choose].output();
              for (int i = 0; i < size; i++)
              {
                  arr5[i].~Array();
              }
              delete[] arr5;
              break;
          }
        }
    } while (choice_1);
}