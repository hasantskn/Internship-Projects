import RPi.GPIO as GPIO
import time
import serial
relay_pin = 35

Serial_port = 'COM7'
Serial_rate = 57600

data_list = []
summation = []

count = 0
sum_of_four = 0

GPIO.setmode(GPIO.BOARD)
GPIO.setup(relay_pin, GPIO.OUT, initial=GPIO.HIGH)

ser = serial.Serial(Serial_port, Serial_rate)

try:
    while True:
        reading = ser.readline().decode('utf-8').strip('\n')
        if(reading =='***********************yeniden kalibre ediliyor...****************************\r'):
            print('***********************yeniden kalibre ediliyor...****************************\r')
            continue
        count += 1
       
        data_list.append(float(reading))
        sum_of_four += float(reading)
        
        
        if(count % 4 == 0):
            summation.append(sum_of_four)
            if(10 > sum_of_four > -10 ):
                print('0')
            else:
                print(int(sum_of_four))
                
            if(sum_of_four > 30 ):
                GPIO.output(relay_pin, GPIO.LOW)
                time.sleep(2)
            else:
                GPIO.output(relay_pin, GPIO.HIGH)
                time.sleep(2)
            count = 0
            sum_of_four = 0
except KeyboardInterrupt:
    print("Exception: KeyboardInterrupt")
finally:
    GPIO.cleanup()
