# 창고 부수기 (Warehouse Wreckage)
- 간단한 창고 부수기 게임을 구현해보자
- 

## 바라보는 방향으로 공 던지기 구현
- get player pawn 노드로 actor location과 control rotation 획득
  - get actor location으로 플레이어의 현재 좌표 획득
  - get control rotation으로 플레이어가 바라보는 방향 획득
- spawn actor 노드로 발사체 소환
  - 발사체 방향을 플레이어가 바라보는 방향으로 회전
  - get actor forward vector로 발사체의 방향을 impulse 노드에 전달 <br>
  +) control rotation vector를 impulse에 바로 전달해도 됨

![shootingBall](images/shootingBall.gif)

## 창고 구현
![warehousePreview](images/warehousePreview.gif)

## 충돌 메쉬 사용
- 게임 시작 시 메쉬들이 서로 팅겨져 나가는 현상 개선
- 10 DOP-Z simplified collision 사용
  
**적용 전**
  
![BeforeSimplifedCollsion](images/UnsimplifiedBarrelMeshes.gif)

**적용 후**
  
![AfterSimplifiedCollision](images/SimplifiedBarrelMeshes.gif)

# 총알 수 구현
- 기본 30발
- 전부 사용 시 발사 불가능
- 전부 사용 후 발사 시도 시 dry fire 효과음 출력

![OutOfAmmo](images/OutOfAmmo.gif)
