# 창고 부수기 (Warehouse Wreckage)
- 간단한 창고 부수기 게임을 구현해보자
- 

## 바라보는 방향으로 공 던지기 구현
![shootingBall](images/shootingBall.gif)

## 창고 구현
![warehousePreview](images/warehousePreview.gif)

## 충돌 메쉬 사용
- 10 DOP-Z simplified collision를 사용하여 게임 시작 시 메쉬들이 서로 팅겨져 나가는 현상 개선
- 적용 전
  
![BeforeSimplifedCollsion](images/UnsimplifiedBarrelMeshes.gif)\

- 적용 후
  
![AfterSimplifiedCollision](images/SimplifiedBarrelMeshes.gif)
