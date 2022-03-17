# Resolução esperada
Existem várias maneiras de se chegar ao resultado esperado, aqui vão algumas das maneiras.

## 1 - Análise de frequência com `grep` e RegEx
Possível resolução:
```grep -oE . cifra.txt | sort | uniq -c```

Ou de maneira ordenada:

```grep -oE . cifra.txt | sort | uniq -c | sort -nk1,1```

A saída do terminal é a seguinte:

```
      1 /
      1 @
      1 F
      1 U
      1 Y
      2 !
      3 "
      3 =
      3 c
      4 A
      4 O
      4 t
      5 (
      6 [
      6 z
      7 |
      7 e
      7 W
      8 P
      9 '
     10 2
     10 E
     10 T
     17 n
     30 b
```

A título de curiosidade, o arquivo cifra.txt decifrado significa _"we're just two lost souls swimming in a fish bowl year after year running over the same old ground what have we found? the same old fears wish you were here"_

## 2 - sed e RegEx
Esse exemplo aqui já precisa pensar um pouco mais para conseguir resolvê-lo por completo, e também existem vários caminhos para chegar ao mesmo resultado. Duas das resoluções enviadas são mencionadas aqui pois foram bem sucintas e claras para resolver o problema com RegEx.

É possível obter o resultado com apenas uma linha neste estilo: 

```
sed -E 's/"Mozilla.+Windows.+"$/Windows/g' ../accesslog.txt|sed -E 's/"Mozilla.+Linux.+"$/Linux/g'|sed -E 's/"Mozilla.+"$/-/g'
```

Umas das soluções enviadas que faz o mesmo processo em mais de uma linha, e sobreescrevendo o arquivo original está a seguir:
```
sed -i -E 's/" "(.+Windows.+)"/" Windows/' ../accesslog.txt
sed -i -E 's/" "(.+Linux.+)"/" Linux/' ../accesslog.txt    
sed -i -E 's/" ".+"/" -/' ../accesslog.txt 
```

## 3 - curl e APIs
O resultado varia de acordo com a API que você escolher. Muitos usaram a PokéAPI, e a única API que foi utilizada e que não foi mencionada antes é a catfact.ninja (fica como recomendação). Uma possível requisição com a PokéAPI é a seguinte:

```
curl --request GET https://pokeapi.co/api/v2/pokemon/pikachu
```
