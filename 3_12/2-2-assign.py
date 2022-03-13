'''
指定作業 2-2
固定初速 v0，拋射角度由 θ=3 deg 開始，每次完成拋射增加 3 deg ：
請在物件視窗，做出多個拋體運動並留下軌跡，同時也使用label指令在畫面上產生一個標籤顯示每次拋射時的角度，並將水平射程R、飛行時間T對上角度theta的關係，以graph指令呈現函數圖
'''

from vpython import *

g = 9.8                 #重力加速度 9.8 m/s^2
size = 0.5              #球半徑 0.5 m
height = 15.0           #球初始高度 15 m
m = 1.0                 #球質量1kg
Fg = vector(0, -m*g, 0) #重力

scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0)) #設定畫面
floor = box(length=80, height=0.01, width=20, color=color.green)  	#畫地板

dt = 0.001

'''---這邊以上都跟之前幾個一樣----'''
v0 = 20 # 初始速度

#建立R-theta圖 （射程與theta角的關係圖
R_graph = graph(title=" Theta-R plot" ,width=600,height=400 , x=100 ,y=10 ,xtitle="theta" , ytitle="R")

R_plot = gcurve( graph=R_graph  , color=color.red)
#建立T-theta圖 （飛行時間與theta角的關係圖
T_graph = graph(title=" Theta-T plot" ,width=600,height=400 , x=100 ,y=10 ,xtitle="theta" , ytitle="T")

T_plot = gcurve( graph=T_graph  , color=color.blue)

'''
這邊解釋一下for loop
range(start,end,step)
代表 for(int i=start ; i<end ; i+=step)
所以for deg in range(3,181,3):就是 
deg 會從3,6,9,12 ...跑到 177 , 180
'''
for deg in range(3,181,3):
	# 將 deg 角度轉成” 徑 “
    theta = radians(deg)
    # 每輪都建立一個球 
    ball = sphere(radius = size, color=color.yellow, make_trail= True , trail_radius=0.1)
    #把球放在中央
    ball.pos=vector( 0, size+0.1, 0)
    # Vx = V0*cos(theta) , Vy = V0*sin(theta) ->就是以theta角拋射的速度分量
    ball.v=vector(v0*cos(theta), v0 *sin(theta) , 0)
    
    #初始化總時間
    t=0
    #加上標籤
    label( pos=vec(0,-10,0), text=f'theta = {deg} deg' ,box = False, height = 20, color=color.yellow)

    while ball.pos.y > size:    #模擬直到球落地 即y=球半徑
        '''就是讓球好好跑完'''
        rate(1/dt)    #每一秒跑 1000 次
        t+=dt
        ball.a = Fg/m 

        ball.v = ball.v + ball.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
        ball.pos = ball.pos + ball.v * dt    #球的末位置 = 前一刻位置 + 速度*時間間隔
    
    '''每輪跑完之後都讓球消失 不然很礙眼'''
    ball.visible = False
    # 印出飛行時間 &距離
    print(f'T = {t}, R = {ball.pos.x} , theta = {deg} deg ')
    # 更新R-theta圖表資料
    R_plot.plot(pos=(deg,ball.pos.x))
    # 更新T-theta圖表資料
    T_plot.plot(pos=(deg,t))

