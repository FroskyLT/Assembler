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
        push edx

        mov ebx, c
        mov ecx, c
        mov edx, 0

        testloop:
            movzx al, byte ptr[ecx]
            cmp al, 0
            jz startforloop

            cmp edx, 10
            jz gofinish

            inc ecx
            inc edx
            jnz	testloop


        startforloop:
            mov edx, 0
        forloop:
            movzx al, byte ptr[ebx]
            cmp al, 0
            jz finish

            sub eax, 48
            imul edx, 10
            add edx, eax
            inc ebx
            jnz	forloop


        gofinish:
            mov edx, 0
        finish:
            mov result, edx

        pop eax
        pop ebx
        pop ecx
        pop edx
    }

    std::cout << result;

        
    return 0;
}
