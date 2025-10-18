#include <stdio.h>

// Função para exibir o menu de atributos (usada duas vezes)
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");

    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");

    printf("Digite a opção desejada: ");
}

// Função para obter o valor do atributo com base na opção escolhida
float obterValor(int opcao, unsigned long int pop, float area, float pib, int pontos) {
    switch (opcao) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return pop / area; // Densidade
        default: return 0.0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // === Carta 1: Brasil ===
    char nomePais1[50] = "Brasil";
    unsigned long int populacao1 = 203062512;
    float area1 = 8515767.0;
    float pib1 = 18690000.0;
    int pontosTuristicos1 = 45;

    // === Carta 2: Alemanha ===
    char nomePais2[50] = "Alemanha";
    unsigned long int populacao2 = 83240525;
    float area2 = 357386.0;
    float pib2 = 4400000.0;
    int pontosTuristicos2 = 50;

    int atributo1, atributo2;

    // === Escolha do primeiro atributo ===
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Validação da primeira escolha
    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nOpção inválida. Encerrando o programa.\n");
        return 1;
    }

    // === Escolha do segundo atributo (sem repetir o primeiro) ===
    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // Validação da segunda escolha
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nOpção inválida ou repetida. Encerrando o programa.\n");
        return 1;
    }

    // === Obtenção dos valores dos atributos ===
    float valor1_attr1 = obterValor(atributo1, populacao1, area1, pib1, pontosTuristicos1);
    float valor2_attr1 = obterValor(atributo1, populacao2, area2, pib2, pontosTuristicos2);

    float valor1_attr2 = obterValor(atributo2, populacao1, area1, pib1, pontosTuristicos1);
    float valor2_attr2 = obterValor(atributo2, populacao2, area2, pib2, pontosTuristicos2);

    // === Impressão dos atributos e valores ===
    printf("\n--- Comparação de Cartas ---\n");
    printf("Carta 1: %s\n", nomePais1);
    printf("Carta 2: %s\n", nomePais2);

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", nomePais1, valor1_attr1);
    printf("%s: %.2f\n", nomePais2, valor2_attr1);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", nomePais1, valor1_attr2);
    printf("%s: %.2f\n", nomePais2, valor2_attr2);

    // === Cálculo dos pontos considerando regras de comparação ===
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // Densidade (menor vence)
        (valor1_attr1 < valor2_attr1) ? pontosCarta1++ :
        (valor2_attr1 < valor1_attr1) ? pontosCarta2++ : 0;
    } else {
        (valor1_attr1 > valor2_attr1) ? pontosCarta1++ :
        (valor2_attr1 > valor1_attr1) ? pontosCarta2++ : 0;
    }

    // Atributo 2
    if (atributo2 == 5) { // Densidade (menor vence)
        (valor1_attr2 < valor2_attr2) ? pontosCarta1++ :
        (valor2_attr2 < valor1_attr2) ? pontosCarta2++ : 0;
    } else {
        (valor1_attr2 > valor2_attr2) ? pontosCarta1++ :
        (valor2_attr2 > valor1_attr2) ? pontosCarta2++ : 0;
    }

    // === Soma total dos atributos ===
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nomePais1, soma1);
    printf("%s: %.2f\n", nomePais2, soma2);

    // === Resultado Final ===
    printf("\n===== Resultado Final =====\n");
    if (soma1 > soma2) {
        printf("Vencedor: Carta 1 (%s)\n", nomePais1);
    } else if (soma2 > soma1) {
        printf("Vencedor: Carta 2 (%s)\n", nomePais2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
