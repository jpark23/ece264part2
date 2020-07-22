#####################################################################################
#                                    PA05 Makefile                                  #
#####################################################################################
# Usefule variables
SRC=main.c parse. school.c
HDR=parse.h school.h
OBJ=$(patsubst %.c,%.o,$(SRC))
INCLUDES=-I./

# Makefile debug statements
$(info Source files: $(SRC))
$(info Header files: $(HDR))
$(info Object files: $(OBJ))

# Recipes
%.o: %.c $(HDR)
	gcc -std=c11 -g -Wall -Werror $(INCLUDES) -c $< -o $@

clean:
	rm -rf *.o
#####################################################################################
#                                     END OF FILE                                   #
#####################################################################################