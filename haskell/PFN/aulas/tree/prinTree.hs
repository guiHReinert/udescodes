import Data.Tree hiding (Tree )

data Tree a b = Branch b (Tree a b) (Tree a b) 
              | Leaf a deriving (Eq,Ord,Show)

toDataTree (Leaf a) = Node a []
toDataTree (Branch b cs ds) = Node b [toDataTree cs, toDataTree ds]

d = Branch "1" (Branch "11" (Leaf "111") (Leaf "112")) 
               (Branch "12" (Leaf "121") (Leaf "122"))

e = toDataTree d
f = putStrLn $ drawTree e

-- insert a element into a tree
treeInsert :: (Ord e) => e -> Tree a e -> Tree a e
treeInsert x Leaf Leaf = Branch x Leaf Leaf Leaf Leaf
treeInsert x (Branch a left right) 
    | x == a = Branch x left right -- returns the same tree if the root elemente is the same as the new one
    | x < a  = Branch a (treeInsert x left) right -- insert the right element
    | x > a  = Branch a left (treeInsert x right) -- insert the left element

 -- creates a tree based on a list, from it's most external nodes to it's root element
treeList :: (Ord e) => [e] -> Tree a e
treeList [] = Leaf
treeList (x:xs) = treeInsert x (treeList xs)
