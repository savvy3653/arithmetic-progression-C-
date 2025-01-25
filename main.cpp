//#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include "push_pop.h"
#include "arithmetic-progression.h"
#include "geometric-progression.h"
std::string strbuff;

double gpm_func(double* array, int& size);
double apm_func(double* array, int& size);


int main(void) {
    int size = 0;
    double* array = new double[size]; // initializing main dynamic array

    std::cout << "List of commands:\n" << "1. push {value}\n" << "2. pop\n" << "3. find {value}\n"
        << "4. range\n" << "5. sum {value}\n" << "6. clear\n" << "7. exit\n" << "(modes: gpm; apm)" << std::endl;
    std::cout << "Enter the mode: ";

    while (1)
    {

        std::getline(std::cin, strbuff);
        std::istringstream iss(strbuff);

        std::string command;
        //int value;

        iss >> command;

        if (command == "gpm") // gpm (geometric progression mode)
        {
            if (gpm_func(array, size) == 0)
                return 0;
            else
                return -1;
        }
        else if (command == "apm") // apm (arithmetic progression mode)
        {
            if (apm_func(array, size) == 0)
                return 0;
            else
                return -1;
        }
        else
            std::cout << "Please enter the mode." << std::endl;
    }


    delete[] array;

    return 0;
}

double gpm_func(double* array, int& size)
{
    Geometric geometric;

    while (1)
    {
        std::getline(std::cin, ::strbuff);
        std::istringstream iss(::strbuff);

        std::string command;
        double value;

        iss >> command;

        if (command == "exit")
            return 0;
        else if (command == "push" && iss >> value)
        {
            push_back(array, size, value);
            geometric.outArr(array, size);
        }

        else if (command == "pop")
        {
            if (pop_out(array, size) != -1)
                geometric.outArr(array, size);
            else
                std::cout << "Array has less than one element!" << std::endl;
        }

        else if (command == "range")
        {
            double range = geometric.rangeArr(array, size);
            if (range != -1)
                std::cout << range << std::endl;
        }

        else if (command == "find" && iss >> value)
        {
            double n = geometric.findN(array, size, value);
            if (n != -1)
                std::cout << n << std::endl;
        }

        else if (command == "sum" && iss >> value)
        {
            double s = geometric.sumN(array, size, value);
            if (s != -1)
                std::cout << s << std::endl;
        }

        else if (command == "clear")
        {
            for (int i = size; i != 0; i--)
                pop_out(array, size);
            geometric.outArr(array, size);
        }
        else if (command == "apm")
        {
            apm_func(array, size);
            break;
        }
        else
        {
            std::cout << "Please enter the correct function." << std::endl;
            continue;
        }
    }

    return 0;
}

double apm_func(double* array, int& size)
{
    Arithmetic arithmetic;

    while (1)
    {
        std::getline(std::cin, ::strbuff);
        std::istringstream iss(::strbuff);

        std::string command;
        double value;

        iss >> command;

        if (command == "exit")
            return 0;
        else if (command == "push" && iss >> value)
        {
            push_back(array, size, value);
            arithmetic.outArr(array, size);
        }

        else if (command == "pop")
        {
            if (pop_out(array, size) != -1)
                arithmetic.outArr(array, size);
            else
                std::cout << "Array has less than one element!" << std::endl;
        }

        else if (command == "range")
        {
            double range = arithmetic.rangeArr(array, size);
            if (range != -1)
                std::cout << range << std::endl;
        }

        else if (command == "find" && iss >> value)
        {
            double n = arithmetic.findN(array, size, value);
            if (n != -1)
                std::cout << n << std::endl;
        }

        else if (command == "sum" && iss >> value)
        {
            double s = arithmetic.sumN(array, size, value);
            if (s != -1)
                std::cout << s << std::endl;
        }

        else if (command == "clear")
        {
            for (int i = size; i != 0; i--)
                pop_out(array, size);
            arithmetic.outArr(array, size);
        }
        else if (command == "gpm")
        {
            gpm_func(array, size);
            break;
        }
        else
        {
            std::cout << "Please enter the correct function." << std::endl;
            continue;
        }
    }

    return 0;
}
