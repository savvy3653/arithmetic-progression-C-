//#include <iostream>

void push_back(double*& oldArr, int& size, const double num) // push a value to array
{
    double* modArr = new double[size + 1];

    for (int i = 0; i < size; i++)
        modArr[i] = oldArr[i];

    modArr[size] = num;
    size++;

    delete[] oldArr;
    oldArr = modArr;
}

double pop_out(double*& oldArr, int& size) // pop a value from array
{
    if (size <= 0)
        return -1;
    double* modArr = new double[size - 1];

    for (int i = 0; i < size - 1; i++)
        modArr[i] = oldArr[i];

    size--;
    delete[] oldArr;
    oldArr = modArr;

    return 0;
}
