#include <stdio.h>
#include <ctype.h>
int main(int argc, char **argv){
  char c;
  int nDigit=0, nWhite=0, nOther =0;
  while ((c=getchar()) != EOF) {
    if((c==' ')||(c=='\n')||(c=='\t')) {
      nWhite++;
      // } else if ((c=='0')||(c=='1')||(c=='2')||(c=='3')||(c=='4')||(c=='5')||(c=='6')||(c=='7')||(c=='8')||(c=='9')){
    }else if (isdigit(c)){
    nDigit++;
  } else {
    nOther++;
  }}
  printf("%i \n",nWhite);
  printf("%i \n",nDigit);
  printf("%i \n",nOther);
  return 0;
}
