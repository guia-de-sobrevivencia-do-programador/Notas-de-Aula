# VSCODE

(Eu vou adicionar imagens depois, confia)

## Se acostumando com a interface

A primeira coisa a se fazer é um projeto. Faça uma pasta no computador. Crie algum arquivo qualquer nele (eu vou fazer alguma_coisa.py pra facilitar a minha vida). Pelo VSCODE, File > Open File ou Ctrl + O.
Depois disso, mostre como o arquivo será aberto na janela principal. Escreva qualquer coisa em menos de 15 segundos para mostrar como é um programa.

A partir daqui, mostraremos as utilidades da barra lateral:

![Imgur](https://i.imgur.com/2dWwM2D.png)

O primeiro é o Explorer. Intuitivo como o Windows Explorer, mostra a organização dos arquivos no seu projeto, e permite operações como criar um arquivo, renomear um arquivo, etc. através do botão esquerdo nele.

Demonstre isso. Renomeie o arquivo, mova ele, e abra ele de novo pelo botão esquerdo


O segundo é o Search. Ele pesquisa referências da palavra procurada dentro de todos os arquivos na pasta selecionada. Rápido para encontrar todas as referências de alguma variável ou função

Escreva bagulho_aleatorio cinco vezes no arquivo, depois a use.


 O terceiro é o Source Control. É uma integração com Git, a qual já deve ser explicada pela aula de Git e GitHub. Permite você publicar uma pasta inteira através do próprio VSCODE. E só isso.


O quarto é o botão de debug, também acessável por Run > Start Debugging ou somente F5. Isso será explicado em sua própria seção da apresentação, mais tarde.


O quinto é o botão de extensões, uma das mais principais características do VSCODE. 

Abra, e mostre a parte principal. Vai parecer mais ou menos como isso:

![Imgur](https://i.imgur.com/Nrn0Ngo.png)

As extensões tem coisas como: Servidores para hostear sites localmente (O Live Server), debuggers para linguagens específicas, corretores automáticos específicos de linguagem, debuggers especializados, WSL, integração com containers, uma extensão que permite duas ou mais pessoas editarem um código local (O Live Share, o meu favorito) e basicamente qualquer coisa já concebida pela psyche humana.

Você pode baixar alguma extensão como exemplo, só saiba o que você está baixando e como deixar isso claro na apresentação.

O sexto botão é o próprio Live Share! Ele está na imagem para mostrar o quão integrado as extensões podem ser. Desde alterações na fluidez de produção do código até em coisas que verdadeiramente moldam o VSCODE.


## Visão de janelas e terminal

Olhando para a parte mais principal do VSCODE, podemos ver algo como isso: 

![Imgur](https://i.imgur.com/V18urSu.png)

Em vermelho temos as abas. Usadas para trocar rapidamente entre códigos abertos.
Em azul temos o botão de rodar o código, similar ao de outras IDEs. Contanto que a língua esteja corretamente instalada (talvez o VSCODE precise de extensões para tal), ao apertar o botão, um script rodará, que executará o código atualmente sendo visto pelo editor.
Em verde temos o editor. Tão bom como qualquer editor de texto. E coloridinho também. 
Em rosa temos os consoles. No caso do meu print, temos a aba de Problems (relativo ao Workspace, talvez nem precise ser explicado), o de Output (preciso pesquisar o que isso faz, mesmo que o nome diga Output, normalmente sai no terminal.), o console de Debug, que fica ativo em sessões de debug, e o glorioso terminal, aquilo que é o seu melhor aliado.
Primeiro explorando a visão do editor, mostre como e possível dividir telas dentro do próprio contexto, tipo assim: 

![Imgur](https://i.imgur.com/ye6ftWu.png)


Tanto pelo botão circulado em rosa, quanto por View > Editor Layout > Split Right (ou down, sei lá, use todas as opções). Útil para ver várias partes do código ao mesmo tempo.

Ou LITERALMENTE só arrasta pra onde você quer. O negócio é flexível. 

![Imgur](https://i.imgur.com/zeQ9AA8.png)

Agora, o terminal.

![Imgur](https://i.imgur.com/gitPGsZ.png)

Através de Terminal > New Terminal ou Ctrl+Shift+’, nós abrimos um terminal.
![Imgur](https://i.imgur.com/OpQcYft.png)

Ele será útil por vários motivos. Mesmo que o VSCODE tenha um botão de rodar, ele, na verdade, roda um script pré-montado e estático no terminal. Pelo terminal, você pode rodar os seus programas com parâmetros na linha de comando. Além disso, você pode executar comandos bash, ou comandos específicos do framework.

Um exemplo seria NODE (sim, eu sei, Javascript, eca), onde o Run não funciona, e você precisa escrever no terminal coisas como npm install, npm start ou npm run dev.

Ou, no nosso caso, o melhor uso é para, claro, rodar Linux. Caso você já tenha o WSL apropriadamente configurado, você pode fazer:

![Imgur](https://i.imgur.com/7MJIgCX.png)

E voilá, estamos agora rodando os programas no subsistema de Linux (que, no meu caso, é o Kali). Isso vai se provar extremamente útil quando nós quisermos usar comandos como apt-get, para rapidamente instalar outras livrarias (ou linguagens até) em nosso projeto.

## Feijão com arroz

E com isso nós temos o conhecimento suficiente para escrever algo no VSCODE!

Escolha uma linguagem de programação. A que você quiser, não faz diferença. Você pode escolher instalar ela globalmente no sistema ao através do terminal, para manter no contexto do repositório.

A primeira coisa é usar o botão de extensões e instalar um pacote de realce de sintaxe. Isso é extremamente importante para ajudar literalmente qualquer programador a não se perder no código.

![Imgur](https://i.imgur.com/nwB5jeM.png)
Sem realce

![Imgur](https://i.imgur.com/xqCkOJC.png)
Com realce

No caso, eu estou usando Python. O pacote que possui realce é o recomendado, ou seja:

![Imgur](https://i.imgur.com/yFNWt4d.png)

Quando o VSCODE detectar que você tenha algo de relevante para desenvolvimento instalado no computador, ele trará um desses pop-ups:

![Imgur](https://i.imgur.com/jBKTqcv.png)

Então, esses pacotes recomendados serão de alta ajuda para o seu desenvolvimento, a não ser que você esteja fazendo algo muito específico.


Tá, como exemplo, eu escrevi este código:

![Imgur](https://i.imgur.com/c9he7X7.png)

Este código pega arquivos compactados em .tar.gz de uma pasta, e descompacta em outra pasta, tudo usando comandos de terminal, importados através de “import os”.

![Imgur](https://i.imgur.com/OpUGH5Q.png)

Podemos ver que ao errar a sintaxe, as cores e os highlights apontam onde os erros estão.

## Debugging

Aqui a coisa fica interessante.

Para um exemplo simples, eu arrumei o seguinte código:

![Imgur](https://i.imgur.com/WJ1aUBE.png)

A ideia é simples: Eu fiz uma função que fala: Usando a função lambda de Python, retorne através de um for uma array de valores definido por uma função que, no caso, deveria ser:

[x * 0, x * 1, x * 2, x * 3, x * 4]

Quando eu chamo multiplier(2), eu defino todos os X como 2. Portanto, a nossa saída deveria ser: 

    [0,2,4,6,8]

Porém, quando rodamos o programa, temos:

![Imgur](https://i.imgur.com/GvrxMEb.png)

Impresso no terminal.

Mas por que? Vamos nos utilizar do debugger do VSCODE:

![Imgur](https://i.imgur.com/WoCKazU.png)

Na parte esquerda das linhas, você pode adicionar pausas. Enquanto você estiver no modo de debug, a execução do código para, para que você consiga ver o estado atual do programa sem que ele termine muito rápido sua execução.

Portanto, vamos rodar em debug, apertando 
![Imgur](https://i.imgur.com/W8ZcxaS.png)
ou usando Ctrl+Shift+D

![Imgur](https://i.imgur.com/rwnzlq9.png)
Durante a declaração da função create_multipliers, podemos ver que, de fato, i está indo de 0 a 4, como esperado. Mas, quando chegamos na linha do print, podemos ver:

![image]()
Em todos os prints, o i está valendo 4.

Se você explorar o suficiente, você descobrirá que por motivos de Programação Orientada a Objetos, por causa de Ligação Dinâmica, o valor utilizado em i é o resultado da função interna. Ou seja, na verdade temos uma array de:

[i*x,i*x,i*x,i*x,i*x] 

E o i é definido como o resultado final de 
```python
i in range(5)
```

, que no caso é 4. Com esse conhecimento, podemos consertar a função. Declarando-a dessa forma:

![image]()

Agora, cada valor de i é salvo.

Podemos abrir o debugger, agora nessa função, e podemos ver:

![image]()

Os valores de i estão corretos e, ainda mais importante:

![image]()

O valor da saída está correto.

## Máquinas virtuais (WSL)


   Para o caso específico do Windows, é possível você instalar distribuições de sistemas operacionais Linux, e usá-los dentro do próprio Windows, com interface em Terminal. O VSCODE detecta quais você possui instalados, e permite você rodar seu código em outro ambiente, caso seja necessário.

   Por exemplo, eu possuo o Ubuntu e Kali para WSL instalados no meu computador. Ao apertar o botão de fazer um novo terminal, eu tenho as alternativas:
   
![image]()

Essas opções se encontram na aba de Terminal (ou Ctrl + ‘).

    Vamos abrir um terminal de Ubuntu, apertando pelo botão, e:
![image]()
   E agora, estamos basicamente dentro do Ubuntu. Um dos principais motivos pelos quais você pode querer fazer isso, é usar bibliotecas únicas do Linux e, especialmente, instalá-las usando o gerenciador de pacotes.

   Isso foi abordado já, na aula de Linux, mas, somente para provar, vamos instalar o Make, e rodar na pasta de testes:
(MUITA IMAGEM)

## Integração com Git

  Na aba de Source Control, caso a pasta que esteja selecionada, seja um repositório vinculado do Git, você pode ver todas as alterações atuais nos arquivos do repositório, e pode, através desta barra:
  
![image]()
 
 Fazer commits com comentários para a branch atual. Além disso, ao clicar nos três pontos ao lado:

![image]()

Podemos ver todas as ações possíveis do Git, e podemos somente clicar nelas, ao invés de digitar no terminal os comandos.
    A explicação destes comandos é feita na aula de Git.

