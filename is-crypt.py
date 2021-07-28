def word_to_number(word, sol_dict):
    number = ''
    for idx, char in enumerate(word):
        number += sol_dict[char]
    new_num = number.lstrip('0')
    if new_num != number and len(number) > 1:
        return None
    return number

def isCryptSolution(crypt, solution):
    sol_dict = {}
    for element in solution:
        sol_dict[element[0]] = element[1]
    numbers = [word_to_number(word, sol_dict) for word in crypt]
    if None in numbers:
        return False
    numbers = [int(x) for x in numbers]
    if numbers[0] + numbers[1] == numbers[2]:
        return True
    return False



crypt = ["SEND", "MORE", "MONEY"]
solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]

assert isCryptSolution(crypt, solution)

crypt = ["TEN", "TWO", "ONE"]
solution = [['O', '1'],
            ['T', '0'],
            ['W', '9'],
            ['E', '5'],
            ['N', '4']]
assert not isCryptSolution(crypt, solution)