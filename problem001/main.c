// Calculul ariei unui triunghi, dat prin laturile sale (formula lui Heron)
// semiperimetrul triunghiului care este jumătate din suma lungimilor laturilor triunghiului
// A = radical din s * (s-a) * (s-b) * (s-c)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // pt strtod

double heron_formula(double a, double b, double c) {
    double s = (a + b + c) / 2.0;  // semi perimetru
    double area = sqrt(s * (s - a) * (s - b) * (s - c));  // formula lui heron
    return area;
}

int valid_triangle(double a, double b, double c) {
    // A triangle is valid if sum of its two sides is greater than the third side
    // Un triunghi este valid atunci cand suma a doua laturi este mai mare ca a 3a
    if (a < 0 || b < 0 || c < 0)
        return 0;
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0;
    return 1;
}

double parse_arg(char *arg) {
    char *endptr;
    double value = strtod(arg, &endptr);

    if (*endptr != '\0' || endptr == arg) {
        fprintf(stderr, "Erore: Nu este un numar valid: %s\n", arg);
        exit(1);
    }

    return value;
}

int main(int argc, char **argv) {
    if(argc != 4) {
        printf("Utilizare: %s <latura1> <latura2> <latura3>\n", argv[0]);
        return 1;
    }

    double a = parse_arg(argv[1]);
    double b = parse_arg(argv[2]);
    double c = parse_arg(argv[3]);

    if (!valid_triangle(a, b, c)) {
        printf("Eroare: Triunghi invalid cu laturile %.2lf, %.2lf, %.2lf\n", a, b, c);
        return 1;
    }

    double area = heron_formula(a, b, c);

    printf("Aria triunghiului cu laturile de lungime %.2lf, %.2lf si %.2lf este %.2lf\n", a, b, c, area);
    return 0;
}
