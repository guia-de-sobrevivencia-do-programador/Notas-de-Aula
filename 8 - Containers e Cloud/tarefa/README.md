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
```
Aqui há 3 exemplos de diferenças, mas não são as únicas
```
  1. **R**: VMs possuem um SO próprio, enquanto containers utilizam recursos do SO do hospedeiro para realizar suas tarefas.
  2. **R**: O consumo de recursos das VMs é maior devido à presença do SO do hóspede.
  3. **R**: Enquanto os containers virtualizam somente o *software* (SO, bibliotecas e dependências), VMs virtualizam o *software* **e** o *hardware* através do hypervisor.
1. VMs e containers possuem propósitos semelhantes. Qual uma vantagem comum entre essas duas tecnologias?
  * **R**: Ambas nos permitem adicionar níveis de isolamento entre o computador físico e as aplicações

## Seção 2 - Docker

Essa seção tem como objetivo exercitar os conceitos de Docker vistos em aula em um exercício prático. Para todos os exercícios, **não é necessário alterar o código JavaScript fornecido**. As respostas às perguntas deverão estar em um arquivo `secao2.txt` dentro do arquivo .zip a ser entregue.

0. Execute a aplicação localmente com o comando `npm start` e faça uma requisição via curl para a mesma (`curl localhost:3000`). Copie as saídas do terminal conforme a instrução acima.
1. Execute a aplicação dentro de um container, expondo a porta `3000` do container na porta `3001` da máquina local. Faça uma nova requisição para a aplicação dentro do container. Copie as saídas do terminal conforme a instrução acima.
2. Por que o IP é diferente nas duas requisições?
  * **R**: No item `0`, a aplicação está rodando no sistema original. Logo, a interface de rede utilizada para recuperar o IP é a do próprio sistema. No item `1`, estamos rodando a aplicação dentro do container, então a interface de rede utilizada é a da rede interna do Docker.

3. Gere uma imagem Docker a partir do Dockerfile disponibilizado. Registre o comando utilizado no arquivo `secao2.txt` da entrega.
  * **R**: `docker build -t <nome_da_imagem>:<versao_da_imagem (opcional)> .` (note o `.` ao final do comando, indicando o caminho do Dockerfile)
5. A aplicação fornecida, além de registrar informações na saída padrão (`stdout`), também registra sua saída em um arquivo de log que se encontra no caminho `/var/log/app/nosso-log.log` do container. Execute um comando para rodar um container, mantendo o arquivo de log em um volume nomeado. Registre esse comando no `secao2.txt`
  * **R**: `docker run <nome_da_imagem>:<versao_da_imagem (opcional) -v <nome_do_volume>:/var/log/app/nosso-log.log`
7. Faça uma requisição para a aplicação em execução dentro do container. Remova o container, suba-o novamente e faça uma nova requisição. Adicione o arquivo `nosso-log.log` no zip da entrega. Note que, se o volume foi criado corretamente no passo anterior, o arquivo deve conter duas linhas com IDs diferentes.
