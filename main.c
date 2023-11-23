#include "Database/database.h"
#include "IO/muat.h"
#include "IO/simpan.h"

void help(boolean isLogin) {
    printf("\nFungsi yang dapat diakses saat ini:\n\n");
    printf("- DAFTAR\n");
    printf("- MASUK\n");
    printf("- SIMPAN\n");
    printf("- MUAT\n");
    printf("- HELP\n");
    printf("- TUTUP_PROGRAM\n");

    if (isLogin) {
        printf("- GANTI_PROFIL\n");
        printf("- LIHAT_PROFIL [namaUser]\n");
        printf("- ATUR_JENIS_AKUN\n");
        printf("- UBAH_FOTO_PROFIL\n");
        printf("- TAMBAH_TEMAN\n");
        printf("- DAFTAR_PERMINTAAN_PERTEMANAN\n");
        printf("- DAFTAR_TEMAN\n");
        printf("- HAPUS_TEMAN\n");
        printf("- SETUJUI_PERTEMANAN\n");
        printf("- KICAU\n");
        printf("- KICAUAN\n");
        printf("- SUKA_KICAUAN [Id_Kicau]\n");
        printf("- UBAH_KICAUAN [Id_Kicau]\n");
        printf("- BALAS [Id_Kicau] [Id_Balasan]\n");
        printf("- BALASAN [Id_Kicau]\n");
        printf("- HAPUS_BALASAN [Id_Kicau] [Id_Balasan]\n");
        printf("- BUAT_DRAF\n");
        printf("- LIHAT_DRAF\n");
        printf("- UTAS [Id_Kicau]\n");
        printf("- SAMBUNG_UTAS [Id_Utas] [Index_Utas]\n");
        printf("- HAPUS_UTAS [Id_Utas ] [Index_Utas]\n");
        printf("- CETAK_UTAS [Id_Utas]\n");
    } 

    printf("\n");
}

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

    printf("Selamat berkicau!\n\n");
    printf("\nUntuk melihat daftar perintah yang dapat diakses, ketik 'HELP'.\n");

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
            IgnoreBlanks();

            char* temp = "";

            while (!EOP)
            {
               temp = stringConcatChar(temp, currentChar);
               ADV();
            }
            
            int idUser = idPengguna(temp);

            lihatProfil(databasePengguna.user[idUser]);
        } else if (CheckInput("ATUR_JENIS_AKUN")) {
            aturJenisAkun(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("UBAH_FOTO_PROFIL")) {
            UBAH_FOTO_PROFIL(&databasePengguna.user[ActiveUser]);
        } else if (CheckInput("DAFTAR_TEMAN")) {
            daftarTeman(ActiveUser);

        } else if (CheckInput("HAPUS_TEMAN")) {
            hapusTeman(ActiveUser);

        } else if (CheckInput("TAMBAH_TEMAN")) {
            TambahTeman(&dataFriendRequest);

        } else if (CheckInput("DAFTAR_PERMINTAAN_PERTEMANAN")) {
            DaftarPermintaanPertemanan(dataFriendRequest);

        } else if (CheckInput("SETUJUI_PERTEMANAN")) {
            SetujuiPertemanan(&dataFriendRequest);

        } else if (CheckInput("KICAU")) {
            Kicau(&dataKicau);

        } else if (CheckInput("KICAUAN")) {
            Kicauan(dataKicau);

        } else if (CheckInput("SUKA_KICAUAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            Suka_Kicau(&dataKicau, IdKicau);

        } else if (CheckInput("UBAH_KICAUAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            Ubah_Kicau(&dataKicau, IdKicau, ActiveUser);

        } else if (CheckInput("BALAS")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            ADVWORD();
            int IdBalasan = WordToInt(currentWord);

            Balas(IdKicau, IdBalasan);

        } else if (CheckInput("BALASAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);

            Balasan(IdKicau);
        } else if (CheckInput("HAPUS_BALASAN")) {
            ADVWORD();
            int IdKicau = WordToInt(currentWord);
            ADVWORD();
            int IdBalasan = WordToInt(currentWord);

            HapusBalasan(IdKicau, IdBalasan);
        } else if (CheckInput("BUAT_DRAF")) {
            buatDraft();

        } else if (CheckInput("LIHAT_DRAF")) {
            lihatDraft();

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

        } else if (CheckInput("HAPUS_UTAS")) {
            ADVWORD();
            int IdUtas = WordToInt(currentWord);
            ADVWORD();
            int index = WordToInt(currentWord);
            HapusUtas(IdUtas, index);

        } else if (CheckInput("CETAK_UTAS")) {
            ADVWORD();
            int IdUtas = WordToInt(currentWord);
            cetakUtas(IdUtas);

        } else if (CheckInput("HELP")) {
            help(isLogin);
        } 
        else if (!CheckInput("TUTUP_PROGRAM")){
            printf("\nPerintah tidak dikenali.\n");
            printf("Untuk melihat daftar perintah yang dapat diakses, ketik 'HELP'.\n");
        }
    }   

    printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.");
    return 0;
}
