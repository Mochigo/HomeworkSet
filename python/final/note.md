## 关于显示

在速度较快的循环中，不断地使用`screen.blit(image, rect)`来绘制图像，同时使用监听键盘鼠标事件`check_event`来对需要随着键盘鼠标而变动的对象进行修改，在本次游戏的代码中，主要就是`Bullet`对象和

`Player`对象

两种`blit`方式：目的是让图像长留在屏幕上

`screen.blit(image, rect)`用来绘制带图片的对象

`pygame.draw.rect(screen, color, rect)`用来绘制`RGB`色彩的矩形对象

以上两者主要看预期想要实现的效果进行选择，

如果希望实时绘制的是自带图片的对象，就是用第一种，意为在`screen(Surface)`上绘制一个大小为`rect`的`image`；

如果只是想绘制一个带色矩形做背景，就选用第二种，意为在`screen(Surface)`上绘制一个颜色为`color `大小为`rect`的矩形 

## 关于`Sprite`：

`sprite`我接触到的现在，最直观的感受就是，最大的引用就是通过`Group`的`update()`方法，可以对其中的每个精灵进行更新，而不用我们手动来操作，