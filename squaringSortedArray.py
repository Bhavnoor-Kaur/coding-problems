def makeSquares(arr):
    squares = []
    for i in arr:
        squares.append(i*i)
    
    l = 0
    r = 0

    while (r < len(squares)):
        if squares[r] < squares[l]:

    return squares