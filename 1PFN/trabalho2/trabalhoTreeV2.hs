-- lines :: String → [String] -- Divide um texto em linhas
-- words :: String → [String] -- Divide uma linha em palavras

-- O objetivo deste trabalho é definir uma função que, dado um documento (arquivo .txt), gere um
-- índice de linhas em que as palavras ocorrem nesse documento, as informações (palavras e lista de
-- linhas em que ocorrem) devem ser armazenada em uma árvore binária de pesquisa declarada como:

import Data.List (sort)
import Data.Char (toLower)

type Doc = String
type Line = String
type Word' = String
type Index = Int

-- A impressão das palavras e índices deve ser feita percorrendo a árvore em ordem.
data Tree = Node Index [Word'] Tree Tree | Leaf
    deriving Show

-- a) Separar o documento em linhas: lines :: Doc → [Line]

-- Resolvida pela implementação da função "lines" da biblioteca padrão de Haskell.

-- b) Numerar as linhas do documento: numLines :: [Line] → [(Int,Line)]

numLines :: Doc -> [(Index, Line)]
numLines xs = numLines' 1 (lines xs)

numLines' :: Index -> [Line] -> [(Index, Line)]
numLines' _ [] = []
numLines' n (x:xs) = (n,x):numLines' (n+1) xs

-- c) Associar a cada ocorrência de uma palavra do documento o número da linha em que essa
-- palavra ocorre: allNumWords :: [(Int,Line)] → [(Int,Word’)]

allNumWords :: [(Index, Line)] -> [(Index, Word')]
allNumWords ys = allNumWords' (worderize ys)

worderize :: [(Index, Line)] -> [(Index, [Line])]
worderize [] = []
worderize ((n,x):xs) = ((n,words x):worderize xs)

allNumWords' :: [(Index, [Line])] -> [(Index, Word')]
allNumWords' ((_,[]):ys) = allNumWords' ys 
allNumWords' [] = []
allNumWords' ((n,(x:xs)):ys) = (n,map toLower x):allNumWords' ((n,xs):ys)

-- d) Inserir elementos em uma lista ordenada, o elemento deve ser inserido em uma posição que
-- mantenha a lista resultante ordenada. Caso a lista já contenha o elemento não deve ocorrer a
-- inserção:

insOrd :: Word' -> [Word'] -> [Word']
insOrd x ys
    | not (isThere x ys) = insOrd' x ys
    | otherwise = ys

insOrd' :: Word' -> [Word'] -> [Word']
insOrd' x [] = [x]
insOrd' x (y:ys)
    | x < y = x:(y:ys)
    | otherwise = y:insOrd' x ys

isThere :: Word' -> [Word'] -> Bool
isThere x [] = False
isThere x (y:ys)
    | x == y = True
    | otherwise = isThere x ys

-- e) Inserir uma palavra e linha de ocorrência na árvore (Tree), caso a palavra já tenha sido
-- inserida apenas a linha deve ser adicionada a lista de linhas relacionadas com a palavra.
-- Deve ser usada a função definida no item anterior para essa tarefa:
-- ins :: Word’ → Int → Tree → Tree

inserTree :: (Index, Word') -> Tree -> Tree
inserTree (i, ws) Leaf = Node i [ws] Leaf Leaf
inserTree (i, ws) (Node it wt left right)
    | i == it = Node it (insOrd ws wt) left right
    | i < it = Node it wt (inserTree (i,ws) left) right
    | i > it = Node it wt left (inserTree (i,ws) right)

-- f) Percorrer a lista com as duplas de palavras e linhas inserido cada uma delas na árvore:
-- mIndexTree :: [(Int,Word’)] → Tree

mIndexTree :: [(Index, Word')] -> Tree
mIndexTree [] = Leaf
mIndexTree (x:xs) = (inserTree x (mIndexTree xs))

makeIndexTree :: Doc -> Tree
makeIndexTree doc = mIndexTree(allNumWords(numLines doc))

-- Texto embutido de teste
lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum"
tesTree = makeIndexTree lorem

-- Ler o arquivo e plotar a árvore
main :: IO()
main = do putStr "Arquivo: "
          file_name <- getLine
          txt <- readFile file_name
          let document = makeIndexTree txt
          print document
          ploTree document

ploTree :: Tree -> IO()
ploTree Leaf = return ()
ploTree (Node it wt left right) = do putStr (show it++": "++show wt++"\n")
                                     ploTree left
                                     ploTree right
