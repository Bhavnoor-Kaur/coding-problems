def backspaceCompare(str1, str2):
    pointer1 = len(str1) - 1
    pointer2 = len(str2) - 1

    while( pointer1 >= 0 or pointer2 >= 0):
        if str1(pointer1) == "#":
            pointer1 -= 2
        if str2(pointer2) == "#":
            pointer2 -= 2
        
        if str1[pointer1] == str2[pointer2]:
            pointer1 -= 1
            pointer2 -= 1
        
        if pointer1 == 0 and pointer2 == 0:
            if str1[pointer1] == str2[pointer2]:
                return True
        return False

    return False
        