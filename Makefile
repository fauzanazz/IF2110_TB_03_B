CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Mesin-Kar
SRC_MESINKAR = ADT/Mesin-Kata/charmachine.c
OBJ_MESINKAR = $(SRC_MESINKAR:.c=.o)

# Mesin-Kata
SRC_MESINKATA = ADT/Mesin-Kata/wordmachine.c
OBJ_MESINKATA = $(SRC_MESINKATA:.c=.o)

# Mesin-Kar-File
SRC_MESINKARFILE = ADT/Mesin-Kata/charmachine-file.c
OBJ_MESINKARFILE = $(SRC_MESINKARFILE:.c=.o)

# String Function
SRC_STRINGFUNC = ADT/Function/string-function.c
OBJ_STRINGFUNC = $(SRC_STRINGFUNC:.c=.o)

# Pcolor
SRC_PCOLOR = ADT/Pcolor/pcolor.c
OBJ_PCOLOR = $(SRC_PCOLOR:.c=.o)

# Matrix Profil
SRC_MATRIXPROFIL = ADT/matrixprofil/matrixprofil.c
OBJ_MATRIXPROFIL = $(SRC_MATRIXPROFIL:.c=.o)

# Pengguna 
SRC_PENGGUNA = ADT/pengguna/pengguna.c
OBJ_PENGGUNA = $(SRC_PENGGUNA:.c=.o)

# Profil
SRC_PROFIL = ADT/Profil/profil.c
OBJ_PROFIL = $(SRC_PROFIL:.c=.o)

# Date Time
SRC_DATETIME = ADT/Time/datetime.c
OBJ_DATETIME = $(SRC_DATETIME:.c=.o)

# Time
SRC_TIME = ADT/Time/time.c
OBJ_TIME = $(SRC_TIME:.c=.o)

# Kicauan
SRC_LISTDIN = ADT/Kicauan/kicauan.c
OBJ_LISTDIN = $(SRC_LISTDIN:.c=.o)

# PrioQueue
SRC_PRIOQUEUE = ADT/PrioQue/prioqueuefriendrequest.c
OBJ_PRIOQUEUE = $(SRC_PRIOQUEUE:.c=.o)

# # Linked List
# SRC_LINKEDLIST = ADT/LinkedList/LinkedList.c
# OBJ_LINKEDLIST = $(SRC_LINKEDLIST:.c=.o)

# # Tagar
# SRC_TAGAR = ADT/Tagar/tagar.c
# OBJ_TAGAR = $(SRC_TAGAR:.c=.o)

# Graf
SRC_GRAF = ADT/Graf/graf.c
OBJ_GRAF = $(SRC_GRAF:.c=.o)

# ListVertex
SRC_LISTVERTEX = ADT/ListVertex/listvertex.c
OBJ_LISTVERTEX = $(SRC_LISTVERTEX:.c=.o)

# Teman
SRC_TEMAN = ADT/Teman/teman.c
OBJ_TEMAN = $(SRC_LISTTEMAN:.c=.o)

# Tree masih error
SRC_TREE = ADT/Tree/tree.c
OBJ_TREE = $(SRC_TREE:.c=.o)

# Balasan Masih error

# Utas
SRC_UTAS = ADT/Utas/utas.c
OBJ_UTAS = $(SRC_UTAS:.c=.o)

# Database
SRC_DATABASE = Database/database.c
OBJ_DATABASE = $(SRC_DATABASE:.c=.o)

# Muat
SRC_MUAT = IO/muat.c
OBJ_MUAT = $(SRC_MUAT:.c=.o)

# Simpan
SRC_SIMPAN = IO/simpan.c
OBJ_SIMPAN = $(SRC_SIMPAN:.c=.o)

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program

main_program: $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_MESINKARFILE) $(OBJ_STRINGFUNC) $(OBJ_LISTDIN) $(OBJ_PRIOQUEUE) $(OBJ_DATETIME) $(OBJ_TIME) $(OBJ_MAIN) $(OBJ_PCOLOR) $(OBJ_MATRIXPROFIL) $(OBJ_PENGGUNA) $(OBJ_PROFIL) $(OBJ_GRAF) $(OBJ_LISTVERTEX) $(OBJ_TEMAN) $(OBJ_UTAS) $(OBJ_DATABASE) $(OBJ_MUAT) $(OBJ_SIMPAN)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program *.o