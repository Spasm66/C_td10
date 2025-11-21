#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE    *f;

    f = fopen("t", "w");
    if (!f)
        exit(EXIT_FAILURE);
    fprintf(f, "hello\n");
    fclose(f);
}