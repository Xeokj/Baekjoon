import sys
input = sys.stdin.readline

def searching(y, x, n):
    # arr[y][x]를 기준으로 아래로 n줄, 오른쪽으로 n줄만큼 살펴봄
    st = arr[y][x]  # 기준 색깔을 지정
    global blue     # 전역변수 blue를 사용
    global white    # 전역변수 white를 사용
    for i in range(y,y+n):
        # 아래로 n줄
        for j in range(x,x+n):
            # 오른쪽으로 n줄
            if arr[i][j] != st:
                # 다른 색이 나올 경우 4등분
                searching(y,x,int(n/2))
                searching(y,x+int(n/2),int(n/2))
                searching(y+int(n/2),x,int(n/2))
                searching(y+int(n/2),x+int(n/2),int(n/2))
                return  # 이미 본 곳을 보지 않도록 return 해준다
    if st: blue += 1
    else: white += 1

N = int(input())
arr = [0 for _ in range(N)]
for i in range(N):
    arr[i] = list(map(int, input().split()))
white = 0   # 초기값 지정
blue = 0    # 초기값 지정
searching(0, 0, N)
print(white)
print(blue)