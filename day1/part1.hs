import Data.Char (isDigit)

main :: IO ()
main = do
    content <- readFile "input.txt"
    let linesOfFiles = lines content
        sums = map sumFirstLastDigit linesOfFiles
    print $ sum sums

sumFirstLastDigit :: String -> Int
sumFirstLastDigit str = 
    let digits = filter isDigit str
        firstDigit = head digits
        lastDigit = last digits
        number = [firstDigit, lastDigit]
    in read number :: Int
