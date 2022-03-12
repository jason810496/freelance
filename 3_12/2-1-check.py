from vpython import *
'''
newton wrong bug ....
'''
g = 9.8                 #重力加速度 9.8 m/s^2
size = 0.5              #球半徑 0.5 m
height = 15.0           #球初始高度 15 m
m = 1.0                 #球質量1kg
Fg = vector(0, -m*g, 0) #重力

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0)) #設定畫面
floor = box(length=20, height=0.01, width=10, color=color.green)  	#畫地板


ball = sphere(radius = size, color=color.yellow, make_trail= True, trail_type="points", interval=100) 	#畫球
ball.pos = vector(-10, size+0.1, 0)  
ball.v = vector(3, 10, 0)           

ball_vpy = sphere(radius = size, color=color.green, make_trail= True, trail_type="points", interval=100) 	#畫球
ball_vpy.pos = vector(-10, size+0.1, 0)
ball_vpy.v = vector(3, 10, 0)

ball_newton = sphere(radius = size, color=color.red, make_trail= True, trail_type="points", interval=100) 	#畫球
ball_newton.pos = vector(-10, size+0.1, 0)
ball_newton.v = vector(3, 10, 0)

dt = 0.001	#時間間隔 0.001 秒
t = 0.0		#模擬初始時間為0秒

damp = 0.2

while ball.pos.y > size or ball_vpy.pos.y > size or ball_newton.pos.y > size:    #模擬直到球落地 即y=球半徑
    rate(1/dt)    #每一秒跑 1000 次
    t = t + dt    #計時器
    
    AirRes = -ball_vpy.v*damp
    
    ball.a = Fg/m 
    ball_vpy.a = Fg/m + AirRes/m
    ball_newton.a = Fg/m

    ball.v = ball.v + ball.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
    ball.pos = ball.pos + ball.v * dt    #球的末位置 = 前一刻位置 + 速度*時間間隔

    ball_vpy.v = ball_vpy.v + ball_vpy.a*dt          
    ball_vpy.pos = ball_vpy.pos + ball_vpy.v * dt 
    
    # newton
    ball_newton.pos.x = ball_newton.v.x * (1 - exp(-damp*t))/damp
    ball_newton.pos.y = - g*t/damp + (damp*ball_newton.v.y + g) * (1 - exp(-damp*t))/damp**2

    # stop the ball 
    if ball.pos.y <= size:
        ball.v=vector(0,0,0)

    if ball_vpy.pos.y <= size:
        ball_vpy.v=vector(0,0,0)

    if ball_newton.pos.y <= size:
        ball_newton.v=vector(0,0,0)

print (t, ball.v)