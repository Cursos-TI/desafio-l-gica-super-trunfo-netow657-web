#include <stdio.h>

int main() {
    // === Carta 1: Fortaleza (CE) ===
    char estado1 = 'C';
    char codigo1[4] = "C01";
    char nomeCidade1[100] = "Fortaleza";
    unsigned long int populacao1 = 2703000;
    float area1 = 314.93;
    float pib1 = 55000.00;
    int pontosTuristicos1 = 20;

    // === Carta 2: Curitiba (PR) ===
    char estado2 = 'P';
    char codigo2[4] = "P02";
    char nomeCidade2[100] = "Curitiba";
    unsigned long int populacao2 = 1963000;
    float area2 = 430.30;
    float pib2 = 90000.00;
    int pontosTuristicos2 = 22;

    // === Cálculos ===
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    float pibPerCapita1 = pib1 / populacao1;
    float pibPerCapita2 = pib2 / populacao2;

    // === Exibição das Cartas ===
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: R$ %.2f\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.6f\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: R$ %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.6f\n", pibPerCapita2);

    // === Comparação por Densidade Populacional (menor valor vence) ===
    printf("\nComparação de cartas (Atributo: Densidade Populacional)\n");
    printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
    printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);

    if (densidade1 < densidade2) {
        printf("Resultado: Carta 1 (%s) venceu com menor densidade populacional!\n", nomeCidade1);
    } else if (densidade2 < densidade1) {
        printf("Resultado: Carta 2 (%s) venceu com menor densidade populacional!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate! Ambas as cartas têm a mesma densidade populacional.\n");
    }

    return 0;
}
