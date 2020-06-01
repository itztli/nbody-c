#!/usr/bin/env python3

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from time import sleep
#from matplotlib.animation import FuncAnimation
import matplotlib.patches as patches


ccolor=['k','r','g']
# Data for plotting

#t = np.arange(0.0, 2.0, 0.01)
#s = 1 + np.sin(2 * np.pi * t)

with open("view3D.dat") as f:
    data = f.readlines()

iterations, npeople, x_As, x_Bs, y_As, y_Bs,z_As, z_Bs, r_circle = data[0].split("\t")
x_A = float(x_As)
x_B = float(x_Bs)
y_A = float(y_As)
y_B = float(y_Bs)
z_A = float(z_As)
z_B = float(z_Bs)
r_circle=float(r_circle)
skip = 0

iterations = iterations[1:]

npeople = int(npeople)
iterations = int(iterations)

X = [[] for x in range(npeople)]
Y = [[] for x in range(npeople)]
Z = [[] for x in range(npeople)]
C = [[] for x in range(npeople)]


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

#fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2,2,gridspec_kw={'width_ratios': [7,2], 'height_ratios': [7,2],'left':0.05, 'right':0.95, 'bottom':0.05, 'top':0.95, 'wspace':0.05, 'hspace':0.05})
#ax3.set_xlim([0, iterations])

iterator = 0
new_sick_vector = []
bar_x=[]

for line in data[1:]:
    if "#" in line[0]:
        ax.cla()
        ax.set_xlim3d(x_A,x_B)
        ax.set_ylim3d(y_A,y_B)
        ax.set_zlim3d(z_A,z_B)
        #ax.axis([x_A, x_B,  y_A, y_B, z_A, z_B])
        
        #iteration, healty,sick,immune,dead,new_sick = line.split("\t")
        iteration=int(line[1:])
        #new_sick = int(new_sick)
        #if new_sick > 0:
        #    bar_x.append(iteration+1)
        #    new_sick_vector.append(new_sick)
        #    ax3.bar(bar_x,new_sick_vector,width=10.0,color='b')

            #print(new_sick_vector)
        #ax3.set(xlabel='x', ylabel='y',
        #       title='TICS UNAM Transmission')
        #ax1.axis([x_A, x_B,  y_A, y_B])
        #ax3.bar([100.0],[1.0])
        #ax1.grid()
        iterator = 0
    else:
        mass, position, velocity = line.split("\t")
        position = position[1:-1]
        #print(position)
        mass=float(mass)
        x,y,z = position.split(",")
        x = float(x)
        y=float(y)
        z=float(z)
        print(x,y,z)
        #v_x,v_y,v_z = velocity.split(",")
        #v_x = float(v_x)
        #v_y=float(v_y)
        #v_z=float(v_z)
        ax.scatter(x, y, z)
        
        #circle = plt.Circle((x, y), r_circle, color=ccolor[c])
        #ax1.add_artist(circle)
        iterator = iterator + 1

    if (iterator == npeople):
        #rect = patches.Rectangle((-47,-42),24,24,color='k',alpha=0.2,fill=True)
        #ax1.add_patch(rect)
        #ax1.text(-45,-25, "Healty: "+healty , fontsize=12)
        #ax1.text(-45,-30, "Sick: "+sick, fontsize=12,color='r')
        #ax1.text(-45,-35, "Immune: "+immune, fontsize=12,color='g')
        #ax1.text(-45,-45, "Dead: "+dead,color='b', fontsize=12)        
        plt.draw()
        #plt.show()        
        #break
        #if (skip==1000):
        
        fig.savefig("animation2/"+("%08d"%iteration)+"-view3D.png")
        #skip=0
        #skip=skip+1
