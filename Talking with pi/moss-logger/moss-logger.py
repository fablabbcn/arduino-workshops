#!/usr/bin/env python


import os
import sys 
import serial 
import time
import datetime


def getDateTime():
  timeNow = time.strftime("%H:%M:%S")
  dateToday = time.strftime("%m/%d/%y")
  return [dateToday, timeNow]


def writeToCsv(datalist):
  header = ["Date","Time","Hum","Temp","IRlight","VLight","VLight","FLight","Lux"]

  fileName = str("logs/" +time.strftime("%y_%m_%d_")+ "moss_log.csv")
  if os.path.exists(fileName):
    f = open(fileName, "a")
  else:
    f = open(fileName, "a+")
    for element in header:
      f.write(element + ",")
    f.write("\n")

  for element in datalist:
    if type(element)==str:
      f.write(element + ",")
    if type(element) == list:
      for i in element:
        f.write(i + ",")
  f.write("\n")
  f.close()


def mainLoop():

  global geolookup

  data = []
  ser = serial.Serial("/dev/ttyACM0", 9600)
  print "Serial Initialized!"

  while 1:
    if ser.inWaiting():
      datetimeData = getDateTime()

      for i in datetimeData:
        data.append(i)

      val = ser.readline().strip('\r\n').split(' ')
      
      for i in range(0, len(val)):
        sensorData = val[i].split(',')
        data.append(sensorData)


      try: 
        writeToCsv(data)
      except:
        print "Error while saving data to CSV file"

      data = []

      time.sleep(1)

mainLoop()