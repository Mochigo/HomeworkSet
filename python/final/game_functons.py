import pygame
from time import sleep
import sys
from bullet import Bullet
import monster as m
import random
import settings as st


def check_events(player, settings, screen, bullets, m1s, m2s, m3s):
    # 监听每个鼠标每个事件
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            check_keydown_events(player, settings, screen, bullets)
        elif event.type == pygame.KEYUP:
            check_keyup_events(event, player)
        elif settings.M1_limits > 0 and event.type == st.CREATE_M1_EVENT:
            create_m1(settings, screen, m1s)
        elif settings.M2_limits > 0 and event.type == st.CREATE_M2_EVENT:
            create_m2(settings, screen, m2s)
        elif event.type == st.CREATE_M3_EVENT:
            if settings.M3_limits > 0 and settings.M1_limits == 0 and settings.M2_limits == 0:
                create_m3(settings, screen, m3s)


def check_keydown_events(player, settings, screen, bullets):
    # 通过get_pressed从而可以同时监听多个按键事件
    keys = pygame.key.get_pressed()
    if keys[pygame.K_SPACE] or keys[pygame.K_j]:
        new_bullet = Bullet(settings, screen, player)
        bullets.add(new_bullet)
    if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
        player.moving_right = True
    if keys[pygame.K_LEFT] or keys[pygame.K_a]:
        player.moving_left = True
    if keys[pygame.K_DOWN] or keys[pygame.K_s]:
        player.moving_down = True
    if keys[pygame.K_UP] or keys[pygame.K_w]:
        player.moving_up = True


def check_keyup_events(event, player):
    if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
        player.moving_right = False
    elif event.key == pygame.K_LEFT or event.key == pygame.K_a:
        player.moving_left = False
    elif event.key == pygame.K_UP or event.key == pygame.K_w:
        player.moving_up = False
    elif event.key == pygame.K_DOWN or event.key == pygame.K_s:
        player.moving_down = False


def update_screen(settings, screen,
                  screen_other_part, screen_game_part,
                  stats, scoreboard,
                  player, bullets,
                  m1s, m2s, m3s):
    screen.fill(settings.bg_color)

    pygame.draw.rect(screen, settings.screen_other_part_color, screen_other_part)
    screen.blit(settings.screen_game_part_image, screen_game_part)

    player.blit_me()
    scoreboard.show_score()
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    for m1 in m1s.sprites():
        m1.blit_me()
    for m2 in m2s.sprites():
        m2.blit_me()
    for m3 in m3s.sprites():
        m3.blit_me()

    pygame.display.flip()


# 获取指定像素大小的图片 -> Surface
def load_image(filename, a):
    image = pygame.transform.scale(
        pygame.image.load(filename), (a[0], a[1]))
    return image


def create_m1(settings, screen, m1s):
    m1 = m.M1(screen, settings)
    m1.rect.top = m1.screen_rect.top
    m1.rect.centerx = random.randint(settings.M1_size[0],
                                     settings.screen_game_part[0] - settings.M1_size[0])
    settings.M1_limits -= 1
    m1s.add(m1)


def create_m2(settings, screen, m2s):
    m2 = m.M2(screen, settings)
    m2.rect.top = m2.screen_rect.top
    m2.rect.centerx = random.randint(settings.M2_size[0],
                                     settings.screen_game_part[0] - settings.M2_size[0])
    settings.M2_limits -= 1
    m2s.add(m2)


def create_m3(settings, screen, m3s):
    settings.M3_limits -= 1
    m3 = m.M3(screen, settings)
    m3s.add(m3)


def update_bullets(bullets, m1s, m2s, m3s):
    bullets.update()
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)

    c1 = pygame.sprite.groupcollide(m1s, bullets, False, True)
    c2 = pygame.sprite.groupcollide(m2s, bullets, False, True)
    c3 = pygame.sprite.groupcollide(m3s, bullets, False, True)
    for m1 in c1.keys():
        m1.is_down = True  # 不直接删除，而是播放完动画再删除
    for m2 in c2.keys():
        m2.blood -= 1
    for m3 in c3.keys():
        m3.blood -= 1


def update_m1s(m1s, game_settings, ticks, player, stats, sb):
    m1s.update(ticks)
    for m1 in m1s.copy():
        if m1.downed:
            m1s.remove(m1)
            stats.score += game_settings.M1_score
            sb.prep_score()
        if m1.rect.bottom >= game_settings.screen_game_part[1]:
            m1s.remove(m1)
            stats.score += game_settings.M1_score
            sb.prep_score()
    if pygame.sprite.spritecollideany(player, m1s):
        player_hit(stats, player, game_settings)


def update_m2s(m2s, game_settings, ticks, player, stats, sb):
    m2s.update(ticks)
    for m2 in m2s.copy():
        if m2.blood == 0:
            m2.is_down = True
        if m2.downed:
            m2s.remove(m2)
            stats.score += game_settings.M2_score
            sb.prep_score()
        if m2.rect.bottom >= game_settings.screen_game_part[1]:
            m2s.remove(m2)
            stats.score += game_settings.M2_score
            sb.prep_score()
    if pygame.sprite.spritecollideany(player, m2s):
        player_hit(stats, player, game_settings)


def update_m3s(m3s, game_settings, ticks, player, stats, sb):
    m3s.update(ticks)
    for m3 in m3s.copy():
        if m3.blood == 0:
            m3.is_down = True
        if m3.downed:
            m3s.remove(m3)
            stats.score += game_settings.M3_score
            sb.prep_score()
    if pygame.sprite.spritecollideany(player, m3s):
        player_hit(stats, player, game_settings)


def player_hit(stats, player, settings):
    stats.player_lefts -= 1
    player.center(settings)
    sleep(0.5)
