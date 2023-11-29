import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 设置中文显示的字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号'-'显示为方块的问题

# 字典存储数据
poets = {
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
# 按作品数量降序排列诗人
sorted_poets = sorted(poets.items(), key=lambda x: x[1], reverse=True)
poets_names = [item[0] for item in sorted_poets]
poets_works = [item[1] for item in sorted_poets]

# 创建条形图
plt.figure(figsize=(10, 6))
plt.barh(poets_names, poets_works, color='skyblue')
plt.xlabel('作品数量')
plt.title('古代诗人作品数量排名')

# 显示图表
plt.gca().invert_yaxis()  # 反转y轴，让作品数量高的排在上面
plt.show()
