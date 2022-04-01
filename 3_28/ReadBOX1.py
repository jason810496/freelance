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


''' input method :

X list , Y list , A list , B list  ,C list
'''

# figure size
fig,ax = plt.subplots(figsize=(10,10))

# df = pd.DataFrame(np.random.randint(0,50,size=(100, 5)), columns=['X','Y','a','b','c'])

# plt.figure(figsize=(10,10))

F = open('BOX.txt', 'r')
RawList = []
x1 ,y1 ,x2 ,y2 = F.readline().split()
# print(x1 ,y1 ,x2, y2)

while True:
    line = F.readline().split()
    if not line : 
        break
    # convert to int list
    line = [int(i) for i in line]
    RawList.append( line )

df = pd.DataFrame( RawList , columns=['X','Y','a','b','c','d','e'])

RGBList = []

Upper = 50
MaxRange = 250 # 50 * 5 = 250

for index, row in df.iterrows():  
    Sum  = row['a']+ row['b']+ row['c']+ row['b']+ row['c']

    Sum /= MaxRange
    # 230/255 = 0.90196078431
    # RGB range [0,1] (float )
    RGBList.append([0.90196078431 ,  Sum ,Sum ])


# use dataframe directly 
# df.plot.scatter(x='X', y='Y', c=RGBList , marker='s')

# use plt.scatter ( marker = 's' -> change scatter plot shape )
ScatterPlot = plt.scatter(df['X'],df['Y'],c=RGBList , marker='s')


# add annotation on plot 
annot = ax.annotate("", xy=(0,0), xytext=(20,20),textcoords="offset points",
                    bbox=dict(boxstyle="round", fc="w"),
                    arrowprops=dict(arrowstyle="->"),horizontalalignment='center', verticalalignment='top')

# set unvisible 
annot.set_visible(False)



# update annotation by index 
def update_annot(Detials):

    # print("Detials : ", idx) >>> {'ind': array([34], dtype=int32)}
    # print("Detials : ", idx["ind"][0]) >>> 34

    index = Detials["ind"][0]
    # get position by ith index 
    pos = ScatterPlot.get_offsets()[ index ]

    # print(pos ) >>> [40.0 1.0] MEANS: [X,Y]
    annot.xy = pos
    annot.set_text( f"a:{df.loc[index]['a']} b:{df.loc[index]['b']} c:{df.loc[index]['c']} d:{df.loc[index]['d']} e:{df.loc[index]['e']}")
    # annot.get_bbox_patch().set_facecolor(cmap(norm(c[idx["idx"][0]])))
    annot.get_bbox_patch().set_alpha(0.4)

# handle event 
def HandleHover(event):
    
    # let annotation visible 
    vis = annot.get_visible()
    if event.inaxes == ax:

        # Contains:bool  , Details:dictionary >>> {'ind': array([34], dtype=int32)} 
        Contains, Detials = ScatterPlot.contains(event)

        if Contains:
            update_annot(Detials)
            annot.set_visible(True)
            fig.canvas.draw_idle()
        else:
            if vis:
                # set unvisible 
                annot.set_visible(False)
                fig.canvas.draw_idle()

# add mouse hover event listener
fig.canvas.mpl_connect("motion_notify_event", HandleHover)

plt.show()
