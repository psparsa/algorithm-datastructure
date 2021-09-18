factorial :: (Integral n) => n -> n
factorial n = product [1..n]

main :: IO ()
main = do 
    putStr "factorial 10 = "
    print (factorial 10)
