'''
指定作業 2-1

黃色為無阻力的理想拋體(ball)
紅色為加入空氣阻力的拋體(ball_vpy)
綠色為上理論解方程式所畫出來的軌跡(ball_newton)

執行流程為，黃球和紅球同時拋出，當紅球和黃球都落地就讓它們直接停在地面上，之後再拋出綠球
'''

from vpython import *

# 跟2-1檢核一樣 就不贅述ㄌ
g = 9.8                 
size = 0.5              
height = 15.0           
m = 1.0                 
Fg = vector(0, -m*g, 0) 
# 這邊也一樣
scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0)) #設定畫面
floor = box(length=20, height=0.01, width=10, color=color.green)  	#畫地板

'''理想拋體（黃色）'''
ball = sphere(radius = size, color=color.yellow, make_trail= True, trail_type="points", interval=100) 	#畫球
ball.pos = vector(0, size, 0)  
ball.v = vector(3, 10, 0)           
'''物理模擬拋體（紅色）'''
ball_vpy = sphere(radius = size, color=color.red, make_trail= True, trail_type="points", interval=100) 	#畫球
ball_vpy.pos = vector(0, size, 0)
ball_vpy.v = vector(3, 10, 0)
'''用方程式解的拋體（綠色）'''
ball_newton = sphere(radius = size, color=color.green, make_trail= True, trail_type="points", interval=100) 	#畫球
ball_newton.pos = vector(0, size, 0)
ball_newton.v = vector(3, 10, 0)

dt = 0.001	#時間間隔 0.001 秒
t = 0.0		#模擬初始時間為0秒

k=0.2		# 空氣阻力係數

while ball.pos.y > 0 or ball_vpy.pos.y > 0: #
    rate(1/dt)    #每一秒跑 1000 次
    t = t + dt    #計時器
    
    # theory
    ball.a = Fg/m 
    ball.v = ball.v + ball.a*dt          
    ball.pos = ball.pos + ball.v * dt   
    
    # vpy
    AirRes = -ball_vpy.v*k
    ball_vpy.a = Fg/m + AirRes/m
    ball_vpy.v = ball_vpy.v + ball_vpy.a*dt          
    ball_vpy.pos = ball_vpy.pos + ball_vpy.v * dt

    # xy_plot.plot(pos=(ball_vpy.pos.x,ball_vpy.pos.y))
    # xy_plot2.plot(pos=(ball_newton.pos.x,ball_newton.pos.y))

    # stop the ball 
    if ball.pos.y <= 0:
        ball.v=vector(0,0,0)

    if ball_vpy.pos.y <= 0:
        ball_vpy.v= vector(0,0,0)

t=0
while ball_newton.pos.y > 0:
        rate(1/dt)    #每一秒跑 1000 次
        t = t + dt    #計時器

        # newton
        ball_newton.pos.x = (ball_newton.v.x * (1 - exp(-k*t)) )/k
        ball_newton.pos.y = - g*t/k + (k*ball_newton.v.y + g) * (1 - exp(-k*t))/k**2

