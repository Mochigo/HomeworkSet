words = input("please enter a sentence: ")
num = 0
character = 0
others = 0
for i in words:
    if '0' <= i <= '9':
        num += 1
    elif 'a' <= i <= 'z':
        character += 1
    else:
        others += 1
print("统计结果为")
print(words, "中共有", num, "个数字", character, "个英文字符", others, "个其它字符")


