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

    while (!CheckInput("TUTUP_PROGRAM")) {
        printf(">> ");
        STARTWORD();

        if (!isLogin && CheckInputOption()) {
            printf("Anda harus login terlebih dahulu.\n");
            continue;
        }

        if (CheckInput("DAFTAR")) {
            Daftar(&databasePengguna);
        } else if (CheckInput("MASUK")) {
            Masuk(&databasePengguna);
        } else if (CheckInput("SIMPAN")) {
            Simpan();
        } else if (CheckInput("MUAT")) {
            Muat();
        } else if (CheckInput("KELUAR")) {
            Keluar();
        } else if (CheckInput("GANTI_PROFIL")) {
            gantiProfil(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("LIHAT_PROFIL")) {
            lihatProfil(databasePengguna.user[ActiveUser]);
        } else if (CheckInput("ATUR_JENIS_AKUN")) {
            aturJenisAkun(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("UBAH_FOTO_PROFIL")) {
            UBAH_FOTO_PROFIL(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("DAFTAR_TEMAN")) {
            // Do something
        } else if (CheckInput("HAPUS_TEMAN")) {
            // Do something
        } else if (CheckInput("TAMBAH_TEMAN")) {
            TambahTeman(&dataFriendRequest);
            // Do something
        } else if (CheckInput("DAFTAR_PERMINTAAN_PERTEMANAN")) {
            DaftarPermintaanPertemanan(dataFriendRequest);
            // Do something
        } else if (CheckInput("SETUJUI_PERTEMANAN")) {
            SetujuiPertemanan(&dataFriendRequest);
            // Do something
        } else if (CheckInput("KICAU")) {
            Kicau(&dataKicau);
            // Do something
        } else if (CheckInput("KICAUAN")) {
            Kicauan(dataKicau);
            // Do something
        } else if (CheckInput("SUKA_KICAUAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            Suka_Kicau(&dataKicau, IdKicau);
            // Do something
        } else if (CheckInput("UBAH_KICAUAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            Ubah_Kicau(&dataKicau, IdKicau, ActiveUser);
            // Do something
        } else if (CheckInput("BALAS")) {
            // Do something
        } else if (CheckInput("BALASAN")) {
            // Do something
        } else if (CheckInput("HAPUS_BALASAN")) {
            // Do something
        } else if (CheckInput("BUAT_DRAF")) {
            buatDraft();
            // Do something
        } else if (CheckInput("LIHAT_DRAF")) {
            lihatDraft();
            // Do something
        } else if (CheckInput("UTAS")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            BuatUtas(IdKicau);
        } else if (CheckInput("SAMBUNG_UTAS")) {
            ADVWORD();
            int IdUtas = WordToInt(currentWord);
            ADVWORD();
            int index = WordToInt(currentWord);
            SambungUtas(IdUtas, index);
            // Do something
        } else if (CheckInput("HAPUS_UTAS")) {
            ADVWORD();
            int IdUtas = WordToInt(currentWord);
            ADVWORD();
            int index = WordToInt(currentWord);
            HapusUtas(IdUtas, index);
            // Do something
        } else if (CheckInput("CETAK_UTAS")) {
            ADVWORD();
            int IdUtas = WordToInt(currentWord);
            cetakUtas(IdUtas);
            // Do something
        } else {
            printf("\nPerintah tidak dikenali.\n");
        }
    }   

    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.");
    return 0;
}
