# 2 - Shell

O que é bash?

O que é scripting

Para que serve?

## Shell Scripting

A extensão `.sh` (ex.: `script.sh`, `banana.sh` e `exemplo.sh`) é usada para identificar scripts em bash, mas não é obrigatório seu uso.

Se você for usar um script como um executável qualquer (invocar ele através da linha de comando com `./script.sh`), vai ser necessário colocar um shebang (`#!`) na primeira linha para definir qual programa ira interpretar o arquivo. No nosso caso vai ser o `/bin/bash`, mas poderia ser `/bin/python3` por exemplo.

A gente pode também definir funções nos nossos scripts. Funções podem ser definidas dentro de scripts assim:

```bash
fun() {
	echo "Estou imprimindo de dentro de uma funcao"
}
```

Essas funções podem ser chamadas como qualquer outro programa. Elas também podem receber argumentos, mas a gente vai falar sobre isso mais para frente (ainda nessa aula).

É possível retornar de funções usando o comando `return`. E também é possível sair do script usando o comando `exit`. Como argumento opcional você pode passar um inteiro para definir o código de saída.

Códigos de saída servem para verificar se seu programa retornou com sucesso ou houve alguma falha no processo. Um código 0 indica sucesso e qualquer outro valor indica falha. Alguns programas usam valores diferentes para indicar qual foi o erro. A gente vai falar como acessar esse código de saída ainda nessa aula.

### Controles de fluxo

Existem vários controles de fluxo que podem te ajudar em um script. A maioria deles (como `if`, `while` e `for`) são bem parecidas com as vistas em linguagens de programações já vistas na graduação como C e Java. Outras são mais incomuns, como o `select`.

```bash
if [ ${VAL} -eq 0 ]
then
	echo Alguma coisa
elif [ ${VAL} -gt 0 ]
then
	echo Alguma outra coisa
else
then
	echo Uma terceira coisa
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
	*bash)
		echo Voce esta usando BASH!
		;;
	*)
		echo Deve ser ZSH, mas talvez DASH, quem sabe SH ou até FISH
		;;
esac
```

```bash
select OPT in direita esquerda frente tras
do
	echo Voce escolheu ${OPT}!
done
```

As condições são testadas rodando um comando (definido na hora) e pegando seu código saída. Ao contrário de C, 0 indica verdadeiro e qualquer outro valor indica falso. Para fazer os testes que você normalmente faria em um programa normal (ex.: `1 < 3`, `"esse" != "aquele"` ou `verdadeiro || falso`) e outros mais focados para scripting (ex.: `arquivo_existe("exemplo.txt")` ou `executavel("outro_script.sh")`), você pode usar o comando `test` (que também pode ser chamado usando um par de colchetes `[` e `]`) e passando alguns testes como argumento. Abra o manual do comando (`man test`) para saber mais.

Você também pode usar os comandos `continue` e `break`.

## Ambiente e Variáveis de ambiente

É possível ver as variáveis de ambiente atuais com o comando `printenv`, rodar um programa em um ambiente novo com `env` e remover uma variável do ambiente atual com `unset`.

Para definir ou atribuir novos valores a variáveis de ambiente você coloca o nome da variável, um sinal de igual (`=`) (sem espaço entre o nome e o símbolo de igual) e o valor que quer dar para a variável (ex.: `VAR=algumvalor`). As variáveis de ambiente tem nomes em caixa alta por padrão (assim como queries de MySQL ou macros em C), mas pode colocar tanto letras minúscula quanto maiúscula (cuidado que o bash é *case sensitive*). Para usar essas variáveis: nome dela com um cifrão na frente; o nome pode ou não estar envolto de chaves (`{}`) (ex.: `$VAR` ou `${VAR}`).

Você também pode pegar variáveis do usuário com o comando `read`. É só invocar ele passando o nome da variável como argumento.

Um exemplo de variáveis pode ser visto no arquivo [`inatorinator`](inatorinator)

Existem alguns outros tipos de variáveis que podem ser utilizadas; uma delas é o arranjo, mas a gente não vai falar de arranjos.

<!--TODO: Referências para variáveis em bash-->

### Export e Define

Você pode definir modificadores quando for criar variáveis para modificar seu funcionamento. Esses são colocados antes das variáveis (ex.: `export VAR=outrovalor`).

O modificador `export` automaticamente exporta os valores para os ambientes que forem gerados dentro desse contexto.  Por último, o `local` .

Também existe o comando `declare` que atribui tipos às variáveis e configura outros atributos (como `readonly` ou até mesmo o próprio `export`), mas não vai ser falado em sala.

<!--TODO: Referências para modificadores de variáveis-->

### Variáveis especiais

Existem algumas variáveis que são bem úteis para scripts em bash. Essas são algumas delas:

* `$?` - Código de saída do último comando executado
* `$0..N` - Nésimo argumento (o argumento 0 é o nome do script do jeito que você escreveu para executá-lo).
* `$#` - Número de argumentos passados para o script ou alguma função. Contagem a partir do segundo argumento.
* `$*` - Todos os argumentos como uma única string
* `$@` - Todos os argumentos devidamente separados em strings

Outras variáveis interessantes:

* `$$` - PID do processo atual
* `$_` - Último argumento do último comando executado

<!--TODO: Referências para variáveis built-in-->

## Rodar múltiplos comandos

A gente pode rodar múltiplos comandos em sequência separando eles com um ponto e vírgula (`;`).

Eles podem também executar dependendo do código de saída do comando que o precede com *es comerciais* (`&&`) ou *pipes* (`||`).

Os *es comerciais* indicam que você só continua executando se o comando anterior foi um sucesso. Caso contrário, retorne com o código de erro do comando que falhou. Já os *pipes* indicam o contrário: só execute o próximo comando caso o anterior tenha falhado.

Você pode também agrupar comandos com parênteses (`()`) para fazer essas correntes de comandos.

Uma última coisa que você pode fazer é executar um comando no plano de fundo e voltar a execução normal sem esperar o comando terminar de rodar simplesmente colocando um *e comercial* no final do comando (ex.: `echo Olá &`).

Tem um outro jeito de executar vários comandos ao mesmo tempo, mas eu vou falar dele daqui a pouco.

## Redirecionamento de Entradas e Saídas

Entradas e saídas de comandos no Linux funciona como arquivos (pipes e streams), e todos os arquivos abertos em um programa tem números identificadores associados a eles (file descriptors). Existem três principais que você deve saber (eles são abertos por padrão em todos os programas):

* `0` - A entrada padrão
* `1` - A saída padrão
* `2` - A saída de erros

### Redirecionar com arquivos:

O primeiro redirecionamento de entradas e saídas é redirecionar de e para um arquivo. Para isso você pode utilizar os comandos menor (`<`) e maior (`>`) no final do comando.

O menor sobrescreve a entrada padrão para em vez de receber do terminal, receber do arquivo que foi passado depois do sinal de menor. O maior sobrescreve a saída padrão para em vez de você escrever no terminal, você escrever em algum arquivo.

O sinal de maior por padrão sobrescreve o arquivo, mas caso você coloque dois sinais de maior (`>>`), a saída é concatenada com o conteúdo que já está no arquivo.

Você também pode, no caso do redirecionamento da saída, indicar qual saída utilizar colocando o número da saída logo antes do sinal de maior (ex.: `echo banana 1> saida.txt` ou `./a.out 2> log_de_erros.txt`).

Por último, você pode copiar o arquivo configurado de um dos três streams para o outro usando um *e comercial* depois do sinal, seguido pelo número do stream que você quer copiar (ex.: `echo Saída de erro, aqui vou eu >&2` ou `./a.out 2>&1`).

### Redirecionar com outros comandos

Um outro tipo de redirecionamento é o de comando para comando. Para isso você pode fazer uma corrente de comandos utilizando um pipe (`|`). O que isso faz é liga diretamente a saída de um comando à entrada do próximo. Isso serve para várias coisas, mas dentre elas manipular saídas de comandos para extrair informações úteis. A gente vai falar mais disso na aula de manipulação de dados.

Você também pode passar a saída de um comando como argumento com um cifrão e parênteses envolvendo o comando (ex.: `rm $(ls)`).

Por último, você pode também substituir arquivos que seriam passados como argumentos por um comando. A saída ou entrada desse comando é associada a um arquivo. Para isso você pode passar um comando envolvido em parênteses e com um sinal de maior ou menor antes (ex.: `./a.out <(echo Eu sou um arquivo)` ou `echo Não sei porquê você faria isso > >(cat -)`).

Da para ver um exemplo com o script [ler\_arquivo](ler_arquivo.sh)

### Redirecionar com outras coisas

Você também pode escrever sua entrada antes de rodar seu programa. Você tem duas opções para isso: Redirecionamento de um argumento ou redirecionamento multilinha.

De um argumento você passa três sinais de menor (`<<<`) e um argumento depois. Esse argumento pode ser várias coisas dentro de aspas também.

O de multilinha é um pouco mais difícil. Você passa dois sinais de menor (`<<`) seguidos de um identificador de fim de entrada (normalmente `EOF`, mas pode ser o que você quiser). Então você pode escrever o quanto quiser. Para terminar, basta escrever o identificador de fim de entrada na última linha.

## Ficar mais rápido no terminal

### Rodar comandos no histórico

Você pode rodar comandos que já foram executados previamente (e até corrigir os erros) com facilidade.

Aqui é como executar...

* `!!` - o último comando
* `!vim` - o último comando que começa com `vim`
* `!?main` - o último comando que contém `main` em algum lugar
* `^ti^it^` - o último comando, substituindo todos os `ti` por `it`

### Glob

Globs são muito úteis para definir um padrão de arquivos para usar como entrada. Eles trocam o padrão que foi escrito por uma lista de argumentos que bate com a especificação antes de rodar o programa.

O asterisco (`*`) é usado para indicar "qualquer coisa" (ex.: `*.c` significa "qualquer coisa que termine em `.c`" e `saida/*` significa "qualquer coisa que está dentro da pasta `saida/`").

Globs também fazem busca recursiva. Para indicar "zero ou mais subdiretórios" basta colocar dois asteriscos (`**`) onde entraria um diretório (ex.: `**/*.c` significa "qualquer coisa nesse diretório e em diretórios abaixo que terminem em `.c`").

Por último, globs também funcionam com listas e sequências. Você pode definir uma lista entre chaves (`{}`) separada por vírgula (`,`) e ele vai criar um argumento por lista utilizando o que já está no argumento. Sequências também podem ser definidas colocando o valor inicial e o valor final separados por dois pontos (`..`), com um terceiro argumento opcional sendo o passo dessa sequência (ex.: `codigos.{c,h}`, `arquivo_{1..100}.txt`, `echo Ímpares: {1..100..2}`).

Essas listas e sequências também podem estar juntas e até dentro uma da outra (ex.: `**/*.{c,h}{,pp}` ou `an{o,el{,ar}}`).

## Customização

E por último mas não menos importante a gente tem a customização do seu bash.

Os arquivos de configuração normalmente começam com um ponto (`.`), que indica um arquivo escondido, daí o nome de arquivos de configuração de *dotfiles*. Existem pessoas que compartilham seus *dotfiles* em sites como o GitHub ou GitLab. Eu recomendo dar uma olhada no *dotfiles* dos professores ou de outras pessoas para ver o que elas fazem para talvez roubar uma ideia ou outra delas.

As configurações do bash ficam no arquivo `.bashrc`, na `home` (`~`) do seu usuário. Nesse arquivo você pode configurar tudo o que quiser, inclusive definir funções que você pode usar como se fossem comandos no seu bash. Eu vou falar de algumas coisas que se pode fazer para aumentar a produtividade.

Muitas vezes você vê que precisa de um comando extra ou que está rodando um comando muito grande várias vezes; para esses casos você pode fazer um `alias`. Um alias troca o que foi digitado por outra coisa. Um exemplo pode ser fazer um alias `gs` para `git status`, `repos` para `cd ~/repos/` ou até mesmo `gti` para `git`.

Para fazer um alias, basta executar o comando `alias` e defini-lo do mesmo jeito que se define uma variável (ex.: `alias gs='git status'`).

Por último, você também pode configurar outros diretórios onde o seu terminal vai checar por comandos. Você pode criar uma pasta com scripts e colocá-la nessa lista para poder usar seus scripts em qualquer lugar. Para isso, basta adicionar um novo diretório na variável `PATH`.

Os diretórios são separados por ponto e vírgula (`;`). Basta exportar a variável com o novo diretório concatenado ao conteúdo que já existia na variável (ex.: `export PATH=${PATH};~/.scripts/`).

## Recursos externos

* `man 1 bash`
* `man 3 history`

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Vilela]()
