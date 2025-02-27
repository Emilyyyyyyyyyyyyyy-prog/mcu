import time
import serial

port = 'COM3'

ser = serial.Serial(port, 115200)

data_hum = open('data_hum.csv', 'w')
data_pres = open('data_pres.csv', 'w')
data_temp = open('data_temp.csv', 'w')

start = time.time()
dtime = 0.25
while time.time() - start < 30:
    ser.write('f'.encode('ascii'))
    humidity = ser.read(7).decode('utf-8')
    pressure = ser.read(8).decode('utf-8')
    temperature = ser.read(7).decode('utf-8')
    data_hum.write(str(time.time()-start) + ' ' + str(humidity))
    data_pres.write(str(time.time()-start) + ' ' + str(pressure))
    data_temp.write(str(time.time()-start) + ' ' + str(temperature))
    print(humidity, pressure, temperature)
    time.sleep(dtime)

