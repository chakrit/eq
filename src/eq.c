#include <stdio.h>
#include <limits.h>

// _____________________________________________________________________________
//                                                                 D E F I N E S
#define BOARD_WIDTH 4
#define BOARD_SIZE (BOARD_WIDTH * BOARD_WIDTH)

typedef int *Board;
typedef char *String;

// _____________________________________________________________________________
//                                                             I N T E R F A C E
void
show_board(Board board)
{
}

// _____________________________________________________________________________
//                                                                   S O L V E R
#if defined(NAIVE)
String
alg_name() { return "Generate-and-verify"; }

long
solve(Board b)
{
  sleep(3);
  return 0;
}

#elif defined(FAST)
String
alg_name() { return "Backtracking"; }

long
solve(Board b)
{
  return 0;
}

#endif

// _____________________________________________________________________________
//                                                                       M A I N
int main()
{
  printf("Board width : %d\r\n", BOARD_WIDTH);
  printf("Board cells : %d\r\n", BOARD_SIZE);
  printf("Algorithm   : %s\r\n", alg_name());
  solve(0);
  return 0;
}

