import serial
import time

ser = serial.Serial('COM3',9600)  # open serial port

#Just establishes Serial communication and sends stuff over. The arduino should write it back.

time.sleep(2)

keepGoing = True

n = 500

byteList = bytearray([1, 1, 1,2, 2, 1, 150
                         #, 56, 30, 147, 3, 210,
                      #89, 111, 78, 184, 151, 17, 129
                         ])


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
