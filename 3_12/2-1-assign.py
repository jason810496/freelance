from vpython import *

g = 9.8                 #重力加速度 9.8 m/s^2
size = 0.5              #球半徑 0.5 m
height = 15.0           #球初始高度 15 m
m = 1.0                 #球質量1kg
Fg = vector(0, -m*g, 0) #重力

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0)) #設定畫面
floor = box(length=40, height=0.01, width=10, color=color.green)  	#畫地板


ball = sphere(radius = size, color=color.yellow, make_trail= True, trail_type="points", interval=100) 	#畫球
ball.pos = vector(-20, size, 0)    #球初始位置
ball.v = vector(3, 10, 0)           #球初速 

ball2 = sphere(radius = size, color=color.red, make_trail= True, trail_type="points", interval=100) 	#畫球
ball2.pos = vector(-20, size, 0)
ball2.v = vector(3, 10, 0)

dt = 0.001	#時間間隔 0.001 秒
t = 0.0		#模擬初始時間為0秒

damp = 0.2

while ball.pos.x <20:    #模擬直到球落地 即y=球半徑
    rate(1/dt)    #每一秒跑 1000 次
    t = t + dt    #計時器
    
    AirRes = -ball2.v*damp
    
    ball.a = Fg/m 
    ball2.a = Fg/m + AirRes/m

    ball.v = ball.v + ball.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
    ball.pos = ball.pos + ball.v * dt    #球的末位置 = 前一刻位置 + 速度*時間間隔

    ball2.v = ball2.v + ball2.a*dt          
    ball2.pos = ball2.pos + ball2.v * dt 
    

    if ball.pos.y <= size and ball.v.y < 0:    #條件：球心高度小於球半徑且速度沿-y軸
            ball.v.y = - ball.v.y    #條件成立則球的速度加一負號表示反彈   

    if ball2.pos.y <= size and ball2.v.y < 0:    #條件：球心高度小於球半徑且速度沿-y軸
            ball2.v.y = - ball2.v.y    #條件成立則球的速度加一負號表示反彈   

print (t, ball.v)