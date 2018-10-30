#include <stdio.h>
/**
 * Familie Meier 
 * 
 * @file meier.c
 * @brief Testet alle moeglichen Kombinationen der Familie Meier
 *
 * Dieses Programm testet welche Kombinatioen von Familienmitgliedern 
 * zusammen feiern können.
 *
 * @author Daniel Kliewer
 * @author Dominik Jülich
 *
 * @return 0
 */
int main (void){

int a, b, c, d;					/*Alfons, Beate, Class, Doerte */

printf("A B C D \n");

  for(a = 0; a < 2; a++){
    for(b = 0; b < 2; b++){
      for(c = 0; c < 2; c++){ 
        for(d = 0; d < 2;d++){
       
  printf("%d %d %d %d  ", a, b, c, d);

  if(a || b || c || d){  			/*Mindestens einer geht zur Feier*/
    if(a && d){					/*Alfons und Dörte passen nicht*/
      printf("Passt nicht\n");
    }
    else{
      if(!b || (b && c)){  			/*Wenn Beate geht, geht Class auch*/
        if((a && c && !b) || !a || !c){		/*Wenn A und C gehen, geht Beate nicht*/
          if (a || (!a && (!d != !c))){		/*Wenn A nicht geht, geht entweder D oder C*/
	    printf("Passt\n");
	  }
	
	  else printf("Passt nicht\n");
        }
        else printf("Passt nicht\n");
      }
      else printf("Passt nicht\n");
    } 			
  } 
  else printf("Passt nicht\n"); 

        }
      }
    }
  }
return 0;
}
