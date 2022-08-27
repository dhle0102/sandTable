import math
import numpy as np
import matplotlib.pyplot as plt
fileRun = "5.txt"
fileSave = "5.txt"
xNeed = []
yNeed = []

def drawPlot(xNeed,yNeed):
    plt.plot(xNeed,yNeed,'-')
    plt.grid(True)
    plt.xlim((-190,190))
    plt.ylim((-190,190))
    plt.show()

def splitText(i):
    i = i[1:len(i)]
    x = i.split('Y')[0]
    y = i.split('Y')[1]
    return x,y

def splitGcode(i):
    i = i[0:len(i)-1]
    #print(i)
    x = i.split(' ')[1][1:]
    y = i.split(' ')[2][1:]
    #print(x," ",y)
    return x,y

def runSaveFile():
    f = open(fileRun, "r")
    for i in f.readlines():
        #print(i)
        #x,y = splitGcode(i)
        x,y = splitText(i)
        xNeed.append(float(x))
        yNeed.append(float(y))
        f.close()
    drawPlot(xNeed,yNeed)
    #checkphangiai(xNeed,yNeed)
    #aveFileGcode(xNeed,yNeed)

def saveFileGcode(xNeed,yNeed):
    f = open(fileSave,'w')
    for i in range(0,len(xNeed)):
        a = "X" + str(xNeed[len(xNeed)-i-1]) + "Y" + str(yNeed[len(xNeed)-i-1]) + "\n" 
        f.write(a)
    f.close()

def checkphangiai(xNeed,yNeed):
    a = 0
    for i in range(0,len(xNeed)-2):
        x = (xNeed[i] - xNeed[i+1])*(xNeed[i] - xNeed[i+1])
        y = (yNeed[i] - yNeed[i+1])*(yNeed[i] - yNeed[i+1])
        d = math.sqrt(x+y)
        if(d > 10):
            a = a +1 
            print(d, " ",i )
    print(a)
if __name__ == "__main__" :
    runSaveFile() 
    print("hello")