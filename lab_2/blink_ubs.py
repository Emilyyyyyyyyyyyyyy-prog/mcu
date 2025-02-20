import time
import serial

port = 'COM3'
baudrate = 9600

ser = serial.Serial(port, baudrate=baudrate)

while 1:
    ser.write('e'.encode('ascii'))
    time.sleep(0.5)
    ser.write('d'.encode('ascii'))
    time.sleep(0.5)
