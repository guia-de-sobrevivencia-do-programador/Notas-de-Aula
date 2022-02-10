# 9 - Potpourri

Outras ferramentas e tópicos que não tivemos tempo de fazer uma aula própria.

## Suite de redes Linux

Antes de falar sobre a suite de ferramentas para redes em Linux, uma breve aula sobre redes:

A internet é a rede mais famosa que conhecemos, mas é somente uma de varias redes que regem a conexão entre computadores.

Cada rede tem seus próprios endereços IPs, e pode ou não estar conectada a internet ou a outra rede. Esses endereços são o que identificam uma máquina ou um nó na rede. Cada máquina em uma rede tem pelo menos um endereço, e cada endereço é único dentro dessa rede.

Por que eu digo "pelo menos"? Porque uma mesma máquina pode ter mais de um endereço vinculado a ela, pois o que retém controle desse endereço não é a máquina ou o sistema operacional, mas sim os dispositivos de rede. Se você tiver um adaptador *WiFi* e um cabo conectados ao seu computador ao mesmo tempo, cada uma dessas entradas (ou *NICs* de *Network Interface Cards*) terão seu próprio endereço de IP distinto.

Uma máquina também pode estar conectada a duas redes ao mesmo tempo. Essa máquina é chamada de *gateway*, pois vira o portão, ou *gateway*, entre uma rede e outra (mas pode ter somente um *gateway* por rede, e esse normalmente é o seu roteador, que conecta sua rede local à internet). Se uma máquina em uma dessas redes quiser se conectar a uma máquina da outra rede, a conexão entre essas duas máquinas vai passar por essa máquina configurada como *gateway*.

Existem vários grupos de endereços que são reservados. Alguns desses grupos são reservados para redes locais, detalhados no RFC 1918. Essas são:

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
