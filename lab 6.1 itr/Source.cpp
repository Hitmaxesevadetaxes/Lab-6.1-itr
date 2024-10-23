#include <iostream>
#include <iomanip> // дл€ форматованого виведенн€
#include <cstdlib> // дл€ rand() та srand()
#include <ctime>   // дл€ time()
#include <Windows.h>

// ‘ункц≥€ дл€ генерац≥њ випадкових чисел у масив≥
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// ‘ункц≥€ дл€ виведенн€ масиву
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// ‘ункц≥€ дл€ обчисленн€ к≥лькост≥ та суми елемент≥в, €к≥ задовольн€ють критер≥й
void countAndSumElements(const int arr[], int size, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < size; ++i) {
        if ((arr[i] > 0) && (arr[i] % 3 != 0)) {
            ++count;
            sum += arr[i];
        }
    }
}

// ‘ункц≥€ дл€ зам≥ни елемент≥в, €к≥ задовольн€ють критер≥й, на нул≥
void replaceWithZero(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if ((arr[i] > 0) && (arr[i] % 3 != 0)) {
            arr[i] = 0;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    const int size = 22;
    int arr[size];
    int count, sum;

    // ≤н≥ц≥ал≥зац≥€ генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // √енеруЇмо масив
    generateArray(arr, size, -10, 35);

    // ¬иводимо згенерований масив
    std::cout << "«генерований масив:\n";
    printArray(arr, size);

    // ќбчислюЇмо к≥льк≥сть та суму елемент≥в, що задовольн€ють критер≥ю
    countAndSumElements(arr, size, count, sum);

    // ¬иводимо к≥льк≥сть та суму
    std::cout << "„исло елемент≥в що задов≥льн€ють умови: " << count << std::endl;
    std::cout << "—ума цих елемент≥в: " << sum << std::endl;

    // «ам≥нюЇмо елементи, що задовольн€ють критер≥й, на нул≥
    replaceWithZero(arr, size);

    // ¬иводимо модиф≥кований масив
    std::cout << "«м≥ненений масив:\n";
    printArray(arr, size);


    return 0;
}
