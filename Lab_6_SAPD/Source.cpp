#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class BubbleSort 
{
private:
    int* array;
    int size;

public:
    BubbleSort(int size) 
    {
        if (size <= 0) 
            throw std::invalid_argument("Array size must be positive");
        

        this->size = size;
        this->array = new int[size];
    }

    ~BubbleSort() 
    {
        delete[] array;
    }

    void fillArrayRandomly(int minValue, int maxValue) 
    {
        if (minValue >= maxValue) 
            throw std::invalid_argument("Invalid range");
        

        srand(time(nullptr));

        for (int i = 0; i < size; i++) 
            array[i] = rand() % (maxValue - minValue) + minValue;
        
    }

    void bubbleSort() 
    {
        for (int i = 0; i < size - 1; i++) 
            for (int j = 0; j < size - i - 1; j++) 
                if (array[j] > array[j + 1]) 
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            
        
    }

    void printArray() 
    {
        for (int i = 0; i < size; i++) 
            std::cout << array[i] << " ";
        
        std::cout << std::endl;
    }
};



int main() 
{
    srand(time(NULL));

    try 
    {
        int size = 0;
        int minValue = -100;
        int maxValue = 100;

        BubbleSort bubbleSort(size);
        bubbleSort.fillArrayRandomly(minValue, maxValue);

        std::cout << "Original Array: ";
        bubbleSort.printArray();

        bubbleSort.bubbleSort();

        std::cout << "Sorted Array: ";
        bubbleSort.printArray();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}