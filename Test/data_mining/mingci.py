import matplotlib.pyplot as plt

# 数据
nouns = {
    '长安': 658,
    '青山': 646,
    '云': 624,
    '夕阳': 465,
    '香': 459,
    '江南': 412,
    '青云': 396,
    '洛阳': 360,
    '山川': 348,
    '南山': 334
}

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文显示的字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号'-'显示为方块的问题

# 提取名词和频率
noun_list = list(nouns.keys())
frequency = list(nouns.values())

# 绘制饼图
plt.figure(figsize=(8, 8))
plt.pie(frequency, labels=noun_list, autopct='%1.1f%%', startangle=140)
plt.title('古代诗词中常见名词比例分布')
plt.axis('equal')  # 保证饼图是圆形
plt.show()