import pygame

# 创建敌机的定时器常量
CREATE_M1_EVENT = pygame.USEREVENT
CREATE_M2_EVENT = pygame.USEREVENT + 1
CREATE_M3_EVENT = pygame.USEREVENT + 2
FIRE_EVENT = pygame.USEREVENT + 3


# have all the relative settings
class Settings():
    def __init__(self):
        # screen
        self.screen_size = (1200, 800)
        self.bg_color = (255, 255, 255)
        # other_part
        self.screen_other_part = (400, 800)
        self.screen_other_part_coordinate = (800, 0)
        self.screen_other_part_color = (0, 0, 0)
        # game_part
        self.screen_game_part = (800, 800)
        self.screen_game_part_coordinate = (0, 0)
        self.screen_game_part_image = pygame.image.load(
            "./images/background.png")
        self.screen_game_part_image = pygame.transform.scale(
            self.screen_game_part_image, self.screen_game_part)
        # player
        self.player_speed = 1.2
        self.player_size = (80, 60)
        self.player_limits = 3

        # enemies' settings
        self.M1_size = (57, 43)
        self.M1_limits = 30
        self.M1_speed = 0.5
        self.M1_down_rate = 500
        self.M1_score = 100

        self.M2_size = (69, 99)
        self.M2_limits = 10
        self.M2_speed = 0.3
        self.M2_blood = 2
        self.M2_score = 500

        self.M3_size = (169, 258)
        self.M3_limits = 1
        self.M3_speed = 0.2
        self.M3_blood = 10
        self.M3_score = 1000

        # bullet
        self.bullet_speed = 3
        self.bullet_height = 30
        self.bullet_width = 6
        self.bullet_color = (60, 60, 60)
        self.bullet_delay = 150
        self.bullet_interval = 150
