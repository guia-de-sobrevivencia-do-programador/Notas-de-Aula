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

O Docker gera artefatos chamados **imagens**, que são definidas por um arquivo de texto chamado `Dockerfile`. Esse arquivo contém um conjunto de instruções para criar um container (como um modelo) e servem como ponto de partida para executar as aplicações no Docker. Em suma, uma imagem contém a aplicação e todas as outras ferramentas e bibliotecas necessárias para sua execução.

### Computação em nuvem (ou Cloud Computing)

TODO:
    * O que é
    * Como as ferramentas acima contribuiram para esse tipo de ambiente

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

### Imagens pré-prontas

* Listar imagens: `docker images` ou `docker image ls`
* Baixar uma imagem: `docker pull <nome_da_imagem>:<tag>`
* Rodar uma imagem: `docker run <nome_da_imagem>:<tag>`
    * No modo interativo: `docker run -ti <nome_da_imagem>:<tag>`
* Listar containers: `docker ps` ou `docker container ls`

## Responsáveis
* [Renan](https://github.com/nkzren)
* [Vini]()
