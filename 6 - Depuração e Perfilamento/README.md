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

O *Valgrind* é um framework para fazer análises dinâmicas. Ela vem com vários instrumentos de Depuração e Perfilamento para melhorar seu programa.

O instrumento que vai ser usado em debugging é o `memcheck`, esse instrumento é um detector de erros de memória (particulamente os erros em C e C++)

Alguns exemplos de erros que podem acontecer no seu programa que o *Valgrind* pode detectar são:

* Variáveis não inicializadas
* Vazamento de memória
* Liberar memória já liberada
* Detectar operações em ponteiros que já foram liberados
* Detectar acesso inválido de memória

Para usar o *Valgrind*:
```sh
valgrind --tool=memcheck --leak-check=yes --track-origins=yes [programa]
```

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
(gdb) condition 2 i == 3
```

Já foi mostrado o comando `print` para imprimir variáveis especificadas, mas caso exista uma variável que precise ser constantemente vigiada, temos o comando `watch`, esse comando vai mostrar todas as mudanças na variável especificada (No exemplo abaixo vamos ver todas as mudanças na variável `variavel`:
```
(gdb) watch variavel
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

Perfilamento, como falado antes, é o ato de identificar e localizar gargalos de performance no seu código. Os tipos mais comuns de gargalos são os gargalos de processamento e gargalo de entrada/saída.

Gargalos de processamento ocorrem quando a velocidade do seu programa é limitada pela velocidade do seu processador ou o acesso à memória principal, já os gargalos de entrada e saída ocorrem quando a velocidade é limitada pelo acesso a arquivos ou à rede (internet).

### Não Instrumentado vs Instrumentado

Vamos dar uma olhada em dois tipos diferentes de ferramentas para identificar e, posteriormente, localizar no código esses gargalos: as instrumentadas e as não instrumentadas.

Ferramentas não instrumentadas fazem suas medições por fora do programa, periodicamente o interrompendo para registrar o estado atual da memória (ou qualquer outra análise que a ferramenta faça), juntando com informações obtidas através do uso de símbolos para inferir quais funções ou instruções estão sendo executadas.

Ferramentas instrumentadas disponibilizam bibliotecas para o desenvolvedor poder criar e inserir chamadas para a ferramenta dentro do seu programa. Quando o programa roda, essas chamadas se comunicam com a ferramenta enviando os dados para gerar um relatório.

### Linux Perf

A primeira das duas ferramentas de perfilamento não instrumentado que vamos mostrar é o *linux\_perf*, ou simplesmente *perf*.

O *perf* é uma ferramenta de perfilamento que possui varias funcionalidades. A primeira que as pessoas normalmente veem é o *perf stat*.

Essa funcionalidade coleta estatísticas sobre a velocidade da CPU, tempo de execução, acesso ao cache e branching, e outros dados interessantes para alguém que esta perfilando.

Podemos ver um exemplo utilizando o programa `fib`. Primeiro rodamos o `fib` com o `perf stat` sem flags:

```bash
perf stat ./fib/fib 40
```

<!-- Explicar resultados e tals -->

Podemos também pedir para o *perf stat* rodar nosso programa varias vezes e tirar a média e o desvio padrão das medidas. Para isso passamos a opção `-r` com o numero de repetições desejado.

```bash
perf stat -r 30 ./fib/fib 36
```

Outra ferramenta do *perf* é o *perf record*, que é complementado pelas ferramentas *perf report* e *perf annotate*.

O *perf record* grava a execução de um programa e salva os dados coletados em um arquivo. *Perf report* lê e trata esses dados, mostrando funções ordenadas por tempo em execução.

O *perf annotate* é uma ferramenta opcional que mostra dentro da função quais as instruções que mais estão contribuindo para o tempo de execução da função.

Vamos ver um exemplo com o programa `httpserver`. Esse programa é composto por um servidor HTTP e um cliente que gera trafico para o servidor. No exemplo o cliente vai ser rodado em um outro computador conectado à mesma rede.

Primeiro vamos gravar a execução do servidor com o *perf record*:

```bash
perf record --call-graph dwarf ./httpserver/httpserver
```

A opção `--call-graph` indica que queremos pegar informações sobre o stack frame das funções para tentar indicar não so a função que está sendo atualmente executada, mas a recursão inteira que levou a essa função atual ser executada.

O argumento `dwarf` passado para a opção indica o formato em que essa informação sera guardada. Nesse caso `dwarf` é a mais comum, então vamos com ela.

Podemos também configurar a frequência com que o *perf report* interrompe a execução do programa para obtermos mais informações, mas com a desvantagem de maior interferência com a performance (por estarmos toda hora interrompendo a execução).

Essa execução cria um arquivo `perf.data` e, caso já exista um arquivo com esse nome, esse é renomeado para `perf.data.old`. Para ler o arquivo vamos usar o *perf report*:

```bash
perf report
```

Dentro da ferramenta podemos analisar várias informações pertinentes como as funções que gastam mais tempo de execução e quais outras funções essa chama.

Aqui a gente pode apertar `+` e `-` para abrir e fechar a lista de funções que são chamadas pela função que a gente está selecionando. Outra tecla interessante é o `d` que filtra por arquivo de origem da função. Para uma lista de outras possíveis ações, aperte `?`.

Uma das coisas que você pode fazer é entrar na anotação da função. Isso vai mostrar o código em assembly da função com uma indicação de quais dessas instruções estão usando mais o tempo da função.

Uma das teclas mais importantes aqui é o `Tab` e o `Shift + Tab` que vão mostrando a lista de instruções mais custosas da função. De novo, aperte `?` caso queira saber mais acoes possíveis.

#### Hotspot

*Hotspot* é uma outra ferramenta que substitui o *perf report*. Ela utiliza a saída do *perf record* para mostrar de maneira mais gráfica os mesmos dados que são visíveis no *perf report*.

Uma adição interessante ao *Hotspot* é o flamegraph. Ele mostra quais funções estão gastando mais tempo de execução com um gráfico em nível onde cada barra significa uma função, a largura indica o tempo de execução e as funções que estão acima são chamadas pelas que estão em baixo.

Nele vemos que uma das funções que mais esta gastando tempo de execução é a `malloc`. Vamos tentar consertar isso!

### Valgrind

Uma outra ferramenta para coleta de dados sobre performance de funções em função do tempo de execução é uma ferramenta da suite *Valgrind*: o *callgrind*.

O *callgrind* diferente do *perf* não vem com uma ferramenta para tratar o arquivo de saída, então vamos usar um outro programa auxiliar chamado *kcachegrind*.

```bash
valgrind --tool=callgrind ./httpserver/httpserver
kcachegrind callgrind.out.*
```

O mais interessante dessa ferramenta se encontra na parte inferior: o *call graph*. Essa ferramenta mostra de maneira bem interativa quais funções estão chamando quais outras, quantas vezes e o tempo que a função ficou sendo executada.

### LTTng

[Site Oficial do LTTng.](https://lttng.org/docs/)

Agora para mostrar uma ferramenta instrumentada de perfilamento temos o *LTTng*. O *LTTng* (*Linux Tracing Toolkit: next generation*) é uma ferramenta de *tracing*.

*Tracing* é o ato de registrar informações sobre a execução de um programa para analise posterior. Esses registros, diferentes das ferramentas não instrumentadas, são configurados e feitos por você através de instruções especializadas inseridas no código fonte da sua aplicação.

O aproveitamento desse tipo de ferramenta depende muito mais da experiencia e criatividade de quem a esta usando, podendo dar resultados incríveis se utilizada corretamente.

Para essa ferramenta teremos dois exemplos: iremos gravar e visualizar os resultados do programa `httpserver` que já esta instrumentado, e iremos instrumentar o programa `fib`.

#### Exemplo 1

Para gravarmos um programa instrumentado com LTTng primeiro precisamos nos certificar de que temos um `session daemon`. Um programa que recebe e gerencia os registros enviados pelos vários programas instrumentados. Para isso vamos tentar listar todas as sessões do *LTTng*:

```bash
lttng list
```
```
> Error: No session daemon is available
```

Isso indica que não temos um *session daemon*. Para criarmos um, podemos rodar o comando `lttng-sessiond` com a opção `-d` para colocar a execução no plano de fundo em vez de ocupar o terminal.

```bash
lttng-sessiond -d
```

Então podemos criar uma sessão para usar com o comando `create` dando o nome de uma sessão como argumento:

```bash
lttng create gsp
```

Agora temos que criar um canal pelo qual iremos receber os dados do *session daemon*. O *LTTng* tem dois tipos de tracing principais: `userspace` e `kernel`. Quando criamos um *channel* precisamos falar qual desses tipos a gente deseja usar.

```bash
lttng enable-channel --userspace httpserver
```

Por ultimo, a gente precisa falar quais eventos a gente deseja receber nesse channel. Não precisamos indicar a sessão, mas precisamos indicar o canal pelo qual desejamos receber os eventos.

```bash
lttng enable-event --userspace httpserver 'httpservertp:*'
```

Agora é só ativar e rodar o programa. Uma vez que estamos satisfeitos, podemos parar a sessão.

```bash
lttng start
# Rodar o programa
lttng stop
```

Os arquivos de saída (diferente dos arquivos de saída das outras ferramentas mostradas aqui) ficam em `~/lttng-traces/`.

Similar ao *Valgrind*, o *LTTng* também não tem ferramenta de visualização própria, mas temos duas opções: *BabelTrace2* para o terminal, e *Trace Compass* como alternativa "gráfica" (mas não muito gráfica).

#### BabelTrace2

O *BabelTrace2* tem uma serie de ferramentas para manipular os dados de tracing, mas iremos utilizar apenas a visualização com o comando *convert*. Esse comando pode ser omitido pois é a opção padrão, mas para buscar mais informações utilize `man babeltrace2-convert`.

Para listar os eventos em ordem de acontecimento, rode:

```bash
babeltrace2 ~/lttng-traces/gsp*
```

#### Trace Compass

Uma outra ferramenta para visualizar o perfilamento é o *Trace Compass*. Essa tem várias opções de filtro e alguns gráficos para mostrar a frequência com que um evento ocorre e filtros por campos.

Para carregarmos um trace, vamos em `File > Import...` e em `Select root directory` colocamos `~/lttng-traces/gsp*`. Podemos ou não criar um experimento na parte de opções em baixo, mas para esse uso simples não é necessário.

#### Exemplo 2

Nesse exemplo iremos instrumentar o programa `fib`.

Iremos criar um evento que registra informações de qual o valor atual com que a função foi chamada e qual o nível da recursão.

Em `tp.h` iremos criar um evento chamado `call` que recebe dois parâmetros: `value` e `recursion_level`, e cujos campos do evento corresponde aos dois parâmetros passados.

```c
// tp.h

LTTNG_UST_TRACEPOINT_EVENT(
	fibtp,
	call,
	LTTNG_UST_TP_ARGS(
		int, value,
		int, recursion_level
	),
	LTTNG_UST_TP_FIELDS(
		lttng_ust_field_integer(int, value, value)
		lttng_ust_field_integer(int, recursion_level, rec_lvl)
	)
)
```

E podemos ver os resultados do mesmo jeito que vimos os do `httpserver`, mas precisamos criar um novo filtro de evento. Já que estamos aqui vamos criar outro canal também para poder desabilitar o canal do `httpserver`.

```bash
lttng disable-channel --userspace httpserver

lttng enable-channel --userspace fib
lttng enable-event --userspace fib 'fibtp:*'

lttng start
# Rodar o programa
lttng stop
```

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Tsu](https://github.com/HTsuyoshi)
