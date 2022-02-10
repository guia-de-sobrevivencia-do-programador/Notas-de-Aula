# 9 - Potpourri

Nesta aula apresentamos algumas ferramentas que também são importantes no dia a dia do programador, mas que não puderam ser incluídos em uma aula própria durante o curso.

## Window manager

### Desktop Environment (DE)

Um *desktop environment* ("ambiente de área de trabalho" ou "ambiente de desktop", abreviado aqui como DE) é um conjunto de programas que implementam a metáfora da "área de trabalho" e que compartilham uma mesma interface gráfica de usuário (GUI), incluindo ícones, barras de ferramentas, papéis de paredes e até mesmo seu próprio *gerenciador de janelas*.

Pode ser comparado com o que é visto no Windows a barra de ferramentas, barra de pesquisa, gerenciador de tarefas etc....

Há vários DEs diferentes que podem ser utilizados com o Linux e o usuário pode escolher aquele que melhor atender suas necessidades. Cada distribuição Linux normalmente opta por um DE para ser oferecido por padrão (ou opta por não oferecer um por padrão) e o personaliza para a distribuição.

<p align="center">
    <img src="./assets/Manjaro_exemplos_de.png" alt="Manjaro Exemplos DE" width="400" height="200" />
</p>

Algumas distribuições permitem que você escolha qual DE você deseja utilizar antes mesmo de você baixar a distribuição. A figura acima mostra as 3 opções de DEs oferecidas oficialmente pela distribuição Linux [Manjaro](https://manjaro.org/download/).


Alguns exemplos de DEs famosos: [GNOME](https://www.gnome.org/), [KDE](https://kde.org/pt-br/), [MATE](https://mate-desktop.org/), [XFCE](https://xfce.org/) e [LXDE](http://www.lxde.org/).

O usuário tem a liberdade de usar programas feito para um DE em outros DEs. Por exemplo, um usuário que esteja usando o `KDE` pode usar programas pensados para o `GNOME` e vice-versa, ainda que provavelmente o programa tenha um aspecto (*look and feel*) diferente do DE utilizado (o tema, ou seja, a escolha de cores, de ícones, etc. do programa será diferente do tema do DE usado).

O [wiki do Arch Linux](https://wiki.archlinux.org/) (que, diga-se de passagem, possui uma documentação excelente sobre tudo que relacionado à Linux) possui uma extensa [lista de DEs](https://wiki.archlinux.org/title/Desktop_environment_%28Portugu%C3%AAs%29#Lista_de_ambientes_de_desktop) para Linux.

### Window Manager (WM)

Um WM ou gerenciador de janelas é o programa que controla o posicionamento e a aparência das janelas em uma interface gráfica (GUI). Por ser mais simples que uma DE completa, normalmente um WM usa menos memória RAM.

O WM pode ser usado dentro de uma DE ou usada de forma independente. Na imagem abaixo podemos ver dois WMs: [sway](https://swaywm.org/) e [i3](https://i3wm.org/).

<p align="center">
    <img src="./assets/Manjaro_exemplos_wm.png" alt="Manjaro Exemplos WM" width="400" height="200" />
</p>

Cada WM é implementado em uma determinada linguagem. Ter conhecimento prévio dessa linguagem pode ajudar bastante para poder configurar o seu WM da maneira que desejar.

Alguns exemplos:

- [awesome](https://awesomewm.org/) pode ser personalizado com código escrito na linguagem de programação Lua;
- [dwm](https://dwm.suckless.org/) requer que seu código-fonte em C seja modificado para ser personalizado;
- [qtile](http://www.qtile.org/) pode ser personalizado com código em Python;
- [xmonad](https://xmonad.org/) pode ser personalizado com código em Haskell.

#### Tipos

Os WMs podem ser classificados em 3 tipos:

* [Stacking](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_de_empilhamento): É o tipo de organização mais comum para usuários de DEs, Windows e OS X, esse tipo de WM os programas ficam `flutuando` pela área de trabalho.

* [Tiling](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_de_tiling): Esse tipo de WM tem uma organização `automática`. Quando novas janelas são criadas elas automaticamentes são organizadas na área de trabalho de uma forma que as janelas não vão se sobrepor, a organização das janelas vai depender do WM usado ou da configuração do WM.

* [Dynamic](https://wiki.archlinux.org/title/Window_manager_%28Portugu%C3%AAs%29#Gerenciadores_de_janela_din%C3%A2micos): Esse tipo de WM abrange os dois tipos mostrados anteriormente o Stacking e o Tiling, O Dynamic consegue `transicionar` entre os modos de Stacking e Tiling, assim fica à escolha do usuário em qual modo ele quer que as janelas fiquem.

### WM x DE

Como visto anteriormente, uma DE é um WM com funcionalidades e programas adicionais que se integram e se complementam para implementar a metáfora de ambiente área de trabalho.

Normalmente um WM atua exclusivamente como um gerenciador de janelas, ou seja, tipicamente um WM não implementa coisas como um sistema de menu, notificações, gerenciador de *clipboard*, gerenciador de redes, gerenciador de *login*, etc. Outros softwares (opcionais) são responsáveis por gerenciar essas coisas. Como um WM oferece menos recursos, optar por usar apenas um WM pode economizar bastante memória RAM do seu computador.

Muitos WMs permitem que o usuário realize todas as operações de gerenciamento de janelas usando apenas o teclado. Usuários proficientes conseguem trabalhar em tais WMs sem tirar as mãos do teclado, o que acelera bastante o trabalho.

### Complementos

Dependendo das necessidades do usuário, pode ser preciso complementar a WM com utilitários que forneçam algumas das funcionalidades adicionais encontradas em DEs:

- Inicializador de programas: [dmenu](https://tools.suckless.org/dmenu/) ou [rofi](https://github.com/davatorium/rofi)
- Painel: [polybar](https://github.com/polybar/polybar)
- Notificações: [dunst](https://github.com/dunst-project/dunst)

## Linters

### O que é um linter?

Linter é uma ferramenta para ajudar no desenvolvimento do seu código. O Linter analisa o código especificado procurando por problemas, podem ser eles problemas técnicos ou problemas de qualidade de código, sendo assim capazes de diagnosticar e arrumar problemas que podem passar despercebidos pelo programador.

O resultado será um código mais legível, consistente e mais fácil de manter, dessa forma também estarão contribuindo para ajudar programadores mais inexperientes à aprender sobre qualidade de código.

Além disso alguns Linters também conseguem manter o código mais seguro e perfomático, mas isso não é uma regra.

### Análise Estática

A análise estática é feito pelos linters para analisar o código em questão sem executar ele, checando por problemas, bugs, vazamento de memória e outros problemas.

### Erros de Sintaxe

Uma das coisas mais básicas que o Linter pode oferecer são verificar erros de sintaxe.

Erros de sintaxe são detectadas pelos compiladores em linguagens `compiladas` como C, C++, Java, etc. Mas em linguagens *interpretadas*, os erros serão encontrados apenas quando o código for executado, e é aí que o uso de um Linter se torna importante.

Um exemplo pode ser erros do `CSS` que vão apenas ser percebidos quando o site for acessado.

### Convenções de código

Convenções de código são de extrema importância quando se quer criar um código para ser mantido ou um cógido que vai ser usado por muitas pessoas.

Ter uma convenção de código único facilita a leitura de um código, ao invés de ter estilos de código de vários desenvolvedores diferentes que iria dificultar a legibilidade do código.

Uma lista de convenções de códigos para diferentes linguagens de programação e para projetos de desenvolvimento de software pode ser vista nesta página da Wikipédia: https://en.wikipedia.org/wiki/Coding_conventions#List_of_coding_standards .
### Problemas em potencial

Um exemplo de problemas em potencial ou *code smells* são, por exemplo, funções grandes.

Dependendo de pessoa para pessoa funções grandes podem ser consideradas potenciais problemas, então é possível configurar o Linter para detectar funções que são maiores que um certo número de linhas e então o desenvolvedor pode verificar esses potenciais problemas e arrumar eles.

### Performace

A performace, já vista em aulas passadas especificamente em perfilamento, é de suma importância para a o desenvolvimento de um aplicativo.

Muitos linters também incluem verificação de performace, eles podem adicionar diferentes tipos de performace e para novos programadores pode ajudar bastante no desenvolvimento e no aprendizado.

### Segurança

A segurança é um dos maiores problemas no desenvolvimento de um código ou o maior problema que os devem se preocupar.

Não se aplica para todos os linters, mas existem linters específicos que podem oferecer verificações de segurança durante o desenvolvimento de um aplicativo.

### Exemplos

Para quem quiser dar uma olhada nos linters existentes e quais linguagens de programação eles conseguem suportar existe um [repositorio](https://megalinter.github.io/5.7.0/all_linters/) com uma variedade de linters especificando sua licença, linguagem, versão, repositório, etc... Existem outros repositórios com indicações de linters como [esse](https://github.com/caramelomartins/awesome-linters).

Vai depender do programador pesquisar e escolher qual linter é melhor para seu uso no dia-a-dia.

## Suite de redes Linux

Antes de falar sobre a suite de ferramentas para redes em Linux, uma breve aula sobre redes:

A Internet é a rede mais famosa que conhecemos, mas é somente uma de várias redes que regem a conexão entre computadores.

Cada rede tem seus próprios endereços IPs, e pode ou não estar conectada à Internet ou à outra rede. Esses endereços são o que identificam uma máquina ou um nó na rede. Cada máquina em uma rede tem pelo menos um endereço, e cada endereço é único dentro dessa rede.

Por que eu digo "pelo menos"? Porque uma mesma máquina pode ter mais de um endereço vinculado a ela, pois o que retém controle desse endereço não é a máquina ou o sistema operacional, mas sim os dispositivos de rede. Se você tiver um adaptador *WiFi* e um cabo conectados ao seu computador ao mesmo tempo, cada uma dessas entradas (ou *NICs* de *Network Interface Cards*) terão seu próprio endereço de IP distinto.

Uma máquina também pode estar conectada a duas redes ao mesmo tempo. Essa máquina é chamada de *gateway*, pois vira o portão, ou *gateway*, entre uma rede e outra (mas pode ter somente um *gateway* por rede, e esse normalmente é o seu roteador, que conecta sua rede local à internet). Se uma máquina em uma dessas redes quiser se conectar a uma máquina da outra rede, a conexão entre essas duas máquinas vão passar por essa máquina configurada como *gateway*.

Existem vários grupos de endereços que são reservados. Alguns desses grupos são reservados para redes locais, detalhados no [RFC 1918](https://datatracker.ietf.org/doc/html/rfc1918). Essas são:

- `10.0.0.0/8`: do endereço `10.0.0.0` a `10.255.255.255`
- `172.16.0.0/12`: do endereço `172.16.0.0` a `172.31.255.255`
- `192.168.0.0/16`: do endereço `192.168.0.0` a `192.168.255.255`

Esses endereços (em notação *CIDR*) não podem aparecer na internet. Quem controla a distribuição de endereços da internet é a IANA (*Internet Assigned Numbers Authority*). Ela que fala quem esta responsável por quais grupos de redes.

Em uma máquina, podem ter vários programas que utilizam a internet ao mesmo tempo. O sistema operacional faz o controle de qual programa é responsável por qual conexão através da associação de portas a programas. Os programas podem pedir por uma porta ao sistema operacional, e quando alguém quiser usar tal programa, ele vai ter que especificar a porta (além do endereço IP) em cada conexão para acessar aquele programa ou serviço rodando naquela máquina.

Com esses conhecimentos a gente pode começar a usar as ferramentas de redes.

### `ssh` e `scp`

#### SSH

SSH (*Secure SHell*) é um programa que permite acesso remoto a uma shell em uma outra máquina.

Para se conectar a um computador remoto, ele precisa estar rodando um servidor SSH e você precisa saber as credenciais de um usuário do sistema. Exemplo:

```bash
ssh user@10.0.0.225
```

Se o servidor não estiver rodando na sua porta padrão, você pode definir a porta através da opção `-p`. Outras opções mais interessantes podem ser descobertas no `man` do ssh como o `-L` e o `-D`.

#### SCP

SCP (*Ssh CoPy*) utiliza o protocolo SSH para copiar arquivos entre dois computadores.

O uso é bem parecido com o SSH: você precisa de uma máquina rodando um servidor. Os parâmetros lembram bastante o próprio comando `cp` do Linux:

```bash
scp <origem> <destino>
```

Tanto a origem quanto o destino podem ser uma pasta em um computador remoto (`usuario@endereco:pasta/a/partir/da/raiz`, ex.: `user@10.0.0.225:Downloads/arquivo.pdf`) ou um arquivo local (`~/caminho/para/o/arquivo`, ex.: `/etc/passwd`).

### `ss`

Ss (*Socket Statistics*) lista todos os processos atualmente vinculados a uma porta.

Algumas opções interessantes que são interessantes de usar com o SS: `-t` para listar somente conexões TCP; `-l` para listar somente as portas ouvindo por conexões (servidores); `-p` para listar o processo responsável por aquela porta e; `-n` para não tentar inferir o nome do serviço a partir do nome da porta.

O comando fica assim:

```bash
ss -tnlp
```

### `python3 -m http.server`

Esse comando python roda o módulo `http.server` como um programa, e cria um pequeno servidor HTTP pelo qual você consegue acessar e baixar arquivos que estão na sua máquina local.

Basta entrar em uma pasta e rodar:

```bash
python3 -m http.server
```

Que um servidor HTTP estará rodando na sua máquina local na porta `8000`. Também e possível escolher a porta em que o servidor vai rodar passando uma porta como argumento. O próximo comando roda um servidor na porta `8080`:

```bash
python3 -m http.server 8080
```

### `ngrok`

Ngrok é uma ferramenta que disponibiliza um endereço na internet para outras pessoas em outras redes locais conseguir acessar seus serviços, que estão rodando dentro da sua rede local.

Você pode expor uma porta, e ela pode estar rodando um servidor HTTP ou um serviço TCP qualquer (que não um servidor HTTP).

Para expor um servidor HTTP, rode:

```bash
ngrok http 8000
```

E para expor um servico TCP qualquer, rode:

```bash
ngrok tcp 42000
```

## Cronjobs e InCronjobs

Cron e InCron são ótimas ferramentas para automação. Com eles é possível executar comandos ou scripts em um determinado horário ou se alguma determinada ação é tomada dentro de um diretório.

### Cron

É um escalonador de [*jobs*](https://en.wikipedia.org/wiki/Job_control_(Unix)) que executa comandos em horários específicos determinados no seu arquivo de configuração. Existem várias implementações de cron, como cronie e fcron.

Confira a documentação da implementação de cron que deseja usar para instruções de como iniciar o seu daemon, que é necessário para que haja o monitoramento. Caso já venha instalado com o seu sistema, provavelmente esse passo não é necessário.


#### Configuração

Geralmente o arquivo de configuração se encontra no diretório `/etc` ou em um subdiretório como `/etc/cron.d`, mas também pode ser acessado usando o comando `crontab -e`.

Algumas implementações de cron colocam comentários para ilustrar o seu funcionamento nas configurações. Ele deve parecer com isso:

```
# ┌───────────── minute (0 - 59)
# │ ┌───────────── hour (0 - 23)
# │ │ ┌───────────── day of the month (1 - 31)
# │ │ │ ┌───────────── month (1 - 12)
# │ │ │ │ ┌───────────── day of the week (0 - 6) (Sunday to Saturday;
# │ │ │ │ │                                   7 is also Sunday on some systems)
# │ │ │ │ │
# │ │ │ │ │
# * * * * * <command to execute>
```

Como é ilustrado acima, cada job é delimitado por uma linha no arquivo onde devemos preencher 6 campos: minuto, hora, dia do mês, mês, dia da semana e comando que deverá ser executado. O símbolo `*` representa qualquer número, ou seja, `10 5 * * * ~/script.sh` seria "No minuto 10, da hora 5, de todo dia do mês, todo mês e todo dia da semana execute o script ~/script.sh". Apesar de não ser comum, você também pode encontrar alguma implementação de cron que possua um campo para segundos.

Outros símbolos:

- `/` : Indica que o comando deve ser executado "a cada" tanto tempo. Por exemplo, `*/5 * * * *` significa "a cada 5 minutos".

- `,` : Usado para determinar mais de um período. Por exemplo, `* 3,4,5 * * *` significa "3,4 e 5 horas".


Combinando todos esses símbolos podemos conseguir comportamentos mais complexos. Por exemplo, `*/5 0,12 * 12 1 echo "o natal tá chegando!" >> ~/mensagens_importantes.txt` determina que durante dezembro, a cada 5 minutos das horas 0 e 12 das segunda-feiras o comando será executado.

### InCron

Ao invés de monitorar a hora, como o cron, o incron monitora diretórios ou arquivos por modificações determinadas no seu arquivo de configuração.

Confira a documentação da implementação de incron que deseja usar para instruções de como iniciar o seu daemon, que é necessário para que haja o monitoramento. Caso já venha instalado com o seu sistema, provavelmente esse passo não é necessário.

#### Configuração

Para editar o arquivo de configurações, basta executar o comando `incrontab -e`

A estrutura de uma linha de configuração do incrontab é da seguinte forma, onde "caminho" é onde se encontra o diretório ou arquivo a ser monitorado, "máscara" é o tipo de ação a ser monitorada e "comando" é o que deve ser executado:

```
<caminho> <máscara> <comando>
```

Tipos de máscara:

`IN_ACCESS`: quando o arquivo monitorado é acessado ou lido

`IN_ATTRIB`: quando algum metadado do arquivo monitorado é alterado

`IN_CLOSE_WRITE`: quando o arquivo monitorado é fechado depois de ser aberto para ser escrito

`IN_CLOSE_NOWRITE`: quando o arquivo monitorado é fechado depois de ser aberto para outra operação que não a de escrever

`IN_CREATE`: quando um arquivo ou diretório é criado dentro diretório monitorado

`IN_DELETE`: quando um arquivo ou diretório é removido dentro diretório monitorado

`IN_DELETE_SELF`: quando o próprio arquivo ou diretório monitorado é removido

`IN_MODIFY`: quando o arquivo monitorado é modificado

`IN_MOVE_SELF`: quando o próprio arquivo ou diretório monitorado é movido

`IN_MOVED_FROM`: quando um arquivo ou diretório é movido de dentro para fora do diretório monitorado

`IN_MOVED_TO`: quando um arquivo ou diretório é movido de fora para dentro do diretório monitorado

`IN_OPEN`: quando o arquivo ou diretório monitorado é aberto

Podemos também referenciar algumas coisas relacionadas aos eventos nos comandos:

- `$$`: é necessário usar esse símbolo para usar o $ como usaria em outras situações. Para acessar a variável de ambiente user, por exemplo `$$USER`

- `$@`: o caminho que está sendo monitorado
 
- `$#`: nome do arquivo ou diretório que acionou o evento

Um exemplo seria mover um arquivo para um subdiretório `Files` no Desktop do usuário assim que o arquivo aparece lá: `/home/$$USER/Desktop IN_MOVED_TO mv /home/$$USER/Desktop/$# /home/$$USER/Desktop/Files/`

O incrontab possui algumas outras possibilidades de configuração que podem ser encotradas no seu manual: `man 5 incrontab`
