import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import math

def readFile(xNeed,yNeed):
    f = open("starFull.gcode", "r")
    for i in f.readlines():
        i = i[4:len(i)-2]
        x = i.split(' ')[0][1:]
        y = i.split(' ')[1][1:]
        #print(x)
        #print(y)
        #x0 = float(x)*math.cos(math.pi/2) + float(y)*math.sin(math.pi/2)
        #y0 = float(x)*(-(math.sin(math.pi/2))) + float(y)*math.cos(math.pi/2)
        #xNeed.append(float(x0+4))
        #yNeed.append(float(y0))
        xNeed.append(float(x))
        yNeed.append(float(y))
    f.close()

def saveFileGcode(xNeed,yNeed):
    f = open("starFull.gcode",'w')
    for i in range(0,len(xNeed)):
        x = round(xNeed[i],3)
        y = round(yNeed[i],3)
        a = "G01 X" + str(x) + " Y" + str(y) + "\n" 
        f.write(a)
    f.close()

def drawPlot(xNeed,yNeed):
    plt.plot(xNeed,yNeed,'-')
    plt.grid(True)
    plt.show()
    saveFileGcode(xNeed,yNeed)

def convertValue(xNeed,yNeed):
    for i in range(0,len(xNeed)):
        g = '{' + str(xNeed[i]) + ',' + str(yNeed[i]) + '},'
        print(g)

if __name__ == "__main__":
    print("begin create function: ")
    xNeed = []
    yNeed = []
    readFile(xNeed,yNeed)
    x = np.array(xNeed)
    y = np.array(yNeed)
    drawPlot(xNeed,yNeed)
    #convertValue(xNeed,yNeed)
    #saveFileGcode(xNeed,yNeed)
    #simlutionValue(xNeed,yNeed)