{-# OPTIONS_GHC -Wno-unused-top-binds #-}

main :: IO ()
main = putStrLn "RODOU"

-- 1. Declare uma função que receba as 3 medidas dos lados de um triangulo, a função deve
-- informar se as medidas podem formar um triângulo Retornando a True em caso
-- afirmativo e False caso contrário, por exemplo:
-- ehTriangulo 10 20 30 => False
-- ehTriangulo 5 3 3 => True,
-- ehTriangulo 5 3 4 => True

-- | b - c | < a < b + c
-- | a - c | < b < a + c
-- | a - b | < c < a + b

-- abs :: Int -> Int -- Redefinindo abs por fins de prática :D
-- abs x = if x >= 0 then x else -x

ehTriangulo :: Int -> Int -> Int -> Bool
ehTriangulo a b c =
  a > abs (b - c)
    && a < b + c
    && b > abs (a - c)
    && b < a + c
    && c > abs (a - b)
    && c < a + b

-- 2. Declare uma função que receba 3 medidas válidas dos lados de um triângulo e retorne
-- se esse triângulo é equilátero, isósceles ou escaleno. O retorno deve ser uma String
-- contendo a classificação do triângulo, por exemplo:
-- tipoTriangulo 5 5 5 => "equilatero"
-- tipoTriangulo 5 3 3 => "isosceles"
-- tipoTriangulo 5 3 4 => "escaleno"

tipoTriangulo :: Int -> Int -> Int -> String
tipoTriangulo a b c
  | (a == b) && (b == c) = "equilatero"
  | (a == b) || (b == c) || (a == c) = "isosceles"
  | otherwise = "escaleno"

-- 3. Usando as funções declaradas nos exercícios anteriores defina uma função que receba
-- as 3 medidas dos lados de um triângulo e retorne se essas medidas formam um triângulo,
-- em caso afirmativo a função deve retornar o tipo do triângulo: equilátero, isósceles ou
-- escaleno, caso contrário deve retornar a string: “não eh um triangulo”.
-- triangulo 5 5 5 => "equilatero"
-- triangulo 5 3 3 => "isosceles"
-- triangulo 5 3 4 => "escaleno"
-- triangulo 15 6 5 => "nao eh um triangulo"

triangulo :: Int -> Int -> Int -> String
triangulo a b c = if ehTriangulo a b c then tipoTriangulo a b c else "nao eh um triangulo"

-- 4. Declare uma função que receba como parâmetro um inteiro n e retorne a soma dos
-- números pares entre 0 e n.
-- somaPares 5 => 4 + 2 + 0 = 6
-- somaPares 8 => 8 + 6 + 4 + 2 + 0 = 20

somaPares :: Int -> Int
somaPares 0 = 0
somaPares n = if even n then n + somaPares (n - 2) else somaPares (n - 1)

-- 5. Declare uma função que receba inteiros (m e n) e retorne a seguinte série: 20m + 21m +
-- 22m+ ... + 2nm. Por exemplo:
-- somaPot2m 6 4 => 6 + 12 + 24 + 48 + 96 = 186
-- somaPot2m 3 3 => 3 + 6 + 12 + 24 = 45

somaPot2m :: Int -> Int -> Int
somaPot2m m 0 = m
somaPot2m m n = 2 ^ n * m + somaPot2m m (n - 1)

-- 6. Declare uma função que receba um número e retorne True caso o número seja primo e
-- False caso contrário. Um número primo é um número natural maior que 1, e que possui
-- apenas dois divisores: 1 e ele mesmo. Por exemplo
-- primo 37 => True
-- primo 10 => False

semiMaiorDivisor :: Int -> Int -> Int
semiMaiorDivisor n 1 = 0
semiMaiorDivisor n d =
  if rem n (d - 1) /= 0
    then semiMaiorDivisor n (d - 1)
    else d - 1

primo :: Int -> Bool
primo n = semiMaiorDivisor n n == 1

-- 7. Uma aproximação para o valor de π pode ser obtida por meio da série:
-- 4/1 – 4/3 + 4/5 – 4/7 + 4/9 – 4/11 + ...
-- Declare uma função chamada seriePI que receba como parâmetro um inteiro n e
-- calcule o valor da série enquanto o termo for maior que 4/n. Execute os seguintes
-- testes:
-- abs (pi – seriePI 100) < 0.1
-- abs (pi – seriePI 10000) < 0.00

regressaoPI 0 0 0 = 0
regressaoPI n d p =
  if d <= n
    then
      p*(4/d) + regressaoPI n (d + 2) ((-1)*p)
    else
      regressaoPI 0 0 0

seriePI n = regressaoPI n 1 1

-- Resposta alternativa da Questão 7

-- seriePI n = pg n 1 1

-- pg 0 0 0 = 0
-- pg n d r = if n >= d
--   then
--     r * (4/d) + pg n (d + 2) (r * (-1)) 
--   else
--     pg 0 0 0
