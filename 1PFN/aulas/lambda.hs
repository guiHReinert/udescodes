--escrever λ: shift + ctrl + u -> 03bb -> enter

inc = (1+)

inc1 = (>10)

v = \a b -> a
f = \a b -> b

map' f [] = []
map' f (x:xs) = f x:(map' f xs)

foo [] = []
foo (f:fs) = f 1:(foo fs)

filter' p [] = []
filter' p (x:xs) = if p x then (x:(filter' p xs)) else filter' p xs

somatorio [] = 0
somatorio (x:xs) = x + somatorio xs

produtorio [] = 1
produtorio (x:xs) = x*produtorio xs

fold' f e [] = e
fold' f e (x:xs) = f x (fold' f e xs)

filter'' p xs = [x|x <- xs, p x]

fat' n = foldr (*) 1 [1..n]

todosv (x:xs) = foldr (&&) True (x:xs)

pares (x:xs) = foldr (&&) True (map (\x -> rem x 2 == 0) (x:xs))
