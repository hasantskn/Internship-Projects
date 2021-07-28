import serial
import time

SERIAL_PORT = 'COM7'
SERIAL_RATE = 57600

def main():
    ser = serial.Serial(SERIAL_PORT, SERIAL_RATE)
    while True:
        for i in range(10,0,-1):
            reading = ser.readline().decode('utf-8').rstrip()
            print(reading)
            time.sleep(0.5)
                
            if(i%5==0):
                ser.write(b'j')
            
if __name__ == "__main__":
    main()
        