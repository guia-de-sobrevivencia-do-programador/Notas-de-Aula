# Resolucao esperada

## Secao 1

Resposta 1: Os arquivo poderiam ser compactados com o seguinte comando `zip -r entrega.zip ./`

Resposta 2: Os arquivo poderiam ser descompactados com o seguinte comando `unzip entrega.zip`

## Secao 2

Resposta 1: Usando o comando `cat textos/texto_1.txt textos/texto_2.txt textos/texto_3.txt` ou como visto na aula seguinte `cat textos/*`. O texto encontrado seria `textos em arquivos diferentes`

Resposta 2: O comando para mostrar strings com 20 caracteres legíveis ou mais seria `strings -n 20 ./executável`. E a string que estaria escondida dentro do arquivo binário era `----- Text0 sup3r secr3to -----`

## Secao 3

Resposta 1: Para encontrar o arquivo `anotacoes_perdidas.txt` o comando `find ./Secao_3 -name anotacoes_perdidas.txt` poderia ser utilizado.

Resposta 2: Para achar um arquivo com 100 Kb ou mais o comando `find ./ -size +100k` poderia ser utilizado

Resposta 3: Usando o comando `grep -r guia\ de\ sobrevivencia\ do\ programador -r ./Secao_3/muitos_textos` o resultado iria mostrar que o `texto_5.txt` e o `texto_2.txt` continham a string `guia de sobrevivencia do programador`

## Secao 4

Resposta 1: Usuário pode ler e escrever no arquivo

Resposta 2: Outros usuários do mesmo grupo do dono do arquivo podem escrever no arquivo

Resposta 3: Qualquer outro usuário pode ler e executar no arquivo
