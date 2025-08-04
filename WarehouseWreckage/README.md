# 창고 부수기 (Warehouse Wreckage)
- 간단한 창고 부수기 게임을 구현해보자
- 30발 장착
- 30발 소진 시 5초후 게임 재시작

## 투사체 발사
- keyboard event로 발사 키 지정
- player pawn 정보(위치, 방향) 가져오기
- actor(투사체) 스폰
- impulse로 발사 구현

![shootingBall](images/shootingBall.gif)

## 창고 구현
- fab에서 에셋 가져오고 사용
- 시간대 조절

![warehousePreview](images/warehousePreview.gif)

## 메쉬 충돌
- 게임 시작 시 메쉬들이 서로 팅겨져 나가는 현상 개선
- 10 DOP-Z simplified collision 사용
  
**적용 전**
  
![BeforeSimplifedCollsion](images/UnsimplifiedBarrelMeshes.gif)

**적용 후**
  
![AfterSimplifiedCollision](images/SimplifiedBarrelMeshes.gif)

## 총알 수 구현
- 기본적인 프로그래밍 개념을 블루프린트에서 구현 (branch, return, variable, etc...)

![OutOfAmmo](images/OutOfAmmo.gif)

## 게임 재시작
- 30발 소진 시 5초후 게임 재시작
- delay, open level node 사용

![GameRestart](images/GameRestart.gif)

## 문제점
- 이동하는 도중 투사체 발사 시 플레이어의 z축이 상승
