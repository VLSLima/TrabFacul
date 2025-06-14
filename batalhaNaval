#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
#include <limits>  // Para numeric_limits

using namespace std;

// Tamanho do tabuleiro e quantidade de navios
const int TAMANHO_TABULEIRO = 5;
const int QUANTIDADE_NAVIOS = 5;

// Usando enum para estados da célula para maior clareza
enum class CellState : char { // Explicitamente char para fácil atribuição
    Water = '~',
    Ship = 'N',
    Hit = 'X',
    Miss = 'O'
};

// Inicializa todos os espaços com '~'
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = static_cast<char>(CellState::Water);
        }
    }
}

// Mostra o tabuleiro no terminal
void mostrarTabuleiro(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], bool esconderNavios) {
    cout << "  0 1 2 3 4\n";
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        cout << i << " ";
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (esconderNavios && tabuleiro[i][j] == static_cast<char>(CellState::Ship)) {
                cout << static_cast<char>(CellState::Water) << " ";
            } else {
                cout << tabuleiro[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Posiciona os navios em posições aleatórias
void posicionarNavios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int naviosPosicionados = 0;

    while (naviosPosicionados < QUANTIDADE_NAVIOS) {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;

        // Garante que não estamos colocando navios em cima de outros
        if (tabuleiro[linha][coluna] != static_cast<char>(CellState::Ship)) {
            tabuleiro[linha][coluna] = static_cast<char>(CellState::Ship);
            naviosPosicionados++;
        }
    }
}

// Realiza ataque e retorna true se acertou
bool realizarAtaque(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == static_cast<char>(CellState::Ship)) {
        tabuleiro[linha][coluna] = static_cast<char>(CellState::Hit); // Acertou navio
        return true;
    } else if (tabuleiro[linha][coluna] == static_cast<char>(CellState::Water)) {
        tabuleiro[linha][coluna] = static_cast<char>(CellState::Miss); // Errou, marcou como água
    }
    // Se a posição já foi atacada (Hit ou Miss), retorna false
    return false;
}

// Conta quantos navios ainda estão de pé
int contarNaviosRestantes(const char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int contador = 0;

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == static_cast<char>(CellState::Ship)) {
                contador++;
            }
        }
    }
    return contador;
}

// Função principal do jogo
void jogarBatalhaNaval() {
    // Criação dos tabuleiros
    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char tabuleiroComputador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicialização
    inicializarTabuleiro(tabuleiroJogador);
    inicializarTabuleiro(tabuleiroComputador);

    // Posicionamento dos navios
    posicionarNavios(tabuleiroJogador);
    posicionarNavios(tabuleiroComputador);

    cout << "============================\n";
    cout << "       BATALHA NAVAL\n";
    cout << "============================\n";
    cout << "Você e o computador têm " << QUANTIDADE_NAVIOS << " navios cada.\n";

    // Loop principal do jogo
    while (true) {
        // TURNO DO JOGADOR
        int linhaAtaque, colunaAtaque;

        cout << "\n>>> SEU TURNO <<<\n";
        cout << "Tabuleiro do Inimigo:\n";
        mostrarTabuleiro(tabuleiroComputador, true); // Esconde os navios do computador

        // Validação robusta de entrada
        cout << "Informe a linha (0 a " << TAMANHO_TABULEIRO - 1 << "): ";
        while (!(cin >> linhaAtaque) || linhaAtaque < 0 || linhaAtaque >= TAMANHO_TABULEIRO) {
            cout << "Entrada inválida ou posição fora do tabuleiro. Digite uma linha válida (0 a " << TAMANHO_TABULEIRO - 1 << "): ";
            cin.clear(); // Limpa o estado de erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
        }

        cout << "Informe a coluna (0 a " << TAMANHO_TABULEIRO - 1 << "): ";
        while (!(cin >> colunaAtaque) || colunaAtaque < 0 || colunaAtaque >= TAMANHO_TABULEIRO) {
            cout << "Entrada inválida ou posição fora do tabuleiro. Digite uma coluna válida (0 a " << TAMANHO_TABULEIRO - 1 << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Verifica se a posição já foi atacada pelo jogador
        if (tabuleiroComputador[linhaAtaque][colunaAtaque] == static_cast<char>(CellState::Hit) ||
            tabuleiroComputador[linhaAtaque][colunaAtaque] == static_cast<char>(CellState::Miss)) {
            cout << "Você já atacou essa posição. Escolha outra.\n";
            continue; 
        }

        bool acertou = realizarAtaque(tabuleiroComputador, linhaAtaque, colunaAtaque);

        if (acertou) {
            cout << "💥 Você acertou um navio!\n";
        } else {
            cout << "💦 Água! Nenhum navio nessa posição.\n";
        }

        // Verifica se o jogador ganhou
        if (contarNaviosRestantes(tabuleiroComputador) == 0) {
            cout << "\n🎉 PARABÉNS! Você destruiu todos os navios inimigos!\n";
            mostrarTabuleiro(tabuleiroComputador, false); // Mostra o tabuleiro do computador com os navios afundados
            break;
        }

        // TURNO DO COMPUTADOR
        cout << "\n>>> TURNO DO COMPUTADOR <<<\n";

        int linhaComp, colunaComp;
        // O computador tenta evitar atacar posições que já atacou
        do {
            linhaComp = rand() % TAMANHO_TABULEIRO;
            colunaComp = rand() % TAMANHO_TABULEIRO;
        } while (tabuleiroJogador[linhaComp][colunaComp] == static_cast<char>(CellState::Hit) ||
                 tabuleiroJogador[linhaComp][colunaComp] == static_cast<char>(CellState::Miss));

        cout << "Computador atacou a posição (" << linhaComp << ", " << colunaComp << ")\n";

        bool compAcertou = realizarAtaque(tabuleiroJogador, linhaComp, colunaComp);

        if (compAcertou) {
            cout << "🔥 O computador acertou seu navio!\n";
        } else {
            cout << "💨 Ele errou o ataque!\n";
        }

        // Verifica se o computador ganhou
        if (contarNaviosRestantes(tabuleiroJogador) == 0) {
            cout << "\n☠️  Derrota! Seus navios foram todos destruídos.\n";
            mostrarTabuleiro(tabuleiroJogador, false); // Mostra o tabuleiro do jogador com os navios afundados
            break;
        }

        // Mostra o tabuleiro do jogador
        cout << "\nSeu tabuleiro atual:\n";
        mostrarTabuleiro(tabuleiroJogador, false); // Não esconde os próprios navios
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    char jogarNovamente;
    do {
        jogarBatalhaNaval(); // Chama a função que contém a lógica do jogo

        cout << "\nDeseja jogar novamente? (s/n): ";
        cin >> jogarNovamente;
        // Limpa o buffer de entrada após a leitura do caractere
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    } while (tolower(jogarNovamente) == 's');

    cout << "\nObrigado por jogar Batalha Naval!\n";

    return 0;
}  
