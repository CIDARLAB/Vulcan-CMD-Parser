import serial
import time

ser = serial.Serial('COM3',9600)  # open serial port

#Sends constantly changing values over to the arduino.

time.sleep(2)

servo_min = 185
servo_max = 500

j = servo_min

while j < 255:
    byteList = bytearray([1, 1, 1, j
                          # , 56, 30, 147, 3, 210,
                          # 89, 111, 78, 184, 151, 17, 129
                          ])
    j+=1
    ser.reset_input_buffer()
    ser.write(byteList)
    time.sleep(2)

j = 0

while j < 244:
    byteList = bytearray([1,1,2,1,j])
    j+=1
    ser.reset_input_buffer()
    ser.write(byteList)
    time.sleep(2)

time.sleep(3)
# data = ser.read(ser.inWaiting())
    # if len(data) == 8:
# print data
print("We done")