bubbleUp :: Ord a => [a] -> [a]
bubbleUp [] = []
bubbleUp [x] = [x]
bubbleUp (x : y : xs)
  | x > y = y : bubbleUp (x : xs)
  | otherwise = x : bubbleUp (y : xs)

bubbleSort :: Ord a => [a] -> [a]
bubbleSort list = foldl (\acc _ -> bubbleUp acc) list [0 .. length list]

myList :: [Integer]
myList = [9, 5, 6, 3, 1, 8, 4, 7, 2]

main :: IO ()
main = do
  putStrLn "Input:"
  print myList
  putStrLn ""
  putStrLn "Output:"
  print (bubbleSort myList)