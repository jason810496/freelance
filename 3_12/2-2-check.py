'''
檢核作業 2-2：

請完成視覺化的圓周圓周運動計時器，並在執行視窗紀錄每繞一圈所花的時間。執行畫面如下圖所示，物件視窗中當物體跨過原點時，執行視窗就會打印出時間。
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

#等等要記錄的現在角度、前一角度和前前角度
pre_pre_theta = 0	#前前角度
pre_theta =0		#前一角度
theta=0				#現在角度

last_time=0
while True:
    rate(1/dt)

    # 紀錄現在角度、前一角度和前前角度
    pre_pre_theta =pre_theta
    pre_theta = theta
    theta += omega*dt    #t時刻的角度

	# 按照圓方程式中參數式的定義
    ball.pos = vector(R*cos(theta), R*sin(theta), 0)
	# 按照講義提示的判斷方式判斷
    if pre_theta%(2*pi) > pre_pre_theta%(2*pi) and pre_theta%(2*pi) > theta%(2*pi):
        print(f"period : {t-last_time}")
        last_time=t
    #記得更新總時間
    t += dt             
