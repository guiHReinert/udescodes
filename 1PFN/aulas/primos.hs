primos = primos' [2..]
primos' (x:xs) = x:primos' (filter (nmultiplos x) xs)
nmultiplos n x = rem x n /= 0

