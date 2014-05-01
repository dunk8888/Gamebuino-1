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
s = serial.Serial("/dev/ttyACM0", 115200) #port is ttyACM0 (may need to change it depending on your arduino port), and baud rate is 115200
time.sleep(2)    #wait for the Serial to initialize

an = 0
key = ''

def main():
    
    stdscr.addstr(4, 50, "Up")
    stdscr.addstr(6, 50, "Down")   
    stdscr.addstr(5, 40, "Left")
    stdscr.addstr(5, 60, "Right")
	
    key = stdscr.getch()
    
    stdscr.refresh()
    if key == curses.KEY_UP: 
		s.write("v")
		main()
		
        
    if key == curses.KEY_DOWN:
		s.write("z")
		main()
	
    if key == curses.KEY_RIGHT: 
		s.write("r")
		main()
		
    if key == curses.KEY_LEFT: 
		s.write("l")
		main()		
      
       
    if key == ord('q'): 
		curses.endwin()   
        

main()
		


