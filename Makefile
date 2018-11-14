all: image.o convert.o main.o
        gcc $^ -o point
        rm *.o
        
image.o: image.c
        gcc -c image.c
convert.o: convert.c
        gcc -c convert.c
main.o: main.c
        gcc -c main.c
