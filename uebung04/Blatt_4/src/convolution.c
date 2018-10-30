/**
 *@file convolution.c
 *@brief Wendet Filter auf pgm Bild an
 *
 *
 * @author Daniel Kliewer
 * @author Dominik Jülich
 *
 * return 0
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmio.h"

int main (void){
 
 	
	int i, j, k, l;
	int w = 0;	
	int h = 0;		
	int* wp = &w;
	int* hp = &h;
	char* fname = "hochalm.pgm";
	unsigned char** pixels;
	float ergebnis;
	/* Kernel */
	float arr[5][5] = { { 0.00366, 0.01465, 0.02564, 0.01465, 0.00366 }, 
						{ 0.01465, 0.05861, 0.09524, 0.05861, 0.01465 }, 
						{ 0.02564, 0.09524, 0.15018, 0.09524, 0.02564 }, 
						{ 0.01465, 0.05861, 0.09524, 0.05861, 0.01465 }, 
						{ 0.00366, 0.01465, 0.02564, 0.01465, 0.00366 } };
	
	pixels = loadPGM(fname, wp, hp);
	
	fname = "hochalm_convolution.pgm";
		
		
	for (i = 0; i <  h; i++) {
			for (j = 0; j < w; j++) {
				/* Randpixel werden weiß gemacht */
				if(i < 2 || j < 2 || h < (i+3) || w < (j+3)) {
				pixels[i][j] = 255;
				}
				else {
					/* Die zwischenergebnisse werden schrittweise zu 'ergebnis' aufaddiert und 
					 * erst als vollstaendige Summe an das Pixel uebergeben  
					 */
					ergebnis = 0;
					for (k = 0; k <  5; k++) {
						for (l = 0; l < 5; l++) {
							ergebnis = ergebnis + arr[k][l] * pixels[i + k - 2][j + l - 2];						}
					}
					pixels[i][j] = (unsigned char)ergebnis;
				}
			}
	}
		
		
		
	savePGM(fname, pixels, w, h);
	
	
	
	/* Gibt allocierten Speicher des arrays frei */
	for (i=0; i < h; ++i) {
  		free(pixels[i]);
	}
	
	free(pixels);
	
	
	return 0;
	
}
