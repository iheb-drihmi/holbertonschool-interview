#!/usr/bin/python3
"""
This script defines a function minOperations that calculates\
the sum of prime factors of a given number.
"""


def minOperations(n):
    """
    Calculate the sum of prime factors of a given number.

    Parameters:
    - n (int): The input number

    Returns:
    - int: The sum of prime factors
    """
    res = 0
    i = 2
    while i <= n:
        while n % i == 0:
            res += i
            n = n / i
        i += 1
    return res
