# 8 - Containers e Cloud

## Conceitos básicos

### Virtualização

Virtualizar ambientes é uma solução de **software** que nos permite simular o **hardware** dos computadores para a criação de ambientes computacionais virtuais. Em outros termos, com a virtualização é possível rodar múltiplos Sistemas Operacionais virtuais simultâneamente em um mesmo computador físico.

Essa tecnologia nos traz alguns benefícios ao lidar com sistemas computacionais. Com ela, conseguimos criar aplicações totalmente isoladas umas das outras, sem que haja interferência de processos do sistema original, ou de outras aplicações. Além disso, podemos aproveitar melhor o hardware, rodando múltiplos servidores em um único computador, normalmente chamado de hospedeiro (ou *host*).

O software utilizado para realizar essa tarefa de virtualizar e compartilhar os recursos físicos dos ambientes virtuais é chamado de [**hypervisor**](https://www.redhat.com/en/topics/virtualization/what-is-a-hypervisor).

### Máquinas Virtuais (ou Virtual Machines, VMs)

Um sistema rodando em um ambiente virtualizado é chamado de **máquina virtual**. Na visão do computador hospedeiro, elas são comumentemente chamados de hóspedes (ou *guests*) e são interpretadas como arquivos que podem ser transferidos entre outros hospedeiros. Esses arquivos que representam as máquinas virtuais também conseguem armazenar o estado dos hóspedes, como memória e processos em execução.

Essa é uma grande vantagem das máquinas virtuais: Em tese, como todo o sistema é simulado eé independente do hardware, é possível realizar migrações para quaisquer sistemas físicos que possuam um hypervisor. 

### Containers

De forma simplória, podemos pensar num container como uma "máquina virtual sem o Sistema Operacional hóspede" (DevOps, por favor não me matem). Se compararmos ambas as tecnologias (VMs e containers), ambas têm um propósito similar: Isolar processos e aplicações no sistema de origem, e o que as diferencia é a forma como cada uma realiza essa tarefa e qual o propósito desse isolamento.

Podemos definir um container como um conjunto de um ou mais processos (ou aplicações) isolados do restante do sistema operacional hospedeiro. A diferença para as VMs aqui é que os containers compartilham os recursos com o SO hospedeiro, ao invés de virtualizar um SO nos hóspedes. Isso faz com que containers possuam uma carga menor se comparado às VMs, tornando-os mais leves e consequentemente reduzindo o tempo de inicialização das aplicações que desejamos. 

### Docker

O Docker é um dos gerenciadores de containers mais utilizados atualmente, e será a ferramenta que utilizaremos nessa aula. De forma resumida, o Docker utiliza duas funcionalidades do kernel do Linux para realizar suas tarefas:
    1. *namespaces*, para prover a camada de isolamento necessária para os containers. Para cada aspecto necessário, um namespace é criado e é ele que limita a visibilidade do container. IDs de processos e interfaces de rede são exemplos desses aspectos.
    2. *control groups*, para alocação e isolamento dos recursos. É essa funcionalidade que limita quais recursos um container tem à sua disposição.

#### Imagens
O Docker gera artefatos chamados **imagens**, que são definidas por um arquivo de texto chamado `Dockerfile`. Esse arquivo contém um conjunto de instruções para criar um container (como um modelo) e servem como ponto de partida para executar as aplicações no Docker. Em suma, uma imagem contém a aplicação e todas as outras ferramentas e bibliotecas necessárias para sua execução.

#### Containers
Como visto anteriormente, os containers são aplicações auto-contidas e isoladas. No caso do Docker, eles são criados a partir de uma imagem. Seu ciclo de vida é gerenciado pelo containerd, um dos processos que compõem o Docker.

#### Volumes e bind mounts
Por padrão, todo o ambiente dos containers, inclusive os arquivos nele contidos, são armazenados somente dentro do container. Volumes e bind mounts são formas de compartilhar arquivos do sistema hospedeiro aos containers e vice-versa.

### Computação em nuvem (ou Cloud Computing)

A computação em nuvem é o modelo de serviço onde a computação - como servidores, armazenamento, rede, análise de dados - é oferecida através da internet. Esse modelo traz algumas vantagensem relação ao modelo tradicional, onde computadores eram comprados e dedicados à servidores, eliminando a necessidade do hardware para oferecer produtos de software: Todos os recursos necessários podem ser contratados pela nuvem, em serviços como a [AWS](https://aws.amazon.com/), [Google Cloud](https://cloud.google.com/) e [Azure](https://azure.microsoft.com/en-us/).

Um dos motivos da ascensão desse tipo de serviço foi a facilitação e popularização dos ambientes de containers. Sua praticidade e portabilidade auxilia nos ambientes em nuvem, onde temos recursos de forma personalizada para hospedar os containers.

Atualmente, a vanguarda da computação em nuvem se concentra na [Cloud Native Foundation](https://www.cncf.io/), sendo responsável pelos principais projetos e ferramentas open-source que estão entre as mais utilizadas em ambientes Cloud, como [Kubernetes](https://kubernetes.io/), [Prometheus](https://prometheus.io/) e [Envoy](https://www.envoyproxy.io/).

## Instalando o Docker

### Docker

* (**Recomendado**) Para Ubuntu, seguir **atentamente** os passos na [documentação do Docker](https://docs.docker.com/engine/install/ubuntu/)
* Após confirmar a instalação corretamente (`sudo docker run hello-world` deve retornar sem erros), adicione seu usuário ao grupo de usuário `docker`:
```sh
sudo usermod -aG docker ${USER}
su - ${USER} # necessário para recarregar os grupos do usuário. Alternativa: reiniciar ou fazer logoff
```

### DockerHub

O [DockerHub](https://hub.docker.com/) é o repositório oficial e público para as imagens docker. Para utilizar as imagens disponibilizadas não é necessário criar uma conta, que é obrigatória apenas caso você queira publicar suas próprias imagens.


## Utilizando o Docker

Abaixo alguns comandos úteis e um Dockerfile de exemplo. Consulte a [documentação oficial](https://docs.docker.com/) e anotem outros comandos e parâmetros que você achar útil. São muitos no início, é bem fácil se perder.

### Imagens pré-prontas

As tags são sempre opcionais, e o valor default é `latest`

* Listar imagens: `docker images` ou `docker image ls`
* Baixar uma imagem: `docker pull <nome_da_imagem>:<tag>`
* Rodar uma imagem: `docker run <nome_da_imagem>:<tag>`
    * No modo interativo: `docker run -ti <nome_da_imagem>:<tag>`
* Executar um comando num container: `docker exec <nome_da_imagem>:<tag> <comando>`
* Listar containers: `docker ps` ou `docker container ls`


### Dockerfile de exemplo

```dockerfile
FROM node:14
WORKDIR /opt/app

COPY ./package.json ./

COPY src/ ./src

RUN npm install

RUN useradd -u 2469 banana
USER banana

ENTRYPOINT ["npm", "start"]
```

### Docker compose

Por vezes, os sistemas podem ter mais de um container para funcionarem. Por exemplo: uma API que se conecta a um banco de dados pode ser separada em 2 containers, um para a API e outro para o BD.

O Docker compose é uma ferramenta bem útil para gerenciar múltiplos containers: com ele podemos criar containers, volumes/bind mounts e redes internas. Seu uso é comumentemente usado em ambientes de desenvolvimento devido à sua praticidade e sua configuração é feita através de um arquivo `.yaml`. Para mais detalhes, consulte a [documentação](https://docs.docker.com/compose/)

## Responsáveis
* [Renan](https://github.com/nkzren)
* [Vini]()
