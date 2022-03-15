'''
1. Pie Plot

2. 
    - vertical bar
    - horizontal bar 
    - stacked bar

3. Scatter Plot

4. Line Plot
    - Multi_line
    - Line + Scatter
5. Box Plot

6. Annotation

'''

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def Pie_Plot():
    OS_list = ["Window" , "Mac" , "Ubuntu" , "Debian" ,"Kali" , "Arch"]
    count = [1358,734,387,278,104,58]

    df = pd.DataFrame( {'OS':count} , index=OS_list)
    df.plot.pie( y='OS' )
    plt.show()

def Vertical_Bar():
    
    langs = ["english" , "chinese" , "hindi", "spanish"]
    population = [370,921,342,471]

    df = pd.DataFrame({"languages":langs,"population":population})

    # x = x_data_list , y=y_data_list
    df.plot.bar( x="languages" , y="population" ,rot=0)

    plt.show()



def Horizontal_bar():
    langs = ["english" , "chinese" , "hindi", "spanish"]
    population = [370,921,342,471]

    df = pd.DataFrame({"languages":langs,"population":population})

    # bar -> barh
    df.plot.barh( x="languages", y="population" )

    plt.show()

def Stacked_bar():
    langs = ["english" , "chinese" , "hindi", "spanish"]
    Men = [370,921,342,471]
    Women =  [123,523,79,201]

    df = pd.DataFrame({"Women":Women,"Men":Men} ,index=langs)

    df.plot.bar(stacked=True)

    plt.show()

def Sactter_Plot():
    # df = pd.DataFrame([[5.1, 3.5, 0], [4.9, 3.0, 0], [7.0, 3.2, 1], [6.4, 3.2, 1], [5.9, 3.0, 2]],columns=['length', 'width', 'species'])
    
    df = pd.DataFrame(np.random.randint(0,50,size=(100, 2)), columns=['X','Y'])
    # c = color style
    df.plot.scatter(x='X', y='Y', c='DarkBlue')
    plt.show()


def Line_Plot():
    df = pd.DataFrame(np.random.randint(50,80,size=(10, 2)), columns=['Stock A','Stock B'])
    df.plot.line()

    plt.show()

def Multi_Line_Plot():
    df = pd.DataFrame(np.random.randint(50,80,size=(10, 3)), columns=['Stock A','Stock B','Stock C'])
    df.plot.line(subplots=True)

    plt.show()

def Line_Scatter_1():

    Y_list = np.random.randint(50,80,size=(10, 1)) 
    plt.scatter( np.arange(10) , Y_list)
    plt.plot(np.arange(10) , Y_list) 
    plt.show()

def Line_Scatter_2():

    Y_list = np.random.randint(50,80,size=(10, 1)) 
    plt.plot(np.arange(10), Y_list, '-o')
    plt.show() 
    plt.show()



def Box_Plot():
    df = pd.DataFrame(np.random.randint(0,80,size=(50, 4)), columns=['A' , 'B' , 'C' , 'D'])
    df.plot.box()
    plt.show()

'''
    annotate draws an arrow connecting two points in an axes:
'''
def Annotation():

    df = pd.DataFrame([124,364,289,221,189,379,103], np.arange(7))

    ax = df.plot.line()

    ax.annotate('temporary min', xy=(4, 189),  xycoords='data',
            xytext=(0.8, 0.95), textcoords='axes fraction',
            arrowprops=dict(facecolor='black', shrink=0.05),
            horizontalalignment='right', verticalalignment='top',
            )
    # withou text
    ax.annotate('', xy=(3, 221),  xycoords='data',
            xytext=(0.3, 0.5), textcoords='axes fraction',
            arrowprops=dict(facecolor='black', shrink=0.05),
            horizontalalignment='right', verticalalignment='top',
            )
    plt.show()


def Test_box():
    fig, ax = plt.subplots()

    ax.text(0.1,0.2, 'red box with text', color='red', 
        bbox=dict(facecolor='none', edgecolor='red'))

    ax.text(0.5,0.4, 'arrow box with text', color='black', 
        bbox=dict(boxstyle="rarrow,pad=0.3",facecolor='none', edgecolor='blue'))

    ax.text(0.2,0.8, 'acircle with text', color='black', 
        bbox=dict(boxstyle="circle,pad=0.2",facecolor='none', edgecolor='green'))


    plt.show()

Test_box()
