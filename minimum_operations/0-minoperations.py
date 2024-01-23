#!/usr/bin/python3
"""
Minimum Operations

"""


def minOperations(n):
    """
    Minimum Operations

    Args:
        n (int): _description_
    Returns:
        int: _description_
    """
    if n <= 1:
        return 0
    else:
        i = 2
        count = 0
        while i <= n:
            if n % i == 0:
                count += i
                n = n / i
            else:
                i += 1
        return count
