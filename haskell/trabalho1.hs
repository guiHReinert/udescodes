type Doc = String
type Line = String
type Word' = String
-- makeindex::Doc -> [([Int], Word')]

numLines xs = numLines' 1 (lines xs)
numLines' _ [] = []
numLines' n (x:xs) = (n,x):numLines' (n+1) xs

isThere y [] = False
isThere y (x:xs) = if y == x then True else isThere y xs

allNumWords xs = allNumWords'(numLines xs)
allNumWords' ((n,x):xs) =

