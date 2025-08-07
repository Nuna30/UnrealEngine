# 장애물 달리기 (Obstacle Assault)
- 폴가이즈 같은 장애물 달리기 게임을 만들어보자

## 움직이는 플랫폼
- cpp Tick() 사용
- SetActorLocation에 매 틱마다 +=1 되는 FVector 전달
- DeltaTime으로 프레임률 차이 극복

![TickPractice](images/TickPractice.gif)
