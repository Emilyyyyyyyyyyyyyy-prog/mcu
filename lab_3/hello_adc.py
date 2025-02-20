import time
import serial

port = 'COM3'

ser = serial.Serial(port, 115200)

data = open('data.csv', 'w')
start = time.time()
dtime = 0.25
while time.time() - start < 30:
    ser.write('a'.encode('ascii'))
    vol = ser.read(10).decode('utf-8')
    data.write(str(time.time()-start) + ' ' + str(vol))
    print(vol)
    time.sleep(dtime)



