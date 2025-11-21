#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
    char name[SIZE];
    unsigned int number;
    int* values;
} sequence;

void    writeSequence(FILE *file, sequence *seq) {
    if (!seq)
        exit(EXIT_FAILURE);
    fprintf(file, "%d first numbers of the %s sequence:\n", seq->number, seq->name);
    for (int i = 0; i < seq->number; i++) {
        fprintf(file, "%d ", seq->values[i]);
    }
    fprintf(file, "\n");
}

void    readSequence(FILE *file, sequence *seq) {
    if (!seq)
        exit(EXIT_FAILURE);
    fscanf(file, "%u first numbers of the %s sequence:\n", &seq->number, seq->name);
    seq->values = malloc(sizeof(int) * seq->number);
    if (!seq->values)
        exit(EXIT_FAILURE);
    for (int i = 0; i < seq->number; i ++) {
        fscanf(file, "%d ", &seq->values[i]);
    }
}

int     main(void) {
    FILE        *f;
    sequence    *seq;
    sequence    *recv;

    seq = malloc(sizeof(sequence));
    recv = malloc(sizeof(sequence));
    seq->number = 5;
    seq->values = malloc(sizeof(int) * seq->number);
    strcpy(seq->name, "fib");
    seq->values[0] = 1;
    seq->values[1] = 1;
    seq->values[2] = 2;
    seq->values[3] = 3;
    seq->values[4] = 5;
    f = fopen("fib", "w");
    writeSequence(f, seq);
    fclose(f);
    f = fopen("fib", "r");
    readSequence(f, recv);
    fclose(f);
    f = fopen("fib", "w");
    writeSequence(f, recv);
    fclose(f);
}