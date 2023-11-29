import matplotlib.pyplot as plt

# 数据
words = {
    '何处': 1637,
    '不知': 1378,
    '万里': 1293,
    '今日': 1148,
    '春风': 1105,
    '白云': 1065,
    '千里': 1042,
    '不可': 987,
    '不见': 884,
    '人间': 864
}

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文显示的字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号'-'显示为方块的问题

# 提取词和词频
word_list = list(words.keys())
frequency = list(words.values())

# 绘制条形图
plt.figure(figsize=(10, 6))
plt.barh(word_list, frequency, color='skyblue')
plt.xlabel('出现频率')
plt.title('古诗词中常用词语出现频率')
plt.gca().invert_yaxis()  # 反转y轴，让词频高的在上面
plt.show()
