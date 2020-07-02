SRC=main.c
OBJ=$(patsubst %.c, %.o, $(SRC))

exe: $(OBJ)
	gcc $(OBJ) -o exe
	./exe

%.o: %.c 
	gcc -c -g -Wall -Werror -std=c11 $<

clean:
	rm exe *.o
	clear