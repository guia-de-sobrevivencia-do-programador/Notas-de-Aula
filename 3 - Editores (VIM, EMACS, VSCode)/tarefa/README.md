# Tarefa

## Seção 1 — Vim

1. Abra o vim em qualquer arquivo, entre no modo de comando, digite o seguinte comando 
`nnoremap B 0iOlá, tudo bem?<CR><Esc>` e então volte ao modo normal. 
O que acontece se você digitar `B` (shift + `b`) no modo normal após salvar o comando?

2. Digite `nnoremap B 0iOlá, tudo bem?<CR><Esc>` dentro de um arquivo chamado `.vimrc`, salve o arquivo na pasta home de seu usuário (~) e saia do editor. 
Então, reabra o vim em qualquer arquivo. 
O mesmo comportamento observado na questão anterior acontece se você digitar `B` enquanto no modo normal? Por quê isso acontece?

## Seção 2 — Emacs

Como vimos em aula, o Emacs é um editor autodocumentado; toda a sua documentação está disponível em seu sofisticado sistema de descrição.

Siga os seguintes passos:
1. Abra o Emacs (digite `emacs` na linha de comando após instalá-lo)
2. Entre no tutorial do Emacs (digite `C-h t`)

Com base no tutorial e usando os métodos de descrição do Emacs vistos em aula, responda:

1. O que faz a sequência de teclas `C-s`? (Dica: veja a seção "SEARCHING" do tutorial ou use `C-h k`?

2. O que faz a sequência de teclas `C-k`? (Dica: veja a seção "INSERTING AND DELETING" do tutorial)

3. Vamos realizar um experimento. Digite algum texto em seu buffer *scratch* (o buffer onde rabiscamos os rascunhos, use o menu `Buffers` ou troque de buffer usando `C-x b`). Agora use `C-k` no início da primeira linha do texto digitado, digite algumas linhas novas e use `C-k` novamente nessas linhas. Agora use o comando `C-y` para fazer o *yank* (colar). 
   Qual o resultado esperado para `C-y`? Se você digitar `C-y` novamente, qual o resultado esperado como resultado do novo comando de *yank*? Logo em seguida ao `C-y`, digite `M-y` (e repita `M-y` algumas vezes). Com base no experimento, qual a diferença entre `C-y` e `M-y`? (Dica: veja a seção "INSERTING AND DELETING" do tutorial)

## Seção 3 — Visual Studio Code
