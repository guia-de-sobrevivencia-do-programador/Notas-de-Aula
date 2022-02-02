# Tarefa

Grande parte das tarefas abaixo podem ser feitas utilizando ferramentas normais do Windows, mas por aprendizado e recomendamos aplicar os conhecimentos adiquiridos em aula!

Em cada Seção vai ser disponibilizada arquivos para realizar a tarefa! Por exemplo para resolver a tarefa da `Seção 1` o aluno terá que entrar na pasta `Seção 1` para conseguir relizar a tarefa.

## Entrega

A entrega do arquivo deve ser feita no formato abaixo nesta mesma pasta foi deixado um [template](./template.md) de respostas:

```
## Seção 1

Resposta 1: Posso compactar usando o comando `#############`

Resposta 2: Posso descompactar usando o comando `#############`

## Seção 2

```

## [Seção 1](./Secao_1) - Ajuda

O intuito dessa seção é fazer o aluno treinar os comandos `man` ou `info` ou `tldr` ou alguma outra documentação, assim o aluno vai conseguir se virar no dia-a-dia caso precise pesquisar sobre um comando que não conhece.

* Usando o comando `zip` como posso compactar 2 arquivos chamados `tarefa_1.txt` e `tarefa_2.txt` e a pasta `codigos` em um arquivo chamado `entrega.zip`?

* Usando o comando `unzip` como posso descompactar o arquivo chamado `entrega.zip` para saber se as tarefas foram compactadas corretamentes? (Verifique se os arquivos dentro dos diretórios estão corretos)

## [Seção 2](./Secao_2) - Leitura

Nesse seção o aluno vai treinar os comandos vistos na aula para ler arquivos.

* Usando o comando `cat` leia todos os arquivos dentro pasta `./textos` de uma vez, qual é a resposta encontrada?

* Usando o comando `strings` procure por strings com mais de 20 caracteres dentro do binário `./executavel`, qual foi a string encontrada?

## [Seção 3](./Secao_3) - Achar coisas

Para os dois primeiros exercícios primeiro extraia o arquivo `muitas_pastas.zip`.

Nesse seção o aluno vai revisar os comandos vistos na aula para achar arquivos, não foi mostrado todas as flags necessárias para resolver esses exercícios mas é possível encontrar explicação desses comandos na nota de aula!


* Usando o comando `find` encontre o arquivo nomeado `anotacoes_perdidas.txt`, qual foi o comando usado para encontrar o arquivo?

* Usando o comando `find` você não lembra o nome do arquivo que perdeu, mas sabe que o arquivo tem mais de 100K, qual foi o comando usado para encontrar o arquivo?

* Usando o comando `grep` procure na pasta `./muitos_textos` e responda quais arquivos tem a string `guia de sobrevivencia do programador` com os arquivos separados por vírgula

## [Seção 4](./Secao_4) - Permissões

Nesse seção o aluno vai revisar os conceitos sobre permissão de arquivos.

Abaixo estão as permissões de acesso para o arquivo `ppeerrmmiissooeess`
```
-rw--w-r-x
```
Escreva quais as permissões de leitura, escrita e execução para: 

* O usuário que criou o arquivo.

* Usuários do mesmo grupo que o dono do arquivo.

* Qualquer outro usuário não incluso nas últimas duas questões.
