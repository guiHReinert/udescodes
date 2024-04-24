--1. Declare uma função que verifica se um elemento pertente a uma lista, a função deve retornar
--a True se o elemento estiver na lista e False caso contrário.

--Exemplo: pertence 3 [1, 4, 3, 2] => True

pertence y [] = False
pertence y (x:xs) = if y == x then True else pertence y xs

intercessao [] _ = []
intercessao (x:xs) ys = if pertence x ys then x:intercessao xs ys else intercessao xs ys

concatenar [] ys = ys
concatenar (x:xs) ys = x:concatenar xs ys

igual [] [] = True
igual [] _ = False
igual _ [] = False
igual (x:xs) (y:ys) = x == y && igual xs ys

inverso [] = []
inverso (x:xs) = inverso xs ++ [x]

--4. Declare uma função que retorne os n últimos elementos de uma lista.
--Exemplo: nUltimos 3 [1, 2, 3, 4, 5, 6] => [4, 5, 6]

nUltimos _ [] = []
nUltimos n (x:xs) = if length (x:xs) == n then (x:xs) else nUltimos n xs

--5. Declare uma função que receba duas listas de números e crie uma lista com a soma do
--primeiro elemento da primeira lista com o primeiro elemento da segunda lista, a soma do
--segundo elemento da primeira lista com o segundo elemento da segunda lista e assim
--sucessivamente até que uma das listas termine.
--Exemplo: soma2 [1, 2, 3, 4] [10, 20, 30] => [11, 22, 33].

soma2 _ [] = []
soma2 [] _ = []
soma2 (x:xs) (y:ys) = (x+y):soma2 xs ys

--6. Declare uma função que receba como parâmetro um número n e retorne uma lista com todas
--as potências de 2 até 2n.
--Exemplo: pot2 4 => [2, 4, 8, 16]

potLista n count = if count <= n then (2^count):potLista n (count+1) else []
pot2 n = potLista n 1

--7. Declare uma função que receba duas listas previamente ordenadas e faça a intercalação
--(merge) dos elementos tendo como resultado a junção das duas listas em uma lista também
--ordenada.
--Exemplo: intercalacao [10, 15, 17, 20] [1, 2, 13, 15, 22] => [1, 2, 10, 13, 15, 15, 17, 20, 22]

intercalacao [] ys = ys 
intercalacao xs [] = xs
intercalacao (x:xs) (y:ys) = if x <= y then x:intercalacao xs (y:ys) else y:intercalacao (x:xs) ys 

--8. Declare uma função que retorne o menor valor de uma lista.
--Exemplo: menor [10, 4, 5, 3, 12] => 3

menor [g] = g
menor (g:gs) = if g < menor gs then g else menor gs

--9. Declare uma função que receba uma lista e um elemento e retorne a lista sem a primeira
--ocorrência desse elemento.
--Exemplo: removerElem 1 [2, 4, 1, 3, 2, 1] => [2, 4, 3, 2, 1]

removerElem n (x:xs) = if x /= n then x:removerElem n xs else xs

--10. Usando as declarações anteriores, declare uma função que ordene os elementos de uma lista.
---Exemplo: ordenar [32, 10, 23, 10, 12, 4] => [4, 10, 10, 12, 23, 32]

ordenar [] = []
ordenar (x:xs) = menor (x:xs):ordenar (removerElem (menor (x:xs)) (x:xs))

--11. Declare uma função que receba um elemento e uma lista ordenada. Insira este elemento na
--lista colocando-o na posição correta, ou seja, a lista resultante deve estar ordenada. Se o
--elemento já pertencer à lista, ele não deve ser incluído.
--Exemplo: ins 12 [6, 9, 10, 15, 20] => [6, 9, 10, 12, 15, 20]

ins n (x:xs) = if pertence n (x:xs) then (x:xs) else ordenar (n:(x:xs))

--12. Declare uma função que receba um número n e uma lista e retorne o n-ésimo elemento da
--lista.
--Exemplo: enesimo 3 [10, 20, 30, 40, 50] => 30

enesimo n (y:ys) = enesimo' n (y:ys) 0
enesimo' n (y:ys) l = if l < (n-1) then enesimo' n ys (l+1) else (y:ys)

--13. Declare uma função que receba um inteiro n e um elemento e e crie uma lista com n
--elementos e.
--Exemplo: repetir 4 10 => [10, 10, 10, 10]

repetir n e = repetir' n e 0
repetir' n e l = if l < n then e:(repetir' n e (l + 1)) else []

--14. Declare uma função que converta um inteiro em um número inteiro em uma String.
--Exemplo: numString 126 => “126”

numString num = inverso (int2char (int2list num))

int2list 0 = []
int2list num = mod num 10 : int2list(div num 10)

int2char [] = []
int2char (x:xs) = [toEnum (x+48)::Char] ++ int2char xs

--15. Declare uma função que converta uma String contendo uma sequência de dígitos para um
--inteiro.
--Exemplo: stringNum “102” => 102

c2d c = fromEnum c - 48
stringNum cs = stringNum' (inverso cs)
stringNum' [] = 0
stringNum' (c:cs) = c2d c + 10 * stringNum' cs

--16. Declare uma função que converta um número binário, representado por uma string, em um
--inteiro.
--Exemplo: bin2int “1110” => 14

bin2int bin = bin2int' (inverso bin) 0
bin2int' [] _ = 0
bin2int' (b:bs) pot = if b == '1' then 2^pot + bin2int' bs (pot + 1) else bin2int' bs (pot + 1)

--17. Declare uma função que converta um número inteiro em binário.
--Exemplo: int2bin: 14 => “1110”



--18. Declare uma função que receba uma String e converta todas letras maiúsculas dessa String
--em letras minúsculas.
--Exemplo: minusculas “AbCdeF” => “abcdef”

minusculas str = minus str

minus [] = []
minus (t:ts) = (c2d t + 32 + '0'):(minus ts)
