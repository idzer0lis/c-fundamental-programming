// Se citesc n numere, n dat (fara a folosi vectori). Sa se afiseze minimul
// se compara fiecare nr cu valoarea minima curenta


// in limbajul de programare C, nu există un mod simplu si direct pentru a citi
// un numar nedefinit de valori de la inputul standard fără a sti în prealabil câte valori vor fi introduse.
// astfel vom cere nr de elemente din set, apoi elementele

// decizii de design:

// in caz de input invalid, nu aruncam si nici nu oprim executia programului
// se reintroduce valoarea, pana cand este una acceptata(numerica)

// programul va converti orice input ca nr real, si rezultatul va fi deasemenea un nr real(double)

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>


double read_double(char* prompt) {
    char str[100];
    char* end;
    double value;

    do {
        printf("%s", prompt);
        fgets(str, sizeof str, stdin);

        errno = 0;
        value = strtod(str, &end);
        // repeta dacă a fost o eroare, niciun caracter nu a fost procesat sau întregul sir nu a fost procesat
    } while (errno || end == str || *end != '\n');

    return value;
}

int main() {
    int n;
    double num, min = DBL_MAX;

    n = (int) read_double("Introduceti numarul de elemente: ");

    printf("Introduceti numerele:\n");
    for (int i = 0; i < n; ++i) {
        num = read_double("Numar: ");
        if (num < min) {
            min = num;
        }
    }

    printf("Minimul este %.2lf\n", min);

    return 0;
}
