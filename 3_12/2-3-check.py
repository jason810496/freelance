'''
指定作業 2-3

延續課堂作業 2-2，請將此圓周運動用 cylinder 指令每隔一小段時間就畫出細線，將此圓周分割成 N 等分。執行畫面如下：

'''

from vpython import *

size = 0.1     #球的大小
theta = 0.0    #初始角度
R = 1.0        #圓周運動半徑
omega = 2*pi   #角速度大小=單位時間繞過的角度
t = 0.0        #初始時間

scene = canvas(width=500, height=500, center=vector(0,0,0), background=vector(148.0/225,228.0/225,204.0/225))
ball = sphere(radius=size, color=color.blue, make_trail=True, interval = 1, retain = 900)

ball.pos = vector(R,0,0)    #球的初始位置
t = 0.0       #初始時間
dt = 0.001    #時間間隔


pre_pre_theta = 0
pre_theta =0
theta=0

''' ---這上面都跟2-2檢核一樣--- '''

last_time=0 # 前一個時刻 （ 要用來算切成N等分的關鍵

Cut = 20.0  # 要切成幾等分
count=0		# 要記錄目前已經畫了幾條線（這樣才不會多畫線

period=0	# 記錄跑一圈要多久
cut_period=0# N分之一圈要多久
while True:
    rate(1/dt)

    """--------------------------"""
    pre_pre_theta =pre_theta
    pre_theta = theta
    theta += omega*dt    #t時刻的角度

    ball.pos = vector(R*cos(theta), R*sin(theta), 0)
    """---這邊也都跟2-2檢核一樣---"""
	
    if period == 0: # 當我們還不知道一圈到底是多久時（只有第一圈還沒跑完時才會成立
    	#就要來檢查是不是跑完一圈了
        if pre_theta%(2*pi) > pre_pre_theta%(2*pi) and pre_theta%(2*pi) > theta%(2*pi):# 剛好跑完一圈時
        	
            period = t-last_time # 我們就可以知道一圈到底要多久 並記錄在period變數
            print(f"period : {t-last_time}")# 印出來檢查一下
            last_time=t # 下一次的上個時刻就是現在的時刻

            cut_period = period/Cut	#切成N分之一圈要多久

            print("cut period ",cut_period)
    
    if period>0 and count < Cut: #當我們知道一圈一圈要多久並且還沒畫滿N條線（這樣才不會多畫線
        span = t-last_time # 記一下當前時刻到上一時刻過了多久

        if span >= cut_period:	#如果過了N分之一圈
            last_time = t # 下一次的上個時刻就是現在的時刻
            count+=1 #又多畫一條
            cylinder(radius=size/50, color=color.black, pos=vector(0,0,0), axis=ball.pos) #畫細線

    t += dt # 記得要更新總時間         
