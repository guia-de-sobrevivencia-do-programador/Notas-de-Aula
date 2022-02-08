# 7 - Metaprogramação

## Introdução

De forma geral, programar seria algo como, "criar código para resolver problemas": Estamos basicamente criando programas a partir de códigos, que são executados para realizar tarefas, solucionando esses problemas. Mas e metaprogramação?

Metaprogramação é uma técnica de programação na qual são criados programas voltados para solucionar problemas do *processo* de criar programas. São ferramentas que tem como objetivo testar, compilar e executar seu código de forma mais eficiente. Geralmente em programas pequenos não temos problemas com esse tipo de tarefa, mas conforme avançamos um sistema e aumentamos sua complexidade, elas passam a se tornar cada vez mais inviáveis de serem gerenciadas manualmente pelos programadores. Pense em metaprogramação em algo como "programas que operam em outros programas".

Atualmente, todas as linguagens mais utilizadas tem uma ou mais ferramentas desse tipo. Exemplos:
  * Java: `Maven`, `Gradle`
  * Python: `pip`, `unittest`
  * JavaScript: `npm`, `yarn`
  * `make`

## Gerenciamento de pacotes

 Um gerenciador de pacotes é um sistema que te ajuda a gerenciar as suas dependências.

 Ele fornecerá um método que baixará e instalará livrarias.
 
* Porque utilizar: 
  * Programa tem entradas (geralmente código), executa uma sequência de passos e gera uma saída.
  * Programas por vezes têm dependências
* O que é uma dependência

  Uma dependência é um pedacinho de código escrito por terceiros e que, no contexto do seu projeto, idealmente resolve um problema para você.

  Um exemplo simples seria uma livraria para plotar gráficos. Certamente, você pode até ser habilidoso o suficiente para conseguir implementar isso você mesmo, mas demoraria muito e, sinceramente, você não precisa reinventar a roda. Este é um problema que foi resolvido de novo e de novo. Portanto, você pode pegar as implementações das outras pessoas e adaptar para o seu código. Assim, essa livraria importada se torna uma dependência.

  Você até pode importar suas dependências na mão, mas aí temos vários problemas que começam a surgir:

    • E se você encontrar uma biblioteca melhor do que a que está implementada? Você precisa baixar, instalar e remover a antiga tudo por sua conta
    • E se tem um update da livraria que você está utilizando, e você quer usar? Você precisa lidar com compatibilidade e fazer uma instalação limpa da dependência na mão

   Em projetos pequenos, isto normalmente não é um problema. Porém, se você está fazendo algo grande de verdade, manter em cheque estes fatores se torna verdadeiramente desafiador.
 
* npm
  * Iniciando um projeto: `package.json`

    Utilize `npm init` para inicializar um projeto. Uma vez que você rodar o comando, um arquivo package.json será criado.

    Todo projeto de Javascript terá um package.json. Além das dependências, ele conterá outros metadados, como o nome do projeto e autor.
 
  * Como adicionar uma dependência
    Adicione dependências com `npm install <biblioteca>`. Ao escrever este comando substituindo <biblioteca> por uma dependência válida, o módulo de sua escolha será, por padrão, instalado na pasta  `./node_modules` do diretório do projeto.

  * Scripts
   Os scripts são definidos no package.json. O seu objetivo é providenciar uma maneira simples de executar tarefas repetitivas, como:

     • Executar testes
     • Iniciar o projeto localmente
     • Buildar o projeto	

	  Eles podem ser executados com `npm run <nome_do_script>`.

	  Você pode fazer scripts de mesmo nome e adicionar “pre” ou “post” no início de cada um, e eles executarão antes e depois, respectivamente, à execução do script cujo nome eles herdam. 

  * Versionamento
	Toda vez que você modificar o seu código de uma forma que ele fique aceitável, você pode mudar o número de versão, especificado no `package.json`, e publicar. Assim, se torna mais fácil procurar por versões passadas do seu código. O npm possui regras específicas direcionadas a isso.
	
	Mas antes, vamos conversar sobre "Versionamento Semântico". O conceito é simples: todas as versões possuem três números: `x.y.z`
	
	 • o X é para versões maiores do programa. Aumente-o quando você fizer mudanças drásticas que tornam o programa incompatível com sua versão anterior.
    	 • o Y é para versões menores. Aumente-o quando forem introduzidas novas funcionalidades ao código pré-existente.
     	 • o Z é para versões de patches. Aumente-o quando forem corrigidos bugs de forma retrocompatível.
	
	Esta é a convenção. Mas por que essa convenção é tão importante para o npm? No caso, é por causa de como o npm update funciona. Com números de versão que seguem essa convenção, caso outra pessoa queira instalar nossos pacotes, ela pode filtrar pelo número de versão.
	
	Um exemplo seria nosso código possuir 3 versões: `1.0.0, 1.1.0, 1.1.1`. Alguém, de fora, escreve nosso pacote no `package.json`. Porém, ele escreve a versão como `>1.0.0`. Nesse caso, isto diz para instalar qualquer versão ACIMA da 1.0.0, ou seja, as outras duas. Ou talvez ele escreva `~1.1.0`, o que significa que isso aceitaria todas as versões de patch dentro da versão menor (ou seja, aceitaria 1.1.1 mas não 1.2.0).


## Integração contínua

Conforme as aplicações crescem, os processos que envolvem gerar novas funcionalidades e versões vão ficando cada vez mais complexos, como atualizar documentações, arquivos de configuração, publicar a nova versão em algum servidor, etc. Também vimos em aulas anteriores formas de criar código colaborativamente, mas normalmente queremos que o código se mantenha uniforme em nosso projeto, checando coisas como espaçamento e indentação.

Além disso, em aplicações muito grandes fica cada vez mais difícil garantir que novas versões não alterem comportamentos que funcionavam corretamente numa versão anterior. Testes manuais nos permitem verificar que tudo está funcionando corretamente, mas testar manualmente não é algo viável em sistemas maiores. Quando começamos a perceber que os processos envolvendo novas mudanças estão começando a consumir tempo demais, podemos introduzir o conceito de **Integração contínua**.

Integração contínua (ou do inglês, *continuous integration - CI*) é um conceito bem abrangente que pode ser resumido como: processo automático que executa toda vez que os arquivos de um repositório são alterados. Existem diversas ferramentas que utilizam esse conceito para prover funcionalidades que são comuns em CIs (como por exemplo o GitHub Actions, ou até o próprio Git através dos *git hooks*). De forma geral, a maior parte dessas ferramentas funciona de forma similar: adicionamos e/ou modificamos um arquivos de configuração que determinam quais tarefas serão executadas em quais momentos, de forma a automatizar processos. Um exemplo muito comum é rodar testes automatizados toda vez que é adicionado um commit ao repositório.

## Testes

Conforme dito na seção anterior, projetos de software maiores possuem algumas necessidades adicionais para manter a saúde do sistema (e consequentemente das pessoas que o mantém). Uma dessas necessidades envolve a criação de testes automatizados para verificar que as partes do sistema ainda se comportam conforme esperado mesmo após as novas mudanças (imaginem ter que testar todas as funcionalidades do Google Meet toda vez que adicionam um fundo de tela novo?). Alguns dos conceitos mais comuns nesses tipos de teste serão listados nas subseções abaixo.

### Testes de unidade (*Unit tests*)

Testes de unidade são feitos para testar pequenas partes do código, a fim de cobrir erros menores nessas unidades, que geralmente são métodos ou funções. A ideia aqui é testar se os componentes que estão sendo desenvolvidos funcionam isoladamente conforme o esperado. Normalmente são os testes mais simples e em maior quantidade.

### Testes de integração (*Integration tests*)

Após confirmar que os componentes do seu sistema funcionam individualmente com os testes de unidade, às vezes é necessário testar como esses componentes funcionam em conjunto: essa é a finalidade dos testes de integração. Esses testes normalmente são mais complexos do que os testes de unidade, pois testam se os componentes estão se comunicando corretamente. Um caso de uso comum para esses testes são conexões com bancos de dados.

### Mocking

Para que possamos limitar o escopo dos testes, muitas vezes precisamos "simular" respostas dos outros componentes não relevantes para o nosso teste. Esse processo é chamado de mocking, onde criamos uma resposta falsa, simulando um comportamento esperado, para que possamos testar somente a parte que nos interessa no momento.

## Responsáveis
* [Renan](https://github.com/nkzren)
* [Caio](https://github.com/4n7hem)
