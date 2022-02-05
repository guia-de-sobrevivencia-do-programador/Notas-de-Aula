# 6 - Depuração e Perfilamento

## Introdução

Nessa aula a gente vai falar sobre depuração e perfilamento, e mostrar algumas ferramentas que facilitam essas praticas.

Depuração é o ato de identificar e buscar por falhas lógicas (ex.: um loop que passa do limite) ou técnicas (ex.: um `malloc` sem `free`) no código fonte do seu programa. A necessidade de depurar vai se tornando cada vez mais aparente conforme o nível de complexidade dos programas que trabalha aumenta.

Muito provavelmente você já colocou vários prints pelo código para ver se a execução chega ate aquele ponto, se um valor esta certo, ou outra coisa parecida.

A segunda parte da aula a gente vai tratar de perfilamento. Perfilamento e um passo depois de depuração; quando seu código já esta funcionando como esperado (quase). Perfilamento é o ato de buscar por gargalos de performance na aplicação (sendo esse gargalo em entrada e saída, ou em processamento) e identificar em que trechos do código fonte esses gargalos estão.

Um exemplo que vocês talvez já devam ter visto que foi necessário perfilar para melhorar a performance do seu código foi em Exercícios Programas ou Juizes Automáticos como o BXComp ou a plataforma URI, onde seu programa tem um tempo máximo em que deve executar uma certa tarefa. Outros casos reais em que performance talvez seja necessária é: inteligencia artificial, algoritmos que rodam em supercomputadores, sistemas embarcados, sistemas críticos, proxies reversas e várias outras coisas.

Tanto perfilamento quanto depuração tem sido parte do cenário de computação a muito tempo e pessoas tem desenvolvido varias ferramentas que te ajudam com essas tarefas. Nessa aula a gente vai passar por alguns conceitos dessas duas práticas e também mostrar algumas ferramentas uteis e mecanismos comuns dessas ferramentas.

Mas antes de começar, vamos falar um pouco sobre símbolos.

### Símbolos

Vocês vão ouvir falar muito de símbolos nessa aula. Esses símbolos são identificadores que ficam no arquivo binário do programa. Eles associam pontos específicos desses arquivos binários a funções e variáveis presentes no código fonte. É através desses símbolos que os *debuggers* e perfiladores sabem de qual parte do código fonte certos trechos do arquivo binário foram gerados, mostrando assim mais informações e facilitando a vida do usuário.

Esses símbolos no são gerados por padrão quando você compila o programa, então se quiser fazer uso deles é necessário passar algumas flags para o compilador na hora de gerar os arquivos binário.

No GCC basta passar a flag `-g` quando for compilar, assim:

```bash
gcc -g main.c
```

Se quiser fazer algumas otimizações úteis para depuração e deixar que o compilador coloque os símbolos específicos para a ferramenta que for usar, basta passar, respectivamente, as flags `-Og` e `-ggdb`, trocando `gdb` pela ferramenta que for usar (ver as ferramentas disponíveis no `man` do GCC). Por ultimo, você pode também controlar o nível de informações colocando um numero entre 0 e 3 após essas outras opções do `-g`. Exemplo:

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

Como falado antes, depuração é o ato de buscar por erros e identificar onde no código fonte eles ocorrem.

Sabendo que existem erros durante a compilação de um código o `compiletime error` e erros durante a execução do código o `runtime error`, a depuração visa facilitar a correção de erros durante a execução do programa.

Alguns exemplos podem ser:

- Não liberar a memória alocada
- Acessar algum endereço errado
- Erros de lógica

Existem dois jeitos de alcançar esse objetivo: da maneira passiva e da maneira ativa.

### Depuração passiva vs ativa

A depuração `passiva` é quando você não tem uma participação ativa na depuração do código, você deixa a ferramenta rodar o programa e, no final, ela gera um relatório de o que pode estar dando errado e em que parte do código isso acontece.

Já a depuração `ativa` é quanto você usa ferramentas e durante a execução do programa verifica valores de variáveis, se as condições estão funcionando corretamente, pode mudar o fluxo do programa e coisas do tipo buscando pelo erro.

Como exemplo de depuração passiva, vamos dar uma olhada no `memcheck`, uma ferramenta da suite de ferramentas *Valgrind*.

### Valgrind

O *Valgrind*...
- varias ferramentas
- memcheck padrao
- vamos ver outras em perfilamento
- Exemplo: soma de vetores
	- addvec

### GDB
#### Frame

Durante a execução de um programa existe uma `stack` que armazena as chamadas de funções, essa `stack` é dividida em pedaço iguais chamadas `frames`, cada `frame` é a data associada com a chamada de uma função. O `frame` contém os argumentos da função, as variáveis locais de cada função e o endereço de qual função está sendo executada.

Usando como exemplo o código de [soma de vetores](./addvec/addvec.c) quando a execução acontece primeiro é chamada a função `main()` depois é chamada a função `add_vec()`, na stack isso é representada como dois frames:

![frame](./assets/frames.png)

Na imagem acima conseguimos ver que estamos na função `add_vec()` dentro da função `main()`.

#### Introdução

Para usar a ferramenta gdb é possível executar o comando `gdb` para depurar o programa `addvec`:

```sh
gdb addvec
```

Depois de exeutar o comando entramos em uma shell iterativa que podemos executar comandos para depurar o programa.

Assim que entramos no gdb o comando `help` é um dos primeiros comandos que pode ajudar o entendimento do programa.

```
(gdb) help
```

O comando `help` pode ser usado com argumentos para ver mais informações sobre um comando ou uma classe (o exemplo abaixo mostra informações sobre `run`).

```
(gdb) help run
```

Conforme for usando o gdb a tela vai encher de comandos, para poder limpar a tela a combinação de teclas `Ctrl + l` pode ser útil.

#### Controle de fluxo

Sabendo como procurar mais informações sobre um programa, agora será apresentado os controles de fluxo.

Para executar um programa podemos usar o comando `run` ou `r` e o comando `start` e `s`.

Com o programa `addvec` aberto no gdb ao executar `run`:
```
(gdb) run
```

O programa vai executar até terminar, pois o comando `run` executar o programa e para ao chegar em um `breakpoint` ou até o término do programa.

Ao tentar executar `start`:
```
(gdb) start
```

Vemos que o programa irá parar na primeira linha depois da função `main()` (Lembrando que só é possível ver o código fonte se o programa foi compilado com símbolos).

Agora para "avançar" o programa podemos usar o comand o `next` ou `n`:
```
(gdb) next
```

O programa vai executar uma linha.

É possível avançar com o comando `next` até a linha 18. Na linha 18 existe uma chamada de função `add_vec()` e para poder ver o conteúdo da função o comando `step` ou `s`.
```
(gdb) step
```

Agora o gdb irá mostrar a execução dentro do frame `add_vec()`.


- `continue` ou `c`: executa o programa até o programa chegar em um `breakpoint` ou acabar de executar o programa
- `finish`: executa o programa até sair do `frame` atual

Para ver o código fonte de um programa pode ser usado o comando `list` (Lembrando que o código só vai ser mostrado se o progama foi compilado com `símbolos`):

- `list` ou `l`: mostra as 10 próximas linhas que vão ser executadas

#### Depurando

Para saber se o programa realmente está funcionando como deveria, ao invés de colocar `print()` no código fonte para saber o valor de uma variável podemos imprimir o valor de cada variável durante a sua execução.

O comando `print` recebe como argumento  o nome da variável que vai ser exibida:

```
(gdb) print variável
```

O comando `print` funciona com a sintaxe da linguagem `C` então caso o usuário queira ver o valor de um ponteiro pode usar algo como o exemplo abaixo:

```
(gdb) print *variável
```

Depois de usar o comando `print` as variáveis que foram vistas vão ficar salvas em alguma variáveis, por exemplo ao rodar o comando abaixo:
```
(gdb) print *variável
```

O gdb vai mostrar algo como o resultado mostrado abaixo:
```
$1 = 12
```

Depurando programas grandes vai existir uma grande variedade de funções, para poder visualizar onde o programa está é possível usar o comando `backtrace` ou `bt`

```
(gdb) backtrace
```

Usando como exemplo o programa `addvec` ele primeiro vai entrar na função `main()` e depois na função `add_vec()`, dentro da função `add_vec()` executando o comando `bt`:

```
#0  add_vec (v1=0x7fffffffe5b0, v2=0x7fffffffe5d0, len=5) at addvec.c:8
#1  0x000055555555526b in main () at addvec.c:19
```

É possível ver que o programa está atualmente no frame `add_vec()` que foi chamado pelo `main()` na linha `19`

Dentro de um frame podemos ver as variáveis que foram enviadas para ele usando o comando `info args`:

```
#0  add_vec (v1=0x7fffffffe5b0, v2=0x7fffffffe5d0, len=5) at addvec.c:8
```

Podemos ver as variáveis locais dentro de um escopo por exemplo as variáveis que podemos acessar dentro da função `add_vec()`:
```
(gdb) info local
```

#### Breakpoints

Como visto na aula 3 algumas IDE's tem a opção de parar a execução do programa (criar `breakpoints`), o gdb também tem essa funcionalidade e pode ser usada com o comando `break` ou `b`.

Para que o programa pare de executar na linha `20` por exemplo:
```
(gdb) break 20
```

Para que o programa pare de executar na função `add_vec()` por exemplo:
```
(gdb) break add_vec
```

Para ver os breakpoints que foram colocados existe o comando `info break`:
```
(gdb) info break
```

Os breakpoints podem ocorrer com condições também para o programa parar de executar na linha `7` qunado o valor de `i` for `4` por exemplo:
```
(gdb) break 7 if i == 4
```

Se o breakpoint já foi colocado é possível colocar uma condição de parada nele com o comando `condition`, para colocar a condição no breakpoint `2` e  a condição `if i == 3`:
```
(gdb) condition 2 if i == 3
```

Já foi mostrado o comando `print` para imprimir variáveis especificadas, mas caso exista uma variável que precise ser constantemente vigiada, temos o comando `watch`, esse comando vai mostrar todas as mudanças na variável especificada (No exemplo abaixo vamos ver todas as mudanças na variável `variavel`:
```
(gdb) variavel
```

Esse comado também aceita condições assim como o comando `break`, então para imrpimir o valor da variável `variavel` quando `i == 3`:
```
(gdb) watch variavel if i == 3
```

Para poder visualizar melhor as variáveis de um programa o comando `dprintf` consegue formatar antes de imprimir as variáveis, por exemplo para imprimir na linha `9` as variáveis `i`, `vec_res[i]` e `(v1[i] + v2[i])`:
```
(gdb) dprintf 9, "Vec[%d]: %d -> %d\n", i, vec_res[i], (v1[i] + v2[i])
```

Agora para remover os breakpoints que foram criados o comando `del` sozinho vai deletar todos os breakpoints existentes:
```
(gdb) del
```

E para deletar apenas um breakpoint específico, por exemplo para deletar o breakpoint `3`:
```
(gdb) del 3
```

Para executar algum comando depois de chegar em um breakpoint (existente) o `commands` pode ajudar, um exemplo é executar o comando `backtrace` quando a execução do programa chegar no breakpoint `2`:
```
(gdb) commands 2
```

E então você pode colocar os comandos que vão ser executados depois terminar com um `end`:
```
(gdb) commands 2
Type commands for breakpoint(s) 2, one per line.
End with a line saying just "end".
>bt
>end
```

Para quem quiser algo mais gráfico a opção `tui` permite ver onde o gdb está vendo o código, para habilitar:
```
(gdb) tui enable
```

## Perfilamento

O que é perfilamento?
- Utilizar ferramentas para descobrir gargalos no seu código
	- Gargalo de processamento
	- Gargalo de input/output
		- Escrita em arquivo
		- Conexão com internet

### Não Instrumentado vs Instrumentado

Instrumentado
- Dentro do código utilizar bibliotecas específicas para perfilar

Não-instrumentado
- Rodar um programa externo

### Linux Perf

Roda o código mostrando estatísticas e dados sobre

(Exemplo: fibonacci 40)

* stat
	- cpu utilizada
	- troca de contexto
	- branches
	- perf stat -r <n>
		- repete a execução do código mostrando variância
	- Exemplo com fib
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

#### Hotspot

(Usar outro exemplo)

Versão + gráfica usando os mesmos dados do linux report

Flame Graph (Precisamos de um código de exemplo)
- Lê o perf.data
- Mostra a recursão das chamadas

Caller
- Mostra o tempo de execução em cada linha
- Threads e CPUs

### Valgrind

* callgrind
	- Mostra mais chamadas feitas na função

* kcachegrind (visualizador do output do callgrind e cachegrind)
	- Mostrar as chamadas que foram feitas na execução
	- Quais funções fizeram outras chamadas
	- Relative
		- Quanto tempo de CPU cada função teve em relação à outra

### LTTng

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

#### Trace Compass 2

(Programa para visualizar o LTTng)

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Tsu](https://github.com/HTsuyoshi)
