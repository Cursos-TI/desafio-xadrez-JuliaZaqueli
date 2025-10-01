#include <stdio.h>

// ==========================================
// FUNÇÕES RECURSIVAS PARA MOVIMENTAÇÃO
// ==========================================

/**
 * Função recursiva para movimento da Torre
 * Move a Torre em linha reta horizontalmente
 * @param casas_restantes: número de casas que ainda faltam percorrer
 */
void moverTorre(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Movimento da Torre: uma casa para a direita
    printf("Direita\n");
    
    // Chamada recursiva para a próxima casa
    moverTorre(casas_restantes - 1);
}

/**
 * Função recursiva para movimento do Bispo
 * Move o Bispo na diagonal (cima e direita)
 * @param casas_restantes: número de casas que ainda faltam percorrer
 */
void moverBispo(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Movimento do Bispo: uma casa na diagonal
    printf("Cima, Direita\n");
    
    // Chamada recursiva para a próxima casa
    moverBispo(casas_restantes - 1);
}

/**
 * Função recursiva para movimento da Rainha
 * Move a Rainha em linha reta horizontalmente
 * @param casas_restantes: número de casas que ainda faltam percorrer
 */
void moverRainha(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes <= 0) {
        return;
    }
    
    // Movimento da Rainha: uma casa para a esquerda
    printf("Esquerda\n");
    
    // Chamada recursiva para a próxima casa
    moverRainha(casas_restantes - 1);
}

// ==========================================
// FUNÇÃO PARA MOVIMENTO DO BISPO COM LOOPS ANINHADOS
// ==========================================

/**
 * Função para movimento do Bispo usando loops aninhados
 * Demonstra movimento diagonal com controle separado para eixos
 */
void moverBispoLoopsAninhados() {
    printf("Movimento do Bispo com loops aninhados:\n");
    
    int casas_para_mover = 5;
    int movimento_vertical, movimento_horizontal;
    
    // Loop externo: controle do movimento vertical (cima)
    for (movimento_vertical = 0; movimento_vertical < casas_para_mover; movimento_vertical++) {
        
        // Loop interno: controle do movimento horizontal (direita)
        for (movimento_horizontal = 0; movimento_horizontal < casas_para_mover; movimento_horizontal++) {
            
            // Para cada par de movimentos, imprimimos uma direção diagonal
            if (movimento_vertical == movimento_horizontal) {
                printf("Cima, Direita\n");
                
                // Break para sair do loop interno após imprimir uma vez por diagonal
                break;
            }
        }
    }
}

// ==========================================
// FUNÇÃO PARA MOVIMENTO COMPLEXO DO CAVALO
// ==========================================

/**
 * Função para movimento complexo do Cavalo usando loops aninhados
 * Move em "L": 2 casas para cima e 1 para a direita
 * Utiliza continue e break para controle de fluxo
 */
void moverCavaloComplexo() {
    printf("Movimento complexo do Cavalo (2 cima, 1 direita):\n");
    
    int movimento_principal, movimento_secundario;
    int casas_verticais = 2;   // Duas casas para cima
    int casas_horizontais = 1; // Uma casa para a direita
    
    // Loop externo: controle dos movimentos principais
    for (movimento_principal = 0; movimento_principal < 3; movimento_principal++) {
        
        // Loop interno: controle dos movimentos secundários
        movimento_secundario = 0;
        while (movimento_secundario < 3) {
            
            // Condição complexa para simular movimento em "L"
            if (movimento_principal < casas_verticais && movimento_secundario == 0) {
                // Movimento vertical: para cima
                printf("Cima\n");
                movimento_secundario++;
                continue; // Continua para próxima iteração do loop interno
            }
            else if (movimento_principal == casas_verticais && movimento_secundario < casas_horizontais) {
                // Movimento horizontal: para a direita
                printf("Direita\n");
                movimento_secundario++;
                continue; // Continua para próxima iteração do loop interno
            }
            else {
                // Break para sair do loop interno quando não há mais movimentos necessários
                break;
            }
            
            movimento_secundario++;
        }
        
        // Condição para otimização: se completou movimento horizontal, pode sair
        if (movimento_principal >= casas_verticais && movimento_secundario >= casas_horizontais) {
            break;
        }
    }
}

// ==========================================
// FUNÇÃO PRINCIPAL
// ==========================================

int main() {
    
    // ==========================================
    // MOVIMENTO DA TORRE (RECURSIVO)
    // ==========================================
    printf("=== MOVIMENTO DA TORRE (RECURSIVO) ===\n");
    printf("Movendo 5 casas para a direita:\n");
    moverTorre(5);
    
    printf("\n");
    
    // ==========================================
    // MOVIMENTO DO BISPO (RECURSIVO)
    // ==========================================
    printf("=== MOVIMENTO DO BISPO (RECURSIVO) ===\n");
    printf("Movendo 5 casas na diagonal (cima e direita):\n");
    moverBispo(5);
    
    printf("\n");
    
    // ==========================================
    // MOVIMENTO DO BISPO (LOOPS ANINHADOS)
    // ==========================================
    printf("=== MOVIMENTO DO BISPO (LOOPS ANINHADOS) ===\n");
    moverBispoLoopsAninhados();
    
    printf("\n");
    
    // ==========================================
    // MOVIMENTO DA RAINHA (RECURSIVO)
    // ==========================================
    printf("=== MOVIMENTO DA RAINHA (RECURSIVO) ===\n");
    printf("Movendo 8 casas para a esquerda:\n");
    moverRainha(8);
    
    printf("\n");
    
    // ==========================================
    // MOVIMENTO COMPLEXO DO CAVALO
    // ==========================================
    printf("=== MOVIMENTO COMPLEXO DO CAVALO ===\n");
    moverCavaloComplexo();
    
    printf("\n");
    
    return 0;
}