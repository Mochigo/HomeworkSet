def gcd(x, y):
    if x < y:
        tmp = x
        x = y
        y = tmp
    while y != 0:
        c = x % y
        x = y
        y = c
    return x


a = int(input("Please enter number one:"))
b = int(input("Please enter number two:"))
print("最大公约数为", gcd(a, b))
print("最小公倍数为", a*b/gcd(a, b))

