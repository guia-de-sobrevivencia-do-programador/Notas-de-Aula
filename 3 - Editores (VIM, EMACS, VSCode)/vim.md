# Vi , Vim e Neovim

Vim é um editor antigo, de código fonte aberto, muito popular entre programadores por ser altamente extensível, e infame por sua curva de aprendizado não amigável a iniciantes. Entretanto, ele é uma versão melhorada (*v* *im*proved) do editor `vi`, que não continha _syntax highlighting_, modo visual, scripting e outras gostosuras.

O vi, predecessor do vim, foi concebido nos anos 70 por Billy Joy com base no editor `ex`, e tem seu nome por ser o modo `*vi*sual` deste. O vi surgiu em uma época onde se acessava computadores através de terminais remotos cujo layout dos teclados era levemente diferente: As setas direcionais eram acessadas pelas teclas `hjkl` e a tecla Escape encontrava-se onde hoje encontramos a tecla Caps Lock.

<img title="teclado do terminal ADM3A" alt="teclado antigo kk" src="./Resources/ADM3A.png">

O vim por sua vez foi criado e mantido por Bram Moolenaar, porém por ser ainda o único *maintainer* do repositório (não permitindo contribuições no código por ninguém além dele mesmo), as atualizações do editor não conseguem acompanhar as vontades da comunidade e, devido a isso, foi criado o editor Neovim, que é um *fork* do editor vim, visando refatorar o código do editor e adicionar novas funcionalidades de maneira mais rápida e centradas na comunidade, mas ainda mantendo compatibilidade com o seu predecessor. Das várias contribuições feitas pela comunidade voltadas para o usuário final, duas que se destacam são o suporte nativo para Language Server Protocols e a adoção de Lua como sua linguagem principal para configuração e scripts.

# Por quê VIM?

Vim preza por uma edição fluida de código. O modo de funcionamento padrão do vim e o `normal mode`. Nesse modo, cada tecla tem um significado e o que você faz e conversar com o editor através de frases.

Essas frases tem uma ação (com um numero de repetições como argumento opcional) e, dependendo da ação, um objeto ou movimento sob o qual essa ação será executada. Por um lado, uma ação pode ser `delete`, `replace`, `change`, `insert`, `paste` e muitas outras. Por outro lado, um objeto ou movimento pode ser uma ou mais (através de argumentos opcionais) palavras, parágrafos, linhas, tudo dentro de um parênteses e várias outras coisas também.

Essa gramática, quando dominada, permite uma edição muito mais rápida e fluida do código sem o sentimento de que você esta pensando para programar. Você pode somente focar no código em si e não no ato de programar.

Para os acostumados com a sintaxe e o jeito de funcionar do vim, editar um arquivo se torna uma tarefa muito menos monótona e muito mais dinâmica: 
Ações complexas requerem poucas teclas digitadas para serem executadas, e tarefas repetitivas podem ser facilmente reexecutadas em outro trecho de código ou ate em vários arquivos diferentes.
Adicionalmente, devido a sua origem, o editor força o usuário a nunca tirar a mão de perto das letras (as chamadas _home row keys_), e isso permite que ações sejam encadeadas sem interrupções. 
Além disso, vim permite que funções novas de edição sejam criadas, dando liberdade ao usuário de customizar qualquer aspecto do editor através de scripts feitos por você e plugins feitos pela comunidade.

# Os básicos.

## Como abrir um arquivo:
Para abrir um arquivo com vim, basta digitarmos no terminal: `vim [nome-do-arquivo]`. Caso o arquivo não exista, o editor tratará de criar esse arquivo para você.

## Ué, porque o que eu escrevo não aparece na tela?

Se você acabou de abrir o editor e já tentou escrever alguma coisa, vai perceber que o resultado não foi nada esperado. 
Isso se dá porque vim funciona através de modos: Quando abrimos o editor, ele está no modo normal, que permite a navegação pelo texto, mas não a edição.
Para editarmos, basta digitar `i` dentro do modo normal, o que nos levará ao modo de inserção, nele podemos digitar sem obstáculos. 
Para voltar ao modo normal, basta apertar a tecla Esc. Essa lógica vale para (quase) todos os modos que você se encontrar.

## Ok, mas como que eu salvo um arquivo?
Você não sai. MUAHAHAHAHAHAH. Brincadeira. Para salvarmos um arquivo, precisamos dizer ao editor que vamos executar um comando.
Para isso, precisamos estar no modo normal e então digitar `:w` e apertar a tecla Enter. Os dois pontos ativam o modo de linha de comando, 
já o caractere `w` (de _write_) indica o comando de salvar o conteúdo escrito na tela para o arquivo. 

A partir de agora é só colinha para refrescar os comandos (ATENÇÃO! `^` antes de um caractere significa que a tecla CTRL deve ser pressionada junto ao mesmo):

# Modo Normal
## Movimentação

-  Toda movimentação pode receber uma quantidade antes que indica quantas vezes será repetida. Ex: `4j` ou `50l`
-  Por caracteres: `h`(esquerda), `j`(baixo), `k`(cima), `l`(direita)
-  Por "palavra": `w` (`word`: começo da próxima palavra), `e`(`end of word`: final da próxima palavra), `b` (`back`: começo da palavra anterior)
-  Por linha (não aceita quantidade): `0`(começo da linha), `^`(começo da linha ignorando caracteres de espaço), `$`(final da linha)
-  Por arquivo: `gg`(Começo do arquivo), `G`(Final do arquivo)
-  Por arquivo (também): `#G`(substitua `#` por um numero: vá para a linha `#`), `#%`(substitua `#` por um numero: vá para o `#` por cento do arquivo. Ex.: `50%`: vá para o meio do arquivo)

## Desfazer ações
-  Desfazer: `u`
-  Refazer: `^R` 

## Deletar
-  Aceita quantidades antes da ação
-  Deletar por movimento: `d` + movimento
-  Deletar linha inteira: `dd`
-  Deletar até o final da linha: `D`

## Copiar e Colar
-  Copiar por movimento: `y` + movimento
-  Copiar linha inteira: `Y` ou `yy`
-  Colar antes do cursor: `P`
-  Colar depois do cursor: `p`

# Modo de Inserção (entra-se a partir do modo normal)
-  Inserir antes do cursor: `i`
-  Inserir antes do primeiro caractere que não é whitespace na linha: `I`
-  Adicionar ao final do cursor: `a` 
-  Adicionar ao final da linha: `A`
-  Sair do modo normal : Tecla Esc

# Modo visual (entra-se a partir do modo normal)
-  Funcionalidade igual ao modo normal, porém selecionando texto.
-  Ativar modo visual por caractere: `v`
-  Ativar modo visual por linha: `V`
-  Ativar modo visual por coluna: `^V` 

# Modo de comandos (entra-se a partir do modo normal ou visual)
-  Ativar modo:  `:`
-  Procurar e substituir uma vez na linha: `s/PADRAO-DE-PROCURA/TEXTO-DE-SUBSTITUICAO/` + tecla ENTER
-  Procurar e substituir todas as ocorrências na linha: `s/PADRAO-DE-PROCURA/TEXTO-DE-SUBSTITUICAO/g` + tecla ENTER
-  Procurar e substituir uma vez na linha, confirmando a substituição: `s/PADRAO-DE-PROCURA/TEXTO-DE-SUBSTITUICAO/c` + tecla ENTER
-  Procurar e substituir em todo o arquivo: `%s/PADRAO-DE-PROCURA/TEXTO-DE-SUBSTITUICAO/` + tecla ENTER

# Recursos externos
- Livro 'Learning the vi and Vim editors', de Arnold Robbins, Elbert Hannah e Linda Lamb (O'Reilly, 7a ed.).
- `vimtutor`, comando instalado em conjunto ao vim que ensina o usuário a usar esse através do próprio editor e de um texto contendo um tutorial.
