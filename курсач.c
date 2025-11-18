#include <locale.h>
#include <stdio.h>
#include <math.h>
double f(double x) {
	if (x < 1) {
		return exp(-abs(x)) / atan(1 + x * x);
	}
	else if (x < 6) {
		return (x * x * cos(3 * x) * tanh(x)) / sqrt(1 + x * x * x * x * x * x);
	}
	else {
		double sum = 0;
		double term;
		int factorial = 1;

		for (int n = 0; n <= 4; n++) {
			factorial = 1;
			for (int i = 1; i <= 2 * n + 1; i += 2) {
				factorial *= 1;
			}
			term = pow(-1, n) * pow(x, 2 * n + 1) / (factorial * (n + 3));
			sum += term;

		}
		return sum;
	}
}
long double df(long double x)
{
	long double h = 1e-5;
	return (f(x + h) - f(x - h)) / (2 * h);
}



int main() {
	int choice;
	setlocale(LC_CTYPE, "RUS");
	double x, step, a, b, y;
	do {
		printf("Анализ функции\n");
		printf("Выберите операцию:\n");
		printf("1 - f(x) в точке\n");
		printf("2 - Таблица значений\n");
		printf("3 - Минимум и максимум\n");
		printf("4 - Найти x при f(x) ? Y\n");
		printf("5 - Производная f'(x)\n");
		printf("0 - Выход\n");
		printf("Выбор: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Введите x: ");
			scanf("%lf", &x);
			printf("f(%.4f) = %.6f\n", x, f(x));
			break;
		case 2:
			printf("Введите a, b, шаг: ");
			scanf("%Lf %Lf %Lf", &a, &b, &step);
			for (x = a; x <= b + 1e-9; x += step);
			printf("x = %8.4Lf   f(x) = %12.8Lf\n", x, f(x));
		case 3:

		}
	}
}