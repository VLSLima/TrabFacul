# Jogo Batalha Naval em C

 Trabalho da matéria - Introdução a programação de computadores: Jogo de batalha naval em C 

---

## Funcionalidades Implementadas:

* Pra criar tabuleiros dinâmicos, utilizei matrizes para representar os tabuleiros do jogador e do computador.
* Posicionei os navios em locais aleatórios no tabuleiro.
* Jogo por turnos, onde o jogador e o computador se revezam para atacar.
* Detecção de Acertos e Erros: Feedback visual claro para acertos ('X') e erros ('O').
* Contagem de Navios: Acompanhamento dos navios restantes para determinar o vencedor.
* Validação de Entrada: Tratamento de entrada inválida do usuário.
* Desenvolvi um ataque especial: O jogador tem a opção de usar uma vez por partida uma habilidade que atinge uma área de 3x3 células.

---

## **Como Compilar e Executar**

Para compilar e executar este jogo, você precisará de um compilador C (como GCC).

1.  **Clone o Repositório:**
    ```bash
    git clone [https://github.com/VLSLima/TrabFacul/blob/main/batalhaNaval.c](https://github.com/SeuUsuario/SeuRepositorioBatalhaNaval.git)
    cd SeuRepositorioBatalhaNaval
    ```

2.  **Compile o Código:**
    Navegue até a pasta onde está o arquivo `batalhaNaval.c`.
    ```bash
    gcc batalhaNaval.c -o batalhaNaval -std=c99
    ```
    *`-std=c99`*: Garante a compatibilidade com funcionalidades do C99 (como `stdbool.h`).

3.  **Execute o Jogo:**
    ```bash
    ./[nome que você definiu como executavel]
    ```

---

## **Estrutura do Código**

Código dividido em funções:

* `inicializarTabuleiro()`: Preenche o tabuleiro com água.
* `mostrarTabuleiro()`: Exibe o estado atual do tabuleiro.
* `posicionarNavios()`: Coloca os navios aleatoriamente.
* `realizarAtaque()`: Processa um ataque em uma única célula.
* `contarNaviosRestantes()`: Conta quantos navios ainda não foram afundados.
* `limparBufferEntrada()`: Auxilia na limpeza do buffer do `scanf`.
* `usarHabilidadeAtaqueAereo()`: Implementa a funcionalidade da bomba 3x3.
* `jogarBatalhaNaval()`: Contém a lógica principal do jogo (loop de turnos).
* `main()`: Ponto de entrada do programa, responsável por inicializar o `rand()` e permitir jogar várias vezes.

---

## **Desenvolvido por**

* Vitor Lima - RA: 202401123854



## **Explicações**

Foi utilizado o *Gemini* para me auxiliar a melhorar alguns pontos do projeto. Espero que curta!
