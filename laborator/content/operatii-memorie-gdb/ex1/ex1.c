#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
    //PARCURGEREA DIN 1 IN 1
    // int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    // unsigned char *char_ptr = (char *)v;
    // for (int i = 0; i < sizeof(v) / sizeof(unsigned char); i++ ) {
    //     printf("%p -> 0x%x\n", char_ptr + i, *(char_ptr + i));
    // }

    //PARCURGEREA DIN 2 IN 2
    // int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    // short *short_ptr = (short *)v;
    // for (int i = 0; i < sizeof(v) / sizeof(short); i++ ) {
    //     printf("%p -> 0x%x\n", short_ptr + i, *(short_ptr + i));
    // }

    //PARCURGEREA DIN 4 IN 4
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    int *int_ptr = (int *)v;
    for (int i = 0; i < sizeof(v) / sizeof(int); i++ ) {
        printf("%p -> 0x%x\n", int_ptr, *(int_ptr + i));
    }

    return 0;
}
