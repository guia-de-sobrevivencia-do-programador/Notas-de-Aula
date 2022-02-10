# Desktop Environment (DE)

Uma DE permite que o usuário tenha uma experiência completa para a interface gráfica do usuário, ícones, barras de ferramentas, papéis de paredes e seu próprio gerenciador de janelas.

Pode ser comparado com o que é visto no Windows a barra de ferramentas, barra de pesquisa, gerenciador de tarefas etc....

Cada distribuição de Linux pode vir ou não com uma DE, dependo da distribuição ela te dá várias opções de DEs como pode ser visto na imagem abaixo:

<p align="center">
    <img src="./assets/Manjaro_exemplos_de.png" alt="Manjaro Exemplos DE" width="400" height="200" />
</p>

Essa imagem dá a opção para o usuário baixar a distribuição [Manjaro](https://manjaro.org/download/) com 3 opções oficiais de DEs.

Geralmente uma DE possui outros aplicativos que ajudam a compôr a interface gráfica do usuário.

Alguns DEs famosos são: `KDE`, `GNOME`, `XFCE`, `MATE`, etc...

O usuário tem a liberdade de adicionar programas de outros DEs por exemplo usando `KDE` eu posso usar programas do `GNOME` (provavelmente o tema dos programas não vai ser o mesmo já que são de DEs diferentes)

[Lista](https://wiki.archlinux.org/title/Desktop_environment_%28Portugu%C3%AAs%29#Lista_de_ambientes_de_desktop) de DEs disponíveis.

# Window Manager (WM)

Um WM ou gerenciador de janelas é o programa que vai controlar o posicionamento e a aparência das janelas em uma interface gráfica (GUI), por ser mais simples que uma DE, normalmente, um WM acaba utilizando menos memória RAM que um DE.

O WM pode ser usado dentro de uma DE ou usada de forma independente na imagem abaixo podemos ver dois WM (sway e i3):

<p align="center">
    <img src="./assets/Manjaro_exemplos_wm.png" alt="Manjaro Exemplos WM" width="400" height="200" />
</p>

## Tipos

Os WMs podem ser classificados em 3 tipos:

* [Stacking](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_de_empilhamento): É o tipo de organização mais comum para usuários de DEs, Windows e OS X, esse tipo de WM os programas ficam `flutuando` pela área de trabalho.

* [Tiling](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_de_tiling): Esse tipo de WM tem uma organização `automática`. Quando novas janelas são criadas elas automaticamentes são organizadas na área de trabalho de uma forma que as janelas não vão se sobrepor, a organização das janelas vai depender do WM usado ou da configuração do WM.

* [Dynamic](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_din%C3%A2micos): Esse tipo de WM abrange os dois tipos mostrados anteriormente o Stacking e o Tiling, O Dynamic consegue `transicionar` entre os modos de Stacking e Tiling, assim fica à escolha do usuário em qual modo ele quer que as janelas fiquem.

# WM x DE

Como visto antes uma DE é um WM com outras coisas que integram o desktop para que ele consiga ter bastantes funcionalidades.

Enquanto o WM é só um gerenciador de tarefas, ou seja ele pode ou não ter coisas como um sistema de menu, notificações, gerenciador de clipboard, gerenciador de internet, gerenciador de login, etc... outros softwares que vão ficar responsáveis por gerenciar essas coisas. Mas como o WM vem sem nada o usuário pode escolher o que ele quer instalar e vai gastar menos memória RAM no seu computador.

Para quem usa bastante o teclado vai ser uma boa opção já que quase nunca você vai precisar tirar suas mãos do teclado.
