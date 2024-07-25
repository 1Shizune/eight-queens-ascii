# eight-queens-ascii
Eight Queens Fancy Print 

For the Fancy Print eight queens' problem the 1-D backtracking algorithm was used to find every 
solution to an 8x8 chess board. Every time an answer was generated, it would be sent to an 
edited print function which can print the visuals of an 8x8 chess board with the queens in the 
positions determined by the array with the solution. The print function achieves this via its 
definition of a box object; A box object is a 5x7 array of characters which can be used to create a 
single spot or square of a chess board. With a box now defined, three box objects are declared 
bb, wb, and *board [8][8]; bb is used for the black boxes in a chess board whereas wb is for the 
white. *board [8][8], being an 8x8 pointer to boxes can be used to fill up the array with already 
defined white and black box variables, in turn creating the chess board look. 
Two more box variables are created, bq and wq. These two box variables represent the visuals of 
a queen which can be user defined character values to fill up the 5x7 array of a box. Black and 
white queens are used on opposite color boxes of the board array so that they are visible when 
they are placed. After all the variables which make up a chess board are defined are ready to be 
used, a for loop is created with the goal is searching through the 1-D array, comparing each 
index to its chess board representation, and placing a queen opposite color of the specific square 
in the board. The board is printed via the use of nested for loops which oversee what is printed in 
each position of the chess board with the use of box pointers (*board[I][j]) and with specified 
parts of a white and black box via [k][l]. 
