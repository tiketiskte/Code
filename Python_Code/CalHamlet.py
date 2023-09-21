def getText():
    txt = open("Python_Code/hamlet.txt", "r").read()
    txt = txt.lower() # 所有英文字母变成小写
    for ch in '!"#$%&()*+,-./:;<=>?@[\\]^_‘{|}~':
        txt = txt.replace(ch, " ") # 将文本中特殊字符替换为空格
    return txt # 获得归一化文本

hamletTxt = getText()
words = hamletTxt.split() # 默认采用空格 返回一个列表类型
counts = {} # 表示单词和出现频率的映射关系
for word in words:
    counts[word] = counts.get(word, 0) + 1
items = list(counts.items())
items.sort(key=lambda x:x[1], reverse=True) # key指定列表中使用哪一个多元选项列作为排序列 该句完成对列表的第二个元素进行由大到小排序
for i in range(10):
    word, count = items[i]
    print("{0:<10}{1:>5}".format(word, count))