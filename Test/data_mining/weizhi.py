import matplotlib.pyplot as plt

# 数据
places = {
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

# 提取地名和频率
place_list = list(places.keys())
frequency = list(places.values())

# 绘制柱状图
plt.figure(figsize=(10, 6))
plt.bar(place_list, frequency, color='skyblue')
plt.xlabel('地名')
plt.ylabel('出现频率')
plt.title('古代诗词中常见地名出现频率')
plt.xticks(rotation=45)  # 旋转x轴标签，使其更易读
plt.tight_layout()
plt.show()
