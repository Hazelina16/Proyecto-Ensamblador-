all:
	nasm -f win64 funciones.asm -o funciones.obj
	gcc main.c juego.c funciones.obj -o juego.exe