# make run f=<FILENAME_WITHOUT_EXTENSION>
all: main.exe

run: main.exe
	./main.exe
	rm main.exe

%.exe: %.c
	gcc -o $@ $< functions.c

clean:
	rm $(wildcard *.o) $(wildcard *.exe)

cleanTXT: 
	rm $(wildcard *.txt)

#Love this shit
toTXT:
	cat main.c >> main.txt