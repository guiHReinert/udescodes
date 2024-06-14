import System.IO

main = do putStr "Arquivo: "
          narq <- getLine
          txt <- readFile narq
          let palavras = words txt
          imprime palavras

--imprime :: [String] -> IO()
imprime [] = return []
imprime (p:ps) = do putStr (p ++ " ")
                    print (length p)
                    putStr "\n"
                    imprime ps
                 
