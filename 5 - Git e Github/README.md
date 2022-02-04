# 5 - Git

[PDF](Git%20e%20Github.pdf)

# Github

## Comandos GIT para interagir com repositórios remotos

### git clone

Com esse comando é possível clonar repositórios remotos na sua máquina.


- Por https
    ```
    git clone https://github.com/username/reponame.git
    ```

- Por ssh
    ```
    git clone git@github.com:username/reponame.git
    ```

### git fetch

Recupera os metadados recentes do repositório remoto. Útil para checar as mudanças antes de baixá-las de fato.

### git pull

Recupera os metadados recentes do repositório remoto e atualiza o repositório local com as mudanças.

### git push

Envia os commits do repositório local para o remoto

## Colaboração e Gerenciamento de Projetos

### Issues

*Issues* são ótimas para comunicação entre usuários e desenvolvedores, e também servem para estabelecer "próximos passos" para o desenvolvimento. Usando as *labels*, que indicam que tipo de *issue* é aquela, usuários de um software podem comunicar bugs para os desenvolvedores ou propor e requisitar funcionalidades, por exemplo.

#### Labels comuns

- **good first issue**: Geralmente usada pelos contribuidores, indica que aquela funcionalidade ou correção a ser implementada é um bom ponto de entrada para quem não está ainda acostumado a contribuir para aquele projeto.

- **bug**: Geralmente usada pelos usuários para reportar algum bug encontrado na execução do software

- **enhancement** e **feature request**: Geralmente usadas pelos usuários para sugerir que alguma funcionalidade seja implementada

As labels também podem ser usadas em pull requests


### Pull Requests

*Pull requests* são uma funcionalidade muito útil para o processo de contribuição em repositórios GIT. Com eles, é possível não só revisar e discutir as mudanças propostas nos commits inclusos em pull requests, mas também permite que contribuidores proponham mudanças adicionais e que os autores do pull request adicionem commits seguintes que implementem tais mudanças.

### Projects

*Projects* é uma seção de gerenciamento de projetos onde é possível usar um quadro no estilo kanban para acompanhar issues, pull requests e fazer outras anotações.

### Wiki

*Wiki* é uma seção no repositório onde você pode escrever uma boa documentação, quando é muito grande ou não é pertinente ao README.

## Automação e CI/CD

### Actions

A *Actions* é plataforma de CI/CD (implementação contínua / entrega contínua) do Github. Com ela, você pode criar rotinas para diferentes tipos de ação no repositório. Um exemplo seria rodar testes automatizados e fazer *linting* de código em cada pull request e (ou) fazer o deploy da aplicação em algum serviço de hospedagem.

### Github Pages

Com esse serviço, é possível hospedar um site simples automaticamente no próprio github, que é atualizado assim que novas mudanças são commitadas no repositório

## Recursos externos

- [Recursos do Github](https://github.com/features)

## Responsáveis
* [Vilela](https://github.com/lk-vila)
* [Furquim](https://github.com/FvFurquim)
