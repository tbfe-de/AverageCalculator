/*
 =================================================================
 Step 1 (Solution see Step 2)
 =================================================================
*/

#include <stdio.h>

void do_averages(FILE* in, FILE* out) {
    char line[100];
    while (fgets(line, sizeof line, in)) {
        float value;
        float sum = 0.0f;
        int count = 0;
        int nchars = 0;
        int nc;
        while (sscanf(&line[nchars], "%f%n", &value, &nc) == 1) {
            sum += value;
            ++count;
            nchars += nc;
        }
        if (count == 0) return;
        fprintf(out, "%f\n", sum/count);
    }
}

int main() {
    do_averages(stdin, stdout);
    return 0;
}
