# -*- coding: utf-8 -*-
"""
Created on Sat Jul  3 14:27:10 2021

@author: hasantskn
"""
import serial


SERIAL_PORT = 'COM7'
SERIAL_RATE = 57600

def main():
    ser = serial.Serial(SERIAL_PORT, SERIAL_RATE)
    while True:
        
        reading = ser.readline().decode('utf-8')
        print(reading)


if __name__ == "__main__":
    main()
        

    


    

