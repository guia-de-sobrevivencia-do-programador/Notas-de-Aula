# Q&A

Aqui registramos e vamos responder algumas perguntas que foram feitas durante a aula.

## Dúvidas da Aula

#### Dúvida 1

- Podemos usar `git add *` para ter o mesmo comportamento de `git add .`?

Não! Usando o comando:
```sh
git add *
```
Primeiro o caractere `*` vai ser expandido e vai selecionar todos os arquivos do diretório atual que não tem um ponto no começo do nome, só depois da expansão que ele vai adicionar os arquivos.

Enquanto o comando:
```sh
git add .
```
Vai adicionar todo o conteúdo da pasta atual (Incluindo alguns arquivos que começam com um ponto).

Resumo:
O comando `git add *` tem quase o mesmo efeito do `git add .`, mas arquivos que começam com um ponto, por exemplo algum arquivo como `.xinit`, não seriam adicionados.

#### Dúvida 2

- Pra que criar uma nova branch?

Branches permitem que você identifique um ponto de mudança no seu repositório, onde o conteúdo da branch começa a se distanciar do conteúdo da branch original. Geralmente, cria-se uma branch ao começar edições que possam alterar muito o conteúdo da branch original, então caso alguma edição radical seja feita nessa branch, ela não alterará o conteúdo da branch anterior a não ser que seja decidido incorporar as mudanças de uma na outra. Em repositórios de aplicações, é bom costume criar um branch que é considerada a principal, e cada programador cria a sua própria branch a partir da principal ao trabalhar com arquivos naquele repositório, garantindo que as mudanças são relacionadas à tarefa específica que o programador está fazendo, e não de todas as tarefas que os programadores estão fazendo naquele repositório. Espera-se que uma branch nova seja reintegrada à principal em algum momento

#### Dúvida 3

- Qual a diferença entre `git merge` e `git rebase`?

O `git merge` cria um novo commit que contém todas as mudanças das duas branches envolvidas, mantendo todo o histórico das branches exatamente da mesma forma. Geralmente é a forma mais segura de aplicar commits de uma branch em outra.

O `git rebase` move todos os commits de uma branch e aplica em outra, reescrevendo o histórico de commits. Devido à reescrita, pode causar problemas com o repositório remoto quando a mesma branch é utilizada por mais de um usuário. A vantagem do rebase é que o histórico de commits fica mais linear se comparado ao merge, então é mais fácil de visualizar as mudanças no histórico.
