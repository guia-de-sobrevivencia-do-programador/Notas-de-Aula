# 6 - Depuração e Perfilamento

## Introdução

Motivação

Símbolos

Assembly

## Depuração

O que é depuração?

Ativa vs Passiva

### Valgrind

(Exemplo: soma de vetores)
* memcheck

(Pesquisar sobre)

### GDB

- Frame
    - Cada chamada é um frame (ambientes de execução no programa)

- Misc
    - help
    - clear (C-l)

- Mostrar como rodar o programa
    - run
    - start
        - next
        - step
    - continue
    - list
    - finish
        - Rodar até o final da função específica
    - print
        - É compatível com C (ex: `print vec_res[0]`)
        - Guarda em variáveis (`$1, $2, $3...`)

- Frame cont.
    - Listar frames (backtrace)
    - Se mover entre os Frames
        - frame $(frame destino)
    - Ex:
        main() -> add_vec()
    - Estando no add\_vec() você quer ver o main()

- Breakpoints
    - info
        - Variáveis de argumento (info args)
        - Variáveis locais (info local e info var)
            - Memória stack e heap
        - Mostra os breakpoints (info break)

    - break

    - break <line> <condition>
        - break 7 if i == 4

    - condition <ID breakpoint> <condition>

    - watch
        - Toda vez que a variável selecionada mudar ele mostra seu valor
            - Valor antigo e novo, local na memória
        - Quando a variável sai do escopo o breakpoint é deletado

    - watch <expression> <condition>
        - watch i if i == -1

    - dprintf (printf dinâmico)
        - (Ficam listados em breakpoints)
        - Explicar os argumentos: localização + String formatting
            - Exemplo: dprintf 7 "Vec[%d]: %d -> $d\n" i vec_res[i] (v1[i] + v2[i])

    - del
        - Remover breakpoints
            - watch também é um breakpoint

    - commands
        - Ex:
            \> backtrace
            \> end

    (opcional)
    - tui enable

## Perfilamento

O que é perfilamento?
- Utilizar ferramentas para descobrir gargalos no seu código
    - Gargalo de processamento
    - Gargalo de input/output
        - Escrita em arquivo
        - Conexão com internet

Instrumentado vs Não Instrumentado

Instrumentado
- Dentro do código utilizar bibliotecas específicas para perfilar

Não-instrumentado
- Rodar um programa externo

### Não Instrumentado

#### Linux Perf

Roda o código mostrando estatísticas e dados sobre

(Exemplo: fibonacci 40)

* stat
    - cpu utilizada
    - troca de contexto
    - branches
    - perf stat -r <n>
        - repete a execução do código mostrando variância
* record
    - grava a execução de um programa
* report
    - resultado da execução
* annotate
    - É possível ver o tempo gasto em cada instrução
    - Mostra mais ou menos onde pode estar o gargalo
    - Keybindings
        - k - Mostrar linhas
        - tab - Mostrar linha que mais gastou tempo
        - shift + tab - Mostrar linha que mais gastou tempo

##### Hotspot

(Usar outro exemplo)

Versão + gráfica usando os mesmos dados do linux report

Flame Graph (Precisamos de um código de exemplo)
- Lê o perf.data
- Mostra a recursão das chamadas

Caller
- Mostra o tempo de execução em cada linha
- Threads e CPUs

#### Valgrind

* cachegrind
    - Quase as mesmas conf do perf stat
    - Quantos cache hit e cache miss ocorreram

* callgrind
    - Mostra mais chamadas feitas na função

* kcachegrind (visualizador do output do callgrind e cachegrind)
    - Mostrar as chamadas que foram feitas na execução
    - Quais funções fizeram outras chamadas
    - Relative
        - Quanto tempo de CPU cada função teve em relação à outra

### Instrumentado

#### LTTng

(Apenas mostrar o que ele consegue fazer no código e + ou - como ficaria o código)

(Precisamos de um código de exemplo)

Linux Tracing Toolkit: Next Generation

Muito mais controle das informações que você quer no seu código

Tracing

(Explicar o que é tracing)

Acompanha a execução do código

[Site Oficial](https://lttng.org/docs/) do LTTng

#### BabelTrace2

(Programa para visualizar o LTTng)

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Tsu](https://github.com/HTsuyoshi)
