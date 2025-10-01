#include <iostream>
#include <bitset>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int original_num,bit_number;
    
    

    cout << "Введите число: " << endl;
    cin >> original_num;

    cout << "Введите номер бита: " << endl;
    cin >> bit_number;

    if (bit_number < 0 or bit_number > 7)
    {
        cout << "Введи нормальное число, дурачок" << endl;
        return 0;
    }

    bitset<8> bitset = original_num;

    cout << original_num << " = " << bitset << endl;

    bool bit = bitset.test(bit_number);

    if (bit == 1)
    {
        bitset.flip(bit_number);
        cout << bitset << endl;
    }
    else if (bit == 0)
    {
        int a, b;
        cin >> a >> b;
       
        if (abs(a) > abs(b)){
            cout << a << a << endl;
        }
        
        
        else if (abs(a) < abs(b))
        {
            cout << b << b << endl; 
        }
    }


    int Number1, Number2;
    bool flag = false;

    cin >> Number1 >> Number2;

    if ((Number1 < 1 or Number1 > 9) or (Number2 < 1 or Number2 > 9)) 
    {
        cout << "Такого значения не существует" << endl;
        return 0;
    }

    cout << Number1 << Number2 << endl;

    if (Number1 == Number2) 
    {
        flag = true;
    }

    switch (flag)
    {
    case true:

        cout << "Дубль" << endl;
        break;

    case false:

        cout << "Не дубль" << endl;
        break;
    }



}

