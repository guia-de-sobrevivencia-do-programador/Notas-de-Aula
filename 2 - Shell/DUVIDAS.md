# Q&A

Aqui registramos e vamos responder algumas perguntas que foram feitas durante a aula.

## Dúvidas da Aula

#### Dúvida 1

- A variável de ambiente é sempre escrita em caixa-alta?

É mais uma convenção do que uma regra. Você pode escrever em caixa-baixa também.

#### Dúvida 2

- Qual a definição de uma variável de ambiente?

Variáveis de ambiente são valores nomeados (variáveis) e dinâmicos (podem mudar em tempo de execução) que podem afetar o comportamento dos processos do computador. As variáveis de ambiente de um novo processo (um programa executado) são herdadas do processo que o criou. Se você executa um processo no terminal, é do shell que o novo processo herdará as variáveis. Em um shell como o Bash, você pode definir novas variáveis de ambiente para os processos que serão executados por esse shell com o comando `export`. As variáveis de ambiente podem ser acessadas pelos programas usando a chamada de sistema `getenv()` (veja o seu manual em `man 3 getenv`).

#### Dúvida 3

- ele usou `Ctrl + C` para parar o looping? (Durante a demonstração de um loop em bashscript)

Isso! `Ctrl+c` significa que você está mandando um sinal de interrupção ao programa que está atualmente rodando

#### Dúvida 4

- Como faz para abrir dois terminais? (Quando o Fukuda abriu mais um terminal)

Ele estava usando tmux, vai ser mostrado mais sobre esse assunto na aula 9.

#### Dúvida 5

- É possível instalar o WSL no Windows 7?

Não é possível.
