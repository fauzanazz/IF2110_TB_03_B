#include <stdio.h>
#include "time.h"

int main() {
    // Test IsTIMEValid
    printf("IsTIMEValid(12, 30, 45): %s\n", IsTIMEValid(12, 30, 45) ? "true" : "false");
    printf("IsTIMEValid(25, 30, 45): %s\n", IsTIMEValid(25, 30, 45) ? "true" : "false");
    printf("IsTIMEValid(12, 70, 45): %s\n", IsTIMEValid(12, 70, 45) ? "true" : "false");
    printf("IsTIMEValid(12, 30, 70): %s\n", IsTIMEValid(12, 30, 70) ? "true" : "false");

    // Test CreateTime
    TIME T;
    CreateTime(&T, 12, 30, 45);
    printf("CreateTime: %02d:%02d:%02d\n", Hour(T), Minute(T), Second(T));

    // Test BacaTIME
    printf("Enter a valid time (HH MM SS): ");
    BacaTIME(&T);
    printf("BacaTIME: %02d:%02d:%02d\n", Hour(T), Minute(T), Second(T));

    // Test TulisTIME
    printf("TulisTIME: ");
    TulisTIME(T);
    printf("\n");

    // Test TIMEToDetik
    long detik = TIMEToDetik(T);
    printf("TIMEToDetik: %ld\n", detik);

    // Test DetikToTIME
    TIME T2 = DetikToTIME(detik);
    printf("DetikToTIME: %02d:%02d:%02d\n", Hour(T2), Minute(T2), Second(T2));

    // Test TEQ
    printf("TEQ(T, T2): %s\n", TEQ(T, T2) ? "true" : "false");

    // Test TNEQ
    printf("TNEQ(T, T2): %s\n", TNEQ(T, T2) ? "true" : "false");

    // Test TLT
    printf("TLT(T, T2): %s\n", TLT(T, T2) ? "true" : "false");

    // Test TGT
    printf("TGT(T, T2): %s\n", TGT(T, T2) ? "true" : "false");

    // Test NextDetik
    TIME nextDetik = NextDetik(T);
    printf("NextDetik: %02d:%02d:%02d\n", Hour(nextDetik), Minute(nextDetik), Second(nextDetik));

    // Test NextNDetik
    TIME nextNDetik = NextNDetik(T, 10);
    printf("NextNDetik: %02d:%02d:%02d\n", Hour(nextNDetik), Minute(nextNDetik), Second(nextNDetik));

    // Test PrevDetik
    TIME prevDetik = PrevDetik(T);
    printf("PrevDetik: %02d:%02d:%02d\n", Hour(prevDetik), Minute(prevDetik), Second(prevDetik));

    // Test PrevNDetik
    TIME prevNDetik = PrevNDetik(T, 10);
    printf("PrevNDetik: %02d:%02d:%02d\n", Hour(prevNDetik), Minute(prevNDetik), Second(prevNDetik));

    // Test Durasi
    TIME TAw, TAkh;
    CreateTime(&TAw, 12, 30, 45);
    CreateTime(&TAkh, 13, 30, 45);
    long durasi = Durasi(TAw, TAkh);
    printf("Durasi: %ld detik\n", durasi);

    return 0;
}