# Linters

## O que é um linter?

Linter é uma ferramenta para ajudar no desenvolvimento do seu código. O Linter analisa o código especificado procurando por problemas, podem ser eles problemas técnicos ou problemas de qualidade de código, sendo assim capazes de diagnosticar e arrumar problemas que podem passar despercebidos pelo programador.

O resultado será um código mais legível, consistente e mais fácil de manter, dessa forma também estarão contribuindo para ajudar programadores mais inexperientes à aprender sobre qualidade de código.

Além disso alguns Linters também conseguem manter o código mais seguro e perfomático, mas isso não é uma regra.

## Análise Estática

A análise estática é feito pelos linters para analisar o código em questão sem executar ele, checando por problemas, bugs, vazamento de memória e outros problemas.

## Erros de Sintaxe

Uma das coisas mais básicas que o Linter pode oferecer são verificar erros de sintaxe.

Erros de sintaxe são detectadas pelos compiladores em linguagens `compiladas` como c, c++, java, etc... Mas para linguagens `interpretadas` os erros apenas vão ser encontrados quando o código for executado, é aí que o Linter entra!

Um exemplo pode ser erros do `CSS` que vão apenas ser percebidos quando o site for acessado.

## Convenções de código

Convenções de código são de extrema importância quando se quer criar um código para ser mantido ou um cógido que vai ser usado por muitas pessoas.

Ter uma convenção de código único facilita a leitura de um código, ao invés de ter estilos de código de vários desenvolvedores diferentes que iria dificultar a legibilidade do código.

## Problemas em potencial

Um exemplo de problemas em potencial ou `code smells` são, por exemplo, funções grandes.

Dependendo de pessoa para pessoa funções grandes podem ser consideradas potenciais problemas, então é possível configurar o Linter para detectar funções que são maiores que um certo número de linhas e então o desenvolvedor pode verificar esses potenciais problemas e arrumar eles.

## Performace

A performace, já vista em aulas passadas especificamente em perfilamento, é de suma importância para a o desenvolvimento de um aplicativo.

Muitos linters também incluem verificação de performace, eles podem adicionar diferentes tipos de performace e para novos programadores pode ajudar bastante no desenvolvimento e no aprendizado.

## Segurança

A segurança é um dos maiores problemas no desenvolvimento de um código ou o maior problema que os devem se preocupar.

Não se aplica para todos os linters, mas existem linters específicos que podem oferecer verificações de segurança durante o desenvolvimento de um aplicativo.


## Exemplos

Para quem quiser dar uma olhada nos linters existentes e quais linguagens de programação eles conseguem suportar existe um [repositorio](https://megalinter.github.io/5.7.0/all_linters/) com uma variedade de linters especificando sua licença, linguagem, versão, repositório, etc... Existem outros repositórios com indicações de linters como [esse](https://github.com/caramelomartins/awesome-linters).

Vai depender do programador pesquisar e escolher qual linter é melhor para seu uso no dia-a-dia.
