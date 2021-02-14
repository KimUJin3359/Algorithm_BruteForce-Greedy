# BruteForce-Greedy

### 반복과 재귀
- 반복과 재귀는 유사한 작업을 수행
- 반복 : 수행하는 작업이 완료될 떄까지
  - 루프(for, while 구조)
  1. 초기화 : 명령문을 실행하기 전에 (한번만) 조건 검사에 사용할 변수의 초기값 설정
  2. 조건검사
  3. 반복할 명령문 실행
  4. 업데이트
- 재귀 : 문제의 해를 구하기 위해 동일하면서 더 작은 문제의 해를 이용
  - 하나의 큰 문제를 해결할 수 있는 더 작은문제로 쪼개고 결과들을 결합
  - 재귀 함수
    - 함수 내부에서 직, 간접적으로 자기 자신을 호출하는 함수
    - 반복구조에 비해 간결하고 이해하기 쉬움
    - 함수 호출은 스택을 사용, 재귀 호출은 반복적인 스택의 사용을 의미하며 메모리 및 속도에서 성능저하가 발생
- 일반적으로, 재귀적 알고리즘은 반복 알고리즘보다 더 많은 메모리와 연산을 요함

### Brute-force(완전 검색 기법)
- 대부분의 문제에 적용이 가능
- 상대적으로 빠른 시간에 문제 해결(알고리즘 설계) 가능
- 문제에 포함된 자료(요소, 인스턴스)의 크기가 작다면 유용
- 완전 검색을 기반으로 greedy나 DP를 이용해서 효율적인 알고리즘을 찾을 수 있음

#### 순열
- 순열(Permutation)
  - 서로 다른 것들 중 몇 개를 뽑아서 한 줄로 나열하는 것
  - 순서화된 요소들의 집합에서 최선의 방법을 찾는 것과 관련
  - n개의 요소들에 대해서 n!개의 순열들이 존재
  - 최소한의 변경을 통해 순열을 생성하는 방법
    - Johnson-Trotter 알고리즘

#### 부분집합
- 집합에 포함된 원소들을 선택하는 것
- 중요 알고리즘들이 원소들의 그룹에서 최적의 부분집합을 찾는 것과 관련
- 생성 방법
  - 바이너리 카운팅
    - 부분집합을 생성하기 위한 가장 자연스러운 방법
    - 원소 수에 해당하는 N개으 ㅣ비트열을 이용
    - n번째 비트 값이 1이면 n번째 원소가 포함되었음을 의미
    
#### 조합
- 조합(Combination)
  - 서로 다른 n개의 원소 중 r개를 순서에 상관없이 골라낸 것
  
### 탐욕 알고리즘
- 최적해를 구하는데 사용되는 근시안적인 방법
- 일반적으로, 머리속에 떠오르는 생각을 검증 없이 바로 구현하면 Greedy 접근
- 각 선택 시점에서 이루어지는 결정은 **지역적으로 최적**이지만, 그 선택들을 계속 수집하여 최종적인 해답을 만들었다고 하여, **그 것이 최적이라는 보장은 없음**
- 최적화 문제 : 가능한 해들 중에서 가장 좋은 해를 찾는 문제
- 동작 과정
  1. 해 선택 : 현재 상태에서 부분 문제의 최적 해를 구한 뒤, 이를 solution set에 추가
  2. 실행 가능성 검사 : 새로운 해 집합이 실행가능한지를 확인(제약 조건 위반 여부)
  3. 해 검사 : 문제의 해가 되는지를 확인
- **탐욕 알고리즘 필수 요소**
  - 탐욕적 선택 속성(greedy choice property) : 탐욕적 선택이 항상 안전함을 보임
  - 최적 부분 구조(optimal substructure property) : 최적화 문제를 정형화(하나의 선택을 하면 풀어야 할 하나의 하위 문제가 남음)
  - 원문제의 최적해 = 탐욕적 선택 + 하위 문제의 최적해

### 탐욕 기법과 동적 계획법의 비교
  - 탐욕 기법
    - 매 단계에서 가장 좋게 보이는 것을 빠르게 선택(지역 최적 선택)
    - 하위 문제를 풀기 전에 선택이 먼저 이루어짐
    - Top-down 방식
    - 일반적으로 빠르고, 간결함
  - 동적 계획법
    - 매 단계의 선택은 해결한 하위 문제의 해를 기반
    - 하위 문제가 우선 해결
    - Bottom-up 방식
    - 좀 더 느리고, 복잡함

### 탐욕 기법의 알고리즘
- Prim
  - N개 노드에 대한 최소 신장 트리 찾기
  - 서브트리를 확장하면서 MST를 찾음
- Kruskal
  - N개 노드에 대한 최소 신장 트리 찾기
  - 싸이클이 없는 서브 그래프를 확장하면서 MST 찾기
- Dijkstra
  - 주어진 정점에서 다른 정점들에 대한 최단경로 찾기
  - 주어진 정점에서 가장 가까운 정점을 찾고, 그 다음을 정점을 반복해서 찾음
- Huffman tree&code
  - 문서의 압축을 위해 문자들의 빈도수에 따라 코드값을 부여
  - 출현 빈도가 낮은 문자부터 선택해서 이진 트리를 완성하고 코드값을 부여
  
  
### 배낭 짐싸기(Knapsack)
- 배낭은 담을 수 있는 물건의 총 무게가 정해져 있음
- 창고에는 여러개의 물건들이 있고 각각의 물건에는 무게와 값이 정해져 있음
- 배낭이 수용할 수 있는 무게를 초과하지 않으면서, 값이 최대가 되는 물건들 고르기
- 0-1 Knapsack
  - 배낭에 물건을 통째로 담아야 하는 문제
  - 물건을 쪼갤 수 없는 경우
  - 방법1
    1. 완전 검색으로 물건들의 집합 S에 대한 모든 부분집합을 구함
    2. 부분집합의 총무게가 W를 초과하는 집합들은 버리고, 나머지 집합에서 총 값이 가장 큰 집합을 선택
    3. 물건의 개수가 증가하면 시간 복잡도도 지수적으로 증가
  - 방법2(greedy)
    1. 값이 비싼 물건부터 채움
    2. 무게가 가벼운 물건부터 채움
    3. 무게당 값이 높은 순서로 물건을 채움
- Fractional Knapsack
  - 물건을 부분적으로 담는 것이 허용되는 문제
  - 물건을 쪼갤 수 있는 경우
  - 방법
    - 무게당 값이 높은 순서로 물건을 채움

### 활동 선택(Activity-selection Problem)
- 시작과 종료 시간이 있는 n개의 활동들을 1 <= i <= n에서 서로 겹치지 않는 최대갯수 활동들의 집합을 구하는문제
- 가능한 많의 회의가 열리기 위한 배정 방법
- 방법1(greedy)
  1) 공집합이 아닌 하위 문제 Si,j가 있고 Si,j에 속한 활동 am은 종료시간이 가장 빠른 활동
  2) 하위문제 Si,j에서 종료시간이 가장 빠른 활동 am을 선택
  3) si,m은 공집합이므로, am을 선택하면 공집합이 아닌 하위문제 Sm,j가 남음
  4) 2, 3 반복
  
#### 관련 문제
[1.Combination](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/CombinationIterative/CombinationIterative/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 조합의 순서쌍을 Iterative한 방식으로 찾고 출력
  
[2.Combination](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/CombinationRecursive/CombinationRecursive/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 조합의 순서쌍을 Recursive한 방식으로 찾고 출력

[3.Permutation](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/PermutationIterative/PermutationIterative/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 순열의 순서쌍을 Iterative한 방식으로 찾고 출력

[4.Permutation](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/PermutationRecursive/PermutationRecursive/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 순열의 순서쌍을 Recursive한 방식으로 찾고 출력

[5.Duplicate Permutation](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/DuplicatedPermutationIterative/DuplicatedPermutationIterative/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 중복 순열의 순서쌍을 Iterative한 방식으로 찾고 출력

[6.Duplicate Permutation](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/DuplicatedPermutationRecursive/DuplicatedPermutationRecursive/main.cpp)
- 문자 갯수, 만들 조합의 길이 및 문자를(문자 갯수만큼) 입력받아 중복 순열의 순서쌍을 Recursive한 방식으로 찾고 출력

[7.Get Max Benefit](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/MaximumBenefit/MaximumBenefit/main.cpp)
- 주어진 숫자판들 중 두 개를 선택해서 정해진 횟수만큼 서로의 자리를 위치를 교환
- 반드시 횟수만큼의 교환이 이루어져야 함
- 위 과정의 최대 결과 값 찾기
- 접근 방법
  - 비교 연산을 통해 가장 큰 max값 찾기(가장 첫 자리 수부터 뒤로 가면서 비교)
  - 지금 비교하는 수 보다 큰 값이 없다면 pass
  - 지금 자릿 수에 있는 값보다 큰 값이 뒤에 있다면 swap
  - 만약, 2, 3, 8, 8, 8를 2번 교환한다 했을 때 최대 값은 88832 => 2와 8을 교환, 3과 8을 교환 => 2와 3처럼 같은 값으로 바뀐 값이 존재한다면, 그 순서를 3, 2 순 즉 큰 순서대로 정렬
  - 횟수만큼 반복

[8.Balance Point](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/BalancePoint/BalancePoint/main.cpp)
- 무중력 공간에 n개의 자성체들이 존재
- x좌표만 존재한다고 가정
- 어떤 물체가 n개의 자성체들이 위치한 직선의 임의의 위치에 존재하면 각 자성체로부터 인력이 작용
- n개의 자성체가 주어졌을 때 n - 1개의 균형점을 찾는 문제
- 접근 방법
  - 이진 탐색
  - 좌/우의 합이 같아질 때 까지 탐색
- 주의할 점
  - 컴퓨터에서 실수의 값은 ==가 존재하기 힘듬(근사한 값을 나타내기 때문)
  - 그렇기 때문에 ==가 아닌 다른 조건을 추가하여 근사값 찾기
    - 이진 탐색에서 좌/우 값을 두었을 때 왼쪽의 힘이 오른쪽의 힘보다 크다면 left + 10 ^ -12(오차값)
    - 오른쪽의 힘이 왼쪽의 힘보다 크다면 right - 10 ^ -12
    - 그 결과 값이 left > right이면 검색 종료
    
[9.Subset Sum](https://github.com/KimUJin3359/BruteForce-Greedy/blob/master/SubsetSum/SubsetSum/main.cpp)
- 부분 집합의 합이 0이되는 부분집합 출력

    
