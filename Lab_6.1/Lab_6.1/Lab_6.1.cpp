// Лабораторна робота № 6.1 (ітераційний спосіб)
// Кучер, Софія
// Пошук елементів одновимірного масиву
// Варіант 8

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

// формування масиву випадковими числами з діапазону [Low, High]
void Create(int* b, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        b[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << b[i];
    cout << endl;
}

// кількість елементів, що задовольняють критерію
int Count(int* b, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (b[i] % 2 == 0 && b[i] <= 0)
            k++;
    return k;
}

// сума елементів, що задовольняють критерію
int Sum(int* b, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (b[i] % 2 == 0 && b[i] <= 0)
            S += b[i];
    return S;
}

// заміна нулями елементів, що задовольняють критерію
void Replace(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        if (b[i] % 2 == 0 && b[i] <= 0)
            b[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));    // ініціалізація генератора випадкових чисел

    const int n = 24;
    int b[n];

    int Low = -15;
    int High = 75;

    Create(b, n, Low, High);
    Print(b, n);

    cout << "Count = " << Count(b, n) << endl;
    cout << "Sum   = " << Sum(b, n) << endl;

    Replace(b, n);
    Print(b, n);

    return 0;
}
