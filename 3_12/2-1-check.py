'''
檢核作業 2-1

"請完成拋體運動的模擬，使球碰到地板會發生反彈，並使用指令描繪出球的運動軌跡。接著請再新增一個球並加入空氣阻力的影響，保留沒有空氣阻力拋體的軌跡與之對照，空氣阻力常數 k 可以自行設定。"

'''

from vpython import *

'''
程式碼中vector( x, y, z ) 都代表空間向量 
無論是位置還是速度都以向量來表示
'''
g = 9.8                 #重力加速度 9.8 m/s^2
size = 0.5              #球半徑 0.5 m
height = 15.0           #球初始高度 15 m
m = 1.0                 #球質量1kg
Fg = vector(0, -m*g, 0) #重力

# 設定畫面（使用者看到的畫面角度
scene = canvas(width=600, height=600,x=0, y=0, center = vector(0,height/2,0)) 
# 建立地板（設定寬度為40 ;也就是左邊界在x=-20 , 右邊界在x=+0 , 
floor = box(length=40, height=0.01, width=10, color=color.green)  	

'''
這邊的ball物件是要畫出 **不計** 空氣阻力的球體斜拋軌跡的球體
'''
# 建立球體 
ball = sphere(radius = size, color=color.yellow, make_trail= True, trail_type="points", interval=100) 
# 設定球初始位置
ball.pos = vector(-20, size, 0)   
#設定球初速  
ball.v = vector(3, 10, 0)           


'''
ball2物件則是要畫出 **計**空氣阻力的球體斜拋軌跡的球體
'''
# 設定與上面的球相同
ball2 = sphere(radius = size, color=color.red, make_trail= True, trail_type="points", interval=100)
ball2.pos = vector(-20, size, 0)
ball2.v = vector(3, 10, 0)

dt = 0.001	#時間間隔 0.001 秒
t = 0.0		#模擬初始時間為0秒

k = 0.2		#空氣阻力係數

while ball.pos.x <20:    #模擬直到球體的x位置在地板的右邊界（x=20 的位置
        rate(1/dt)    #每一秒跑 1000 次
        t = t + dt    #開始模擬到現在的總時間 

        AirRes = -ball2.v*k # 計算空氣阻力（公式為： f = (-k)*v )

        ball.a = Fg/m  # 理論狀態中球的加速度
        ball2.a = Fg/m + AirRes/m # 計空氣阻力狀態中球的加速度

        ''''理論狀態中的球'''
        ball.v = ball.v + ball.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
        ball.pos = ball.pos + ball.v * dt    #球的末位置 = 前一刻位置 + 速度*時間間隔
        ''''計空氣阻力狀態中球的球'''
        ball2.v = ball2.v + ball2.a*dt          #球的末速度 = 前一刻速度 + 加速度*時間間隔
        ball2.pos = ball2.pos + ball2.v * dt 	#球的末位置 = 前一刻位置 + 速度*時間間隔


        if ball.pos.y <= size and ball.v.y < 0:    #條件：球心高度小於球半徑且速度沿-y軸
                ball.v.y = - ball.v.y    #條件成立則球的速度加一負號表示反彈   

        if ball2.pos.y <= size and ball2.v.y < 0: #同上
                ball2.v.y = - ball2.v.y      

#print (t, ball.v)
