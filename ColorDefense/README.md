# [ Color Defense ]
- 1~7 빨주노초파남보 890 툴
- 파초노주빨 순으로 체력 여러 개인 옵젝 / 빨강으로 갈 수록 크기가 미미하게 작아짐
- 시작 메뉴판 : 설정을 다 지워야 시작 / 게임 컨셉 자연스럽게 학습
- 대쉬, 점프

## 크립 이동
<details>
<summary>NavMesh</summary>
- navigation mesh <br>
- 삼각형은 유일한 평면을 결정하기 때문에 NavMesh에서 폴리곤으로 삼각형 사용 <br>
- PlaceActors / NavMeshBoundsVolume 으로 NavMesh 자동 생성 <br>
- P로 자동생성된 NavMesh를 볼 수 있음 <br>
- NavMeshBoundsVolume 설치 시 RecastNavMesh-Default actor 자동 생성
- RecastNavMesh-Default / Details / Display / Draw Offset 으로 경사면에서의 NavMesh 생성 조절

<details>
<summary>reference</summary>
https://dev.epicgames.com/documentation/en-us/unreal-engine/basic-navigation-in-unreal-engine
</details>

</details>
