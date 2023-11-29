import matplotlib.pyplot as plt

# 数据
adjectives = {
    '远': 2653,
    '长': 2592,
    '新': 2458,
    '深': 2189,
    '高': 2159,
    '好': 2048,
    '老': 1482,
    '旧': 1460,
    '清': 1411,
    '难': 1370
}

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文显示的字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号'-'显示为方块的问题

# 提取形容词和频率
adjective_list = list(adjectives.keys())
frequency = list(adjectives.values())

# 绘制水平条形图
plt.figure(figsize=(10, 6))
plt.barh(adjective_list, frequency, color='skyblue')
plt.xlabel('出现频率')
plt.title('古代诗词中常见形容词出现频率')
plt.gca().invert_yaxis()  # 反转y轴，让频率高的在上面
plt.show()
