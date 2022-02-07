# Tarefa

## Entrega

A entrega do arquivo deve ser feita no formato abaixo nesta mesma pasta foi deixado um [template](./template.md) de respostas:

```
## Seção 1

Resposta 1: Os arquivo(s) que contém vazamento de memória (são/é) `#############`

Resposta 2: Os arquivo(s) que executam o comando `free()` em um bloco já liberado (são/é) `#############`

## Seção 2

```

## [Seção 1](./Secao_1) - Depuração (Valgrind)

* Usando o `Valgrind` qual dos arquivos dentro da pasta `Secao_1` tem um vazamento de memória?

* Usando o `Valgrind` qual dos arquivos dentro da pasta `Secao_1` o comando `free()` é usado duas vezes para liberar memória na mesma variável?

## [Seção 2](./Secao_2) - Depuração (GDB)

* Usando o `gdb` qual é o valor da variável `numero` dentro do for quando o valor de `i` é `85`?

* Usando o `dprintf` dentro do gdb como seria um comando de exemplo para imprimir o valor de `numero` e `i`?

## [Seção 3](./Secao_3) - Perfilamento

* Compile o arquivo dentro da pasta `Secao_3` e use alguns dos programas mostrados durante a aula para descobrir qual das funções dentro do código é a mais demorada, e escreva qual das funções demorou mais.
