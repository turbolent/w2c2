module Main (main) where

import System.Environment (getArgs)

main :: IO ()
main = do
    putStrLn "Hello from Haskell!"
    args <- getArgs
    putStrLn ("Arguments: " ++ show args)
