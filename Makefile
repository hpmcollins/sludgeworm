all:
	windres app.rc -O coff -o app.o
	gcc main.c app.o -o swrm.exe -mwindows
elongated:
	windres app.rc -O coff -o app.o
	gcc main.c app.o -o sludgeworm.exe -mwindows
resmaker:
	windres app.rc -O coff -o app.o
