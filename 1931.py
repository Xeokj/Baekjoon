import sys
input = sys.stdin.readline

N = int(input())
ans = 1 # 최소 하나 이상의 회의는 할 수 있으므로
conf = [0 for _ in range(N)]    # for _ in range(): 변수 없이 반복문 실행
# 끝나는 시간을 기준으로 오름차순 정렬하고, 끝나는 시간이 같으면 시작되는 시간을 기준으로 오름차순 정렬
for i in range(N):
    conf[i] = list(map(int, input().split()))
# 정렬
conf.sort(key=lambda x: (x[1], x[0]))
# 기준 시간(회의가 끝나는 시간)을 잡는다
end = conf[0][1]
for i in range(1, N):
    # 회의가 시작되는 시간이 기준 시간 이후일 때만 회의 진행 가능하므로
    if conf[i][0] >= end:
        end = conf[i][1]    # 기준 시간 재설정
        ans += 1    # 회의가 하나 끝났으므로 1 증가
print(ans)