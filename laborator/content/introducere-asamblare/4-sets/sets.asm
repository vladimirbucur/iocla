%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx
    mov eax, 139
    mov ebx, 169
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

    ; TODO1: reuniunea a doua multimi
    mov ecx, eax
    or ecx, ebx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO2: adaugarea unui element in multime
        ; adaugarea elementelor 3 4
    or eax, 8
    or eax, 16
    PRINTF32 `%u\n\x0`, eax

    ; TODO3: intersectia a doua multimi
    mov edx, eax
    and edx, ebx
    PRINTF32 `%u\n\x0`, edx

    ; TODO4: complementul unei multimi
    mov ecx, eax
    not ecx
    PRINTF32 `%u\n\x0`, ecx

    ; TODO5: eliminarea unui element
    ; elimin {3}
    mov edx, 8    ; (2^3)
    not edx
    and eax, edx
    PRINTF32 `%u\n\x0`, eax

    ; TODO6: diferenta de multimi EAX-EBX
    mov edx, eax
    and edx, ebx
    xor edx, eax
    PRINTF32 `%u\n\x0`, edx

    xor eax, eax
    ret
