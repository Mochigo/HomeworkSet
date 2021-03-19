import turtle


def yellow_bg():
    turtle.pencolor('white')
    turtle.speed(60)

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
    turtle.speed(15)
    turtle.pensize(8)
    turtle.pencolor('black')

    turtle.penup()
    turtle.setpos(-125, 50)
    turtle.pendown()

    turtle.fillcolor("white")
    turtle.begin_fill()
    length = 2
    turtle.left(90)
    for i in range(1, 181):
        turtle.right(2)
        '''
        if i == 45:
            print(turtle.pos())
        elif i == 90:
            print(turtle.pos())
        elif i == 135:
            print(turtle.pos())
        elif i == 180:
            print(turtle.pos())
        '''
        if i == 110:
            turtle.pencolor('white')
        elif i == 160:
            turtle.pencolor('black')

        if i <= 45:
            length += 0.0825
        elif i <= 90:
            length -= 0.0825
        elif i <= 135:
            length += 0.0825
        else:
            length -= 0.0825
        turtle.forward(length)
    turtle.end_fill()


def face():
    # 左眼
    turtle.pencolor('black')
    turtle.pensize(1)

    turtle.penup()
    turtle.setpos(-30, 50)
    turtle.pendown()

    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.circle(15)
    turtle.end_fill()

    # 眼睛连线
    turtle.right(90)
    turtle.pensize(8)
    turtle.forward(60)

    # 右眼
    turtle.pensize(1)
    turtle.right(90)

    turtle.penup()
    turtle.setpos(30, 50)
    turtle.pendown()

    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.circle(15)
    turtle.end_fill()


def body():
    turtle.pensize(1)
    turtle.pensize(8)
    turtle.pencolor('black')

    # left body
    turtle.penup()
    turtle.setpos(-103.10, -3.76)
    turtle.pendown()
    turtle.fillcolor("white")
    turtle.begin_fill()
    turtle.right(90)
    length = 1
    while turtle.ycor() > -300.0:
        turtle.left(2)
        turtle.forward(length)
        length += 0.31
    print(turtle.pos())

    # right body
    turtle.penup()
    turtle.setpos(103.10, -3.76)
    turtle.pendown()
    # turtle.fillcolor("white")
    # turtle.begin_fill()
    turtle.left(90)
    length = 1
    while turtle.ycor() > -300.0:
        turtle.right(2)
        turtle.forward(length)
        length += 0.3
    print(turtle.pos())

    turtle.pencolor('white')
    turtle.penup()
    turtle.setpos(272.20, -300.68)
    turtle.pendown()
    turtle.right(88)
    turtle.forward(539.35)

    turtle.pencolor('black')

    turtle.penup()
    turtle.setpos(105.46, -0.97)
    turtle.pendown()

    face_length = 3.65
    turtle.left(50)
    for i in range(110, 161):
        turtle.right(2)
        turtle.forward(face_length)
        if i <= 135:
            face_length += 0.0825
        else:
            face_length -= 0.0825

    turtle.end_fill()


def main():
    yellow_bg()
    head()
    face()
    body()
    turtle.hideturtle()

    input()


if __name__ == '__main__':
    main()