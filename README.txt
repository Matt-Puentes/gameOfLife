Matthew Puentes jan 30

This program is a simple simulator for "Conway's game of life", a game wherein small autonomous cells are either "Alive" or "Dead" based on 
their neighboring cells.

During the creation of this program most issues and difficulties were encountered early on, as learning how double arrays worked in C provided a
challenge. Once it was covered in class and I did research on my own, the rest of the program proved not too difficult to complete. Most of my
efforts this project went towards helping other people diagnose issues with their code, and helping them on their way to a final product.

All work in this program was my original work.

In order to run this program, you should start in the directory of the .c files, and type "make" in the terminal. You should then create a text file
titled "input" if there is none, and put the desired starting configuration in, with blank spaces marked as 'o' and filled spaces marked as 'x'.
The program can be run as follows, as it is recommended to run this program from terminal. 
./Life [x size of board] [y size of board] [maximum number of generations] [input file name] [whether the program should print any output y/n] [whether the program should wait for a keystroke every generation y/n]
The last two arguments are optional, and default to 'n' or no.
When running with the "pause" feature enabled it is recommended to use the "enter" or "Return" keys to prevent user input from cluttering the output
from the terminal.

Test Cases can be found in the TestCases.txt in this directory



LOOP INVARIANTS (Sorted by file/function):
-------------Board.c-------------
--void printBoard
	for (int j = 0; j < y; j++) //these two for loops increment by one each time. j goes through the columns in the array and i goes through
	for (int i = 0; i < x; i++) //the rows. they iterate until they reach the number of rows/columns respectively.

-------------Life.c-------------

--char** initArray
	for (i = 0; i < x; i++) //i increments by one each loop, and goes until it reaches the number of columns in the array.

--void fillArray
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.

--void fillArrayFromFile
	while (readingFile) {//this loop has two variables, "lengthCounter" and "heightCounter" that iterate when a
		//character is read and when a newline is read respectively. lengthCounter also loops back to zero whenever heightCounter iterates
		//The loop terminates once an EOF character is found.

	while (!(i > maxLengthCounter && j > heightCounter)) {//this loop has two variables, "i" and "j" that iterate when a
		//character is read and when a newline is read respectively. i also loops back to zero whenever j iterates
		//The loop terminates once both i is greater than maxLengthCounter. and y is greater than heightCounter

-------------Game.c-------------

--int getNeighbors
	for (int a = 1; a >= -1; a--) {//These two loops are used to go "around" a point in a 2D array. a and b both iterate from 1 to -1, going
	for (int b = 1; b >= -1; b--) {//down by one each loop. The loop terminates when both variables get to -1.

--void updateBoard
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.

	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.

--void backupBoard
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
	
--void checkRepeats
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.

--void checkDead
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
	for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.

--void gameLoop
	for (int i = 0; i <= gens; i++) { //this loop iterates i to the number of generations it is supposed to run. i increments at the end of the loop.