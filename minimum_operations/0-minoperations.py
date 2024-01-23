#!/usr/bin/python3


"""
Calculate the minimum operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations required to

    Args:
        n (int): The target number of 'H' characters.

    Return:
        int: The minimum number of operations needed.
    """
    if n <= 1:
        return 0
    
    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
