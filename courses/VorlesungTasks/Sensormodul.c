#include <stdio.h>

int main(void)
{
    unsigned char status = 0xA7;  

    int fehler        = (status & (1 << 7)) != 0;
    int uebertemp     = (status & (1 << 6)) != 0;
    int unterspannung = (status & (1 << 5)) != 0;

    unsigned char messwert = status & 0x0F;

    printf("Status-Byte: 0x%02X\n", status);

    printf("Fehler: %s\n", fehler ? "JA" : "NEIN");
    printf("Übertemperatur: %s\n", uebertemp ? "JA" : "NEIN");
    printf("Unterspannung: %s\n", unterspannung ? "JA" : "NEIN");

    printf("Messwert (Bits 0–3): %u\n", messwert);

    return 0;
}