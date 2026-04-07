data Mordrassil a = Node a (Mordrassil a) (Mordrassil a) | Leaf
    deriving (Show, Ord, Eq)

-- creates a tree with a single node
singleton :: a -> Mordrassil a
singleton x = Node x Leaf Leaf

-- insert a element into a tree
treeInsert :: (Ord e) => e -> Mordrassil e -> Mordrassil e
treeInsert x Leaf = singleton x
treeInsert x (Node a left right) 
    | x == a = Node x left right -- returns the same tree if the root elemente is the same as the new one
    | x < a  = Node a (treeInsert x left) right -- insert the right element
    | x > a  = Node a left (treeInsert x right) -- insert the left element

 -- find a element in the tree
treeElem :: (Ord e) => e -> Mordrassil e -> Bool
treeElem x Leaf = False -- no element on an empty tree
treeElem x (Node a left right)
    | x == a = True -- found the element
    | x < a  = treeElem x left -- know it is lower than the root element
    | x > a  = treeElem x right -- know it is higher than the root element

 -- creates a tree based on a list, from it's most external nodes to it's root element
treeList :: (Ord e) => [e] -> Mordrassil e
treeList [] = Leaf
treeList (x:xs) = treeInsert x (treeList xs)

tree2List :: (Ord e) => Mordrassil e -> [e]
tree2List Leaf = []
tree2List (Node e left right) = tree2List left ++ [e] ++ tree2List right

-- return the biggest value on the tree
bigTree :: (Num e) => (Ord e) => Mordrassil e -> e
bigTree tree = bigTree' tree 0

bigTree' :: (Eq e) => (Ord e) => Mordrassil e -> e -> e
bigTree' Leaf x = x 
bigTree' (Node a left right) x
    | a <= x = bigTree' right x
    | a > x = bigTree' right a