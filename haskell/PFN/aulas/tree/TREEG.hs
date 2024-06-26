 -- Notas GABRIEL TWINK

data Arvore a = No a (Arvore a) (Arvore a) | Folha
    deriving Show

ins e Folha = No e Folha Folha
ins e (No x esq dir)  | e == x = No x esq dir
                      | e < x = No x (ins e esq) dir
                      | otherwise = No x esq (ins e dir)
                      
lA [] = Folha
lA (x:xs) = (ins x(lA xs))

emOrdem (No x esq dir) = emOrdem esq ++ [x] ++ emOrdem dir
