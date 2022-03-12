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
floor = box(length=80, height=0.01, width=20, color=color.green)  	#畫地板

dt = 0.001	#時間間隔 0.001 秒
v0 = 20

R_graph = graph(title=" Theta-R plot" ,width=600,height=400 , x=100 ,y=10 ,xtitle="theta" , ytitle="R")

R_plot = gcurve( graph=R_graph  , color=color.red)

T_graph = graph(title=" Theta-T plot" ,width=600,height=400 , x=100 ,y=10 ,xtitle="theta" , ytitle="T")

T_plot = gcurve( graph=T_graph  , color=color.blue)

for deg in range(3,181,3):
    theta = radians(deg)
    ball = sphere(radius = size, color=color.yellow, make_trail= True , trail_radius=0.1) 	#畫球
    ball.pos=vector( 0, size+0.1, 0)
    ball.v=vector(v0*cos(theta), v0 *sin(theta) , 0)
    t=0
    label( pos=vec(0,-10,0), text=f'theta = {deg} deg' ,box = False, height = 20, color=color.yellow)

    while ball.pos.y > size:    #模擬直到球落地 即y=球半徑
        rate(1/dt)    #每一秒跑 1000 次
        t+=dt
        ball.a = Fg/m 

        ball.v = ball.v + ball.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
        ball.pos = ball.pos + ball.v * dt    #球的末位置 = 前一刻位置 + 速度*時間間隔

    ball.visible = False
    print(f'T = {t}, R = {ball.pos.x} , theta = {deg} deg ')
    R_plot.plot(pos=(deg,ball.pos.x))
    T_plot.plot(pos=(deg,t))

# print (t, ball.v)