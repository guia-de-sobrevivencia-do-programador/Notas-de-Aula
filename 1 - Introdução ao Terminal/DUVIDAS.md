# Q&A

Aqui registramos e vamos responder algumas perguntas que foram feitas durante a aula.

#### Dúvida 1

- O que é ambiente `unix`?

Unix é um sistema operacional antigo que segue o padrão POSIX. Alguns sistemas operacionais atualmente (como o OSX e o Linux) são baseados em Unix e seguem (pelo menos parcialmente) o padrão POSIX :) Esses sistemas operacionais são os "ambientes unix".

#### Dúvida 2

- (Sobre permissões e tipo do arquivo) Não tem nada fica um `-`? Na frente?

Explicação está nasnotas de aula! Procure na seção de permissões.

#### Dúvida 3

- o que é o `cd`?

Explicação está nas notas de aula! Procure na seção de comandos.

#### Dúvida 4

- O que seria o `total 4` e os valores `3` e `1` antes do usuário? (durante a demonstração do comando `ls -l`)

Esses números são a quantidade de referências que o sistema de arquivos tem a esse arquivo.ls (link count). Um arquivo regular normalmente tem uma referência, a não ser que tenha links para ele (daí o número aumenta).

#### Dúvida 5

- Como ele escolhe o caminho? Por exemplo, se na pasta `aula1` tiver 2 pastas: `eu-sou-uma-pasta-` e `eu-sou-uma-pasta-2`? Qual caminho ele escolhe?

O cd pega o caminho exato que você mandar, então se você executar o comando
```sh
cd uma-pasta-
```
e houver dois `arquivos uma-pasta-` e `uma-pasta-2`, ele escolhe a que se encaixa exatamente com o argumento. E se você executar 
```sh
cd uma-pasta-
```
e só houver o diretório `uma-pasta-2`, ele dá erro.

#### Dúvida 6

- Como sai do `cat`? (Depois de usar o comando `cat` sem argumentos)

`Ctrl+d` ou `Ctrl+c`

#### Dúvida 7

- `Diretórios` com espaços

Para mencionar diretórios ou arquivos com espaços é possível usar a barra ao contrário `\`.
Supondo que exista uma pasta chamada `Pasta com espaços`, podemos entrar nessa pasta usando o comando `cd`:


```sh
cd Pasta\ com\ espaços
```

O mesmo serve para apagar ou criar uma pasta com espaços:

```sh
rmdir Pasta\ com\ espaços
```

```sh
mkdir Pasta\ com\ espaços
```

#### Dúvida 8

Aqui o comando `man strings` não funcionou e exibiu:

```sh
No manual entry for strings
```

Você pode tentar instalar os dois pacotes para o seu sistema: `man-db` e `man-pages`

```sh
sudo apt-get install man-db man-pages
```

#### Dúvida 9

É `Ctrl+l` ou ctrl `Shift+l`? (Para limpar o terminal)

É `Ctrl + l`, mas não funciona em todos os terminais

#### Dúvida 11

O `find` só funciona no diretório atual?

Não, o primeiro argumento para o `find` é o diretório onde ele vai começar a procurar, mas ele vai descer em todas as subpastas buscando por arquivos

#### Dica

Flags do `grep`

`-A`: After
`-B`: Before
`-C`: Context
`-a`: around (a mesma coisa que C)

