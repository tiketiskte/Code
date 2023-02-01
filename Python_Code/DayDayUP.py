def dayUP(df):
    dayUP = 1
    for i in range(365):
        if i % 7 in [0, 6]:
            dayUP = dayUP * (1 - 0.01)
        else:
            dayUP = dayUP * (1 + df)
    return dayUP
dayfactor = 0.01
while dayUP(dayfactor) < 37.78:
    dayfactor += 0.001
print("{:.3f}".format(dayfactor))