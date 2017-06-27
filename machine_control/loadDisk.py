import serial
from time import sleep

try:
    ser = serial.Serial("/dev/ttyACM0", 115200)
except:
    ser = serial.Serial("/dev/ttyACM1", 115200)


sleep(1)
ser.write(b"GO S2 D \n")
print("S2 move")

