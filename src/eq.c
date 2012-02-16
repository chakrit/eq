#include <stdio.h>

#if defined(NAIVE)
#define MODE_STR "Generate-and-verify algorithm."
#elif defined(FAST)
#define MODE_STR "Backtracking algorithm."
#else
#define MODE_STR "Unknown mode :/"
#endif

int main()
{
  printf(MODE_STR);
  printf("\r\n");
  return 0;
}

