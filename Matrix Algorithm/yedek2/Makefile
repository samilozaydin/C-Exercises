all:matrisProgram	run

matrisProgram:mainProgram.o	matrisoperations.o
	gcc	mainProgram.o	matrisoperations.o	-o	project
mainProgram.o:mainProgram.c
	gcc	-c	mainProgram.c
matrisoperations.o:matrisoperations.c	matrisoperations.h
	gcc	-c	matrisoperations.c
clean:
	del	*.o	project.exe
run:
	project.exe