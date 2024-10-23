#include <iostream>
#include <iomanip> // ��� ������������� ���������
#include <cstdlib> // ��� rand() �� srand()
#include <ctime>   // ��� time()
#include <Windows.h>

// ������� ��� ��������� ���������� ����� � �����
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// ������� ��� ��������� ������
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// ������� ��� ���������� ������� �� ���� ��������, �� ������������� �������
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

// ������� ��� ����� ��������, �� ������������� �������, �� ���
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

    // ����������� ���������� ���������� �����
    srand(static_cast<unsigned>(time(0)));

    // �������� �����
    generateArray(arr, size, -10, 35);

    // �������� ������������ �����
    std::cout << "������������ �����:\n";
    printArray(arr, size);

    // ���������� ������� �� ���� ��������, �� ������������� �������
    countAndSumElements(arr, size, count, sum);

    // �������� ������� �� ����
    std::cout << "����� �������� �� ������������ �����: " << count << std::endl;
    std::cout << "���� ��� ��������: " << sum << std::endl;

    // �������� ��������, �� ������������� �������, �� ���
    replaceWithZero(arr, size);

    // �������� ������������� �����
    std::cout << "��������� �����:\n";
    printArray(arr, size);


    return 0;
}
