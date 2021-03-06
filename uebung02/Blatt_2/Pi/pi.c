#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @file pi.c
 * @brief Monte-Carlo-Bestimmung der Kreiszahl Pi
 * 
 * Die Kreiszahl Pi wird bestimmt indem um einen Kreis mit
 * dem Radius 1 ein Quadrat gelegt wird. Dann werden zufällig 
 * Punkte in dieses Quadrat gesetzt und geguckt wie oft ein Punkt
 * im Kreis landet. Aus der Trefferquote laesst sich Pi experimentell
 * bestimmen, welche dann auf dem Terminal ausgegeben wird.
 * 
 * @author Daniel Kliewer
 * @author Dominik Jülich
 *
 * @return 0
 */
int main(void){
  
  int niter = 0;
  double x, y;
  int i, count = 0;
  double z, pi;
  int seed = time(NULL);

  printf("Anzahl der Stichproben: ");
  scanf("%d",&niter);
  
  srand(seed);
  
  for (i = 0; i < niter; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    z = x * x + y * y;
    if (z <= 1) count++;
  /* printf("%.2f %.2f\n",x,y); */
  }

  pi= (double)count / niter * 4;
  printf("Anzahl der Stichproben: %d, Pi ist ungefaehr: %g \n",niter,pi);
return 0;
}
