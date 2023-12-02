# 1302.py
N = int(input())
books = {}
for i in range(N):
    name = input()
    if name in books:
        books[name] += 1
    else:
        books[name] = 1
Max = 0
sortedb = dict(sorted(books.items()))
for i in sortedb:
    if (sortedb[i]) > Max:
        Max = sortedb[i]
        ans = i
print(ans)