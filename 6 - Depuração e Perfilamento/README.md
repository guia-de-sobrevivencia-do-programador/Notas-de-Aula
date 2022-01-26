# 6 - Depuração e Perfilamento

## Introdução

Nessa aula a gente vai falar sobre depuração e perfilamento, e mostrar algumas ferramentas que facilitam essas praticas.

Depuração é o ato de identificar e buscar por falhas lógicas (ex.: um loop que passa do limite) ou técnicas (ex.: um `malloc` sem `free`) no código fonte do seu programa. A necessidade de depurar vai se tornando cada vez mais aparente conforme o nível de complexidade dos programas que trabalha aumenta.

Muito provavelmente você já colocou vários prints pelo código para ver se a execução chega ate aquele ponto, se um valor esta certo, ou outra coisa parecida.

A segunda parte da aula a gente vai tratar de perfilamento. Perfilamento e um passo depois de depuração; quando seu código já esta funcionando como esperado (quase). Perfilamento é o ato de buscar por gargalos de performance na aplicação (sendo esse gargalo em entrada e saída, ou em processamento) e identificar que trechos do código fonte esses gargalos estão.

Um exemplo que vocês talvez já devam ter visto que foi necessário perfilar para melhorar a performance do seu código foi em Exercícios Programas ou Juizes Automáticos como o BXComp ou a plataforma URI, onde seu programa tem um tempo máximo em que deve executar uma certa tarefa. Outros casos reais em que performance talvez seja necessária é: inteligencia artificial, algoritmos que rodam em supercomputadores, sistemas embarcados, sistemas críticos, proxies reversas e várias outras coisas.

Tanto perfilamento quanto depuração tem sido parte do cenário de computação a muito tempo e pessoas tem desenvolvido varias ferramentas que te ajudam com essas tarefas. Nessa aula a gente vai passar por alguns conceitos dessas duas práticas e também mostrar algumas ferramentas uteis e mecanismos comuns dessas ferramentas.

Mas antes de começar, vamos falar um pouco sobre símbolos.

### Símbolos

Vocês vão ouvir falar muito de símbolos nessa aula. Esses símbolos são identificadores que ficam no arquivo binário do programa. Eles associam pontos específicos desses arquivos binários a funções e variáveis presentes no código fonte. É através desses símbolos que os *debuggers* e perfiladores sabem de qual parte do código fonte certos trechos do arquivo binário foram gerados, mostrando assim mais informações e facilitando a vida do usuário.

Esses símbolos no são gerados por padrão quando você compila o programa, então se quiser fazer uso deles é necessário passar algumas flags para o compilador na hora de gerar os arquivos binário.

No GCC e CLANG basta passar a flag `-g` quando for compilar, assim:

```bash
gcc -g main.c
```

Se quiser fazer algumas otimizações úteis para depuração e deixar que o compilador coloque os símbolos específicos para a ferramenta que for usar, basta passar, respectivamente, as flags `-Og` e `-ggdb`, trocando `gdb` pela ferramenta que for usar (ver as ferramentas disponíveis no `man` do GCC/CLANG). Por ultimo, você pode também controlar o nível de informações colocando um numero entre 0 e 3 após essas outras opções do `-g`. Exemplo:

```bash
# -Og: Otimização para depuração
# -g: Inserir simbolos no binário gerado, voltados para depuracao usando gdb e com o maximo de informacoes possivel
gcc -Og -ggdb3 main.c
```

Níveis de símbolos:
- `0`: Nenhum simbolo. Nega `-g`
- `1`: Mínimo de informação para funcionar com alguma coisa. Sem informações sobre variáveis locais por exemplo.
- `2`: Padrão.
- `3`: Informações extras como macros e funções inline.

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
