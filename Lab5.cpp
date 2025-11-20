#include <iostream>
#include <math.h>

double avg(int num1, int num2) 
{
	std::cout << "Нахождение среднего из 2-х чисел" << std::endl;
	return float(num1 + num2) / 2;
}
double avg(int num1, int num2, int num3) 
{
	std::cout << "Нахождение среднего из 3-х чисел" << std::endl;
	return float(num1 + num2 + num3) / 3;
}
void lab1(int x) 
{
	int q, z;
	float y;

	q = x * x;
	z = pow(x, 5);
	y = 1 / float(x);

	std::cout << "Int: " << "Минимальное значение: " << INT_MIN << " Максимальное значение: " << INT_MAX << " Количесво бит: " << sizeof(int) * 8 << std::endl;
	std::cout << "Float: " << "Минимальное значение: " << FLT_MIN << " Максимальное значение: " << FLT_MAX << " Количесво бит: " << sizeof(float) * 8 << std::endl;
	std::cout << std::endl;

	std::cout << "x во 2 степени: " << q << std::endl;
	std::cout << "x в 5 степени: " << z << std::endl;
	std::cout << "обратное число: " << y << std::endl;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	int point;

	std::cout << "Выберите первый или второй пункт: " << std::endl;
	std::cin >> point;

	if ((point < 1) or (point > 2)) 
	{
		std::cout << "Такого пункта не сущетвует" << std::endl;
 		return 0;
	}

	if (point == 1) 
	{
		int num1, num2, num3;
		int cnt = 0;
		double res;

		std::cout << "Введите 3 числа:" << std::endl;

		std::cin >> num1 >> num2 >> num3;

		if (num1 != 0) 
		{
			cnt += 1;
		}
		if (num2 != 0) 
		{
			cnt += 1;
		}
		if (num3 != 0) 
		{
			cnt += 1;
		}

		if (cnt == 2) 
		{
			if (num1 == 0) 
			{
				res = avg(num2, num3);
				std::cout << res;
			}
			if (num2 == 0) 
			{
				res = avg(num1,num3);
				std::cout << res;
			}
			if (num3 == 0) 
			{
				res = avg(num1, num2);
				std::cout << res;
			}
		}
		if (cnt == 3) 
		{
			res = avg(num1, num2, num3);
			std::cout << res;
		}
	}
	if (point == 2) 
	{
		int x, q, z;
		float y;

		std::cout << "Введите любое значеие X кроме 0: " << std::endl;
		std::cin >> x;

		if (x == 0)
		{
			return 0;
		}
		lab1(x);
	}
	return 0;
}
