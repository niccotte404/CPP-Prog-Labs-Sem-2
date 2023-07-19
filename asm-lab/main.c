#include <stdio.h>
#include <malloc.h>

//void PartSort(const uint64_t arr[], uint64_t n){
//    for (uint64_t i = 0; i < n - 1; i++){
//        for (uint64_t j = 0; j < n - i - 1; j++){
//            uint64_t i1 = j;
//            uint64_t j1 = j+1;
//            asm(
//                    "movq %1, %%rax\n\t" // rax = i
//                    "movq %2, %%rbx\n\t" // rbx = j
//
//                    "movq %0, %%rdi\n\t" // rdi = *arr
//                    "addq %%rax, %%rdi\n\t" // rdi += rax
//                    "movq (%%rdi), %%rax\n\t" // rax = arr[i]
//                    "movq %0, %%rdi\n\t" // rdi += rax
//                    "addq %%rbx, %%rdi\n\t" // rdi += rbx
//                    "movq (%%rdi), %%rbx\n\t" // rbx = arr[j]
//
//                    "cmpq %%rbx, %%rax\n\t" // rbx > rax
//                    "jle skip_swap\n\t"
//
//                    "movq %0, %%rax\n\t" // rax = *arr
//                    "movq %1, %%rcx\n\t" // rcx = i
//                    "movq %2, %%rbx\n\t" // rbx = j
//                    "leaq (%%rax,%%rcx, 8), %%rdi\n\t" // rdi = *arr[i]
//                    "leaq (%%rax,%%rbx, 8), %%rsi\n\t" // rsi = *arr[j]
//                    "movq (%%rdi), %%rdx\n\t" // rdx = arr[i]
//                    "movq (%%rsi), %%rcx\n\t" // rcx = arr[j]
//                    "movq %%rdx, (%%rsi)\n\t" // arr[j] = rdx
//                    "movq %%rcx, (%%rdi)\n\t" // arr[j] = rcx
//
//
//                    "skip_swap:\n\t"
//                    :
//                    : "r"(arr), "r"(i1), "r"(j1)
//                    : "%rax", "%rbx", "%rcx", "%rdi"
//            );
//        }
//    }
//}


//void FullSort(const uint64_t* arr, uint64_t n){
//    asm (
//            "movq %[n], %%rcx\n\t"
//            "movq %[arr], %%rdi\n\t"
//            "movq $0, %%rbx\n\t"
//            "outer_loop:\n\t"
//            "cmpq %%rcx, %%rbx\n\t"
//            "je end_outer_loop\n\t"
//
//            "movq $0, %%rax\n\t"
//            "movq $1, %%rdx\n\t"
//            "inner_loop:\n\t"
//            "cmpq %%rcx, %%rdx\n\t"
//            "je end_inner_loop\n\t"
//
//            "movl (%%rdi, %%rax, 4), %%esi\n\t"
//            "movl (%%rdi, %%rdx, 4), %%edi\n\t"
//            "cmpl %%esi, %%edi\n\t"
//            "jle skip\n\t"
//
//            "movl %%edi, (%%rdi, %%rax, 4)\n\t"
//            "movl %%esi, (%%rdi, %%rdx, 4)\n\t"
//
//            "skip:\n\t"
//            "addq $1, %%rdx\n\t"
//            "addq $1, %%rax\n\t"
//            "jmp inner_loop\n\t"
//
//            "end_inner_loop:\n\t"
//            "addq $1, %%rbx\n\t"
//            "jmp outer_loop\n\t"
//            "end_outer_loop:\n\t"
//            :
//            :[n]"m"(n), [arr]"m"(arr)
//            : "cc", "memory", "%rax", "%rdi", "%rbx", "%rdx", "%esi", "%edi", "%rcx"
//            );
//}

//void SwapAsm(const uint64_t* arr, uint64_t n){
//
//    int i = 3;
//    int elem = 0;
//
//    asm (
//            "movq %[i], %%rax\n\t" // move i to rax
//            "movq $4, %%rbx\n\t" // move 4 to rbx
//            "mulq %%rbx\n\t" // multiply rax by rbx
//            "movq %[arr], %%rdi\n\t" // move array address to rdi
//            "addq %%rax, %%rdi\n\t" // add rax to rdi
//            "mov (%%rdi), %[elem]\n\t" // move arr[i] to elem
//            :
//            : [arr]"r"(arr), [i]"r"(i), [elem]"r"(elem)
//            : "%rax", "%rbx", "%rdi"
//            );
//
//    printf("The %d-th element is %d\n", i, elem);
//}



void Sort(const int * array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            asm volatile(
                "movl (%[i]), %%eax\n\t"
                "movl (%[j]), %%ebx\n\t"
                "cmpl %%ebx, %%eax\n\t"
                "jle skip_swap\n\t"
                "xchgl %%eax, %%ebx\n\t"
                "movl %%eax, (%[i])\n\t"
                "movl %%ebx, (%[j])\n\t"
                "skip_swap:\n\t"
                :
                : [i]"r"(&array[j]), [j]"r"(&array[j+1])
                : "%eax", "%ebx"
                );
        }
    }
}

int main() {
    FILE * file = fopen("elements.txt", "r");
    int * array = (int*) malloc (sizeof (int) * 1000);
    int cout = 0;
    for(int i = 0; !feof(file); i++) {
        fscanf(file, "%d", &array[i]);
        cout++;
    }
    fclose(file);

    Sort(array, cout);

    FILE* NewFile = fopen("sorted.txt", "w");
    if (NewFile == NULL) printf("File error!");
    for (int i = 0; i < cout; ++i)
        fprintf(NewFile, "%d\n", array[i]);
    fclose(NewFile);

    for (int i = 0; i < cout; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}