import pygame.font


class ScoreBoard():
    """显示得分信息的类"""

    def __init__(self, settings, screen, stats, screen_other_part):
        """初始化得分需要的属性"""
        self.screen = screen
        self.screen_rect = screen.get_rect()
        self.settings = settings
        self.stats = stats

        self.loc_rect = screen_other_part

        self.text_color = (0, 0, 0)
        self.font = pygame.font.SysFont("None", 48)
        self.score_image = None
        self.score_rect = None

        self.prep_score()

    def prep_score(self):
        score_str = str(self.stats.score)
        self.score_image = self.font.render(score_str, True, self.text_color, self.settings.bg_color)
        self.score_rect = self.score_image.get_rect()
        self.score_rect.centerx = self.loc_rect.centerx
        self.score_rect.centery = self.loc_rect.centery

    def show_score(self):
        self.screen.blit(self.score_image, self.score_rect)
