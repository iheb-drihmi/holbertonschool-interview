#!/usr/bin/python3
"""
UTF8 validator
"""


def validUTF8(data):
    """validation"""
    i = 0

    for byte in data:
        a = 1 << 7
        if i == 0:
            while byte & a:
                i += 1
                a >>= 1
            if i == 0:
                continue

            elif i == 1 or i > 4:
                return False
        else:
            if not (byte & (1 << 7) and not (byte & (1 << 6))):
                return False
        i -= 1

    return i == 0
