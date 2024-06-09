-- lines :: String → [String] -- Divide um texto em linhas
-- words :: String → [String] -- Divide uma linha em palavras

type Doc = String
type Line = String
type Word' = String
-- makeindex::Doc -> [([Int], Word')]

docTeste = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

-- a) Separar o documento em linhas: lines :: Doc -> [Line]
-- resolvido pela implementação da função "lines" pela bilbioteca padrão de Haskell

-- b) Numerar as linhas do documento:
-- numLines :: [Line] -> [(Int,Line)]
numLines xs = numLines' 1 (lines xs)

numLines' :: Int -> [Line] -> [(Int, Line)]
numLines' _ [] = []
numLines' n (x:xs) = (n,x):numLines' (n+1) xs

isThere y [] = False
isThere y (x:xs) = if y == x then True else isThere y xs

-- c) Associar a cada ocorrência de uma palavra do documento, o número da linha em que essa
-- palavra ocorre:

allNumWords :: [(Int, Line)] -> [(Int, Word')]
allNumWords ys = allNumWords' (worderizer ys)

worderizer :: [(Int, Line)] -> [(Int, [Line])]
worderizer [] = []
worderizer ((n,x):xs) = ((n,words x):worderizer xs)

allNumWords' :: [(Int, [Line])] -> [(Int, Word')]
allNumWords' ((_,[]):ys) = allNumWords' ys 
allNumWords' [] = []
allNumWords' ((n,(x:xs)):ys) = (n,x):allNumWords' ((n,xs):ys)

-- d) Ordenar alfabeticamente as ocorrências de palavras no texto:
-- sortLs :: [(Int,Word')] -> [(Int,Word')]

-- sortLs ((n,x):xs) = 

-- e) Juntar as várias ocorrências de cada palavra, produzindo, para cada palavra, a lista dos
-- números das linhas em que a palavra ocorre:
-- almalgamate :: [(Int,Word')] -> [([Int],Word')]



-- f) Eliminar, da lista de números de linhas em que cada palavra ocorre, as repetições de um
-- mesmo número de linha:
--shorten :: [([Int],Word')] -> [([Int],Word')]


