def factorial(num):
    res = 1
    for i in range(2, num+1):
       res *= i
    return res


sum = 0
for i in range(1, 10+1):
    sum += factorial(i)
print("1 + 2! + 3! + ...... + 10! =", sum)