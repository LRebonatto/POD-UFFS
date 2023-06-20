#include <stdio.h>
typedef struct {
    int inteiro;
    int decimal;
} Flutuante;

Flutuante setFloat(int inte, int deci) {
    Flutuante value;
    value.inteiro = inte;
    value.decimal = deci;
    return value;
}
void printFloat(Flutuante value) {
    printf("%d,%d \n", value.inteiro, value.decimal);
}
Flutuante sumFloat(Flutuante val1, Flutuante val2) {
    Flutuante soma;
    soma.inteiro = val1.inteiro + val2.inteiro;
    soma.decimal = val1.decimal + val2.decimal;
    if (soma.decimal > 9) {
        soma.inteiro += 1;
        soma.decimal = soma.decimal - 10;
    }
    return soma;
}
int main() {
    Flutuante p1, p2, soma;
    p1 = setFloat(10, 6);
    p2 = setFloat(10, 6);
    printFloat(p1);
    printFloat(p2);
    soma = sumFloat(p1, p2);
    printFloat(soma);
    return 0;
}
