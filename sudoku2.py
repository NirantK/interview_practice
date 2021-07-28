"""
https://app.codesignal.com/interview-practice/task/SKZ45AF99NpbnvgTn/description
"""

true_grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
false_grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '3', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '.', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]

def has_repeated_int(values):
    b = set()
    for element in values:
        if element in b and element != '.':
            return True
        else:
            b.add(element)
    return False

def sudoku2(grid):
    A = grid
    subgrids = []
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            subgrids.append(A[i][j:j+3] + A[i+1][j:j+3] + A[i+2][j:j+3])

    for subgrid in subgrids:
        flat = [item for sublist in subgrid for item in sublist]
        if has_repeated_int(flat):
            return False
    
    for row in A:
        if has_repeated_int(row):
            return False
    for column in zip(*reversed(A)):
        if has_repeated_int(column):
            return False
    return True

assert not sudoku2(false_grid)
assert sudoku2(true_grid)