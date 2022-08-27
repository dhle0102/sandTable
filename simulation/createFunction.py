import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import math

def readFile(xNeed,yNeed):
    f = open("heart.gcode", "r")
    for i in f.readlines():
        i = i[1:len(i)-2]
        #print(i)
        x = i.split(' ')[1]
        y = i.split(' ')[2]
        print(x+y)
        #print(x)
        #print(y)
        #x0 = float(x)*math.cos(math.pi/2) + float(y)*math.sin(math.pi/2)
        #y0 = float(x)*(-(math.sin(math.pi/2))) + float(y)*math.cos(math.pi/2)
        #xNeed.append(float(x0+4))
        #yNeed.append(float(y0))
        #xNeed.append(float(x))
        #yNeed.append(float(y))
        xNeed.append(x)
        yNeed.append(y)
    f.close()
    saveFileGcode(xNeed,yNeed)

def saveFileGcode(xNeed,yNeed):
    f = open("heart.txt",'w')
    for i in range(0,len(xNeed)):
        a = xNeed[i] + yNeed[i] + "\n" 
        f.write(a)
    f.close()

def drawPlot(xNeed,yNeed):
    plt.plot(xNeed,yNeed,'-')
    plt.grid(True)
    plt.show()
    plt.xlim((-220,220))
    plt.ylim((-220,220))
    #saveFileGcode(xNeed,yNeed)

def convertValue(xNeed,yNeed):
    for i in range(0,len(xNeed)):
        g = '{' + str(xNeed[i]) + ',' + str(yNeed[i]) + '},'
        print(g)

if __name__ == "__main__":
    print("begin create function: ")
    xNeed = []
    yNeed = []
    readFile(xNeed,yNeed)
    #x = np.array(xNeed)
    #y = np.array(yNeed)
    drawPlot(xNeed,yNeed)
    #convertValue(xNeed,yNeed)
    #saveFileGcode(xNeed,yNeed)
    #simlutionValue(xNeed,yNeed)