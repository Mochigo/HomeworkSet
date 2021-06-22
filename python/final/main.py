import sys
import pygame
import pygame.sprite

import settings as st
import game_functons as gf

from settings import Settings
from game_stats import GameStats
from scoreBoard import ScoreBoard
from Player import Player


def run_game():
    """main game function"""
    # 初始化游戏并创建一个屏幕对象
    pygame.init()
    pygame.display.set_caption("Plane Wars")
    game_settings = Settings()

    framerate = pygame.time.Clock()  # 设置framerate来获取时间和帧率，是用来控制m1爆炸的动画速率
    # 监听是否有按键被长按，如果有，则根据设置的delay延迟重复触发
    pygame.key.set_repeat(
        game_settings.bullet_delay,
        game_settings.bullet_interval)  # 实现子弹连续间隔发射

    # 设置定时器事件：创建敌机事件
    pygame.time.set_timer(st.CREATE_M1_EVENT, 1000)
    pygame.time.set_timer(st.CREATE_M2_EVENT, 3000)
    pygame.time.set_timer(st.CREATE_M3_EVENT, 5000)
    pygame.time.set_timer(st.FIRE_EVENT, 2000)

    # screen is an instance of class Surface
    # Surface can be recognized as a image
    # use Surface.blit can show another image on current Surface
    screen = pygame.display.set_mode((game_settings.screen_size))
    screen_other_part = pygame.Rect(
        game_settings.screen_other_part_coordinate[0],
        game_settings.screen_other_part_coordinate[1],
        game_settings.screen_other_part[0],
        game_settings.screen_other_part[1])
    screen_game_part = game_settings.screen_game_part_image.get_rect()

    stats = GameStats(game_settings)
    sb = ScoreBoard(game_settings, screen, stats, screen_other_part)

    player = Player(screen, game_settings)
    bullets = pygame.sprite.Group()
    m1s = pygame.sprite.Group()
    m2s = pygame.sprite.Group()
    m3s = pygame.sprite.Group()

    # 开始游戏的主循环
    while True:
        framerate.tick(game_settings.M1_down_rate)
        ticks = pygame.time.get_ticks()
        # 监视键盘和鼠标事件
        gf.check_events(player, game_settings, screen, bullets, m1s, m2s, m3s)
        # 让角色可见
        player.update(bullets, game_settings, screen, ticks)

        gf.update_bullets(bullets, m1s, m2s, m3s)
        gf.update_m1s(m1s, game_settings, ticks, player, stats, sb)
        gf.update_m2s(m2s, game_settings, ticks, player, stats, sb)
        gf.update_m3s(m3s, game_settings, ticks, player, stats, sb)

        # 让最近绘制的屏幕可见
        gf.update_screen(
            game_settings, screen,  # 固定参数
            screen_other_part, screen_game_part,  # 屏幕划分
            stats, sb,  # 计分板
            player, bullets,
            m1s, m2s, m3s  # 可移动的角色
        )


def main():
    run_game()


if __name__ == '__main__':
    main()
