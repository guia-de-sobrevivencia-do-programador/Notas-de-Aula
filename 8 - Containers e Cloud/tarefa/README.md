# Tarefa

## Entrega

A entrega desta tarefa será um arquivo `.zip` contendo a pasta tarefa com as modificações de cada seção e os arquivos extras indicados. Os arquivos devem seguir o seguinte formato:

```
Ex0: 
saida_de_exemplo_do_exercicio_0
saida_de_exemplo_do_exercicio_0
saida_de_exemplo_do_exercicio_0

Ex1:
saida_de_exemplo_do_exercicio_1
saida_de_exemplo_do_exercicio_1
saida_de_exemplo_do_exercicio_1
```

## Seção 1 - Virtualização, VMs e containers

Para essa seção, serão feitas algumas perguntas, que devem ser respondidas em um arquivo `secao1.txt` no zip da entrega.

0. Cite pelo menos 3 diferenças entre uma máquina virtual e um container.
1. VMs e containers possuem propósitos semelhantes. Qual uma vantagem comum entre essas duas tecnologias?

## Seção 2 - Docker

Essa seção tem como objetivo condensar todos os conceitos de Docker vistos em aula em um exercício prático. Para todos os exercícios, **Não é necessário alterar o código JavaScript**, e eventuais respostas textuais deverão estar em um arquivo `secao2.txt`.

* As saídas dos exercícios `0` e `1` desta seção deverão estar no arquivo `secao2.txt` seguindo o seguinte formato:

0. Execute a aplicação localmente com o comando `npm start` e faça uma requisição via curl para a mesma (`curl localhost:3000`). Copie as saídas do terminal conforme a instrução acima.
1. Execute a aplicação dentro de um container, expondo a porta `3000` do container na porta `3001` da máquina local. Faça uma nova requisição para a aplicação dentro do container. Copie as saídas do terminal conforme a instrução acima.
2. Porque o IP é diferente nas duas requisições?
3. Gere uma imagem Docker a partir do Dockerfile disponibilizado. Registre o comando utilizado no arquivo `secao2.txt` da entrega.
4. A aplicação, além de registrar informações na saída padrão (`stdout`), também registra sua saída em um arquivo de log que se encontra no caminho `/var/log/app/nosso-log.log` do container. Execute um comando para rodar um container, mantendo o arquivo de log em um volume nomeado. Registre esse comando no `secao2.txt`
5. Faça uma requisição para a aplicação dentro do container. Remova o container, suba-o novamente e faça uma nova requisição. Adicione o arquivo `nosso-log.log` no zip da entrega. Note que, se o volume foi criado corretamente no passo anterior, o arquivo deve conter duas linhas com ids diferentes.
