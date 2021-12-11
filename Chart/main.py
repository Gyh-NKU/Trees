from pyecharts.charts import Line
# from pyecharts.charts import Bar
from pyecharts import options as opts

x = []
for i in range(1, 50):
    x.append(str(i * 10000))
types = ['BST', 'AVL', 'BTree', 'RBT']
ins = [[], [], [], []]
ser = [[], [], [], []]
dele = [[], [], [], []]
for case in range(0, 4):
    with open('./test/ResultOf' + types[case] + 'Chart(Random).txt') as f:
        str = f.read()
        digs = (str.split(' '))
    # print(digs)
    for i in range(0, 50):
        ins[case].append(float(digs[i * 3]))
        ser[case].append(float(digs[i * 3 + 1]))
        dele[case].append(float(digs[i * 3 + 2]))

lineins = Line()
lineins.add_xaxis(x)
for case in range(0, 4):
    lineins.add_yaxis(types[case], ins[case], is_smooth=True)
lineins.set_global_opts(title_opts=opts.TitleOpts(title='插入比较', subtitle='随机数据'))
lineins.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
lineins.render("insert.html")


linedel = Line()
linedel.add_xaxis(x)
for case in range(0, 4):
    linedel.add_yaxis(types[case], dele[case], is_smooth=True)
linedel.set_global_opts(title_opts=opts.TitleOpts(title='删除比较', subtitle='随机数据'))
linedel.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
linedel.render("delete.html")

lineser = Line()
lineser.add_xaxis(x)
for case in range(0, 4):
    lineser.add_yaxis(types[case], ser[case])
lineser.set_global_opts(title_opts=opts.TitleOpts(title='搜索比较', subtitle='随机数据'))
lineser.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
lineser.render("search.html")

ins2 = [[], [], [], []]
ser2 = [[], [], [], []]
dele2 = [[], [], [], []]
for case in range(0, 4):
    with open('./test/ResultOf' + types[case] + 'Chart(Monotonically).txt') as f:
        str2 = f.read()
        digs2 = (str2.split(' '))
    # print(len(digs2))
    for i in range(0, int(len(digs2)/3-3)):
        ins2[case].append(float(digs2[i * 3]))
        ser2[case].append(float(digs2[i * 3 + 1]))
        dele2[case].append(float(digs2[i * 3 + 2]))

lineins2 = Line()
lineins2.add_xaxis(x)
for case in range(0, 4):
    lineins2.add_yaxis(types[case], ins2[case], is_smooth=True)
lineins2.set_global_opts(title_opts=opts.TitleOpts(title='插入比较', subtitle='单调数据'))
lineins2.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
lineins2.render("insert2.html")


linedel2 = Line()
linedel2.add_xaxis(x)
for case in range(0, 4):
    linedel2.add_yaxis(types[case], dele2[case], is_smooth=True)
linedel2.set_global_opts(title_opts=opts.TitleOpts(title='删除比较', subtitle='单调数据'))
linedel2.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
linedel2.render("delete2.html")

lineser2 = Line()
lineser2.add_xaxis(x)
for case in range(0, 4):
    lineser2.add_yaxis(types[case], ser2[case])
lineser2.set_global_opts(title_opts=opts.TitleOpts(title='搜索比较', subtitle='单调数据'))
lineser2.set_series_opts(label_opts=opts.LabelOpts(is_show=False))
lineser2.render("search2.html")
