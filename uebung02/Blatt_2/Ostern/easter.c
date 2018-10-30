#include <stdio.h>
#include <stdlib.h>
/**
 * @file easter.c
 * @brief Berechnet Datum von Ostern 
 * 
 * Es werdern Jahreszahlen aus einer Datei gelesen und mit dem jeweiligen Datum
 * von Ostern in eine anderer Datei geschrieben. Das Datum fuer Ostern wird 
 * in diesem Programm berechnet.
 *
 * @author Daniel Kliewer
 * @author Dominik Jülich
 *
 *return 0
 */
int main(void)
{ 
  int i;
  int year, goldy, cent, skippedly;
  int cofa, epact, d, n;    


  FILE *in, *out;

  in  = fopen("./years.in","r");
  out = fopen("./easter_dates.out","w+");
  
  for (i = 0; i < 8; i++){
  
    fscanf(in,"%d", &year);
 
    goldy 	= (year % 19) + 1;
    cent 	= (year / 100) + 1;
    skippedly 	= (3 * cent / 4) - 12;
    cofa 	= ((8 * cent + 5) / 25) - 5;
    d		= (5 * year / 4) - skippedly - 10;
    epact	= (11 * goldy + 20 + cofa - skippedly) % 30;
    n		= 44 - epact;
    n 		= n + 7 - ((d + n) % 7);

    if (n > 31){
      n = n - 31;
      fprintf(out,"%d - April %d \n", year, n);  
    }
    else  fprintf(out,"%d - March %d \n", year, n);  
  }

  fclose(in);
  fclose(out);
  

    printf("Es ist vollbracht\n");
    return 0;
}
