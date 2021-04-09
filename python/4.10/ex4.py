import os
import json

ab = {}
if os.path.exists("addressbook.json"):
    with open(r'addressbook.json', 'r', encoding='utf-8') as f_r:
        ab = json.load(f_r)

print("|--- 欢迎使用通讯录程序 ---|")
print("|--- 1、显示通讯录清单  ---|")
print("|--- 2、查询联系人资料  ---|")
print("|--- 3、插入新的联系人  ---|")
print("|--- 4、删除已有的联系人---|")
print("|--- 0、退出-------------|")
op = int(input("请选择功能菜单（0-4）:"))
while op != 0:
    if op == 1:
        for key in ab:
            print(key)
    elif op == 2:
        name = input("请输入想查询的联系人: ")
        print("联系人姓名：" + name)
        print("联系人电话：" + ab[name])
    elif op == 3:
        name = input("请输入想增加的联系人: ")
        telephone = input("请输入欲新增的电话号码: ")
        ab[name] = telephone
    elif op == 4:
        name = input("请输入想删除的联系人: ")
        del ab[name]
    elif op == 0:
        break
    else:
        print("请重新输入")
    op = int(input("请选择功能菜单（0-4）: "))
print("退出，谢谢您的使用")

with open('addressbook.json', 'w') as f_w:
    json.dump(ab, f_w)
