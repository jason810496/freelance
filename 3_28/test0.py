import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

'''
x = np.random.rand(15)
y = np.random.rand(15)

PropertyList = []

RGBList = []

fig,ax = plt.subplots()

ScatterPlot = plt.scatter(x,y,c=RGBList)
'''
fig,ax = plt.subplots()

df = pd.DataFrame(np.random.randint(0,50,size=(100, 5)), columns=['X','Y','a','b','c'])
    # c = color style

    # r:230 , g=b=range (max=150 , )

RGBList = []


for index, row in df.iterrows():  
    Sum  = row['a']+ row['b']+ row['c']
    # RGBList.append( [230,row['RGB'],row['']] )

    Sum /= 150
    # 230/255 = 0.90196078431
    RGBList.append([0.90196078431 ,  Sum ,Sum ])


# df.plot.scatter(x='X', y='Y', c=RGBList , marker='s')

ScatterPlot = plt.scatter(df['X'],df['Y'],c=RGBList , marker='s')


annot = ax.annotate("", xy=(0,0), xytext=(20,20),textcoords="offset points",
                    bbox=dict(boxstyle="round", fc="w"),
                    arrowprops=dict(arrowstyle="->"),horizontalalignment='center', verticalalignment='top')
annot.set_visible(False)




def update_annot(idx):

    # print("idx : ", idx) >>> {'ind': array([34], dtype=int32)}
    # print("idx : ", idx["ind"][0]) >>> 34

    index = idx["ind"][0]
    pos = ScatterPlot.get_offsets()[ index ]

    # print(pos ) >>> [40.0 1.0] MEANS: [X,Y]
    annot.xy = pos
    annot.set_text( f"a:{df.loc[index]['a']} b:{df.loc[index]['b']} c:{df.loc[index]['c']}")
    # annot.get_bbox_patch().set_facecolor(cmap(norm(c[idx["idx"][0]])))
    annot.get_bbox_patch().set_alpha(0.4)

def HandleHover(event):
    vis = annot.get_visible()
    if event.inaxes == ax:
        cont, idx = ScatterPlot.contains(event)
        if cont:
            update_annot(idx)
            annot.set_visible(True)
            fig.canvas.draw_idle()
        else:
            if vis:
                annot.set_visible(False)
                fig.canvas.draw_idle()

fig.canvas.mpl_connect("motion_notify_event", HandleHover)

plt.show()