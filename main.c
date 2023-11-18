#include "Database/database.h"

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

    Muat();
 
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    
    while (!CheckInput("TUTUP_PROGRAM")){
        printf(">> ");
        STARTWORD();

        if (CheckInput("DAFTAR")) {
            // Do something
        } else if (CheckInput("MASUK")) {
            // Do something
        } else if (CheckInput("KELUAR")) {
            // Do something
        } else if (CheckInput("GANTI_PROFIL")) {
            // Do something
        } else if (CheckInput("LIHAT_PROFIL")) {
            // Do something
        } else if (CheckInput("ATUR_JENIS_AKUN")) {
            // Do something
        } else if (CheckInput("UBAH_FOTO_PROFIL")) {
            // Do something
        } else if (CheckInput("DAFTAR_TEMAN")) {
            // Do something
        } else if (CheckInput("HAPUS_TEMAN")) {
            // Do something
        } else if (CheckInput("TAMBAH_TEMAN")) {
            // Do something
        } else if (CheckInput("DAFTAR_PERMINTAAN_PERTEMANAN")) {
            // Do something
        } else if (CheckInput("SETUJUI_PERTEMANAN")) {
            // Do something
        } else if (CheckInput("KICAU")) {
            // Do something
        } else if (CheckInput("KICAUAN")) {
            // Do something
        } else if (CheckInput("SUKA_KICAUAN")) {
            // Do something
        } else if (CheckInput("UBAH_KICAUAN")) {
            // Do something
        } else if (CheckInput("BALAS")) {
            // Do something
        } else if (CheckInput("BALASAN")) {
            // Do something
        } else if (CheckInput("HAPUS_BALASAN")) {
            // Do something
        } else if (CheckInput("BUAT_DRAF")) {
            // Do something
        } else if (CheckInput("LIHAT_DRAF")) {
            // Do something
        } else if (CheckInput("UTAS")) {
            // Do something
        } else if (CheckInput("SAMBUNG_UTAS")) {
            // Do something
        } else if (CheckInput("HAPUS_UTAS")) {
            // Do something
        } else if (CheckInput("CETAK_UTAS")) {
            // Do something
        } else if (CheckInput("SIMPAN")) {
            // Do something
        } else if (CheckInput("MUAT")) {
            Muat();
        } else {
            printf("\nPerintah tidak dikenali.\n");
        }
    }
    
    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.");
    return 0;
}
