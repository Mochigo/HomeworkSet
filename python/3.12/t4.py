count = 0
for i in range(1,4+1):
    for j in range(1, 4+1):
        for k in range(1, 4+1):
            if i != j and j != k and k != i:
                print(100*i+10*j+k)
                count += 1
print("共有", count, "个无重复的三位数")