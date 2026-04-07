main = do putStr "Arquivo: "
          narq <- getLine
          txt <- readFile narq
          let tam = length txt
          putStr (show (tam-1) ++ "\n")


                 

