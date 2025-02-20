import serial

port = 'COM3'
baudrate = 9600

ser = serial.Serial(port, baudrate=baudrate)

t = 'hello!\n'
ser.write(t.encode('utf-8'))
print(ser.read(6).decode('utf-8'))


