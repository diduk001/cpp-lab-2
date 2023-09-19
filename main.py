def double_factorial(x):
    res = 1
    for i in range(x, 0, -2):
        res *= i
    return res

def get_t(x):
    numerator = sum(pow(x, 2 * k + 1) / double_factorial(2 * k + 1) for k in range(11))
    denominator = sum(pow(x, 2 * k) / double_factorial(2 * k) for k in range(11))
    return numerator / denominator

def f(y):
    numerator = (7 * get_t(0.25) + 2 * get_t(1 + y))
    denominator = (6 - get_t(y * y - 1))
    return numerator / denominator

if __name__ == '__main__':
    print("y\t| f(y)")
    print('-' * 30)
    for y in range(-9, 11):
        print(f"{y}\t| {f(y)};")