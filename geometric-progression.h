#pragma once
#include <iostream>
#include <cmath>

/*
 * @file arithmetic-progression.h
 * @brief A class for performing arithmetic calculations with progressions.
 *
 * This header file contains `Arithmetic` class, which provides methods
 * to work with numeric arrays. The class includes functions for deriving an array by,
 * find the range of the progression, find the element of the progression, and calculate the sum
 * of a progression.
 *
 * All methods of the class work with arrays of double type.
 * 
*/

class Geometric
{
public:
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

        double range = arr[1] / arr[0]; // q = (An+1)/An
        return range;
    }

    double findN(double* arr, const int size, double num) // finding an element in progression
    {
        double range = rangeArr(arr, size);
        if (range != -1)
        {
            double a1 = arr[0];
            double q = pow(range, num - 1);

            return a1 * q;
        }
        else
            return -1;
    }

    double sumN(double* arr, const int size, double num) // summ of progression elements from 1st to specified element
    {
        double a1 = arr[0];
        double q = rangeArr(arr, size);
        double qn = pow(q, num);
        if (q != 1)
        {
            double div = (qn - 1) / (q - 1);
            return a1 * div;
        }
        else
            return num * a1;
    }

};