import copy
import pdb
# 입력을 받는다.
N,M,K = [int(x) for x in input().split()]

#Variables
initial_yangbun =      [[0  for col in range(N)] for row in range(N)]
fresh_namu      =      [[[] for col in range(N)] for row in range(N)]

# Yangbun input
for i in range(N):
    initial_yangbun[i] = [int(x) for x in input().split()]

yangbun = [[5 for x in range(N)] for y in range(N)]

#append Namu map
for i in range(M):
    X1, Y1, Z1 = [int(x) for x in input().split()]
    fresh_namu[Y1-1][X1-1].append(Z1)

for i in range(K): #K 년

    dead_namu = [[[] for col in range(N)] for row in range(N)]

    for x in range(N):
        for y in range(N):
            fresh_namu[y][x].sort() #어린나무부터
            delist = []

            for u in range(len(fresh_namu[y][x])):
                # 봄 자신의 나이만큼 양분을 먹고 나이가 1증가한다.
                if( yangbun[y][x] - fresh_namu[y][x][u] >= 0 ):
                    yangbun[y][x] -= fresh_namu[y][x][u]
                    fresh_namu[y][x][u] += 1
                #나머지는 꽥
                else:
                    delist.append(fresh_namu[y][x][u])
                    dead_namu[y][x].append(fresh_namu[y][x][u])

            for u in delist:
                fresh_namu[y][x].remove(u)

    for  x in range(N):
        for y in range(N):
            for u in range(len(dead_namu[y][x])):
                yangbun[y][x] += int(dead_namu[y][x][u]/2)

    #가을에는 나무가 번식한다.번식하는 나무는 나이가 5의 배수여야하며,인접한 8개의 칸에 나이가 1인 나무가 생긴다.

    new_namu = [[[] for col in range(N)] for row in range(N)] #New list

    for x in range(N):
        for y in range(N):

            for u in range(len(fresh_namu[y][x])):
                if(fresh_namu[y][x][u] % 5 == 0): #5의 배수이면
                # (x+1,y)
                    if(x+1 < N):
                        new_namu[y][x+1].append(1)
                # (x+1, y+1)
                    if(x + 1 < N and y + 1 < N):
                        new_namu[y+1][x+1].append(1)
                # (x+1, y-1)
                    if(x+1 < N and y-1 >= 0):
                        new_namu[y-1][x+1].append(1)
                #(x, y+1)
                    if(y+1 < N):
                        new_namu[y+1][x].append(1)
                #(x, y-1)
                    if(y-1 >= 0):
                        new_namu[y-1][x].append(1)
                #(x-1,y)
                    if(x-1>= 0):
                        new_namu[y][x-1].append(1)
                #(x-1,y+1)
                    if(x-1 >= 0 and y+1 <N):
                        new_namu[y+1][x-1].append(1)
                #(x-1,y-1)
                    if(x-1 >= 0 and y-1 >=0):
                        new_namu[y-1][x-1].append(1)

    for x in range(N):
        for y in range(N):
            fresh_namu[y][x] += new_namu[y][x]

    # 겨울에는 양분이 추가된다.
    for x in range(N):
        for y in range(N):
            yangbun[y][x] += initial_yangbun[y][x]

    #살아있는 나무수?


l = 0
for x in range(N):
    for y in range(N):
        #pdb.set_trace()
        l += len(fresh_namu[y][x])


print(l)
