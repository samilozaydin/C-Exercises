#include <stdint.h>
#include <stdio.h>

#ifndef islemler
#define islemler

uint8_t *readFile(char *, int *);
int sizeFile(FILE *);
uint8_t *createArray(int);
uint8_t *sumFile(uint8_t *, uint8_t *, int, int, int *);
void displayNumber(uint8_t *, int);
uint8_t *substractFile(uint8_t *, uint8_t *, int, int, int *, char *);
uint8_t *removeZeros(uint8_t *, int *);
void printIntoFile(uint8_t *, int, char);
void readResult();

#endif