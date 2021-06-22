import pygame
from bullet import Bullet
import game_functons as gf


# 游戏中玩家控制的主体
class Player():
    # 初始化
    def __init__(self, screen, settings):
        self.screen = screen

        # images 用来存放飞机的不同状态，目前有normal和up的特殊状态
        self.images = {}
        self.images["normal"] = pygame.image.load("./images/life.png")  # 平常状态
        self.images["moving_up"] = gf.load_image("./images/me1.png", (46, 57))  # 按W或者↑时的图形
        self.image = self.images["normal"]

        # rect主要用来控制飞机的位置
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        self.rect.centerx = settings.screen_game_part[0] / 2
        self.rect.centery = settings.screen_game_part[1] - settings.player_size[1] / 2
        self.centerx = float(self.rect.centerx)
        self.centery = float(self.rect.centery)

        self.speed = settings.player_speed

        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False
        self.onshoot = False

    def blit_me(self):
        # 在屏幕上绘制player
        self.screen.blit(self.image, self.rect)

    def update(self, bullets, settings, screen, current_time, rate=60):
        # 在无限循环中，根据变量来不断改变player的相关属性
        if self.moving_right and self.rect.right <= settings.screen_game_part[1]:
            self.centerx += self.speed
        if self.moving_left and self.rect.left >= self.screen_rect.left:
            self.centerx -= self.speed
        if self.moving_down and self.rect.bottom <= self.screen_rect.bottom:
            self.centery += self.speed
        if self.moving_up:
            self.image = self.images["moving_up"]
            if self.rect.top >= self.screen_rect.top:
                self.centery -= self.speed
        else:
            self.image = self.images["normal"]

        if self.onshoot:
            new_bullet = Bullet(settings, screen, self)
            bullets.add(new_bullet)

        self.rect.centerx = self.centerx
        self.rect.centery = self.centery

    def center(self, settings):
        self.centerx = settings.screen_game_part[0] / 2
        self.centery = settings.screen_game_part[1] - settings.player_size[1] / 2
