//Persio Sanchez
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

void print(int q[]) {
   static int solution = 0;
   int i, j, k, l;
   typedef char box[5][7];   // Define a new structure called a box, which is a char array that is 5x7 spaces 
   box bb, wb, *board[8][8]; // board is an 8x8 array of pointers to boxes.
                             

   // Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
   // You only need to create one of each, since the chessboard can contain many pointers to the same box.
   
   for (i=0; i<5; i++) //Define what a White and Black box look like
      for (j=0; j<7; j++) {
         wb[i][j] = ' ';
         bb[i][j] = char(219);
      }
   
   //The look of a queen is defined here, the char's are placed in a way that allows the queen's to be highlighted when they are placed on a different colored background
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

   for(i=0; i<8; i++) //Create the look of a board, which alternates between the white color(&wb) and black color(&bb)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb; //board array doesnt store the visuals of a white or black box, it gets them from the pointer values
         else
            board[i][j] = &bb;
   
   // Set up the current solution on the chessboard by placing pointers to bq and wq in the appropriate squares.
   // i.e. connect solutions q[] with fancy queen bq/wq via pointer board
   // Write the code.

   cout << "Solution #" << ++solution << ":\n ";
   
   // Print upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   for (int i = 0; i < 8; i++) //Get the row position of the queen in column i 
   {
    	int row = q[i];  
    	if ((i + row) % 2 == 0) // If the square is black, use a white queen  
		{        
    		board[row][i] = &wq;
    	} 
			else // If the square is white, use a black queen
			{		
    			board[row][i] = &bq;
    		}
}
   
   
   // Print the board
   for (i=0; i<8; i++)          // for each board row
      for (k=0; k<5; k++) {     // for each box row
         cout << char(179);
         for (j=0; j<8; j++)    // for each board column
            for (l=0; l<7; l++) // for each box column               
               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      
	  			// board[i][j] is the box pointer in the ith row, jth column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.
	  
	  }

   cout << " ";
   for (i=0; i<7*8; i++) //Bottom border of the board
      cout << char(196);
   cout << "\n\n";
}

int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;

    while (c >= 0) {  
        c++;
        if (c > 7) //Send each solution to the print function to get a new board    
		{      
            print(q);     
            c--;
        }
        else q[c] = -1;
        while (c >= 0) 
		{ 
        	q[c]++;          
            if (q[c] > 7) c--; 
            else              
            
				if (ok(q, c)) break; 
        }
    }
    return 0;
}
