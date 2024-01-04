#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened

    """

    opened = []
    keys = [0]
    while True:
        if keys == []:
            if len(boxes) == len(opened):
                return True
            else:
                return False

        current_key = keys[0]
        keys.pop(0)

        if current_key < len(boxes):
            opened.append(current_key)
            for key in boxes[current_key]:
                if key not in opened and key not in keys:
                    keys.append(key)
        else:
            pass
