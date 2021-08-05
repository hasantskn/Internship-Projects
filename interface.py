from tkinter import *
import RPi.GPIO as GPIO
import time
from threading import Timer,Thread,Event

pencere=Tk()
frame1= Frame(pencere)
frame1.pack()
frame2= Frame(pencere)
frame2.pack()

RELAY_PIN_K8 = 29
RELAY_PIN_K7 = 31
RELAY_PIN_K6 = 33
RELAY_PIN_K5 = 35
RELAY_PIN_K4 = 19
RELAY_PIN_K3 = 23

																																																											


def run():
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K8, GPIO.OUT, initial= GPIO.HIGH)
	GPIO.output(RELAY_PIN_K8, GPIO.LOW)

	sistem_low_timer = Timer(5 , pinKapat_K8)
	sistem_low_timer.start()
																																																											
		

def run_1():

	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K7, GPIO.OUT, initial=GPIO.HIGH)
	GPIO.output(RELAY_PIN_K7, GPIO.LOW)

	sistem_low_timer = Timer(5 , pinKapat_K7)
	sistem_low_timer.start()
		
def run_2():
	
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K6, GPIO.OUT, initial=GPIO.HIGH)
	GPIO.output(RELAY_PIN_K6, GPIO.LOW)

	sistem_low_timer = Timer(5 , pinKapat_K6)
	sistem_low_timer.start()
       

def run_3():

	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K5, GPIO.OUT, initial=GPIO.HIGH)
	GPIO.output(RELAY_PIN_K5, GPIO.LOW)

	sistem_low_timer = Timer(5 , pinKapat_K5)
	sistem_low_timer.start()
def run_4():

	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K4, GPIO.OUT, initial=GPIO.HIGH)
	GPIO.output(RELAY_PIN_K4, GPIO.LOW)
	
	sistem_low_timer = Timer(5 , pinKapat_K4)
	sistem_low_timer.start()

def run_5():
     
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(RELAY_PIN_K3, GPIO.OUT, initial=GPIO.HIGH)
	GPIO.output(RELAY_PIN_K3, GPIO.LOW)
	sistem_low_timer = Timer(5 , pinKapat_K3)
	sistem_low_timer.start()

def pinKapat_K8():
	GPIO.output(RELAY_PIN_K8, GPIO.HIGH)
	
def pinKapat_K7():
	GPIO.output(RELAY_PIN_K7, GPIO.HIGH)
		
def pinKapat_K6():
	GPIO.output(RELAY_PIN_K6, GPIO.HIGH)

def pinKapat_K5():
	GPIO.output(RELAY_PIN_K5, GPIO.HIGH)
	
def pinKapat_K4():
	GPIO.output(RELAY_PIN_K4, GPIO.HIGH)

def pinKapat_K3():
	GPIO.output(RELAY_PIN_K3, GPIO.HIGH)
	
	
	

		
        
        
buton1 = Button(text = "Relay K8",fg="black",bg="yellow",command = run)
buton2 = Button(text = "Relay K7",fg="black",bg="yellow",command = run_1)
buton3 = Button(text = "Relay K6",fg="black",bg="yellow",command = run_2)
buton4 = Button(text = "Relay K5",fg="black",bg="yellow",command = run_3)
buton5 = Button(text = "Relay K4",fg="black",bg="yellow",command = run_4)
buton6 = Button(text = "Relay K3",fg="black",bg="yellow",command = run_5)

buton1.pack()
buton2.pack()
buton3.pack()
buton4.pack()
buton5.pack()
buton6.pack()


pencere.mainloop()
