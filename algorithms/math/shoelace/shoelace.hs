import Data.Array

data Vector = Point
  { x :: Int,
    y :: Int
  }

instance Show Vector where
  show :: Vector -> String
  show (Point x y) = "X: " ++ show x ++ " Y: " ++ show y

getPoint :: Int -> Int -> Vector
getPoint = Point

points :: [Vector]
points = [getPoint 0 0, getPoint 3 8, getPoint 8 5, getPoint 12 10, getPoint 15 3]

toDouble :: Int -> Double
toDouble = fromIntegral

getX :: Vector -> Double
getX (Point x _) = toDouble x

getY :: Vector -> Double
getY (Point _ y) = toDouble y

shoeLace' :: [Vector] -> Double
shoeLace' [] = 0
shoeLace' [vector] = 0
shoeLace' (a : b : rest) =
  (getX a * getY b) - (getX b * getY a) + shoeLace' (b : rest)

shoeLace :: [Vector] -> Double
shoeLace vectors = abs (shoeLace' vectors / 2.0)

main :: IO ()
main = do
  putStrLn "Points:"
  mapM_ print points
  putStrLn ""
  putStrLn "Result:"
  print (shoeLace points)
