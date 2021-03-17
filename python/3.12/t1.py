grade = int(input("please enter your grade: "))
level = ""
if grade > 100 or grade < 0:
    level = "成绩无效"
elif grade >= 90:
    level = "A"
elif grade >= 70:
    level = "B"
elif grade >= 60:
    level = "C"
else:
    level = "D"
if level == "成绩无效":
    print(level)
else:
    print("Your level is ", level)
