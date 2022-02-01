import serial 
import time 
import pyautogui

ArduinoSerial = serial.Serial('COM',9600) 
time.sleep(2) #wait for 2 seconds 

while 1:
    incoming = str (ArduinoSerial.readline()) #read the serial data 
    print incoming
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        pyautogui.hotkey('ctrl', 'left')  

    if 'Forward' in incoming:
        pyautogui.hotkey('ctrl', 'right') 

    if 'Vup' in incoming:
        pyautogui.hotkey('ctrl', 'down')
        

    if 'Vdown' in incoming:
        pyautogui.hotkey('ctrl', 'up')

    incoming = "";
    