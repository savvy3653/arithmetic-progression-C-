//#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include "push_pop.h"
#include "array_actions.h"


int main(void) {
    int size = 0;
    std::string strbuff;
    double* array = new double[size]; // initializing new dynamic array

    std::cout << "List of commands:\n" << "1. push {value}\n" << "2. pop\n" << "3. find {value}\n"
              << "4. range\n" << "5. sum {value}\n" << "6. clear\n" << "7. exit" << std::endl;

    while (1)
    {
        std::getline(std::cin, strbuff);
        std::istringstream iss(strbuff);

        std::string command;
        int value;

        iss >> command;

        if (command == "exit")
            break;
        else if (command == "push" && iss >> value)
        {
            push_back(array, size, value);
            outArr(array, size);
        }
        else if (command == "pop")
        {
            if (pop_out(array, size) != -1)
                outArr(array, size);
            else
                std::cout << "Array has less than one element!" << std::endl;
        }
        else if (command == "range")
        {
            int range = rangeArr(array, size);
            if (range != -1)
                std::cout << range << std::endl;
        }
        else if (command == "find" && iss >> value)
        {
            int n = findN(array, size, value);
            if (n != -1)
                std::cout << n << std::endl;
        }
        else if (command == "sum" && iss >> value)
        {
            int s = sumN(array, size, value);
            if (s != -1)
                std::cout << s << std::endl;
        }
        else if (command == "clear")
        {
            for (int i = size; i != 0; i--)
                pop_out(array, size);
            outArr(array, size);
        }
    }

    delete[] array;

    return 0;
}
