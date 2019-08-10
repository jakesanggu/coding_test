'''
Table [  [Ti, Pi] , [] , [] ... [] ]
expectation = [ total_money1,  total_money2,  total_money3  ]
'''

table = []
expectation = []


def search(sel, choice, money):
    global table
    global expectation
    # Workable ?
    duration = table[sel][0]
    if sel + duration <= len(choice) and 0 not in choice[sel:sel + duration]:
        choice[sel:sel + duration] = [0] * duration
        money += table[sel][1]
    else:
        choice[sel] = 0
    if 1 not in choice:
        expectation.append(money)
        return

    for i in range(len(choice)):
        if choice[i] == 1:
            search(i, choice[:], money)


def solution():
    global table
    global expectation

    N = int(input())
    table = [[0, 0] for x in range(N)]

    for i in range(N):
        table[i][0], table[i][1] = map(lambda x : int(x), input().split())

    choice = [1 for x in range(N)]
    expectation = []

    for i in range(N):
        search(i, choice, 0)

    if expectation:
        return max(expectation)
    else:
        return 0


print(solution())

