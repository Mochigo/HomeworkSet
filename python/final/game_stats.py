class GameStats():
    def __init__(self, settings):
        """初始化统计信息"""
        self.settings = settings
        self.reset_stats()
        self.score = 0
        self.game_active = False

    def reset_stats(self):
        """初始化可能随着游戏变化的信息"""
        self.score = 0
        self.player_lefts = self.settings.player_limits
