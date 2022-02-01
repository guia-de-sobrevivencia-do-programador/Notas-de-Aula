# 2 - Shell

## Introdução

### Bash

Bash (ou Bourne-Again SHell) é um de vários shells disponíveis hoje em dia. Dentre todos eles, o bash é definitivamente o mais popular. Ele é encontrada na maioria dos sistemas que rodam Linux.

Um shell é um interpretador de linguagem de comandos; o que usamos para interagir com o sistema operacional através de um terminal. É ele que recebe o que digitamos, interpreta e executa programas.

Sendo um dos principais meios de interação entre o computador e o usuário, os shells tem evoluído bastante durante os anos e hoje em dia fazem muito mais do que só executar comandos.

O bash pode ser usado de maneira interativa e não interativa. De maneira interativa, a shell aceita entrada vinda do teclado. Já o modo não interativo, aceita comandos vindos de outros programas ou de arquivos. Conseguir rodar programas de arquivos é uma das funcionalidades mais poderosas do bash, e iremos explorar ela aqui.

### Scripts

Scripts são programas interpretados (sem a necessidade de serem traduzidos diretamente para código de máquina). Normalmente utilizados para automatizar processos ou tarefa repetitivas onde a implementação de uma solução é fácil e rápida.

Com um conhecimento bom de bash e de alguns dos programas mais famosos do Linux, você consegue automatizar ou simplificar praticamente qualquer aspecto da sua interação com o computador. Esses scripts podem ir desde [configurar os seus monitores](https://github.com/JoaoFukuda/dotfiles/blob/main/scripts/monsetup) até [uma implementação de docker](https://github.com/p8952/bocker): tudo é possível.

## Breve Introdução ao Bash Scripting

A extensão `.sh` (ex.: `script.sh`, `banana.sh` e `exemplo.sh`) é usada para identificar scripts em bash, mas seu uso não é obrigatório.

Se você for usar um script como um executável qualquer (invocar ele através da linha de comando com `./script.sh`), vai ser necessário colocar um shebang (`#!`) na primeira linha para definir qual programa ira interpretá-lo. No nosso caso vai ser o programa `/bin/bash`, mas poderia ser `/bin/python3` por exemplo.

## Ambiente e Variáveis de ambiente

A primeira coisa com que vamos nos depara quando fala de bash scripting são ambientes e variáveis de ambiente.

Uma analogia com outras linguagens: o ambiente em bash é o escopo e as variáveis de ambiente são as variáveis locais. Não existem variáveis globais.

É possível ver as variáveis com o comando `printenv`, rodar um programa em um ambiente separado com o comando `env` e remover variáveis do ambiente atual com `unset`.

Para definir ou atribuir novos valores a variáveis de ambiente você coloca o nome da variável, um sinal de igual (`=`) (sem espaço entre o nome e o símbolo de igual) e o valor que quer dar para a variável (ex.: `VAR=algumvalor`). As variáveis de ambiente tem nomes em caixa alta por convenção, mas pode colocar tanto letras minúscula quanto maiúscula (cuidado que o bash é sensível à caixa da letra). Para usar essas variáveis é só colocar nome dela com um cifrão na frente; o nome pode ou não estar envolto de chaves (`{}`) (ex.: `$VAR` ou `${VAR}`).

Você também pode pegar variáveis do usuário com o comando `read`. É só invocar ele passando o nome da variável como argumento.

Um exemplo de variáveis pode ser visto no arquivo [`inatorinator`](inatorinator.sh)

Existem alguns outros tipos de variáveis que podem ser utilizadas como o arranjo. Se quiser saber mais, leia o manual (`man bash`) ou a info (`info bash` em `Basic Shell Features > Shell Parameters` ou `Bash Features > Arrays`) do bash.

### Export e outros modificadores

Você pode definir modificadores quando for criar variáveis para modificar seu funcionamento. Esses são colocados antes das variáveis (ex.: `export VAR=outrovalor`).

O modificador `export` automaticamente exporta os valores para os ambientes que forem gerados dentro desse ambiente.

Também existe o comando `declare` que atribui tipos às variáveis e configura outros atributos (como `readonly` ou até mesmo o próprio `export`) e pode ser estudado em mais detalhes nos manuais e na info (`Shell Builtin Commands > Bash Builtins`) do bash.

## Funções

Podemos definir funções nos nossos scripts. Elas podem ser definidas assim:

```bash
function fun() {
	echo "Essa funcao imprime uma mensagem"
}

# Ou

fun() {
	echo "Essa tambem"
}
```

Funções podem ser chamadas apenas digitando o nome delas como se estivesse executando qualquer outra função. Mais para frente veremos que elas também podem receber argumentos.

É possível retornar de funções usando o comando `return`, e sair do script usando o comando `exit`. Como argumento opcional, você pode passar um inteiro para definir o código de saída.

Códigos de saída servem para verificar se seu programa retornou com sucesso ou se houve alguma falha. Um código de saída 0 indica sucesso e qualquer outro valor indica uma falha. Alguns programas usam valores diferentes para identificar falhas diferentes (`man errno`).

## Controles de fluxo

Existem vários controles de fluxo que podem te ajudar em um script em bash. A maioria deles são bem parecidas com as vistas em outras linguagens de programação como o `if/else`, `while`, `for` e `switch`. Outras são mais incomuns, como o `select` e o `until`.

O `select` funciona como um loop, mas em vez de andar por valores predeterminados, ele pede para o usuário escolher uma opção toda a iteração, já o `until` é o mesmo que um `while` com a sua condição negada.

As condições são testadas rodando um comando e pegando seu código de saída. Em Bash, 0 indica verdadeiro e qualquer outro valor indica falso.

Para fazer as condicionais que você faria em outras linguagens (com operações lógicas e aritméticas ex.: `1 < 3`, `"esse" != "aquele"` ou `verdadeiro || falso`) e outras mais focadas para scripting (ex.: `arquivo_existe("exemplo.txt")` ou `executavel("script.sh")`), você pode usar o programa `test` e passar esses testes como argumento. O manual do comando `test` (`man test`) tem mais informações de como são feitas essas condicionais.

```bash
if [ 1 -eq 0 ]
then
	echo Nao vai ser impresso
elif test 3 -lt 4
then
	echo Esse vai ser
else
	echo Esse nao
fi
```

```bash
while true
do
	echo Loop infinito
done
```

```bash
for NOME in julio vitor lucas joao
do
	echo Nome: ${NOME}
done
```

```bash
case ${SHELL}
in
	bash)
		echo Voce esta usando BASH!
		;;
	*sh)
		echo Deve ser ZSH, mas talvez DASH, quem sabe FISH ou até SH
		;;
	*)
		echo Voce esta usando alguma shell que nao termine em sh...
		;;
esac
```

```bash
select OPT in direita esquerda frente tras
do
	echo Voce escolheu ${OPT} de todas as opcoes!
done
```

## Variáveis especiais

Existem algumas variáveis que são bem úteis para scripts em bash. Essas são algumas delas:

* `$?` - Código de saída do último comando executado
* `$0..N` - Nésimo argumento (o argumento 0 é o nome do script do jeito que você escreveu para executá-lo).
* `$#` - Número de argumentos passados para o script ou alguma função. Contagem a partir do segundo argumento.
* `$*` - Todos os argumentos como uma única string
* `$@` - Todos os argumentos devidamente separados em strings

Outras dessas variáveis podem ser vistas no man ou na info (`Shell Variables`) do bash.

## Rodar múltiplos comandos

Podemos rodar múltiplos comandos em sequência separando eles com um ponto e vírgula (`;`).

Eles podem também continuar executando dependendo do código de saída do comando que foi executado antes substituindo o ponto e vírgula com dois *Es comerciais* (`&&`) ou *pipes* (`||`).

Os *Es comerciais* indicam que você só continua executando se o comando anterior foi um sucesso. Caso contrário, retorne com o código de erro do comando que falhou. Já os *pipes* indicam o contrário: só execute o próximo comando caso o anterior tenha falhado.

Você pode também agrupar comandos com parênteses (`()`) para controlar a precedência da execução.

Uma última coisa que você pode fazer é executar um comando no plano de fundo e voltar ao terminal sem esperar o comando terminar de executar simplesmente colocando um *E comercial* no final do comando (ex.: `(sleep 3; echo Olá) &`). Desse jeito é possível voltar a ter controle do terminal para poder rodar outros comandos assincronamente. Cuidado que as saídas do programa ainda aparecem no terminal!

Tem um outro jeito de executar vários comandos ao mesmo tempo, mas eu vou falar sobre ele daqui a pouco.

## Entradas e Saídas

Entradas e saídas de comandos no Linux funcionam como arquivos, e todos os arquivos abertos em um programa tem números identificadores associados a eles (file descriptors). Existem três principais que você deve saber (eles são normalmente abertos por padrão no começo da execução):

* `0` - A entrada padrão (`stdin`)
* `1` - A saída padrão (`stdout`)
* `2` - A saída de erros padrão (`stderr`)

### Redirecionar com arquivos

O primeiro redirecionamento de entradas e saídas é redirecionar de e para um arquivo. Para isso, podemos utilizar os comandos menor (`<`) e maior (`>`) no final do comando.

O menor sobrescreve a entrada padrão para receber do arquivo que foi passado depois do sinal de menor em vez de receber do terminal. O sinal de maior sobrescreve a saída padrão para um arquivo em vez de escrever no terminal.

O sinal de maior sobrescreve o arquivo por padrão, mas caso você coloque dois sinais de maior (`>>`), a saída é concatenada com o conteúdo que já estava no arquivo.

É possível também, no caso do redirecionamento da saída, indicar qual saída utilizar colocando o número da saída logo antes do sinal de maior (ex.: `echo banana 1> saida.txt` ou `./a.out 2> log_de_erros.txt`).

Por último, você pode copiar o arquivo configurado de um dos três streams para o outro usando um *E comercial* depois do sinal seguido pelo número do stream que você quer copiar (ex.: `echo Saída de erro, aqui vou eu >&2` ou `./a.out 2>&1`).

### Redirecionar com outros comandos

Um outro tipo de redirecionamento é o de comando para comando. Para isso você pode fazer uma corrente de comandos utilizando pipes (`|`). O que isso faz é liga diretamente a saída de um comando à entrada do próximo. Isso serve para várias coisas, mas dentre elas manipular saídas de um comando utilizando outro para extrair informações úteis. Vamos tocar mais nesse assunto na aula de manipulação de dados.

Também é possível usar a saída de um comando como argumento de outro colocando um cifrão na frente e parênteses envolta do comando (ex.: `rm $(ls)`).

Por último, você pode também substituir arquivos que seriam passados como argumentos por um comando. A saída ou entrada desse comando é associada a um arquivo. Para isso você pode passar um comando envolto de parênteses com um sinal de maior ou menor antes para um arquivo com permissões de somente saída ou entrada respectivamente (ex.: `./a.out <(echo Eu sou um arquivo)` ou `echo Não sei porquê você faria isso > >(cat -)`(ex.: `./a.out <(echo Eu sou um arquivo)` ou `echo Não sei porquê você faria isso > >(cat -)`)); não é possível ter um arquivo de entrada e saída ao mesmo tempo utilizando essa funcionalidade.

Podemos ver um exemplo disso utilizando o script [ler\_arquivo](ler_arquivo.sh).

### Redirecionar com outras coisas

Você também pode redirecionar outras coisas como, por exemplo, escrever a entrada inteira antes de rodar um programa. Há duas opções para isso: redirecionamento de um argumento ou redirecionamento multilinha.

#### Redirecionamento de um argumento

Para o redirecionamento de um argumento, é preciso passar três sinais de menor (`<<<`) e a entrada depois. Esse argumento pode estar dentro de aspas também. Segue um exemplo:

```bash
programa_que_recebe_entrada <<<argumento
```

Para utilizar espaços na sua entrada, basta colocar aspas no argumento:

```bash
programa_que_recebe_entrada <<<"argumento com espaços"
```

#### Redirecionamento multilinha

O redirecionamento multilinha é um pouco mais difícil. É preciso passa dois sinais de menor (`<<`) seguidos por um identificador de fim de entrada (normalmente `EOF`, mas pode ser qualquer coisa). Então você pode escrever o quanto quiser. Para terminar, basta escrever o identificador de fim de entrada sozinho na última linha.

```bash
programa_que_recebe_entrada <<EOF
Entrada multilinha
para esse programa
EOF
```

## Comandos avançados

### Rodar comandos do histórico

É possível rodar comandos que já foram executados previamente (e até corrigir os erros) com facilidade.

Tem como executar...

* `!!` - o último comando
* `!vim` - o último comando que começa com `vim`
* `!?main` - o último comando que contém `main` em algum lugar
* `^ti^it^` - o último comando, substituindo todos os `ti` por `it`

### Globbing e Expansões

Globs e expansões são muito úteis para definir arquivos para passar como argumento a partir de um padrão. Eles substituem o padrão que foi escrito por uma lista de argumentos que bate com o padrão antes de rodar o programa.

O asterisco (`*`) é usado para indicar "qualquer coisa" (ex.: `*.c` significa "qualquer coisa que termine em `.c`" e `saida/*` significa "qualquer coisa que está dentro da pasta `saida/`").

Também é possível utilizar globs para fazer buscas recursivas em diretórios. Para indicar "zero ou mais subdiretórios" basta colocar dois asteriscos (`**`) onde entraria um diretório (ex.: `**/*.c` significa "qualquer coisa no diretório atual e em subdiretórios que terminem em `.c`").

Por último, há também expansões. Você pode definir uma lista entre chaves (`{}`) separando os elementos por vírgula (`,`) e ele vai ser substituído por um argumento por elemento. Sequências podem ser definidas colocando o valor inicial e o valor final separados por dois pontos (`..`), com um terceiro argumento opcional sendo o passo dessa sequência (ex.: `codigos.{c,h}`, `arquivo_{1..100}.txt`, `echo Ímpares: {1..100..2}`).

Essas listas e sequências também podem estar juntas e até dentro umas das outras (ex.: `**/*.{c,h}{,pp}` ou `an{o,el{,ar}}`).

## Customização

E por último mas não menos importante temos a customização do seu bash. Isso ajuda a deixar permanente qualquer configuração recorrente ou muito útil.

Os arquivos de configuração normalmente começam com um ponto (`.`), que indica um arquivo escondido em Linux, daí o nome de uma coleção de arquivos de configuração acabou sendo chamado de *dotfiles*. Existem pessoas que compartilham seus *dotfiles* em sites como o GitHub ou GitLab. Eu recomendo dar uma olhada no *dotfiles* dos professores ou dos colegas para ver o que eles fazem e talvez incorporar algumas dessas opções nas suas próprias configurações.

As configurações do bash ficam no arquivo `.bashrc`, na `home` (`~`) do seu usuário. Nesse arquivo você pode configurar tudo o que quiser, inclusive definir funções que você pode usar como se fossem comandos no seu bash. Eu vou falar de duas coisas que podem ser feitas para começar.

### Alias

Muitas vezes você vê que precisa de um comando extra ou que está rodando um comando muito grande várias vezes; para esses casos você pode fazer um `alias`. Um alias troca o que foi digitado por outra coisa. Um exemplo pode ser fazer um alias `gs` para `git status`, `repos` para `cd ~/repos/` ou até mesmo `gti` para `git`.

Para fazer um alias, basta executar o comando `alias` e defini-lo do mesmo jeito que se define uma variável (ex.: `alias gs='git status'`).

### A variável `PATH`

Por último, também é possível configurar outros diretórios onde o seu terminal vai checar por comandos. Você pode criar uma pasta com scripts e colocá-la nessa lista para poder usar seus scripts de qualquer lugar. Para isso, basta adicionar um novo diretório na variável `PATH`.

Os diretórios são separados por um ponto e vírgula (`;`). Basta exportar a variável com o novo diretório concatenado ao conteúdo que já existia na variável (ex.: `export PATH=${PATH};~/.scripts/`).

## Recursos externos

* Manual/Info do bash (`man 1 bash` e `info bash`)
* Manual/Info do comando `test` (`man 1 test` e `info test`)
* Manual/Info do histórico do bash (`man 3 history` e `info history`)
* Partes II e III do livro `Linux Command Line and Shell Scripting Bible` de Richard Blum e Christine Bresnahan
* Livro `Shell Scripting` de Jason Cannon.

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Vilela]()
