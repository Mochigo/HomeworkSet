from pygame.sprite import Sprite
import pygame
import game_functons as gf


class M1(Sprite):
    def __init__(self, screen, settings):
        super(M1, self).__init__()
        self.settings = settings
        self.screen = screen

        self.image = gf.load_image("./images/enemy1.png", (57, 43))
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        self.y = float(self.rect.y)

        self.speed = settings.M1_speed

        self.is_down = False
        self.downed = False
        self.down_images_length = 4
        self.down_images = [pygame.image.load("./images/enemy1_down" + str(i) + ".png")
                            for i in range(1, self.down_images_length + 1)]
        self.down_images_index = 0
        self.last_time = 0

    def update(self, current_time, rate=60):
        if not self.is_down:
            self.y += self.speed
            self.rect.y = self.y
            return
        if current_time > self.last_time + rate:
            self.image = self.down_images[self.down_images_index]
            self.down_images_index += 1
            self.last_time = current_time
            if self.down_images_index == self.down_images_length:
                self.downed = True

    def blit_me(self):
        self.screen.blit(self.image, self.rect)


class M2(Sprite):
    def __init__(self, screen, settings):
        super(M2, self).__init__()
        self.screen = screen
        self.settings = settings

        self.image = gf.load_image("./images/enemy2.png", (69, 99))
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        self.y = float(self.rect.y)

        self.speed = settings.M2_speed
        self.blood = settings.M2_blood

        self.is_down = False
        self.downed = False
        self.down_images_length = 4
        self.down_images = [pygame.image.load("./images/enemy2_down" + str(i) + ".png")
                            for i in range(1, self.down_images_length + 1)]
        self.down_images_index = 0
        self.last_time = 0

    def update(self, current_time, rate=60):
        if not self.is_down:
            self.y += self.speed
            self.rect.y = self.y
            return
        if current_time > self.last_time + rate:
            self.image = self.down_images[self.down_images_index]
            self.down_images_index += 1
            self.last_time = current_time
            if self.down_images_index == self.down_images_length:
                self.downed = True

    def blit_me(self):
        self.screen.blit(self.image, self.rect)


class M3(Sprite):
    def __init__(self, screen, settings):
        super(M3, self).__init__()
        self.screen = screen
        self.settings = settings

        self.image = gf.load_image("./images/enemy3_n1.png", (169, 258))
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        self.y = float(self.rect.y)
        self.rect.centerx = settings.screen_game_part[0] / 2
        self.rect.bottom = 0

        self.speed = settings.M3_speed
        self.blood = settings.M3_blood

        self.is_down = False
        self.downed = False
        self.down_images_length = 6
        self.down_images = [pygame.image.load("./images/enemy3_down" + str(i) + ".png")
                            for i in range(1, self.down_images_length + 1)]
        self.down_images_index = 0
        self.last_time = 0

    def update(self, current_time, rate=60):
        if not self.is_down:
            if self.y <= self.settings.screen_game_part[1] / 4:
                self.y += self.speed
                self.rect.y = self.y
            return
        if current_time > self.last_time + rate:
            self.image = self.down_images[self.down_images_index]
            self.down_images_index += 1
            self.last_time = current_time
            if self.down_images_index == self.down_images_length:
                self.downed = True

    def blit_me(self):
        self.screen.blit(self.image, self.rect)
