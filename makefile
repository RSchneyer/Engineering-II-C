# make run f=<FILENAME_WITHOUT_EXTENSION>
all: $(f).exe

run: $(f).exe
	./$(f).exe
	rm $(f).exe

%.exe: %.o
	gcc -o $@ $<

%.o: %.c
	gcc -c $<
     
clean:
	rm $(wildcard *.o) $(wildcard *.exe)

cleanTXT: 
	rm $(wildcard text_files/*.txt) $(wildcard *.txt) 

#Love this shit
toTXT:
	cat $(f).c >> text_files/$(f).txt