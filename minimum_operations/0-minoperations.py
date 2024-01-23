#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """
    Calculates the fewest number of operations required to
    obtain exactly n 'H' characters in the file.

    Args:
        n (int): The target number of 'H' characters.

    Returns:
        int: The minimum number of operations needed.
    """

    if n <= 1:
        return 0

    operations = 0

    while n % 2 == 0:
        operations += 2
        n //= 2

    i = 3
    while i * i <= n:
        while n % i == 0:
            operations += i
            n //= i
        i += 2

    if n > 2:
        operations += n

    return int(operations)
