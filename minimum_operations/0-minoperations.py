#!/usr/bin/python3


"""
Calculates the minimum operations
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to reach exactly n H characters.

    Args:
    - n (int): Target number of H characters.

    Returns:
    - int: The fewest number of operations needed.
           If n is impossible to achieve, returns 0.
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
