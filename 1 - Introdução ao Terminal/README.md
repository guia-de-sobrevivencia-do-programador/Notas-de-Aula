# 1 - Introdução ao Terminal

## Conceitos

### Terminal emulator (urxvt, st, kitty, alacritty, cmd, powershell…)

O emulador de terminal é um programa para exibir e receber texto. Nós como usuários o utilizamos para se comunicar com o computador. Apesar de comumente nos referirmos a ele como Terminal, é na verdade um emulador de terminal, um dispositivo eletrônico não mais utilizado (teletype ou TTY).

Tanto no windows existe o cmd e o powershell quanto no linux onde existe uma variedade de terminais diferentes. Para as distros Ubuntu padrão, o seu terminal será o GNOME Terminal: nele podemos escrever comandos e interagir com o computador de maneira direta. Para abrir seu terminal, existe um atalho: `CTRL + ALT + T`

Exemplo de um emulador de terminal:

![Gnome terminal](./assets/Gnome_terminal.png)

Terminal antigo:

![Terminal antigo](./assets/Terminal_antigo.png)

### Shell (bash, zsh, dash, fish…)

O shell é o programa que está sendo rodado por trás do emulador de terminal, sendo de suma importância para os terminais.

O shell é o responsável por entender o que você está escrevendo e interpretar nossos comandos. Cada shell tem uma linguagem própria para interpretar seus comandos, a shell por padrão instalada no sistema operacional unix é o bash, conhecendo essa linguagem mais a fundo é possível criar scripts e usar ela como uma linguagem de programação.

Sendo praticamente uma linguagem de programação existe o conceito de variáveis de ambiente, essas variáveis são importantes para guardar informações utilizadas pelo shell.

Para o shell entender os comandos que o usuário quer digitar é usado uma variável especial chamada PATH, essa variável define quais programas estão no escopo da shell, ou seja todos os programas na variável PATH podem ser executados independentemente de onde o usuário estiver.

Nada mais que um programa que roda programas. (Aqui dá pra falar de variáveis de ambiente)

Em sua shell é provável que a tenha um texto como o da imagem acima, esse texto representa o nome do seu usuário e o nome de sua máquina separados por um @ e onde você se encontra atualmente.

Na imagem acima é possível ver que o usuário é o azz e o computador é o doom, atualmente o usuário se encontra em seu diretório HOME representada por uma variável `~`.

## Comandos

### echo

O comando echo é um simples programa que repete o argumento digitado pelo usuário.

Ex:
```bash
echo Olá mundo!
```


### cd (change directory)

O cd é um comando para mudar de diretório e navegar em seu computador, caso queira entrar/sair de um diretório. "cd /etc/passwd" indica a mudança de contexto para o caminho global "etc/passwd". "cd -" indica que o diretório a ser carregado é o último diretório acessado pelo usuário. Já "cd" (sem argumentos) e "cd ~" ambos retornam para a pasta home do usuário.

#### Caminho Relativo

Existe uma notação em unix que representa o próprio diretório ao qual o usuário se encontra presente: "." . Nada mais é que um atalho utilizado para escrever caminhos relativos ao diretório atual.

Se o resultado de um pwd é "/Users/enrique.silva/Desktop", então podemos representar um arquivo chamado "oi.txt", armazenado nesta pasta, da seguinte maneira: "./oi.txt". Exceto em casos específicos, esse ponto pode ser omitido sem perda do contexto de caminho relativo.

É possível se referir também ao diretório parente ao que nosso usuário se encontra, utilizando o símbolo "..". Utilizando-se do exemplo acima, "../ola.txt" se refere a um arquivo "olar.txt", contido na pasta "enrique.silva", que também contém "Desktop".

Caminhos relativos poupam caracteres de maneira elegante: Por exemplo, "./../../" em nosso exemplo indicaria o diretório "/Users".

#### Caminho Global

Todo arquivo ou diretório em um sistema unix possui um caminho global que indica como acessar o arquivo a partir da base do sistema. Chamamos essa base do sistema de raiz, ou root, e não existem diretórios que a contenham. Existe um símbolo reservado para essa raiz, e é "/".

Portanto, caso haja uma pasta chamada "users" dentro da raiz, seu caminho global é "/users". Caso exista um diretório "emanuel" contido em "users", representamos seu caminho global como: "/users/emanuel" Reparem que enquanto é o primeiro caractere da string, a barra indica a raiz do sistema e enquanto está contida no meio da string, a barra é um separador de diretórios.

Existe também o símbolo "~", indicador do caminho global até a pasta "/home/USUARIO" (ou "/users/USUARIO" no MacOS), onde USUARIO é o nome do usuário que está usando a shell.

### ls (list)

O comando ls tem o objetivo de mostrar os arquivos e diretórios contidos em um diretório, caso não receba argumentos ele vai mostrar os arquivos do diretório atual.

Por ser um programa de linha de comando ele pode receber argumentos (Flags). Assim dando mais detalhes sobre os arquivos do diretório especificado.

Algumas flags importantes podem ser:
* `-l` ou `–long`: Mostra a permissão do arquivo, tamanho do arquivo, última vez em que o arquivo foi modificado e o nome do arquivo em uma lista.
* `-a`: No linux existem arquivos que não são exibidos normalmente chamados de dotfiles (Começam com um ponto, vamos abordar mais adiante), esses arquivos podem ser vistos usando a flag `-a`.

## Permissões

### Diretórios != Arquivos

### RWX (Read Write Execute)

Cada arquivo tem permissões de read ("r"), write ("w") e execute ("x"), essas permissões são aplicadas para 3 tipos de usuários: dono do arquivo, usuário do mesmo grupo do dono do arquivo e quaisquer outros usuários. Essas permissões podem ser vistas com o comando ls e a flag -l.
Ex:
```
    drwxr--r-x
```

Sempre separamos as strings de permissões em 4 partes, uma parte de apenas um char e as demais de 3 chars. Em nosso exemplo, eis as partes: 1a: "d"  2a: "rwx"  3a: "r--"  4a: "r-x".
* A primeira parte indica se aquele nome se refere a um diretório ou não.
* A segunda parte indica as permissões de acesso para usuário ao arquivo ou diretório.
* A terceira, as permissões para o grupo de usuários ao qual o atual pertence.
* A quarta, as permissões para todos os outros usuários não contidos na regra anterior.

Vale lembrar que o símbolo  "-" em uma posição indica a ausência daquela característica.

### Usuários e Grupos

### whoami

O comando whoami é um comando utilizado para mostrar o usuário atual.

### groups

O comando groups é o comando utilizado para mostrar os grupos que o usuário atual pertence.

### id

Análogo ao "groups", mostra o número de identificação de cada grupo que o usuário atual pertence

## Ajuda

### `–help` ou `-h`

Normalmente para cada comando existe uma flag "-h" ou a flag "–-help" que imprime no terminal instruções de como usar o programa. Apesar de não ser regra, muitos programas utilizam da boa prática de incluir tais flags.

### man

Comando que procura por uma página de instruções de um programa específico nas páginas de manual do sistema operacional. Entende-se como o manual uma coleção de textos chamados de páginas, cada uma documentando uma característica específica do sistema. Geralmente quando um programa novo é baixado através de um package manager, baixa-se em conjunto suas páginas para serem adicionadas ao manual. Para aprendermos a como utilizar o "man", basta digitar o comando "man man".

### tldr

O tldr é um programa que recebe como argumento o nome de outro programa e lista e explica alguns comandos úteis do programa especificado. Geralmente é usado quando o usuário está sem tempo para ler o manual ou ver o uso -h ou —-help de um programa específico.

## Arquivos

### cat

Permite concatenar arquivos, exibindo o resultado final na tela do terminal. Apesar disso, também é muito utilizado apenas para exibir os conteúdos de um arquivo. Outro detalhe importante de se mencionar é que não necessariamente o programa precisa ler um arquivo, pois ele também pode ler texto digitado como entrada pelo terminal ao receber o símbolo "-" ao invés do nome de algum arquivo.

Para imprimir o conteúdo de um arquivo chamado "archive-name":
```bash
cat archive-name
```

Para concatenar dois ou mais arquivos, basta adicionar os nomes de cada arquivo separados por espaço ao final do comando, como por exemplo:
```bash
cat file1 file2 file4 file4
```

### less/more

### head/tail

O comando head exibe por padrão as primeiras 10 linhas de um arquivo, é possível também especificar o número de linhas ou o número de bytes a ser imprimido. Para imprimir as 3 primeiras linhas de um arquivos chamado "texto":
```bash
head -n 3 texto
```

O comando tail exibe por padrão as últimas 10 linhas de um arquivo, é possível, assim como o comando head, especificar o número de linhas ou bytes a ser imprimido. Para imprimir os 10 últimos bytes de um arquivo chamado “texto”:
```bash
tail -c 10 texto
```

### strings

## Modificar

### mv

Permite com que o usuário possa mover arquivos ou diretórios em seu computador.

Para mover um arquivo chamado “Tarefa 2” para uma pasta chamada “~/Tarefas”:
```bash
mv ‘Tarefa 2’ ./Tarefas/
```
Obs: Lembre-se de usar as aspas em arquivos com espaços no nome, caso o contrário o comando mv vai considerar “Tarefa” e “2” como dois aquivos separados

Também é utilizado para renomear aquivos em seu computador, para renomear um arquivo “novo documento” para “trabalho final”: 
```bash
mv ‘novo documento’ ‘trabalho final’.
``

Caso seja especificado mais de dois argumentos, por padrão, todos os arquivos especificados com exceção do último serão enviados para a localização do último argumento. Caso o usuário queira enviar os arquivos “Tarefa_Redes.pdf”, “Tarefa_OAC.pdf” e “Tarefa_IP.pdf” para o diretório “./Tarefas”:
```bash
mv Tarefa_Redes.pdf Tarefa_OAC.pdf Tarefa_IP.pdf ./Tarefas

### cp

## Criar

### mkdir

Permite com que o usuário crie diretórios. Para criar um diretório chamado “Downloads”:
```bash
mkdir  Downloads
```
É possível também criar vários diretórios colocando mais argumentos. Para criar 3 diretórios “Fotos”, “Vídeos” e “Arquivos”:
```bash
mkdir Fotos Vídeos Arquivos
```
Caso queira criar uma hierarquia de pastas é possível usar a flag `-p` ou `–parents`, assim diretórios inexistentes serão criados. Por exemplo criar uma pasta “Vídeos de gato” dentro de uma pasta “Vídeos”:
```bash
mkdir Vídeos/Vídeos\ de\ gato -p
```

### touch

Permite que o usuário mude a data de modificação de um arquivo e caso o arquivo não exista ele cria um arquivo vazio. Para modificar um arquivo “redação” para o horário atual:
```bash
touch redação
```

## Editando

## Achar coisas

### find

Permite que o usuário possa pesquisar por arquivos em seu diretório, recebendo o diretório para procurar o arquivo e a expressão em seguida.

Arquivos com a extensão “.cpp” no diretório atual:
```bash
find ./ -name ‘*.cpp’
```

Arquivos que foram modificados nos últimos 7 dias no diretório “tarefas”:
```bash
find ./tarefas -daystart -mtime -7
```

Arquivos entre 500Kb e 10Mb no diretório atual:
```bash
find ./ -size +500k -size 10M
```

### grep

Permite que o usuário procure por strings dentro de um arquivo. O primeiro argumento é a expressão que o usuário quer encontrar e os próximos argumentos são os arquivos que o usuário vai procurar pela expressão.

Para encontrar a palavra “urgente” no arquivo “tarefas”:
```bash
grep urgente ./tarefas
```

Para encontrar a palavra “trabalho_final.cpp” em todas as pastas dentro de “Downloads”:
```bash
grep –recursive trabalho_final.cpp ./Downloads
```

## Responsáveis
* [Tsu](https://github.com/HTsuyoshi)
* [Emanuel](https://github.com/Oiapokxui)
