230504 부터 기록 시작

[230504]
1158.c 요세푸스 문제



[git 파일 덮어쓰기]
1. git fetch --all
2. git reset --hard origin/master


[[git push 하는 방법]]
//저장소 생성 및 연결
$ git init
$ git remote add origin [원격저장소 주소]
$ git branch -m master main // master branch를 main으로 이름 변경


[파일 업로드]
$ git pull (또는 git pull origin [브랜치 이름])
$ git add .
$ git commit -m "commit message"
$ git push (또는 git push origin [브랜치 이름])


[추가적인 명령어]
// 연결된 원격 저장소 확인
git remote -v

// 기존 원격 저장소와의 연결 삭제
git remote rm origin

// branch 이름 확인
git branch

// 브랜치 기본(default)이름 설정
// 저장소 만들때마다 브랜치 이름 변경하기 귀찮아서 하는 것
// [브랜치 이름]을 main으로하면 git init 할 때마다 branch 이름이 main으로 됨
git config --global init.defaultBranch [브랜치 이름]

// 현재 branch 이름 확인
git status

// add한 파일 모두 취소
git rm --cached -r .


