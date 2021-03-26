import sys

length = 5


def is_number(c):
    if '0' <= c <= '9':
        return True
    return False


num = input("请输入一个五位数字: ")
if len(num) != length:
    print("长度输入错误")
    sys.exit(0)
for i in range(0, len(num)//2):
    if is_number(num[i]) and is_number(num[length - i - 1]):
        if num[i] == num[length - i - 1]:
            continue
        else:
            print("不是回文数")
            sys.exit(0)
    else:
        print("出现非法字符")
        sys.exit(0)
if is_number(num[len(num)//2]):
    print("该数字是回文数")
else:
    print("出现非法字符")
