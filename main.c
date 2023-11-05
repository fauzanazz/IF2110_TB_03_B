#include <stdio.h>
#include "ADT/Function/string-function.h"
#include "ADT/Kicauan/kicauan.h"

int main(){

    // ASCII ART BURBIR
    printf("              _____                    _____                    _____                    _____                    _____                    _____           \n");
    printf("             /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\          \n");
    printf("            /::\\    \\                /::\\____\\                /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\         \n");
    printf("           /::::\\    \\              /:::/    /               /::::\\    \\              /::::\\    \\               \\:::\\    \\              /::::\\    \\        \n");
    printf("          /::::::\\    \\            /:::/    /               /::::::\\    \\            /::::::\\    \\               \\:::\\    \\            /::::::\\    \\       \n");
    printf("         /:::/\\:::\\    \\          /:::/    /               /:::/\\:::\\    \\          /:::/\\:::\\    \\               \\:::\\    \\          /:::/\\:::\\    \\      \n");
    printf("        /:::/__\\:::\\    \\        /:::/    /               /:::/__\\:::\\    \\        /:::/__\\:::\\    \\               \\:::\\    \\        /:::/__\\:::\\    \\     \n");
    printf("       /::::\\   \\:::\\    \\      /:::/    /               /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\              /::::\\    \\      /::::\\   \\:::\\    \\    \n");
    printf("      /::::::\\   \\:::\\    \\    /:::/    /      _____    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    ____    /::::::\\    \\    /::::::\\   \\:::\\    \\   \n");
    printf("     /:::/\\:::\\   \\:::\\ ___\\  /:::/____/      /\\    \\  /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\ ___\\  /\\   \\  /:::/\\:::\\    \\  /:::/\\:::\\   \\:::\\____\\  \n");
    printf("    /:::/__\\:::\\   \\:::|    ||:::|    /      /::\\____\\/:::/  \\:::\\   \\:::|    |/:::/__\\:::\\   \\:::|    |/::\\   \\/:::/  \\:::\\____\\/:::/  \\:::\\   \\:::|    | \n");
    printf("    \\:::\\   \\:::\\  /:::|____||:::|____\\     /:::/    /\\::/   |::::\\  /:::|____|\\:::\\   \\:::\\  /:::|____|\\:::\\  /:::/    \\::/    /\\::/   |::::\\  /:::|____| \n");
    printf("     \\:::\\   \\:::\\/:::/    /  \\:::\\    \\   /:::/    /  \\/____|:::::\\/:::/    /  \\:::\\   \\:::\\/:::/    /  \\:::\\/:::/    / \\/____/  \\/____|:::::\\/:::/    /  \n");
    printf("      \\:::\\   \\::::::/    /    \\:::\\    \\ /:::/    /         |:::::::::/    /    \\:::\\   \\::::::/    /    \\::::::/    /                 |:::::::::/    /   \n");
    printf("       \\:::\\   \\::::/    /      \\:::\\    /:::/    /          |::|\\::::/    /      \\:::\\   \\::::/    /      \\::::/____/                  |::|\\::::/    /   \n");
    printf("        \\:::\\  /:::/    /        \\:::\\__/:::/    /           |::| \\::/____/        \\:::\\  /:::/    /        \\:::\\    \\                  |::| \\::/____/      \n");
    printf("         \\:::\\/:::/    /          \\::::::::/    /            |::|  ~|               \\:::\\/:::/    /          \\:::\\    \\                 |::|  ~|             \n");
    printf("          \\::::::/    /            \\::::::/    /             |::|   |                \\::::::/    /            \\:::\\    \\                |::|   |           \n");
    printf("           \\::::/    /              \\::::/    /              \\::|   |                 \\::::/    /              \\:::\\____\\               \\::|   |           \n");
    printf("            \\::/____/                \\::/____/                \\:|   |                  \\::/____/                \\::/    /                \\:|   |           \n");
    printf("             ~~                       ~~                       \\|___|                   ~~                       \\/____/                  \\|___|    \n");
    printf("\n\n");

    //* Inisialisasi ---------------------------------

    // Load path konfigurasi
    char folder;
    printf("Silahkan masukkan folder untuk dimuat: ");
    //TODO: Implementasikan mesin kata
    scanf("%s", &folder);

    // Load File
    FILE *balasan;
    FILE *draf;
    FILE *kicauan;
    FILE *pengguna;
    FILE *utas;
    
    //! Belum di implementasikan mesin kata
    // buka file
    balasan = fopen("Config/balasan.config","r");
    draf = fopen("Config/draf.config","r");
    kicauan = fopen("Config/kicauan.config","r");
    pengguna = fopen("Config/pengguna.config","r");
    utas = fopen("Config/utas.config","r");


    // Cek file
    // if (balasan == NULL|| draf == NULL|| kicauan == NULL|| pengguna == NULL|| utas == NULL) {
    //     printf("File tidak dapat dibuka.\n");
    //     return 1;
    // }

    printf("File konfigurasi berhasil dimuat!\n");
    
    //* Inisialisasi ---------------------------------

    //* Input -------------------------------------

    //TODO: Implementasikan Mesin kata
    while (1)
    {
        // Buat input
        char input;
        printf(">> ");
        STARTWORD();

        if (CheckInput("DAFTAR")){
            printf("Anda telah memilih untuk mendaftar.\n");
        } else if (CheckInput("MASUK")) {
            
        } else if (CheckInput("KELUAR")) {
            
        } 
    }
    
    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.");
    return 0;
}
