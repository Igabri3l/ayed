#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
  char c;

  printf("(getch example) please type a letter...");
  c = getch();
  printf("\nYou typed: %c\n", c);

  printf("(getche example) please type a letter: ");
  c = getche();
  printf("You typed: %c\n", c);

  return 0;

}