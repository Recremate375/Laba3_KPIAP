#include "Functions.h"

using namespace std;

int input_int(int min, int max)
{
    int i;
    bool fail = true;
    do
    {
        cin >> i;
        if (cin.fail() || i > max || i < min)
            cout << "Error" << endl;
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

double input_double(double min, double max)
{
    double i;
    bool fail = true;
    do
    {
        cin >> i;
        if (cin.fail() || i > max || i < min)
            cout << "Error" << endl;
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}
