# 2 - Shell

## Shell Scripting

Arquivos `.sh`

Shebang (`#!`)

Funções

### Flow control

* `if; then; elif; then; else; then; fi`
* `while; do; done`
* `for in; do; done`
* `case; in; esac`
* `select; do; done`

## Ambiente e Variáveis de ambiente

`env` e `printenv`

`VAR=algumacoisa`, `$VAR` e `${VAR}`

`unset`

`VAR=("valor 1" "valor 2" "valor B")`, `${VAR[@]}` e `VAR[0]}`

`${VAR[@]:1}` e `${VAR[@]:0:1}`

### Variáveis especiais

`$#`, `$$`, `$0..`, `$*` e `$@`

`$?` e `$_`

### Export e Define

`export VAR=outrcoisa`

`define VAR=umaterceiracoisa`

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

`<()` e `>()`

### Redirecionar com arquivos:

`>`, `>>`, `<`

### Redirecionar com outras coisas

`<<` e `<<<`

## Rodar comandos no histórico

* `!vim` - começa com `vim`
* `!?main` - tem `main` em algum lugar no comando
* `^ti^it^` - roda o último comando substituindo todos os `ti` por `it`

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

`source` e `.`

`PS1`, `PS2` e `PS3`

`PATH` e `CDPATH`

`set`, `shopt`

## Recursos externos

* `man 1 bash`
* `man 3 history`

## Responsáveis
* [Fukuda](https://github.com/JoaoFukuda)
* [Vilela]()
