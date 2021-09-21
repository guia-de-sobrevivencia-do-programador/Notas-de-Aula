# 2 - Shell

Saber bash e scripting é muito útil para aumentar sua produtividade em ambientes Linux.

## Shell Scripting

Arquivos terminados em `.sh` (ex.: `script.sh`, `banana.sh` e `exemplo.sh`) são usados para identificar scripts em bash, mas não são obrigatórios.

Se você for usar um script como um executável qualquer (invocar ele através da linha de comando com `./script.sh`), vai ser necessário colocar um shebang (`#!`) na primeira linha para definir qual programa ira interpretar o arquivo. No nosso caso vai ser o `/bin/bash`, mas poderia ser `/bin/python3` por exemplo.

Funções podem ser definidas e chamadas dentro de scripts assim:

```bash
fun() {
	echo "Estou imprimindo de dentro de uma funcao"
}
```

É possível retornar de funções usando o comando `return`. E pode retornar do programa principal usando o comando `exit`. Como argumento opcional você pode passar um inteiro.

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

As condições são feitas rodando um comando (definido na hora) e pegando a sua saída. 0 indica verdadeiro e qualquer outro valor indica falso. Para fazer os testes que você "normalmente" faria em um programa normal, você pode usar o comando `test` (que também pode ser chamado usando um par de colchetes `[` e `]`) e passando alguns testes. Abra o manual do comando (`man test`) para saber mais.

## Ambiente e Variáveis de ambiente

É possível ver as variáveis de ambiente atuais com o comando `printenv`, rodar um programa em um ambiente novo com `env` e remover uma variável do ambiente atual com `unset`.

Para definir/redefinir variáveis de ambiente você coloca o nome da variável, um `=` **sem espaço entre o nome e o `=`** e o valor que quer dar para a variável (ex.: `VAR=algumacoisa`). As variáveis de ambiente tem nomes em caixa alta por padrão (tipo query de MySQL), mas pode colocar minúscula ou maiúscula (cuidado que o bash é *case sensitive*). Para usar essas variáveis: nome dela com um cifrão na frente; o nome pode ou não estar envolto de `{}` (ex.: `$VAR` ou `${VAR}`).

Você também pode pegar variáveis do usuário com o comando `read`. É só invocar ele passando o nome da variável como argumento.

Um exemplo de variáveis pode ser visto no arquivo [`inatorinator`](inatorinator)

### [[ Candidato a remoção

Existem alguns outros tipos de variáveis que podem ser utilizadas; uma delas é o arranjo.

`VAR=("valor 1" "valor 2" "valor B")`, `${VAR[@]}` e `VAR[0]}`

`${#VAR[@]}` ou `${#VAR[*]}`, `${VAR[@]:1}` e `${VAR[@]:0:1}`

### ]]

### Export e Define

`export VAR=outracoisa`

`define VAR=umaterceiracoisa`

### Variáveis especiais

`$#`, `$$`, `$0..`, `$*` e `$@`

`$?` e `$_`

## Rodar múltiplos comandos

`;`, `&&` e `||`

`&`

## Redirecionamento de Entradas e Saídas

Entradas e saídas de comandos no Linux funciona como arquivos (pipes e streams).

* `0` - stdin
* `1` - stdout
* `2` - stderr

### Redirecionar com outros comandos

`|`

`$()`, `<()` e `>()`

### Redirecionar com arquivos:

`>`, `>>`, `<`

### Redirecionar com outras coisas

`<<` e `<<<`

## Rodar comandos no histórico

* `!!` - o último comando
* `!vim` - começa com `vim`
* `!?main` - tem `main` em algum lugar no comando
* `^ti^it^` - último comando, substituindo todos os `ti` por `it`

## Glob

`*`

`**`

`{1,2,3}`

`{1..4}`

#### ExtGlob

`!(*.txt)`

## Customização

### BashRC

`alias` e `unalias`

`source`, `exec` e `.`

`set`, `shopt`

`PATH` e `CDPATH`

### Cosméticos

`PS1`, `PS2` e `PS3`

ANSI Escape Sequences

## Recursos externos

* `man 1 bash`
* `man 3 history`

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Vilela]()
