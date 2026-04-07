

mapL :: (a->b) -> Lista a -> Lista b
mapL _ Nil = Nil
mapL f (Cons x xs) = Cons (fx) (mapL f xs)
