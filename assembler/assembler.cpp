#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2) { 
        std::cout << "Missing parameter";
        return 0;
    }
    if (argc > 2) {
        std::cout << "To many arguments";
        return 0;
    }

    char* c = argv[1];
    int result;

    __asm {
        push eax
        push ebx
        push ecx

        mov ebx, c
        mov ecx, 0

        forloop:
            movzx al, byte ptr[ebx]
            cmp al, 0
            jz finish
            sub eax, 48
            imul ecx, 10
            add ecx, eax
            inc ebx
            jnz	forloop

        finish:
            mov result, ecx

        pop eax
        pop ebx
        pop ecx
    }

    std::cout << result;

        
    return 0;
}
