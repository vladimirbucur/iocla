%include "../utils/printf32.asm"

%define ARRAY_LEN 7

section .data

input dd 122, 184, 199, 242, 263, 845, 911
output times ARRAY_LEN dd 0

section .text

extern printf
global main
main:

    xor eax, eax
    mov ecx, ARRAY_LEN

    ; TODO push the elements of the array on the stack
    ; TODO retrieve the elements (pop) from the stack into the output array
    xor edx, edx
push_arr:
    push dword [input + 4 * edx]
    inc edx
    loop push_arr

    mov ecx, ARRAY_LEN
    
    xor edx, edx
pop_arr:
    pop dword [output + 4 * edx]
    inc edx
    loop pop_arr

    PRINTF32 `Reversed array: \n\x0`
    xor ecx, ecx
print_array:
    mov edx, [output + 4 * ecx]
    PRINTF32 `%d\n\x0`, edx
    inc ecx
    cmp ecx, ARRAY_LEN
    jb print_array

    xor eax, eax
    ret
