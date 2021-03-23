import turtle
import math

# turtle.seth(angle) 设置朝向
# turtle.pos() 返回坐标
# turtle.penup() 提起笔
# turtle.pendown() 放下笔
# turtle.setpos() 放在选定位置
# turtle.xcor() 返回当前pos的x坐标
# turtle.ycor() 返回当前pos的y坐标
# turtle.Turtle() 会返回一个新的turtle实例，从而实现多个turtle同时运动

# 椭圆参数
a = 100.0
b = 70.0

def gety(x):
    return math.sqrt(b * b - x * x * b * b / (a * a))


def yellow_bg():
    # pen set
    turtle.pencolor('white')
    turtle.speed(100)

    # set the start position
    turtle.penup()
    turtle.setpos(-300, 300)
    turtle.pendown()

    turtle.fillcolor("yellow")
    turtle.begin_fill()
    total_times = 4
    for times in range(total_times):
        turtle.forward(600)
        turtle.right(90)
    turtle.end_fill()


def head():
    # pen set
    turtle.pensize(6)
    turtle.pencolor('black')
    turtle.speed(100)

    # set the start position
    turtle.penup()
    turtle.setpos(-100, 0)
    turtle.pendown()

    turtle.fillcolor("white")
    turtle.begin_fill()
    speed = 2
    x = -100.0
    while x <= 100.0:
        y = gety(x)
        turtle.goto(x, y)
        x += speed

    x = -100.0
    while x <= 100.0:
        y = gety(x)
        turtle.goto(-x, -y)
        x += speed
    turtle.end_fill()


'''
def face():
    r = 10

    # pen set
    turtle.pensize(8)
    turtle.pencolor('black')
    turtle.speed(1)

    # set the left eye start position
    turtle.penup()
    turtle.setpos(-40, -r)
    turtle.pendown()

    # left eye
    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.circle(r)
    turtle.end_fill()

    # set the right eye start position
    turtle.penup()
    turtle.setpos(40, -r)
    turtle.pendown()

    # right eye
    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.circle(r)
    turtle.end_fill()

    # a straight line between eyes
    turtle.penup()
    turtle.setpos(-40, 0)
    turtle.pendown()

    turtle.forward(80)
'''


def body():
    left_arm_start = -65.0
    right_arm_start = 65.0
    speed = 0.25

    # pen set
    turtle.pensize(8)
    turtle.pencolor('black')
    turtle.speed(10)

    turtle.penup()
    turtle.setpos(left_arm_start, -gety(left_arm_start))
    turtle.pendown()

    turtle.fillcolor('white')
    turtle.begin_fill()

    # left arm
    turtle.penup()
    turtle.setpos(left_arm_start, -gety(left_arm_start))
    turtle.pendown()
    turtle.seth(180)

    length = 2
    while turtle.ycor() > -300.0:
        turtle.left(2)
        turtle.forward(length)
        length += speed

    # top
    turtle.pencolor('white')
    turtle.penup()
    turtle.setpos(left_arm_start, -gety(left_arm_start))
    turtle.pendown()
    turtle.seth(0)

    turtle.forward(2 * math.fabs(turtle.xcor()))

    # right arm
    turtle.pencolor('black')
    turtle.seth(0)

    length = 2
    while turtle.ycor() > -300.0:
        turtle.right(2)
        turtle.forward(length)
        length += speed

    # bottom
    turtle.pencolor('white')
    turtle.seth(180)

    distance = math.fabs(turtle.xcor())
    turtle.forward(2 * distance)

    turtle.end_fill()

    # face line
    turtle.pencolor('black')
    turtle.penup()
    turtle.setpos(left_arm_start, -gety(left_arm_start))
    turtle.pendown()

    x = left_arm_start
    while x <= right_arm_start:
        y = gety(x)
        turtle.goto(x, -y)
        x += 2


def hands():
    high = -125
    distance = 100
    speed = 0.25

    turtle.pencolor('black')
    turtle.seth(225)

    turtle.penup()
    turtle.setpos(-distance, high)
    turtle.pendown()

    length = 2
    while turtle.ycor() > -300.0:
        turtle.left(1)
        turtle.forward(length)
        length += speed

    turtle.seth(-45)

    turtle.penup()
    turtle.setpos(distance, high)
    turtle.pendown()

    length = 2
    while turtle.ycor() > -300.0:
        turtle.right(1)
        turtle.forward(length)
        length += speed


# 实现了同时画两只眼睛
def face():
    r = 10
    speed = 1

    turtle.penup()
    turtle.setpos(0, 0)
    turtle.pendown()

    tl = turtle.Turtle()
    tr = turtle.Turtle()

    # tl pen set
    tl.pensize(8)
    tl.pencolor('black')
    tl.speed(100)
    tl.seth(180)

    # tr pen set
    tr.pensize(8)
    tr.pencolor('black')
    tr.speed(100)
    tr.seth(0)

    step = 1
    while tr.xcor() <= 30.0:
        tl.fd(step)
        tr.fd(step)

    tl.fillcolor("black")
    tr.fillcolor("black")
    tl.begin_fill()
    tr.begin_fill()

    tr_x_pos = tr.xcor()
    tl_x_pos = tl.xcor()
    while tr_x_pos <= 50.0:
        tr_y_pos = math.sqrt(r * r - math.pow((tr_x_pos-40), 2))
        tr.goto(tr_x_pos, tr_y_pos)
        tr_x_pos += speed

        tl_y_pos = math.sqrt(r * r - math.pow((tl_x_pos+40), 2))
        tl.goto(tl_x_pos, tl_y_pos)
        tl_x_pos -= speed

    tr_x_pos = tr.xcor()
    tl_x_pos = tl.xcor()
    while tr_x_pos >= 30.0:
        tr_y_pos = math.sqrt(r * r - math.pow((tr_x_pos-40), 2))
        tr.goto(tr_x_pos, -tr_y_pos)
        tr_x_pos -= speed

        tl_y_pos = math.sqrt(r * r - math.pow((tl_x_pos + 40), 2))
        tl.goto(tl_x_pos, -tl_y_pos)
        tl_x_pos += speed

    tl.end_fill()
    tr.end_fill()

    tl.hideturtle()
    tr.hideturtle()


def main():
    yellow_bg()
    head()
    face()
    body()
    hands()

    turtle.hideturtle()

    input()


if __name__ == '__main__':
    main()
