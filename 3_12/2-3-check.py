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

last_time=0

Cut = 20.0
count=0

period=0
cut_period=0
while True:
    rate(1/dt)

    # update theta
    pre_pre_theta =pre_theta
    pre_theta = theta
    theta += omega*dt    #t時刻的角度

    ball.pos = vector(R*cos(theta), R*sin(theta), 0)

    if period == 0:
        if pre_theta%(2*pi) > pre_pre_theta%(2*pi) and pre_theta%(2*pi) > theta%(2*pi):
            period = t-last_time
            print(f"period : {t-last_time}")
            last_time=t

            cut_period = period/Cut

            print("cut period ",cut_period)
    
    if period>0 and count < Cut:
        span = t-last_time

        if span >= cut_period:
            last_time = t
            count+=1
            cylinder(radius=size/50, color=color.black, pos=vector(0,0,0), axis=ball.pos) #畫細線

    t += dt             