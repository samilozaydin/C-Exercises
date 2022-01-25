all:fileProgram	run

fileProgram:main.o	islemler.o
	gcc	main.o	islemler.o	-o	project
main.o:main.c
	gcc	-c	main.c
islemler.o:islemler.c	islemler.h
	gcc	-c	islemler.c
clean:
	del	*.o	project.exe
run:
	project.exe