import serial

Serial_port = 'COM9'
Serial_rate = 57600

data_list = []
summation = []

count = 0
sum_of_four = 0


ser = serial.Serial(Serial_port, Serial_rate)
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
                print(int(sum_of_four))   #total weight
                count = 0
                sum_of_four = 0
