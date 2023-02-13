insert' :: Ord a => a -> [a] -> [a]
insert' e [] = [e]
insert' e xs@(x : xs') =
  case compare e x of
    GT -> x : insert' e xs'
    _ -> e : xs

insertionSort :: Ord a => [a] -> [a]
insertionSort = foldr insert' []

myList :: [Integer]
myList = [9, 5, 6, 3, 1, 8, 4, 7, 2]

main :: IO ()
main = do
  putStrLn "Input:"
  print myList
  putStrLn ""
  putStrLn "Output:"
  print (insertionSort myList)