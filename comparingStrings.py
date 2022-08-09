def backspaceCompare(str1, str2):
    pointer1 = len(str1) - 1
    pointer2 = len(str2) - 1

    while( pointer1 >= 0 or pointer2 >= 0):
        i1 = getNextValid(str1, pointer1)
        i2 = getNextValid(str2, pointer2)

        if i1 < 0 and i2 < 0:
            return True
        if i1 < 0 or i2 < 0:
            return False
        if str1[i1] != str2[i2]:
            return False
        
        pointer1 = i1 - 1
        pointer2 = i2 - 1

    return True

def getNextValid(str, index):
    backspaceCount = 0
    while(index >= 0):
        if str[index] == "#":
            backspaceCount += 1
        elif backspaceCount > 0:
            backspaceCount -= 1
        else:
            break

        index -= 1
    
    return index
        
def main():
    print(backspaceCompare("xy#z", "xzz#"))
    print(backspaceCompare("xy#z", "xyz#"))
    print(backspaceCompare("xp#", "xyz##"))
    print(backspaceCompare("xywrrmp", "xywrrmu#p"))

main()