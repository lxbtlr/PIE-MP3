from mpl_toolkits import mplot3d
import os
import serial
import numpy as np
import time 
import re
import math
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns



ser = serial.Serial("COM17",115200) #change the port to 'COM6' if windows

endkey = re.compile(r'DONE')

def sendData(d):
    # sending whatever data we want to the arduino
    ser.write((d+"\r\n").encode())


def receive_data():
    # receiving data over serial from the arduino
    
    line = ""
    while True:
        bytesToRead = ser.inWaiting()
        ip = ser.readline(bytesToRead).decode('utf-8')

        
        
        


def write_data(d):
    # used to record data to csv for other programs
    c = open('savefile.csv','w')
    c.write(str(d)) # putting text into the csv
    c.write("\n")
    c.close()


# Commands:
# Kp value, default 5       KP: X
# base speed                BS: X
# start, stop               START, STOP

def header():
    print("################################")
    print("#        Control Center        #")
    print("#  #")


stillupWINKY = True
while stillupWINKY:

    if True:
        stillupWINKY = False




