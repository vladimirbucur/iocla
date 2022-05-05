%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands (use direct addressing of memory. Hint: esp)
    mov ecx, NUM
push_nums:
    ;push ecx
    sub esp, 4
    mov dword [esp], ecx
    loop push_nums

    ;push 0
    sub esp, 4
    mov dword [esp], 0

    ;push "mere"
    sub esp, 4
    mov dword [esp], "mere"

    ;push "are "
    sub esp, 4
    mov dword [esp], "are "
    
    ;push "Ana "
    sub esp, 4
    mov dword [esp], "Ana "

    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above

    mov eax, esp
    mov ecx, ebp
    sub ecx, esp

addr_val:

    PRINTF32 `%x \x0`, eax
    PRINTF32 `%hhd\n\x0`, [eax]

    inc eax
    loop addr_val

    ; TODO 3: print the string

    xor ebx, ebx
    mov ebx, esp

    xor ecx, ecx
    mov ecx, ebp
    sub ecx, esp

print_string:
    xor eax, eax
    mov al, byte[ebx]
    cmp eax, 0
    je out_print
    PRINTF32 `%c\x0`, byte[ebx]
    inc ebx
    loop print_string

out_print:

    PRINTF32 `\n\x0`

    ; TODO 4: print the array on the stack, element by element.

    add ebx, 4
    xor ecx, ecx
    mov ecx, NUM

print_array:
    PRINTF32 `%hhu \x0`, byte[ebx]
    add ebx, 4
    loop print_array

    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret

