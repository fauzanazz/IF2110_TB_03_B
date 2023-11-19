#include "Database/database.h"
#include "IO/muat.h"
#include "IO/simpan.h"

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

    //* Inisialisasi --------------------------------

    int muat = 0;

    do {
        muat = Muat();
    }
    while (!muat);

    printf("Selamat berkicau!\n");

    while (!CheckInput("TUTUP_PROGRAM")){
        printf(">> ");
        STARTWORD();

        if (CheckInput("DAFTAR")) {
            Daftar(&databasePengguna);
        } else if (CheckInput("MASUK")) {
            Masuk(&databasePengguna);
        } else if (CheckInput("KELUAR")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }

            Keluar();
        } else if (CheckInput("GANTI_PROFIL")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            gantiProfil(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("LIHAT_PROFIL")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            lihatProfil(databasePengguna.user[ActiveUser]);
        } else if (CheckInput("ATUR_JENIS_AKUN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            aturJenisAkun(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("UBAH_FOTO_PROFIL")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            UBAH_FOTO_PROFIL(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("DAFTAR_TEMAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("HAPUS_TEMAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("TAMBAH_TEMAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("DAFTAR_PERMINTAAN_PERTEMANAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("SETUJUI_PERTEMANAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("KICAU")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("KICAUAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("SUKA_KICAUAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("UBAH_KICAUAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("BALAS")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("BALASAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("HAPUS_BALASAN")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("BUAT_DRAF")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("LIHAT_DRAF")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("UTAS")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("SAMBUNG_UTAS")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("HAPUS_UTAS")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("CETAK_UTAS")) {
            if (!isLogin){
                printf("\nAnda harus login terlebih dahulu.\n");
                continue;
            }
            // Do something
        } else if (CheckInput("SIMPAN")) {
            Simpan();
        } else if (CheckInput("MUAT")) {
            Muat();
        } else if (!CheckInput("TUTUP_PROGRAM")){
            printf("\nPerintah tidak dikenali.\n");
        }
    }
    
    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.");
    return 0;
}
