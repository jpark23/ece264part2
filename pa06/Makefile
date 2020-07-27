#####################################################################################
#                                    PA06 Makefile                                  #
#####################################################################################
SRC=main.c parse.c grade.c
HDR=parse.h grade.h
OBJ=$(patsubst %.c,%.o,$(SRC))
INCLUDES=-I./

$(info Source files: $(SRC))
$(info Header files: $(HDR))
$(info Object files: $(OBJ))

prog: $(OBJ) $(HDR)
	gcc -o $@ $^

%.o: %.c $(HDR)
	gcc -std=c11 -g -Wall -Werror $(INCLUDES) -o $@ -c $<

clean:
	rm -rf *.o prog
#####################################################################################
#                                     END OF FILE                                   #
#####################################################################################