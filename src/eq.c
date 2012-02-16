#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// _____________________________________________________________________________
//                                                                 D E F I N E S
#define BOARD_W 10
#define BOARD_H 10
#define BOARD_SIZE (BOARD_W * BOARD_H)

#define CELL_BLANK '.'
#define CELL_QUEEN 'Q'
#define CELL_BAD 'x'

typedef char Cell;
typedef Cell *Board;
typedef const char *String;

// Memoize x y ?
#define XY(x_, y_) (y_ * BOARD_H + x_)

#define BOARD_LOOP(block_) do {   \
  int xi, yi;                       \
  for (yi = 0; yi < BOARD_H; yi++)   \
    for (xi = 0; xi < BOARD_W; xi++) \
    { block_; }                   \
} while(0);

// _____________________________________________________________________________
//                                                                   E N G I N E
Board
new_board()
{
  Board board = (Board)malloc(sizeof(Cell) * BOARD_SIZE);
  BOARD_LOOP({ board[XY(xi, yi)] = CELL_BLANK; });

  return board;
}

void
show_board(Board board)
{
  BOARD_LOOP({
    if (xi == 0) printf("\r\n");
    putchar(board[XY(xi, yi)]);
  });

  printf("\r\n");
}

bool
can_place_queen(Board board, int x, int y)
{
  int i, xi, yi;
  Cell cell;

  // straight search (assume square board)
  for (i = 0; i < BOARD_W; i++)
    if (board[XY(i, y)] == CELL_QUEEN || board[XY(x, i)] == CELL_QUEEN)
      return false;

  // diag search
  for (xi = x + 1, yi = y + 1; (xi < BOARD_W) && (yi < BOARD_H); xi++, yi++)
    if (board[XY(xi, yi)] == CELL_QUEEN)
      return false;

  for (xi = x + 1, yi = y - 1; (xi < BOARD_W) && (0 <= yi); xi++, yi--)
    if (board[XY(xi, yi)] == CELL_QUEEN)
      return false;

  for (xi = x - 1, yi = y + 1; (0 <= xi) && (yi < BOARD_H); xi--, yi++)
    if (board[XY(xi, yi)] == CELL_QUEEN)
      return false;

  for (xi = x - 1, yi = y - 1; (0 <= xi) && (0 <= yi); xi--, yi--)
    if (board[XY(xi, yi)] == CELL_QUEEN)
      return false;

  // no threatening queen in sight
  return true;
}

void
place_queen(Board board, int x, int y)
{
  board[XY(x, y)] = CELL_QUEEN;
}

void
remove_queen(Board board, int x, int y)
{
  // TODO: Assert there is a queen
  board[XY(x, y)] = CELL_BLANK;
}

bool
validate_board(Board board)
{
  // replay all queens each with can_place_queen
  Board reference = new_board();
  BOARD_LOOP({
    switch (board[XY(xi, yi)]) {
    case CELL_BLANK: break;
    case CELL_QUEEN:
      if (!can_place_queen(reference, xi, yi)) {
        free(reference);
	reference = 0;
        return false;
      }
      
      place_queen(reference, xi, yi);
      break;
    }
  });

  free(reference);
  reference = 0;
  return true;
}

// _____________________________________________________________________________
//                                                                   S O L V E R
#if defined(NAIVE)
String
alg_name() { return "Generate-and-verify"; }

bool
try_column(Board b, int column)
{
  if (column >= BOARD_W)
    return validate_board(b);

  int yi;
  for (yi = 0; yi < BOARD_H; yi++) {
    place_queen(b, column, yi);
    if (try_column(b, column + 1))
      return true;

    remove_queen(b, column, yi);
  }

  return false;
}

bool
solve(Board b)
{
  return try_column(b, 0);
}

// _____________________________________________________________________________
#elif defined(FAST)
String
alg_name() { return "Backtracking"; }

bool
try_column(Board b, int column)
{
  if (column >= BOARD_W)
    return validate_board(b);

  int yi;
  for (yi = 0; yi < BOARD_H; yi++) {
    if (can_place_queen(b, column, yi)) {
      place_queen(b, column, yi);
      if (try_column(b, column + 1))
	return true;

      remove_queen(b, column, yi);
    }
  }

  return false;
}

long
solve(Board b)
{
  return try_column(b, 0);
}

#endif

// _____________________________________________________________________________
//                                                                       M A I N
int
main()
{
  // banner
  printf("Board width : %d\r\n", BOARD_W);
  printf("Board cells : %d\r\n", BOARD_SIZE);
  printf("Algorithm   : %s\r\n", alg_name());

  // inits
  Board board = new_board();

  // solver
  printf("Initial ---");
  show_board(board);

  if (solve(board))
    printf("Solved  ---");
  else
    printf("FAILED  ---");

  show_board(board);

  // cleanup
  free(board);
  board = 0;

  return 0;
}

