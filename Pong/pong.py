#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial
import time
import curses
stdscr = curses.initscr()
curses.cbreak()
stdscr.keypad(1)

stdscr.addstr(0,0,"Hit 'q' to quit")
stdscr.refresh()
s = serial.Serial("/dev/ttyACM1", 115200) #port is 11 (for COM12), and baud rate is 9600
#time.sleep(2)    #wait for the Serial to initialize

an = 0
key = ''

def main():

    
    
    key = stdscr.getch()
    
    stdscr.refresh()
    if key == curses.KEY_UP: 
		s.write("v")
		main()
		#key = stdscr.getch()
       # stdscr.addstr(2, 51, "Up")
       # stdscr.refresh()
        
       
        
        
    if key == curses.KEY_DOWN:
		s.write("z")
		main()
		#key = stdscr.getch()
        #stdscr.addstr(6, 50, "Down")
        
       # stdscr.refresh()
       
    if key == ord('q'): 
		curses.endwin()   
        

main()
		


