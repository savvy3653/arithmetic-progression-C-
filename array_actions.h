#include <iostream>

inline void outArr(double* arr, const int size) // printing the array elements
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

double rangeArr(double* arr, const int size) // finding the range of progression
{
    if (size < 2)
    {
        std::cout << "Array has less than two elements." << std::endl;
        return -1;
    }

    int range = arr[1] - arr[0];
    return range;
}

double findN(double* arr, const int size, double num) // finding an element in progression
{
    double range = rangeArr(arr, size);
    if (range != -1)
        return arr[0] + rangeArr(arr, size) * (num - 1);
    else
        return -1;
}

inline double sumN(double* arr, const int size, double num) // summ of progression elements from 1st to specified element
{
    return ((arr[0] + findN(arr, size, num)) / 2) * num;
}
