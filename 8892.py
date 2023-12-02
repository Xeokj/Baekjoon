# 8892.py
T = int(input())
while T:
    k = int(input())
    arr = list()
    for i in range(k):
        arr.append(input())
    flg = 0
    for i in range(k):
        for j in range(k):
            if i == j: continue
            org = arr[i] + arr[j]
            if org[::-1] == org:
                print(org)
                flg = 1
                break
        if flg: break
    if flg == 0:
        print(0)
    T -= 1