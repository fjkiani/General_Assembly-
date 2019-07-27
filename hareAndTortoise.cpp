
// tortoiseandhare.cpp
#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>
#include <ctime>
#include <iomanip>
using std::setw;

const int RACE_END = 70;

/* prototype to moveTortoise  */
void moveTortoise (int *tortoise);
/* prototype to moveHare */
void moveHare (int *hare);
/* prototype for current position */
void currentPosition (int *, int *);


int main()
{
  //init variables 
   int tortoise = 1; 
   int hare = 1;
   int timer = 0;

   srand( time( 0 ) );

   cout << "ON YOUR MARK, GET SET\nBANG               !!!!"
        << "\nAND THEY�RE OFF    !!!!\n";
   
   // controls race
   while ( tortoise != RACE_END && hare != RACE_END ) {
      /* Write call for moveTortoise here */
      moveTortoise (&tortoise);
      /* Write call for moveHare here */
      moveHare (&hare);
      /* Write call for printCurrentPositions here */
      currentPosition (&tortoise, &hare);

      ++timer;

   } // end while

   // determine winner
   if ( tortoise >= hare )
      cout << "\nTORTOISE WINS!!! YAY!!!\n";

   else
      cout << "Hare wins. Yuch.\n";

   cout << "TIME ELAPSED = " << timer << " seconds" << endl;

   return 0;

   
} // end main

// move tortoise
/* Write function definition header for moveTortoise here */
void moveTortoise (int *turtlePtr) {

   int x = 1 + rand() % 10;

   // determine which move to make
   if ( x >= 1 && x <= 5 )        // fast plod
      *turtlePtr += 3;

   else if ( x == 6 || x == 7 )   // slip
      *turtlePtr -= 6;

   else                           // slow plod
      ++( turtlePtr );
   
   // ensure that tortoise remains within subscript range
   if ( *turtlePtr < 1 )
      *turtlePtr = 1;

   else if ( *turtlePtr > RACE_END )
      *turtlePtr = RACE_END;

} // end function moveTortoise

// move hare
/*function definition for moveHare */
void moveHare (int *harePtr) {


   int y = 1 + rand() % 10;

   /* statements that move hare */
   if ( y >= 1 && y <= 5 )        // fast plod
      *harePtr += 3;

   else if ( y == 6 || y == 7 )   // slip
      *harePtr -= 6;

   else                           // slow plod
      ++( *harePtr );
   
   // ensure that tortoise remains within subscript range
   if ( *harePtr < 1 )
      *harePtr = 1;

  
   /* Write statements that test if hare is before
      the starting point or has finished the race */
     else if ( *harePtr > RACE_END )
      *harePtr = RACE_END;

} // end function moveHare

// output positions of animals
/*  function definition for printCurrentPositions */
void currentPosition (int *snapperPtr, int *bunnyPtr) {
   if ( *bunnyPtr == *snapperPtr ) 
      cout << setw( *bunnyPtr ) << "OUCH!!!";      

   else if ( *bunnyPtr < *snapperPtr ) 
      cout << setw( *bunnyPtr ) << "H" 
           << setw( *snapperPtr - *bunnyPtr ) << "T";

   else
      cout << setw( *snapperPtr ) << "T" 
           << setw( *bunnyPtr - *snapperPtr ) << "H";

   cout << "\n";

} // end function printCurrentPositions


