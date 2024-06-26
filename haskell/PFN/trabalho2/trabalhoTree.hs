-- lines :: String → [String] -- Divide um texto em linhas
-- words :: String → [String] -- Divide uma linha em palavras

-- O objetivo deste trabalho é definir uma função que, dado um documento (arquivo .txt), gere um
-- índice de linhas em que as palavras ocorrem nesse documento, as informações (palavras e lista de
-- linhas em que ocorrem) devem ser armazenada em uma árvore binária de pesquisa declarada como:

type Doc = String
type Line = String
type Word' = String
type Index = Int

lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum"

data Erdtree a = No a (Erdtree a) (Erdtree a) | Leaf
    deriving Show

-- A impressão das palavras e índices deve ser feita percorrendo a árvore em ordem.

-- data Tree = Node Word' [Int] Tree Tree | Leaf deriving Show
-- makeIndexTree :: Doc -> Tree



-- a) Separar o documento em linhas: lines :: Doc → [Line]

-- Resolvida pela implementação da função "lines" da biblioteca padrão de Haskell.

-- b) Numerar as linhas do documento: numLines :: [Line] → [(Int,Line)]

numLines :: Doc -> [(Int, Line)]
numLines xs = numLines' 1 (lines xs)

numLines' :: Int -> [Line] -> [(Int, Line)]
numLines' _ [] = []
numLines' n (x:xs) = (n,x):numLines' (n+1) xs

isThere :: a -> [a]-> Bool
isThere y [] = False
isThere y (x:xs) = if y == x then True else isThere y xs

-- c) Associar a cada ocorrência de uma palavra do documento o número da linha em que essa
-- palavra ocorre: allNumWords :: [(Int,Line)] → [(Int,Word’)]

allNumWords :: [(Int, Line)] -> [(Int, Word')]
allNumWords ys = allNumWords' (worderize ys)

worderize :: [(Int, Line)] -> [(Int, [Line])]
worderize [] = []
worderize ((n,x):xs) = ((n,words x):worderize xs)

allNumWords' :: [(Int, [Line])] -> [(Int, Word')]
allNumWords' ((_,[]):ys) = allNumWords' ys 
allNumWords' [] = []
allNumWords' ((n,(x:xs)):ys) = (n,x):allNumWords' ((n,xs):ys)

-- d) Inserir elementos em uma lista ordenada, o elemento deve ser inserido em uma posição que
-- mantenha a lista resultante ordenada. Caso a lista já contenha o elemento não deve ocorrer a
-- inserção:
-- insOrd :: a → [a] → [a]



-- e) Inserir uma palavra e linha de ocorrência na árvore (Tree), caso a palavra já tenha sido
-- inserida apenas a linha deve ser adicionada a lista de linhas relacionadas com a palavra.
-- Deve ser usada a função definida no item anterior para essa tarefa:
-- ins :: Word’ → Int → Tree → Tree



-- f) Percorrer a lista com as duplas de palavras e linhas inserido cada uma delas na árvore:
-- mIndexTree :: [(Int,Word’)] →Tree
