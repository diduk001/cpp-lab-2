#include <stdio.h>

// pow(base, power) = base**power
long double pow(long double base, int power)
{
  long double result = 1;
  for (int i = 0; i < power; i++)
  {
    result *= base;
  }
  return result;
}

// double_factorial(initial_value) = initial_value!!
long double double_factorial(long double initial_value)
{
  long double result = 1;
  for (int k = initial_value; k > 0; k -= 2)
  {
    result *= k;
  }
  return result;
}

// getT(x) = t(x)
long double getT(long double x)
{
  long double numerator = 0; // Общий числитель
  for (int k = 0; k <= 10; k++)
  {
    long double sum_numerator = pow(x, 2 * k + 1);             // Суммируемый числитель
    long double sum_denominator = double_factorial(2 * k + 1); // Суммируемый знаменатель

    numerator += sum_numerator / sum_denominator;
  }

  long double denominator = 0; // Общий знаменатель
  for (int k = 0; k <= 10; k++)
  {
    long double sum_numerator = pow(x, 2 * k);             // Суммируемый числитель
    long double sum_denominator = double_factorial(2 * k); // Суммируемый знаменатель

    denominator += sum_numerator / sum_denominator;
  }

  return numerator / denominator;
}

// Требуемая функция
long double getResult(long double y)
{
  long double numerator = 7 * getT(0.25) + 2 * getT(1 + y); // Числитель
  long double denominator = 6 - getT(y * y - 1);            // Знаменатель

  return numerator / denominator;
}

int main()
{
  long double y;
  printf("Введите y > ");
  scanf("%Lf", &y);

  long double result = getResult(y);
  printf("Результат: %.10Lf\n", result);
}