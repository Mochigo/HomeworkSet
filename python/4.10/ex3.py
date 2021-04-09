import random


def main():
    colors = {
        0: '方块',  # 0-12
        1: '黑桃',  # 13-25
        2: '红桃',  # 26-38
        3: '梅花',  # 39-51
    }
    nums = {
        1: '1',
        2: '2',
        3: '3',
        4: '4',
        5: '5',
        6: '6',
        7: '7',
        8: '8',
        9: '9',
        10: '10',
        11: 'J',
        12: 'Q',
        0: 'K'
    }

    # 0-51 代表 52张牌
    x = [i for i in range(0, 52)]
    queue = random.sample(x, 52)
    for i in range(0, 52):
        print(colors[queue[i] // 13] + nums[queue[i] % 13])


if __name__ == '__main__':
    main()
