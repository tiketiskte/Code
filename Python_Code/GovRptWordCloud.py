import jieba
import wordcloud

f = open("Python_Code/GovRpt.txt", "r", encoding="utf-8")
t = f.read()
f.close()
ls = jieba.lcut(t)
txt = " ".join(ls) # 用空格分隔的长字符串txt
w = wordcloud.WordCloud(width=1000, height=700,\
                        background_color="white",\
                        font_path="msyh.ttc",\
                        max_words=15
                        )
w.generate(txt)
w.to_file("grwordcloud.png")