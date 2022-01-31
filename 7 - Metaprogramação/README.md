# 7 - Metaprogramação

## Introdução

De forma geral, programar seria algo como, "criar código para resolver problemas": Estamos basicamente criando programas a partir de códigos, que são executados para realizar tarefas, solucionando esses problemas. Mas e metaprogramação?

Metaprogramação é um conjunto de programas voltados para solucionar problemas do *processo* de criar programas. São ferramentas que tem como objetivo testar, compilar e executar seu código de forma mais eficiente. Geralmente em programas pequenos não temos problemas com esse tipo de tarefa, mas conforme avançamos um sistema e aumentamos sua complexidade, elas passam a se tornar cada vez mais inviáveis de serem gerenciadas manualmente pelos programadores. Pense em metaprogramação em algo como "programas que operam em outros programas".

Atualmente, todas as linguagens mais utilizadas tem uma ou mais ferramentas desse tipo. Exemplos:
  * Java: `Maven`, `Gradle`
  * Python: `pip`, `unittest`
  * JavaScript: `npm`, `yarn`
  * `make`

## Gerenciamento de pacotes

 Um gerenciador de pacotes é um sistema que te ajuda a gerenciar as suas dependências.

 Ele fornecerá um método que baixará e instalará livrarias.
 
* Porque utilizar: 
  * Programa tem entradas (geralmente código), executa uma sequencia de passos e gera uma saída.
  * Programas por vezes têm dependências
* O que é uma dependência

  Uma dependência é um pedacinho de código escrito por terceiros e que, no contexto do seu projeto, idealmente resolve um problema para você.

  Um exemplo simples seria uma livraria para plotar gráficos. Certamente, você pode até ser habilidoso o suficiente para conseguir implementar isso você mesmo, mas demoraria muito e, sinceramente, você não precisa reinventar a roda. Este é um problema que foi resolvido de novo e de novo. Portanto, você pode pegar as implementações das outras pessoas e adaptar para o seu código. Assim, essa livraria importada se torna uma dependência.

  Você até pode importar suas dependências na mão, mas aí temos vários problemas que começam a surgir:

    • E se você encontrar uma livraria melhor do que a que está implementada? Você precisa baixar, instalar e remover a antiga tudo por sua conta
    • E se tem um update da livraria que você está utilizando, e você quer usar? Você precisa lidar com compatibilidade e fazer uma instalação limpa da dependência na mão

   Em projetos pequenos, isto normalmente não é um problema. Porém, se você está fazendo algo grande de verdade, manter em cheque estes fatores se torna verdadeiramente desafiador.
 
* npm
  * Iniciando um projeto: `package.json`

    Utilize npm init para inicializar um projeto. 	Uma vez que você rodar o comando, um arquivo package.json será criado.

    Todo projeto de Javascript terá um package.json. Ele conterá não somente as dependências como outros metadados, como o nome do projeto e autor.
 
  * Como adicionar uma dependência
    Adicione dependências com npm install <livraria>. Ao escrever este comando substituindo <livraria> por uma dependência válida, o módulo de sua escolha será, por padrão, instalado na pasta  /node_modules do diretório do projeto.

  * Scripts
   Os scripts são definidos no package.json. O seu objetivo é providenciar uma maneira simples de executar tarefas repetitivas, como:

     • Executar testes
     • Iniciar o projeto localmente
     • Buildar o projeto	

	  Eles podem ser executados com npm run <nome_do_script>.

	  Você pode fazer scripts de mesmo nome e adicionar “pre” ou “post” no início de cada um, e eles executarão antes e depois, respectivamente, à execução do script cujo nome eles herdam. 

  * Versionamento
	Toda vez que você modificar o seu código de uma forma que ele fique aceitável, você pode mudar o número de versão, especificado no `package.json`, e publicar. Assim, se torna mais fácil procurar por versões passadas do seu código. O npm possui regras específicas direcionadas a isso.
	
	Mas antes, vamos conversar sobre Versionamento Semantico. O conceito é simples: Todas as versões possuem três números: `x.y.z`
	
	 • o X é para versões maiores do programa. Aumente-o quando você fizer mudanças drásticas que tornam o programa incompatível com sua versão anterior.
    	 • o Y é para versões menores. Aumente-o quando forem introduzidas novas funcionalidades ao código pré-existente.
     	 • o Z é para versões de patches. Aumente-o quando forem corrigidos bugs de forma retrocompatível.
	
	Esta é a convenção. Mas por que é tão importante para o npm? No caso, é por causa de como o npm update funciona. Com versões nesses padrões, caso outra pessoa queira instalar nossos pacotes, ela pode filtrar pelo número de versão.
	
	Um exemplo seria nosso código possuir 3 versões: `1.0.0, 1.1.0, 1.1.1`. Alguém, de fora, escreve nosso pacote no `package.json`. Porém, ele escreve a versão como `>1.0.0`. Nesse caso, isto diz para instalar qualquer versão ACIMA da 1.0.0, ou seja, as outras duas. Ou talvez ele escreva `~1.1.0`, o que significa que isso aceitaria todas as versões de patch dentro da versão menor (ou seja, aceitaria 1.1.1 mas não 1.2.0).


## Integração contínua
* O que é: gerenciamento do ciclo de vida da aplicação e automatização dos processos de publicação
* Conforme as aplicações crescem, os processos que envolvem gerar uma nova versão vão ficando cada vez mais complexos
* Integração contínua em suma: processo automático que executa toda vez que o código é alterado

## Testes
* Conceitos
* Testes de unidade
* Testes de integração

## Responsáveis
* [Renan](https://github.com/nkzren)
* [Caio](https://github.com/4n7hem)
