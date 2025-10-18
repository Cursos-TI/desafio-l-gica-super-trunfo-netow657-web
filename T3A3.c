#include <stdio.h>

int main() {
    // === Carta 1: Brasil ===
    char nomePais1[50] = "Brasil";
    unsigned long int populacao1 = 203062512;
    float area1 = 8515767.0;
    float pib1 = 18690000.0; // em milhões
    int pontosTuristicos1 = 45;

    // === Carta 2: Alemanha ===
    char nomePais2[50] = "Alemanha";
    unsigned long int populacao2 = 83240525;
    float area2 = 357386.0;
    float pib2 = 4400000.0; // em milhões
    int pontosTuristicos2 = 50;

    // === Cálculos de densidade e PIB per capita (caso precise depois) ===
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // === Menu Interativo ===
    int opcao;

    printf("===== SUPER TRUNFO: Comparação de Cartas =====\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite o número da opção desejada: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s...\n", nomePais1, nomePais2);

    switch (opcao) {
        case 1: // População
            printf("\n--- Atributo: População ---\n");
            printf("%s: %lu\n", nomePais1, populacao1);
            printf("%s: %lu\n", nomePais2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu com maior população!\n", nomePais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu com maior população!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("\n--- Atributo: Área ---\n");
            printf("%s: %.2f km²\n", nomePais1, area1);
            printf("%s: %.2f km²\n", nomePais2, area2);

            if (area1 > area2) {
                printf("Resultado: %s venceu com maior área!\n", nomePais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu com maior área!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("\n--- Atributo: PIB ---\n");
            printf("%s: R$ %.2f milhões\n", nomePais1, pib1);
            printf("%s: R$ %.2f milhões\n", nomePais2, pib2);

            if (pib1 > pib2) {
                printf("Resultado: %s venceu com maior PIB!\n", nomePais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu com maior PIB!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("\n--- Atributo: Pontos Turísticos ---\n");
            printf("%s: %d pontos\n", nomePais1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomePais2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu com mais pontos turísticos!\n", nomePais1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu com mais pontos turísticos!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (MENOR valor vence!)
            printf("\n--- Atributo: Densidade Demográfica ---\n");
            printf("%s: %.2f hab/km²\n", nomePais1, densidade1);
            printf("%s: %.2f hab/km²\n", nomePais2, densidade2);

            if (densidade1 < densidade2) {
                printf("Resultado: %s venceu com menor densidade demográfica!\n", nomePais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu com menor densidade demográfica!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("\nOpção inválida! Por favor, escolha um número entre 1 e 5.\n");
            break;
    }

    return 0;
}
