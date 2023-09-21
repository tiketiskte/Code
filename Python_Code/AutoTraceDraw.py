import turtle as t
t.title("自动轨迹绘制")
t.setup(800, 600, 0, 0)
t.pencolor("red")
t.pensize(5)
# 数据读取
datals = []
f = open("Python_Code/AutoTraceDrawData.txt")
for line in f:
    line = line.replace("\n", "") # 去除换行信息
    datals.append(list(map(eval, line.split(','))))
    # map将后面的字符串转换为数字
    print(line)
f.close()
# 自动绘制
# datals 是一个列表 其中每行代表一个操作 而其每行中6个数值代表参数
for i in range(len(datals)):
    t.pencolor(datals[i][3], datals[i][4], datals[i][5])
    t.fd(datals[i][0])
    if datals[i][1]:
        t.right(datals[i][2])
    else:
        t.left(datals[i][2])
t.done()