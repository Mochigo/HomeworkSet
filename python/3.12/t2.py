def isprime(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True


n = int(input("请输入一个正整数: "))
res = str(n)+"="
while n != 1:
    for i in range(2, n+1):
        # 如果 i 是素数 并且 n 能被 i 整除
        while isprime(i) and n % i == 0:
            if n / i != 1:
                res = res + str(i) + "*"
            else:
                res = res + str(i)
            n /= i
print(res)
