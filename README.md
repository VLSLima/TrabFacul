# Jogo Batalha Naval em C

Este repositório contém a implementação de um jogo de Batalha Naval simples, desenvolvido em linguagem C, como sendo parte de um dos trabalos da disciplina de Introdução à Programação de Computadores.

---

## **Funcionalidades Implementadas**

* **Tabuleiros Dinâmicos:** Utiliza matrizes para representar os tabuleiros do jogador e do computador.
* **Posicionamento Aleatório de Navios:** Os navios são posicionados em locais aleatórios no tabuleiro.
* **Turnos de Ataque:** Jogo por turnos, onde o jogador e o computador se revezam para atacar.
* **Detecção de Acertos e Erros:** Feedback visual claro para acertos ('X') e erros ('O').
* **Contagem de Navios:** Acompanhamento dos navios restantes para determinar o vencedor.
* **Validação de Entrada:** Tratamento de entrada inválida do usuário.
* **Habilidade Especial: Ataque Aéreo (Bomba 3x3):** O jogador tem a opção de usar uma vez por partida uma habilidade que atinge uma área de 3x3 células.

---

## **Como Compilar e Executar**

Para compilar e executar este jogo, você precisará de um compilador C (como GCC).

1.  **Clone o Repositório:**
    ```bash
    git clone [https://github.com/VLSLima/TrabFacul/blob/main/batalhaNaval.c](https://github.com/SeuUsuario/SeuRepositorioBatalhaNaval.git)
    cd SeuRepositorioBatalhaNaval
    ```
    (Substitua `SeuUsuario/SeuRepositorioBatalhaNaval.git` pelo link real do seu repositório).

2.  **Compile o Código:**
    Navegue até a pasta onde está o arquivo `batalhaNaval.c`.
    ```bash
    gcc batalhaNaval.c -o batalhaNaval -std=c99
    ```
    *`batalhaNaval.c`*: Substitua pelo nome do seu arquivo `.c`.
    *`-o batalha_naval`*: Define o nome do executável gerado (você pode escolher outro nome).
    *`-std=c99`*: Garante a compatibilidade com funcionalidades do C99 (como `stdbool.h`).

3.  **Execute o Jogo:**
    ```bash
    ./[nome que você definiu como executavel]
    ```

---

## **Estrutura do Código**

O código é dividido em funções para facilitar a modularidade:

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

Criei esse projeto em uma tarde, e devido ao pouco tempo disponivel, utilizei o *Gemini* para me auxiliar a melorar alguns pontos do projeto. Espero que curta!
