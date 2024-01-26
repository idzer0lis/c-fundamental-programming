//Program care identifica tipul tastei apasate
//(se poate folosi o instructiune switch care citeste codul ASCII corespunzator tastei apasate; functie de acest cod se va afisa, dupa caz
//1 din cele 4 raspunsuri: "ati tastat o litera mare, o litera mica, o cifra, un alt caracter decat litera sau cifra" )

#include <stdio.h>

int main() {
    char c;
    printf("Introduceti un caracter: ");
    c = getchar();

    if (c >= 'A' && c <= 'Z') {
        printf("Ati tastat o litera mare.\n");
    } else if (c >= 'a' && c <= 'z') {
        printf("Ati tastat o litera mica.\n");
    } else if (c >= '0' && c <= '9') {
        printf("Ati tastat o cifra.\n");
    } else {
        printf("Ati tastat un alt caracter decat litera sau cifra.\n");
    }

    return 0;
}
