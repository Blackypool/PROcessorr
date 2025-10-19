#include <stdio.h>

void generate_simple(const char* input_file, const char* output_file) {
    FILE* in = fopen(input_file, "r");
    FILE* out = fopen(output_file, "w");
    
    fprintf(out, "; Простой вывод через RAM\n");
    fprintf(out, "PUSH 0x1000\n");
    fprintf(out, "POPM 0\n");
    
    // Загружаем и сразу выводим каждый символ
    int addr = 0x1000;
    char buffer[1024];
    
    while (fgets(buffer, sizeof(buffer), in)) {
        for (int i = 0; buffer[i] && buffer[i] != '\n' && buffer[i] != '\r'; i++) {
            // Загружаем в RAM
            fprintf(out, "PUSH %d\n", (int)buffer[i]);
            fprintf(out, "PUSH %d\n", addr);
            fprintf(out, "POPM 0\n");
            
            // Сразу выводим из RAM
            fprintf(out, "PUSH %d\n", addr);
            fprintf(out, "PUSHM 0\n");
            fprintf(out, "OUT\n");
            
            addr++;
        }
        // Перевод строки
        fprintf(out, "PUSH 10\n");
        fprintf(out, "PUSH %d\n", addr);
        fprintf(out, "POPM 0\n");
        fprintf(out, "PUSH %d\n", addr);
        fprintf(out, "PUSHM 0\n");
        fprintf(out, "OUT\n");
        addr++;
    }
    
    fprintf(out, "HLT\n");
    
    fclose(in);
    fclose(out);
}

int main() {
    generate_simple("z_1.txt", "simple_art.asm");
    return 0;
}