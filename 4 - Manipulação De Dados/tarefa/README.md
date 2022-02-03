# Tarefa

## 1 - Análise de frequência com `grep` e RegEx
Um dos meios mais ingênuos de gerar mensagens criptografadas é o de substituir cada caractere de sua mensagem original por um outro pré-determinado. Algo como um dicionário que diz que se X=1, U=5 e A=!, teriamos que `XUXA` pode ser reescrito como `151!`. Um problema sério deste método de cifrar mensagens é que há muitos caracteres que se repetem em uma mensagem (como o espaço, sinais de pontuação e a letra "a" no português), e alguém pode com uma simples análise de frequência pode descobrir a chave/dicionário que decifra a mensagem, ou seja, identificar a frequência de cada caractere da mensagem, e fazer algumas tentativas e erro para ler a mensagem na integra, substituindo dos caracteres mais frequentes na cifra para os mais frequentes de sua língua.

Neste exercício temos uma linha de texto no arquivo `cifra.txt` que foi criptografada utilizando o método de substituição. Sua tarefa é utilizar o comando `grep` e, quando necessário, expressões regulares para gerar uma tabela que contém na primeira coluna a frequência de aparições de um caractere, e na segunda coluna o caractere que está fazendo referência. Obviamente você também pode utilizar outros comandos como o `uniq` para esta tarefa, mas **deve** utilizar o comando `grep`. A tabela final pode ser ordenada da maneira que preferir, desde que contenha todas as referências de caracteres.

Exemplo de tabela que o comando deveria gerar:
```
1 ?
1 5
1 b
1 M
2 1
2 j
2 v
3 !
3 #
3 ,
3 g
3 y
4 '
4 :
4 `
4 d
4 m
5 l
5 L
6 F
6 i
6 u
7 >
7 h
7 K
7 t
8 .
8 f
8 n
8 w
9 6
10 =
10 2
10 o
10 r
10 s
10 Z
15 a
17 W
25 e
30 
```

Salve esta saída em um arquivo chamado `1.txt`.

## 2 - sed e RegEx
Utilizando novamente o arquivo `acesslog.txt` (você pode baixá-lo novamente [por aqui](https://www.kaggle.com/kmanchikalapudi/accesslog-5-19-2021txt)), há uma parte do log referente ao [User-Agent](https://developer.mozilla.org/pt-BR/docs/Web/HTTP/Headers/User-Agent), que é o cabeçalho de informações do de uma requisição que o usuário fez para o servidor que está gerando o log. Por meio dele é possível identificar qual sistema operacional está rodando o navegador que efetuou a requisição.

User-agent (referente a uma máquina Windows neste caso):
`"Mozilla/5.0 (Windows NT 6.1; rv:17.0) Gecko/17.0 Firefox/17.0"`

Sua tarefa é identificar se o user-agent faz referência à uma máquina Linux, Windows ou nenhum dos dois Sistemas Operacionais, e então substituir todo este campo do log usando `sed` pela palavra `Linux`, `Windows` ou `-` (caso não seja Windows/Linux ou não tenha informações sobre a origem).

Como exemplo:
```
ANTES: 75.119.215.210 - - 19/May/2021:05:25:32 "POST /wp-login.php HTTP/1.1" 301 - "-" "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:62.0) Gecko/20100101 Firefox/62.0"

DEPOIS: 75.119.215.210 - - 19/May/2021:05:25:32 "POST /wp-login.php HTTP/1.1" 301 - "-" Linux
```

Você deve retornar o log inteiro alterado pelas substituições e os comandos utilizados em um txt.

## 3 - curl e APIs

Escolha uma API que não seja a viacep e faça uma requisição `GET` usando o `curl`. Você pode escolher APIs de acesso público como a [PokéAPI](https://pokeapi.co/) e a [Randomuser.me](https://randomuser.me/) , ou restritas por credenciais como a do [Spotify](https://developer.spotify.com/documentation/web-api/) e a do [Twitter](https://developer.twitter.com/en/docs/twitter-api). Caso escolha fazer uma requisição em uma API privada você **não precisa e nem deve** enviar suas chaves de acesso no comando que acompanha a tarefa (pode escrever algo como `<chave_api>` no lugar). 

Para essa tarefa é necessário executar o `curl` com a url que faz a requisição à API (e para a autenticação também, caso esteja utilizando). Vale lembrar que a formatação da url vai variar, e você precisa verificar na documentação da API como é o formato esperado por ela.

Salve o retorno da API em um arquivo chamado `3.txt`. Caso veja que há informações sensíveis no retorno, pode sustituí-las no arquivo final por `<removido_para_entrega>` onde achar pertinente.

## Entrega

A entrega sera um arquivo zipado chamado `aula4.zip` (ou rar, tar etc, desde que possa ser aberto usando o Linux) contendo:
- Um arquivo `comandos.txt` contendo os comandos utilizados para resolver cada uma das três tarefas, indicando se o comando faz referência à tarefa 1,2 ou 3;
- Os três arquivos com a saída de cada um dos exercícios.

