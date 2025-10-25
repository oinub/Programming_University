#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "russian");
    
    
    int numbers[10];
    cout << "Введите 10 целых чисел:\n";  
    cout << "Введите число 1: ";
    for (int i = 0; i < 10; ++i)  
    {
        if (i > 0) {
            cout << "Введите число " << i + 1 << ": ";  
        }
        std::cin >> numbers[i];  
    }

    int len = sizeof(numbers) / sizeof(numbers[0]) - 1;  

    if (numbers[0] > numbers[len])  
    {
        for (int i = 0; i < 10 - 1; i++) {
            for (int j = 0; j < 10 - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    std::swap(numbers[j], numbers[j + 1]);
                }


            }
        }
    }

    cout << "Результирующий массив: ";
    for (int i = 0; i < 10; ++i)  
    {
        cout << numbers[i] << " ";  
    }
    cout << endl;
    

    int M[3][4] = { 0 };
    cout << "\nВведите элементы матрицы 3x4 (12 чисел):" << endl;
 
    for (int i = 0; i < 3; ++i)
    {
        cout << "Строка " << i + 1 << " (4 числа через пробел или Enter): " << endl;
        for (int j = 0; j < 4; ++j)
        {
            std::cin >> M[i][j];
        }
    }

    cout << "\nВведенная матрица:" << endl;
   
    for (int i = 0; i < 3; ++i)
    {
        cout << endl;
        for (int j = 0; j < 4; ++j) 
        {
            cout << M[i][j] << " ";
        }
    }
    cout << endl;

    int summ[4] = { 0 };
    for (int j = 0; j < 4; ++j)
    {
        for (int(i) = 0; i < 3; ++i) 
        {
            summ[j] += M[i][j];
        }
    }

    cout << "\nСуммы столбцов матрицы:" << endl;
    cout << "Столбец 1: " << summ[0] << endl;
    cout << "Столбец 2: " << summ[1] << endl;
    cout << "Столбец 3: " << summ[2] << endl;  
    cout << "Столбец 4: " << summ[3] << endl;  


    int max_index = 0;

    for (int i = 1; i < 4; ++i) {
        if (summ[i] > summ[max_index]) {
            max_index = i;
        }
    }

    for (int i = 0; i < 3; i++) 
    {
        M[i][max_index] = 0;
    }
    
    cout << "Результирующая матрица M:" << endl;
    cout << endl;

    for (int i = 0; i < 3; ++i)
    {
        cout << endl;
        for (int j = 0; j < 4; ++j)
        {
            cout << M[i][j] << " ";
        }
    }
}