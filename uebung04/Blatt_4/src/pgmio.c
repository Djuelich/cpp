#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Kein echtes readline da es nur in bestimmten Faellen ganze Zeilen liest */
char *readLine(FILE *file) {

	if (file == NULL) {
		printf("Error: file pointer is null");
		exit(1);
	}
	
	int maxLineLength = 128;
	char *lineBuffer = (char *)malloc(sizeof(char) * maxLineLength);
	
	if (lineBuffer == NULL) {
		printf("Error allocating memory for line buffer.");
		exit(1);
	}
	
	char ch = getc(file);
	int count = 0;
	
	/* Erlaubt keine Leerzeichen am Wort- oder Zeilenanfang */
	while(ch == ' ' || ch == '\t'){
		ch = getc(file);
	}
	/* Wenn Kommentar dann wird ganze Zeile gelesen, ansonsten nur ein Wort */
	if (ch == '#') {
		while ((ch != '\n') && (ch != EOF)) {
			if (count == maxLineLength) {
				maxLineLength += 128;
				lineBuffer = realloc(lineBuffer, maxLineLength);
				if (lineBuffer == NULL) {
				printf("Error reallocating space for line buffer.");
				exit(1);
				}
			}
			lineBuffer[count] = ch;
			count++;
			ch = getc(file);
		}
	}
	else{
		while ((ch != '\t') && (ch != ' ') && (ch != '\n') && (ch != EOF)) {
			if (count == maxLineLength) {
				maxLineLength += 128;
				lineBuffer = realloc(lineBuffer, maxLineLength);
				if (lineBuffer == NULL) {
				printf("Error reallocating space for line buffer.");
				exit(1);
				}
			}
			lineBuffer[count] = ch;
			count++;
			ch = getc(file);
		}
	}
	if(count < maxLineLength - 1) {
		lineBuffer[count] = '\0';
	}
	else {
		maxLineLength += 1;
		lineBuffer = realloc(lineBuffer, maxLineLength);
			if (lineBuffer == NULL) {
				printf("Error reallocating space for line buffer.");
				exit(1);
			}
			lineBuffer[count] = '\0';
	}
	return lineBuffer;
}

void savePGM(char* filename, unsigned char** pixels, int w, int h){
	
	int i,j;
	
	FILE* fp;
	fp = fopen(filename,"w");
	fprintf(fp,"P2\n");
	fprintf(fp,"%d\n", w);
	fprintf(fp,"%d\n", h);
	fprintf(fp,"255\n");
	
	for(i=0;i<h;i++){ 			
		for(j=0;j<w;j++){ 	
			fprintf(fp,"%d\n",pixels[i][j]);
		}
	}
	
}

unsigned char** loadPGM(char* filename, int* w, int* h)	{
	FILE* fp;
 	char* c;
 	int i,j;
 	unsigned char** arr;
 	
 	
	fp = fopen(filename, "r+");
	
	if(fp != NULL) {
		c = readLine(fp);
			/* prueft ob es sich um pgm datei handelt */
			if (c[0] != 'P' || c[1] != '2'){				
				free(c);
				printf("Error: the filetype is not PGM\n");
				exit(1);
			}
		free(c);
		
		
		/* setzt w */
		c = readLine(fp);
			/* ueberspringt Kommentare */
			while (c[0] == '#'){
			free(c);
			c = readLine(fp);
			}
		*w = atoi(c);
		free(c);
		
		/* setzt h */
		c = readLine(fp);
		*h = atoi(c);
		free(c);
		
		/* ueberspringt maximalen Farbwert */
		c = readLine(fp);
		free(c);
		
	
		/* allociert speicher fuer array mit h zeilen und w spalten */
		arr = (unsigned char **)malloc(*h * sizeof(unsigned char *));
   		for (i=0; i < *h; i++){
        	arr[i] = (unsigned char *)malloc(*w * sizeof(unsigned char));
		}
		
		/* fuellt array */
		for (i = 0; i <  *h; i++){
			for (j = 0; j < *w; j++){
				c = readLine(fp);
				arr[i][j] = (unsigned char)atoi(c);
				free(c);
			}
		}
		return arr;
	}
	printf("Error: Datei wurde nicht gefunden oder ist leer\n");
	exit(1);
}
	
	

