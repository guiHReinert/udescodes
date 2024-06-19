-- lines :: String → [String] -- Divide um texto em linhas
-- words :: String → [String] -- Divide uma linha em palavras

import Data.List -- sortOn
import System.IO

type Doc = String
type Line = String
type Word' = String

main = do putStr "Arquivo: "
          file_name <- getLine
          txt <- readFile file_name
          let document = makeindex txt
          plotar document

plotar :: [([Int], Word')] -> IO()
plotar [] = return ()
plotar ((ns,l):ls) = do putStr (l ++ ": ")
                        print ns
                        plotar ls

lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum"

makeindex :: Doc -> [([Int], Word')]
makeindex d = sortLs(shorten(amalgamate(allNumWords(numLines d))))

-- a) Separar o documento em linhas: lines :: Doc -> [Line]
-- resolvido pela implementação da função "lines" pela bilbioteca padrão de Haskell

-- b) Numerar as linhas do documento:

numLines :: Doc -> [(Int, Line)]
numLines xs = numLines' 1 (lines xs)

numLines' :: Int -> [Line] -> [(Int, Line)]
numLines' _ [] = []
numLines' n (x:xs) = (n,x):numLines' (n+1) xs

isThere y [] = False
isThere y (x:xs) = if y == x then True else isThere y xs

-- c) Associar a cada ocorrência de uma palavra do documento, o número da linha em que essa
-- palavra ocorre:

allNumWords :: [(Int, Line)] -> [(Int, Word')]
allNumWords ys = allNumWords' (worderize ys)

worderize :: [(Int, Line)] -> [(Int, [Line])]
worderize [] = []
worderize ((n,x):xs) = ((n,words x):worderize xs)

allNumWords' :: [(Int, [Line])] -> [(Int, Word')]
allNumWords' ((_,[]):ys) = allNumWords' ys 
allNumWords' [] = []
allNumWords' ((n,(x:xs)):ys) = (n,x):allNumWords' ((n,xs):ys)

-- e) Juntar as várias ocorrências de cada palavra, produzindo, para cada palavra, a lista dos
-- números das linhas em que a palavra ocorre:

amalgamate :: [(Int, Word')] -> [([Int], Word')]
amalgamate [] = []
amalgamate ((n,x):xs) = cleanize ((conjugate x ((n,x):xs), x): amalgamate xs) []

conjugate :: Word' -> [(Int, Word')] -> [Int]
conjugate _ [] = []
conjugate x ((n,y):ys)
    | x == y = n: conjugate x ys
    | otherwise = conjugate x ys 

cleanize :: [([Int], Word')] -> [Word'] -> [([Int], Word')]
cleanize [] _ = [] 
cleanize (((n:ns),x):xs) ws
    | not (isThere x ws) = ((n:ns),x) : cleanize xs (x:ws)
    | otherwise = cleanize xs ws

-- f) Eliminar, da lista de números de linhas em que cada palavra ocorre, as repetições de um
-- mesmo número de linha:
--shorten :: [([Int],Word')] -> [([Int],Word')]

shorten :: [([Int], Word')] -> [([Int], Word')]
shorten [] = []
shorten ((ns,x):xs) = (shorten' ns [], x) : shorten xs

shorten' :: [Int] -> [Int] -> [Int]
shorten' [] _ = []
shorten' (n:ns) ans
    | not (isThere n ns) = n : shorten' ns (n:ans)
    | otherwise = shorten' ns ans

-- d) Ordenar alfabeticamente as ocorrências de palavras no texto:
-- sortLs :: [(Int,Word')] -> [(Int,Word')]

sortLs :: [([Int], Word')] -> [([Int], Word')]
sortLs xs = sortOn snd xs

