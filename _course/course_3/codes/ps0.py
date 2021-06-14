"""
Write a program that does the following in order:
    1.Ask the user to enter a number "x"
    2.Ask the user to enter a number "y"
    3.Prints out number "x", raised to the power "y"
    4.Prints out the log (base 2) of "x"
"""
from math import log

if __name__ == "__main__":

    # asking the user to enter a number x
    x = int(input("Input number X: "))
    y = int(input("Input number Y: "))

    print(f"x^y = {x**y}\n")
    print(f"log(x) = {log(x)}\n")
