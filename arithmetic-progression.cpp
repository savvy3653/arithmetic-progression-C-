#include <iostream>
#include <string>
#include <ctime>


void push_back(int*& oldArr, int& size, const int num) // push a value to array
{
    int* modArr = new int[size+1];

    for (int i = 0; i < size; i++)
        modArr[i] = oldArr[i];

    modArr[size] = num;
    size++;

    delete[] oldArr;
    oldArr = modArr;
}

void pop_out(int*& oldArr, int& size) // pop a value from array
{
    int* modArr = new int[size-1];

    for (int i = 0; i < size - 1; i++)
        modArr[i] = oldArr[i];

    size--;
    delete[] oldArr;
    oldArr = modArr;
}

void outArr(int* arr, const int size) // printing the array elements
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int rangeArr(int* arr, const int size) // finding the range of progression
{
    if (size < 2)
    {
        std::cout << "Too little of elements in array." << std::endl;
        return -1;
    }
    
    int range = arr[1] - arr[0];
    return range;
}

int findN(int* arr, const int size, int num) // finding an element in progression
{
    int range = rangeArr(arr, size);
    if (range != -1)
        return arr[0] + rangeArr(arr, size) * (num - 1);
    else
        return -1;
}

int sumN(int* arr, const int size, int num) // summ of progression elements from 1st to specified element
{
    return ((arr[0] + findN(arr, size, num)) / 2) * num;
}

int main(void) { // main func
    int size = 0, buff = 0;
    std::string strbuff;
    int* array = new int[size];

    while (std::getline(std::cin, strbuff))
    {
        if (strbuff == "push")
        {
            std::cin >> buff;
            push_back(array, size, buff);
            outArr(array, size);
        }
        else if (strbuff == "pop")
        {
            pop_out(array, size);
            outArr(array, size);
        }
        else if (strbuff == "range")
        {
            int range = rangeArr(array, size);
            if (range != -1)
                std::cout << range << std::endl;
        }
        else if (strbuff == "find")
        {
            std::cin >> buff;
            int n = findN(array, size, buff);
            if (n != -1)
                std::cout << n << std::endl;
        }
        else if (strbuff == "sum")
        {
            std::cin >> buff;
            int s = sumN(array, size, buff);
            if (s != -1)
                std::cout << s << std::endl;
        }
        else if (strbuff == "clear") // clear the full array
        {
            for (int i = size; i != 0; i--)
                pop_out(array, size);
            outArr(array, size);
        }
        else if (strbuff == "exit")
            break;
    }

    delete[] array;

    return 0;
}
