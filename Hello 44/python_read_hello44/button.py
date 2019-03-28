
# Works with button_serial_simple_hello44.ino

import serial
import webbrowser  

serialPort = serial.Serial(port = '/dev/tty.usbserial-FT9OYH06', baudrate=9600,
                           bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

prevFirstCharacter = '0'

while(1):
    if(serialPort.in_waiting > 0):

        serialString = serialPort.readline()
        print(serialString)

        firstCharacter = serialString[0];


        if(firstCharacter == '1' and prevFirstCharacter == '0'):
			webbrowser.open_new_tab('https://www.youtube.com/watch?v=nsv7OzujbLE')

        prevFirstCharacter = firstCharacter
