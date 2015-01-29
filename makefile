#makefile

FLD = ./fieldline/fieldline

all: main.o $(FLD).o
	g++ -o main main.o $(FLD).o

fieldline.o: $(FLD).cpp $(FLD).h funcs.h
	g++ -o $(FLD).o -c $(FLD).cpp

main.o: main.cpp funcs.h
	g++ -o main.o -c main.cpp

# removes all object files, main exectuable and backup files
clean:
	rm *.o $(FLD).o main *~
