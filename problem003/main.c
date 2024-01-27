// Determinarea si afisarea maximului a 3 numere date

#include <stdio.h>
#include <stdlib.h>  // pt EXIT_FAILURE

int main() {
    double num1, num2, num3;
    printf("Introduceti trei numere: ");

    if (scanf("%lf %lf %lf", &num1, &num2, &num3) != 3) {
        fprintf(stderr, "Eroare: nu ati introdus trei numere valide.\n");
        return EXIT_FAILURE; // 1 :D
    }

    if (num1 >= num2 && num1 >= num3)
        printf("Numarul maxim este %.2lf", num1);
    else if (num2 >= num1 && num2 >= num3)
        printf("Numarul maxim este %.2lf", num2);
    else
        printf("Numarul maxim este %.2lf", num3);

    return 0;
}
