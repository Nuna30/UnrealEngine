# 장애물 달리기 (Obstacle Assault)
- 폴가이즈 같은 장애물 달리기 게임을 만들어보자

## 움직이는 플랫폼
- cpp Tick() 사용
- SetActorLocation, GetActorLocation에 FVector 전달
- DeltaTime으로 프레임률 차이 극복 + 플랫폼의 속력 구현

![TickPractice](images/TickPractice.gif)

## 앞뒤로 움직이는 플랫폼
- FVector::Dist, if 사용
- 시작점에서 100cm 좌우 반복 운동

![MovingBackAndForthgPlatform](images/MovingBackAndFormPlatform.gif)

## 매우 빠른 반복 운동
- 속력이 너무 빠르면 제한지점을 벗어나도 delta time 동안 많은 거리를 이동 <br>
  => 플랫폼이 예상치 못한 곳까지 이동하게 됨
- GetSafeNormal로 제한 거리 계산 <br>
  => 제한지점을 벗어나면 SetActorLocation(제한지점)

![GetSafeNormal](images/GetSafeNormal.gif)

## 캐릭터를 미는 큐브
![CollisionGlitch](images/CollisionGlitch.gif)
<br>**Collision Glitch**<br>
- 캐릭터 코드는 움직이지 않으면 collision을 확인하지 않음
- 위와 같은 현상 발생

![CharacterMoveComponent](images/CharacterMoveComponent.gif)
<br>**CharacterMovementComponent**<br>
- 캐릭터를 매 tick 마다 z += 1, z -= 1 하도록 BP_ThirdPersonCharacter 수정
- CharacterMovementComponent, MoveUpdatedComponent 사용
- 하지만 캐릭터가 정면만 바라보는 버그 발생 <br>


![GetActorRotation](images/GetActorRotation.gif)
<br>**Get Actor Rotation**<br>
- 캐릭터의 rotation도 업데이트되도록 수정
- GetActorRotation 사용 <br>

## 회전체
- FRotator, AddActorLocalRotation 사용

![Rotator](images/Rotator.gif)
