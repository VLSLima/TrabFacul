#include <stdio.h>   // Para printf, scanf, getchar
#include <stdlib.h>  // Para rand, srand
#include <time.h>    // Para time
#include <stdbool.h> // Para tipo bool (C99)
#include <ctype.h>   // Para tolower

// Tamanho do tabuleiro e quantidade de navios
#define TAMANHO_TABULEIRO 5
#define QUANTIDADE_NAVIOS 5

// Usando enum para estados da célula para maior clareza (compatível com C)
enum CellState {
    WATER = '~',
    SHIP = 'N',
    HIT = 'X',
    MISS = 'O'
};

// Protótipos das funções
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void mostrarTabuleiro(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], bool esconderNavios);
void posicionarNavios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
bool realizarAtaque(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);
int contarNaviosRestantes(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void limparBufferEntrada();
void usarHabilidadeAtaqueAereo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void jogarBatalhaNaval();

// Limpa o buffer de entrada para evitar problemas com scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Inicializa todos os espaços com '~'
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = WATER;
        }
    }
}

// Mostra o tabuleiro no terminal
void mostrarTabuleiro(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], bool esconderNavios) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Condicional dentro de loops aninhados (requisito 3)
            if (esconderNavios && tabuleiro[i][j] == SHIP) {
                printf("%c ", WATER); // Esconde o navio
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Posiciona os navios em posições aleatórias
void posicionarNavios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int naviosPosicionados = 0;

    while (naviosPosicionados < QUANTIDADE_NAVIOS) {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;

        // Condicional para garantir que não estamos colocando navios em cima de outros
        if (tabuleiro[linha][coluna] != SHIP) {
            tabuleiro[linha][coluna] = SHIP;
            naviosPosicionados++;
        }
    }
}

// Realiza ataque em uma única célula e retorna true se acertou
bool realizarAtaque(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return false; // Posição inválida
    }

    if (tabuleiro[linha][coluna] == SHIP) {
        tabuleiro[linha][coluna] = HIT; // Acertou navio
        return true;
    } else if (tabuleiro[linha][coluna] == WATER) {
        tabuleiro[linha][coluna] = MISS; // Errou, marcou como água
    }
    // Se a posição já foi HIT ou MISS, não faz nada e retorna false
    return false;
}

// Conta quantos navios ainda estão de pé
int contarNaviosRestantes(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int contador = 0;

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == SHIP) {
                contador++;
            }
        }
    }
    return contador;
}

// Nova função para a Habilidade Especial: Ataque Aéreo (Bomba 3x3)
// Requisito 3: Aplicar condicionais dentro de loops aninhados para simular áreas de efeito
void usarHabilidadeAtaqueAereo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int centroLinha, centroColuna;
    printf("\n--- HABILIDADE ESPECIAL: ATAQUE AÉREO (BOMBA 3x3) ---\n");
    printf("Escolha o centro do ataque (0 a %d):\n", TAMANHO_TABULEIRO - 1);

    printf("Informe a linha central: ");
    while (scanf("%d", &centroLinha) != 1 || centroLinha < 0 || centroLinha >= TAMANHO_TABULEIRO) {
        printf("Entrada inválida ou fora do tabuleiro. Digite uma linha válida (0 a %d): ", TAMANHO_TABULEIRO - 1);
        limparBufferEntrada();
    }
    limparBufferEntrada(); // Limpa o buffer após scanf

    printf("Informe a coluna central: ");
    while (scanf("%d", &centroColuna) != 1 || centroColuna < 0 || centroColuna >= TAMANHO_TABULEIRO) {
        printf("Entrada inválida ou fora do tabuleiro. Digite uma coluna válida (0 a %d): ", TAMANHO_TABULEIRO - 1);
        limparBufferEntrada();
    }
    limparBufferEntrada(); // Limpa o buffer após scanf

    int acertosHabilidade = 0;
    printf("Bomba lançada nas proximidades de (%d, %d)!\n", centroLinha, centroColuna);

    // Loops aninhados para a área de efeito da habilidade
    for (int i = centroLinha - 1; i <= centroLinha + 1; i++) {
        for (int j = centroColuna - 1; j <= centroColuna + 1; j++) {
            // Condicionais para verificar se a posição está dentro do tabuleiro
            if (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
                // Condicional para evitar atacar posições já atingidas (opcional, mas boa prática)
                if (tabuleiro[i][j] != HIT && tabuleiro[i][j] != MISS) {
                    bool acertou = realizarAtaque(tabuleiro, i, j);
                    if (acertou) {
                        acertosHabilidade++;
                    }
                }
            }
        }
    }

    if (acertosHabilidade > 0) {
        printf("💥 O ataque aéreo atingiu %d navio(s)!\n", acertosHabilidade);
    } else {
        printf("💦 O ataque aéreo não atingiu nenhum navio.\n");
    }
}

// Função principal do jogo
void jogarBatalhaNaval() {
    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char tabuleiroComputador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Variável para controlar o uso da habilidade especial
    bool habilidadeAereaUsada = false;

    // Inicialização
    inicializarTabuleiro(tabuleiroJogador);
    inicializarTabuleiro(tabuleiroComputador);

    // Posicionamento dos navios
    posicionarNavios(tabuleiroJogador);
    posicionarNavios(tabuleiroComputador);

    printf("============================\n");
    printf("       BATALHA NAVAL\n");
    printf("============================\n");
    printf("Você e o computador têm %d navios cada.\n", QUANTIDADE_NAVIOS);

    // Loop principal do jogo
    while (true) {
        // TURNO DO JOGADOR
        int linhaAtaque, colunaAtaque;
        char escolhaAcao;

        printf("\n>>> SEU TURNO <<<\n");
        printf("Tabuleiro do Inimigo (seus ataques):\n");
        mostrarTabuleiro(tabuleiroComputador, true); // Esconde os navios do computador

        // Pergunta se o jogador quer usar a habilidade especial
        if (!habilidadeAereaUsada) {
            printf("Você tem 1 Habilidade Especial de Ataque Aéreo (Bomba 3x3) disponível.\n");
            printf("Deseja usar a Habilidade Especial agora? (s/n): ");
            scanf(" %c", &escolhaAcao); // Espaço antes de %c para consumir nova linha
            limparBufferEntrada(); // Limpa o buffer após scanf

            if (tolower(escolhaAcao) == 's') {
                usarHabilidadeAtaqueAereo(tabuleiroComputador);
                habilidadeAereaUsada = true;
                // Após usar a habilidade, pula para a verificação de vitória e turno do computador
                if (contarNaviosRestantes(tabuleiroComputador) == 0) {
                    printf("\n🎉 PARABÉNS! Você destruiu todos os navios inimigos com o ataque aéreo!\n");
                    mostrarTabuleiro(tabuleiroComputador, false);
                    break;
                }
                goto proximoTurnoComputador; // Pula para o turno do computador
            }
        }

        // Ataque normal se a habilidade não foi usada ou se o jogador optou por não usar
        printf("Informe a linha para ataque normal (0 a %d): ", TAMANHO_TABULEIRO - 1);
        while (scanf("%d", &linhaAtaque) != 1 || linhaAtaque < 0 || linhaAtaque >= TAMANHO_TABULEIRO) {
            printf("Entrada inválida ou posição fora do tabuleiro. Digite uma linha válida (0 a %d): ", TAMANHO_TABULEIRO - 1);
            limparBufferEntrada();
        }
        limparBufferEntrada();

        printf("Informe a coluna para ataque normal (0 a %d): ", TAMANHO_TABULEIRO - 1);
        while (scanf("%d", &colunaAtaque) != 1 || colunaAtaque < 0 || colunaAtaque >= TAMANHO_TABULEIRO) {
            printf("Entrada inválida ou posição fora do tabuleiro. Digite uma coluna válida (0 a %d): ", TAMANHO_TABULEIRO - 1);
            limparBufferEntrada();
        }
        limparBufferEntrada();
        
        // Verifica se a posição já foi atacada pelo jogador
        if (tabuleiroComputador[linhaAtaque][colunaAtaque] == HIT ||
            tabuleiroComputador[linhaAtaque][colunaAtaque] == MISS) {
            printf("Você já atacou essa posição. Escolha outra.\n");
            continue; 
        }

        bool acertou = realizarAtaque(tabuleiroComputador, linhaAtaque, colunaAtaque);

        if (acertou) {
            printf("💥 Você acertou um navio!\n");
        } else {
            printf("💦 Água! Nenhum navio nessa posição.\n");
        }

        // Verifica se o jogador ganhou
        if (contarNaviosRestantes(tabuleiroComputador) == 0) {
            printf("\n🎉 PARABÉNS! Você destruiu todos os navios inimigos!\n");
            mostrarTabuleiro(tabuleiroComputador, false); // Mostra o tabuleiro do computador com os navios afundados
            break;
        }

    proximoTurnoComputador:; // Label para o goto (usado quando a habilidade é ativada)
        // TURNO DO COMPUTADOR
        printf("\n>>> TURNO DO COMPUTADOR <<<\n");

        int linhaComp, colunaComp;
        // O computador tenta evitar atacar posições que já atacou
        do {
            linhaComp = rand() % TAMANHO_TABULEIRO;
            colunaComp = rand() % TAMANHO_TABULEIRO;
        } while (tabuleiroJogador[linhaComp][colunaComp] == HIT ||
                 tabuleiroJogador[linhaComp][colunaComp] == MISS);

        printf("Computador atacou a posição (%d, %d)\n", linhaComp, colunaComp);

        bool compAcertou = realizarAtaque(tabuleiroJogador, linhaComp, colunaComp);

        if (compAcertou) {
            printf("🔥 O computador acertou seu navio!\n");
        } else {
            printf("💨 Ele errou o ataque!\n");
        }

        // Verifica se o computador ganhou
        if (contarNaviosRestantes(tabuleiroJogador) == 0) {
            printf("\n☠️  Derrota! Seus navios foram todos destruídos.\n");
            mostrarTabuleiro(tabuleiroJogador, false); // Mostra o tabuleiro do jogador com os navios afundados
            break;
        }

        // Mostra o tabuleiro do jogador
        printf("\nSeu tabuleiro atual:\n");
        mostrarTabuleiro(tabuleiroJogador, false); // Não esconde os próprios navios
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    char jogarNovamente;
    do {
        jogarBatalhaNaval(); // Chama a função que contém a lógica do jogo

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente); // Espaço antes de %c para consumir nova linha
        limparBufferEntrada(); // Limpa o buffer após scanf

    } while (tolower(jogarNovamente) == 's');

    printf("\nObrigado por jogar Batalha Naval!\n");

    return 0;
}
