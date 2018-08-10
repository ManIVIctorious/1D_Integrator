# Compiler and Compilerflags
CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror -march=native

EXEDIR = $(if ${MyLocalPath}, ${MyLocalPath}, bin)
EXE = $(EXEDIR)/1d-Integrator

OBJ = main.o InputFunction.o Integral.o
LIB = -lm `pkg-config --cflags --libs gsl`

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

clean:
	rm -f $(OBJ) $(EXE)
