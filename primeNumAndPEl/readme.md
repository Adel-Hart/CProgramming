# 소수&팰린드롬
 https://www.acmicpc.net/problem/1747





 ## 펠린드롬 logic
 case1. xxxyxxx 꼴
 case2. xxxxxx 꼴

 -> 자리수 홀짝으로 구분 가능

 자리수 k

 1번째와 k번째 비교
 2번째와 k-1번째
 반복 (k//2 까지)


 제일 안쪽 수부터 비교하는게, 시간 이득
 저 위에 로직 뒤집어서 ㄱㄱ

 ### 자리수 logic?
 10으로 0 되기 전까지 나누기.

 ### 정수 분리 logic?
 10으로 나누면, 나머지는 해당 정수의 첫째자리
 그 몫을 또 10으로 나누면 둘째 자리.


## 소수확인 logic
 n-1 까지, 나눴을 때 나눠 떨어지면 ok(나머지 x 면 ok)

 ### 최적화 1
  6 -> 1, 2, 3(6/2)
  16 -> 1, 2, 4, 8(6/2)

  2이상 부터 짝수면, 무조건 x

 ### 최적화 2
  홀수라면?
  15 -> 3, 5
  33 -> 3, 11
  17^2 -> 17?

  (폐기 ㅇㅇ)

 ### 최적화 3 (구글링 인용)
   자기 자신의 절반 부터는 몫이 0이니, 절반 미만 까지만 판별
   이래도 O(N)이다.

 ### 최적화 4 (구글링 인용)
   "에라토스테네스의 체" -> 해당 알고리즘에 적합 x

 ### 최적화 5 (구글링 인용)
   N^(1/2) 까지 반복하기
   ? : 1/2까지 숫자 중에서
   인수가 있다면 나열 시 그 인수의 중간 부터
   중간 전 * 중간 후 꼴이기 때문

   ex) 80
   -> 1, 2, 4, 5, 8, 10, [16], 20, 40, 80

    [16] 값이 중간, 즉 sqrt(80) 값 전까지 하면 됨.

    -> 시간 복잡도 O(N^(1/2))


 # 로직 순서?

   펠린드롬 먼저 -> 소수 판별




 # 개선점
 + 1. 팰린드롬 판별 로직의 가독성 부족 (배열 index 때문에 -1 혹은 +1이 있어서)
 

 