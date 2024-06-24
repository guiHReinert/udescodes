
-- data Int = -2147483648 | -2147483647 | ... | -1 | 0 | 1 | 2 | ... | 2147483647

data Bool = True | False
data Point = Point Float Float
    deriving (Show)

data Shape = Circle {center :: Point, radius :: Float} |
             Rectangle {center :: Point, coordinates :: Point}
    deriving (Show)

-- deriving (Show): makes the type directly showable on output
-- deriving (Eq): makes the type constructors comparable with == or /=
-- deriving (Ord): 

surface :: Shape -> Float
surface (Circle _ r) = pi * r^2
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)
-- $: Same as (abs (x2 - x1)) * (abs (y2 - y1))

data Person = Person { firstName :: String,
                       lastName :: String,
                       age :: Int,
                       height :: Float,
                       phoneNumber :: String,
                       flavor :: String
                       } deriving (Show)

-- AULA DIA 19/06

data Semana = Dom | Seg | Ter | Qua | Qui | Sex | Sab
    deriving (Show, Eq, Ord)
data Dupla a b = Par {primeiro :: a, segundo :: b}
    deriving (Show)
