def hanoi(n, a, b, c):
    if n == 1:
        print(a, "->", c)
        return
    hanoi(n-1, a, c, b)
    print(a, "->", c)
    hanoi(n-1, b, a, c)
    return


num = int(input("请输入汉诺塔层数:"))
A, B, C = 'A', 'B', 'C'
hanoi(num, A, B, C)

