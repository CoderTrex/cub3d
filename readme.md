문제점

1. 해당 map 유효성 탐색중에 아래의 지도와 같이 아래가 뚫려있는 경우 확인이 안됨
예시)
111111111
100000001
100001101
111111

2. 색 가져올 때 isdigital 함수가 정상적으로 작동하지 않음

3. 2차원 문자배열에 마지막 값인 null에 접근하면 segfault가 뜬다.

------------------------------------------------------

## 08.18

Makefile 수정함: mlx/Makefile도 fclean 추가하기

free_all() 함수 만들 것

64byte leak은 어디서 나는 건지 모르겠음..

img.ceil && img.floor 안쓰임 > 삭제