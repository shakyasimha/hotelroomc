#ifndef SETCONSOLECURSORPOSITION_H_INCLUDED
#define SETCONSOLECURSORPOSITION_H_INCLUDED

#ifndef CONSOLEFUNCTIONS_H_INCLUDED
#define CONSOLEFUNCTIONS_H_INCLUDED

#include <windows.h>

//gotoxy() function starts here:

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }

//End of gotoxy() function


#endif // CONSOLEFUNCTIONS_H_INCLUDED


#endif // SETCONSOLECURSORPOSITION_H_INCLUDED
