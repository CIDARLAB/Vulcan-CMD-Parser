import serial
import time

#Lets you set a value to set the syringe pump to.

ser = serial.Serial('COM3',9600)  # open serial port


time.sleep(2)

keepGoing = True


byteList = bytearray([1, 1, 1, 185
                         #, 56, 30, 147, 3, 210,
                      #89, 111, 78, 184, 151, 17, 129
                         ])

#max range
#byteList = bytearray([1, 1, 2, 1, 244
#                          #, 56, 30, 147, 3, 210,
#                       #89, 111, 78, 184, 151, 17, 129
#                         ])

while keepGoing:
    ser.reset_input_buffer()

    #write the data
    ser.write(byteList)
    time.sleep(2)
    # Reads the incoming data
    data = ser.read(ser.inWaiting())
    # print int(data.encode('bin'), 2)
    print data
ser.close()             # close port