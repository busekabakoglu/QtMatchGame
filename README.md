Authors : Buse Kabakoğlu, Fatih Akgöz
# CmpE 230 Project 3 Report
## Problem:
Writing a simple card matching game in qt using C++ and QtCreator.
## Solution:
We mostly worked with MainWindow class and UI.  
We added 2 QLabel to write “Tries:” and “Pairs:” on top of the window.  
We added 2 LCDDisplays to write corresponding numbers of tries and matches found.  
We added a QButton RESET to restart the matching game.  
We added 24 Buttons as cards to match.  
All 24 buttons were added to a buttongroup.  
A dictionary of Buttons and Labels is used as internal values of the buttons.  
We used the signal of the buttonGroup to with a parameter int to perform necessary
operations when a button is pressed.  
Signal of the buttonGroup is connected to hello slot of MainWindow class.  
Signal of RESET button is connected to reset slot of MainWindow class.  
reset method of MainWindow class shuffles the cards and Restart the game to its
initial position.  
hello method handles clicks of each button manipulating the text and activity of the
buttons also changing the aforementioned LCD displays.  
