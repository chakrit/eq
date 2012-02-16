#include <stdio.h>
#include <limits.h>

// _____________________________________________________________________________
//                                                                 D E F I N E S
#define BOARD_W 4
#define BOARD_H 4
#define BOARD_SIZE (BOARD_W * BOARD_H)

#define CHAR_BORDER '…'
#define CHAR_BLANK '.'
#define CHAR_QUEEN 'Q'

typedef char Cell;
typedef char *Flags;
typedef char *Board;
typedef char *String;

// our coordinate system
int xy(int x, int y) { return y * BOARD_W + x; }

// _____________________________________________________________________________
//                                                             I N T E R F A C E
void
show_board(Board board)
{
  int x, y;
  for (y = 0; y < BOARD_H; y++)
    for (x = 0; x < BOARD_W; x++)
    {
      
    }
}

// allocs
Board alloc_board() { return (Board)malloc(sizeof(Cell) * BOARD_SIZE); }
Flags alloc_flags() { return (Flags)malloc(sizeof(Cell) * BOARD_W); }

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
  // banner
  printf("Board width : %d\r\n", BOARD_W);
  printf("Board cells : %d\r\n", BOARD_SIZE);
  printf("Algorithm   : %s\r\n", alg_name());

  // inits
  Board game = alloc_board();

  // solver
  solve(0);

  // cleanup
  free(game);

  return 0;
}

