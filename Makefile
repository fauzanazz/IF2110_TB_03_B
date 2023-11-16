CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Mesin-Kar
SRC_MESINKAR = ADT/Mesin-Kata/charmachine.c
OBJ_MESINKAR = $(SRC_MESINKAR:.c=.o)

# Mesin-Kata
SRC_MESINKATA = ADT/Mesin-Kata/wordmachine.c
OBJ_MESINKATA = $(SRC_MESINKATA:.c=.o)

SRC_INISIALISASI = ADT/Function/string-function.c
OBJ_INISIALISASI = $(SRC_INISIALISASI:.c=.o)

SRC_DATETIME = ADT/Time/datetime.c
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)

SRC_TIME = ADT/Time/time.c
OBJ_TIME = $(SRC_TIME:.c=.o)

SRC_LISTDIN = ADT/Kicauan/kicauan.c
OBJ_LISTDIN = $(SRC_LISTDIN:.c=.o)

SRC_PRIOQUEUE = ADT/PrioQue/prioqueuefriendrequest.c
OBJ_PRIOQUEUE = $(SRC_PRIOQUEUE:.c=.o)

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)


.PHONY: all clean test

all: main_program

main_program: $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_INISIALISASI) $(OBJ_LISTDIN) $(SRC_PRIOQUEUE) $(OBJ_DATETIME) $(OBJ_TIME) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program *.o