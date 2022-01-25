# vi , vim e Neovim

Vim é um editor de código fonte aberto antigo, muito popular entre programadores por ser altamente extensível e infame por sua dificuldade inicial de uso.
Entretanto, vim é uma versão melhorada (*vi* i*m*proved) do editor `vi`, que não continha _syntax highlighting_, modo visual, scripting e outras gostosuras.
Billy Joy programou o vi nos anos 70,  com base em no editor `ex` e tem seu nome por ser o modo `*vi*sual` deste. O vi surgiu em uma época onde se acessava computadores 
através de terminais remotos, cujo layout dos teclados era levemente diferente: As setas direcionais eram acessadas pelas teclas `hjkl` e a tecla Escape 
econtrava-se onde encontramos a Caps Lock. [MOSTRAR LAYOUT TECLADO ANTIGO] 
Vim foi criado e mantido por Bram Moolenaar, porém o fato de ser ainda o único *maintainer* do repositório, as atualizações do editor não conseguem acompanhar 
as vontades da comunidade e devido a isso, criou-se o editor Neovim, que é um *fork* do editor vim, visando refatorar o editor e adicionar novas funcionalidades 
de maneira mais rápida, mas ainda mantendo compatibilidade com o seu predecessor. Neovim tem suporte nativo a Language Server Protocols, adota Lua como sua linguagem principal para
scripts [ETC ETC PREENCHER]

# Por quê VIM?
Para os acostumados com a sintaxe e o jeito de funcionar do vim, editar um arquivo se torna uma torna muito menos monótona e muito mais dinâmica: 
Ações complexas requerem poucas teclas digitadas para serem computadas e tarefas repetitivas podem ser facilmente repetidas com uma ou duas teclas (`.` ou `@`).
Adicionalmente, devido a sua origem, o editor força o usuário a nunca tirar a mão de perto das letras, e isso permite que ações sejam encadeadas sem interrupções. 
Além disso, vim permite que funções novas de edição sejam criadas, dando liberdade ao usuário de customizar 

# Os básicos.

## Como abrir um arquivo:
Para abrir um arquivo com vim, basta digitarmos no terminal: `vim [nome-do-arquivo]`. Caso o arquivo não exista, o editor tratará de criar esse arquivo para você.

## Ué, porque o que eu escrevo não aparece na tela?

Se você acabou de abrir o editor e já tentou escrever alguma coisa, vai perceber que o resultado não foi nada esperado. 
Isso se dá porque vim funciona através de modos: Quando abrimos o editor, ele está no modo normal, que permite a navegação pelo texto, mas não a edição.
Para editarmos, basta digitar `i` dentro do modo normal, o que nos levará ao modo de inserção, nele podemos digitar sem obstáculos. 
Para sairmos do modo de inserção, basta apertar a tecla Esc que voltaremos ao modo normal. Essa lógica vale para todos os modos que você se encontrar.

## Ok, mas como que eu salvo um arquivo?
Você não sai. MUAHAHAHAHAHAH. Brincadeira. Para salvarmos um arquivo, precisamos dizer ao editor que vamos executar um comando.
Para isso, precisamos estar no modo normal e então digitar `:w` e apertar a tecl Enter. Os dois pontos ativam o modo de linha de comando, 
já o caractere `w` indica o comando de salvar o conteúdo escrito na tela para o arquivo. 
