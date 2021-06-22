from pygame.sprite import Sprite
import pygame


class Bullet(Sprite):
    def __init__(self, ai_settings, screen, player):
        super(Bullet, self).__init__()

        self.screen = screen
        self.image = pygame.image.load("./images/bullet1.png")
        self.rect = self.image.get_rect()
        # self.rect = pygame.Rect(0, 0, ai_settings.bullet_width, ai_settings.bullet_height)
        self.rect.centerx = player.rect.centerx
        self.rect.bottom = player.rect.top

        self.y = float(self.rect.y)
        self.color = ai_settings.bullet_color
        self.speed = ai_settings.bullet_speed

    def update(self):
        self.y -= self.speed
        self.rect.y = self.y

    def draw_bullet(self):
        # pygame.draw.rect(self.screen, self.color, self.rect)
        self.screen.blit(self.image, self.rect)
