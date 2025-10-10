#include <iostream>
#include <bitset>

int main() 
{
    setlocale(LC_ALL, "Russian"); // добавление русского языка
    using namespace std; // вызов команды std чтобы не вызывать ее в ручную
    cout << "Первая часть: " << endl;
    int original_num,bit_number, decimal_num; // целые числа
    
    cout << "Введите число: " << endl;
    cin >> original_num; // ввод числа с клавиатуры

    bitset<8> bitset = original_num; // перевод числа в двоичную запись с 8 разрядами

    cout << original_num << " = " << bitset << endl; // вывод двочной записи числа

    cout << "Введите номер бита: " << endl;
    cin >> bit_number; // ввод числа с клавиатуры

    if (bit_number < 0 or bit_number > 7) // проверка корректности номера бита
    {
        cout << "Введи нормальное число, дурачок" << endl; // вывод в случае неправильного ввода
        return 0;
    }

    bool bit = bitset.test(bit_number); // нахождение значения выбранного бита

    if (bit == 1)
    {
        cout << "Подравляю, выбранный бит равен 1" << endl;
        bitset.flip(bit_number); // инверсия выбранного бита с 1 на 0
        decimal_num = bitset.to_ulong(); // обратный перевод в десятичную
        cout << bitset << " = " << decimal_num << endl; // вывод получившегося числа
    }
    else if (bit == 0)
    {
        cout << "Выбранный бит равен 0, в наказание вводите 2 числа: " << endl;
        int a, b; // целые числа
        cin >> a >> b; // ввод с клавиатуры
       
        if (abs(a) > abs(b))
        {
            cout << a << a << endl; // вывод большего числа дважды без пробелов
        }
        
        
        else if (abs(a) < abs(b)) 
        {
            cout << b << b << endl; // вывод большего числа дважды без пробелов
        }
    }

    cout << "Вторая часть: " << endl;
    int Number1, Number2; // целые числа
    bool flag = false; // ввод значиения флага

    cout << "Введите две цифры" << endl;
    cin >> Number1 >> Number2; // ввод чисел с клавиатуры

    if ((Number1 < 1 or Number1 > 9) or (Number2 < 1 or Number2 > 9)) // проверка на правильнось ввода
    {
        cout << "Я же сказал цифры, дурачок" << endl; // в случае неправильного ввода
        return 0;
    }

    cout << Number1 << Number2 << endl; // вывод двух цифр слитно

    if (Number1 == Number2) // проверка равенства
    {
        flag = true; // присвоение значения true
    }

    switch (flag)
    {
    case true: // если flag принял значение true

        cout << "Дубль" << endl; // вывод надписи
        break;

    case false: // если flag принял значение false

        cout << "Не дубль" << endl; // вывод надписи
        break;
    }
}