/**
 *@file pgmtest.c
 *@brief Testet loadPGM und savePGM
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
 
 	
	int i;
	int w = 0;	
	int h = 0;		
	int* wp = &w;
	int* hp = &h;
	char* fname = "hochalm.pgm";
	unsigned char** pixels;
	
	
	
	pixels = loadPGM(fname, wp, hp);
	
	fname = "hochalm_copy.pgm";
	
	savePGM(fname, pixels, w, h);
	
	/* Gibt allocierten Speicher des arrays frei */
	for (i=0; i < h; ++i) {
  		free(pixels[i]);
	}
	
	free(pixels);
	
	
	return 0;
	
}
