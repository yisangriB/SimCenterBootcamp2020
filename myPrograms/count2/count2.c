#include <stdio.h>

int main(int argc, char **argv) {
  char c;
  int nDigit=0, nWhite=0, nOther =0;
  while ((c==getchar()) != EOF ){

    if (c=='0'||c=='1'||c=='2'||c=='3')
      nDigit++;
    else if(c==' ')
      nWhite++;
    else
      nOther++;

  }
  printf("digites: %i, %i, %i\n",nDigit,nWhite,nOther);
  return 0;
}
