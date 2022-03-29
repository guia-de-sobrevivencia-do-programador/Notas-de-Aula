# Tarefa

## Seção 1 — Vim

Resposta 1: Deve aparecer ser inserida uma linha escrito "Olá, tudo bem?" acima da linha que o cursor se encontrava antes do comando.

Resposta 2: Sim. Acontece porque todo o conteúdo do arquivo .vimrc é executado antes do vim permitir a edição pelo usuário.

## Seção 2 — Emacs

Resposta 1: `C-s` invoca o método *isearch-forward* (ou *search-forward*, ambos corretos) que busca uma *string* no *buffer* de forma incremental.

Resposta 2: `C-k` invoca a função *kill-line* que mata a posição do cursor até o fim da linha (outras formas de dizer o mesmo: mata o conteúdo de uma linha OU recorta o conteúdo de uma linha)

Resposta 3:

- O resultado esperado para o primeiro `C-y` (*yank*) é colar o conteúdo das últimas linhas matadas/recordadas com o `C-k`.

- O resultado esperado para o `M-y` é substituir o conteúdo colado pelo `C-y` pelo conteúdo da primeira linha matada/recordada com o primeiro `C-k`

- No Emacs, strings *killed*/recortadas são removidas no texto e armazenadas em uma fila chamada de *kill-ring*. `C-y` *yank*/cola o texto mais recente inserido no *kill-ring*. `M-y` percorre os kills anteriores e permite você *yank*/colar um texto recortado/*killed* mais antigo.

## Seção 3 — Visual Studio Code

Resposta 1: *Tomorrow Night Blue*

Resposta 2: O que aparece na pasta é um arquivo `.workspace-code`. Ele serve para fazer configurações relacionadas ao *VSCODE* no contexto do projeto, como ativar/desativar *plugins*, etc.

Resposta 3: Será gerada uma estrutura de pastas, mas com um arquivo `settings.json` e um arquivo `App.java`. o `settings.json` terá configurações de caminho para a pasta raiz e para onde as dependências são instaladas, e o `App.java` será só um *Hello World*.
