/*
* @file matrisoperations.h
* @description This program is a matrix algorithm.
* @assignment Project 1
* @date 11.12.2021
* @author Samil Bilal OZAYDIN samilbilal.ozaydin@stu.fsm.edu.tr
*/

#ifndef matrisoperations
#define matrisoperations

int **operasyon1(int **, int **, int, int, int);
void matrisYazdirma(int **, int);
void matrisFree(int **, int);
int **matrisOlustur(int);
void notExpandedMatrisOperation(int **, int **, int **, int, int, int);
void temporaryMatrisOlustur(int *, int *, int, int, int, int);
void temporaryMatrisYazdir(int *, int);
void cozumMatrisDoldur(int *, int *, int *, int, int);
void ExpandedMatrisOperation(int **, int **, int **, int, int, int);
void expandedMatrisDoldur(int **, int **, int, int);
void matrisDoldur(int **, int);

#endif