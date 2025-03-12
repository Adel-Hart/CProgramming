#include "funcSet.h"
#include "basicFuncSet.h"
#include <iostream>
#include <math.h>




bool isPalin(int num, int digit){ //팰린드롬s 판별 함수.
    
    int cycle = digit / 2; //자릿수의 반만큼만 비교하면 됨.

    int* digitArry = digitSeparate(num); //자릿수 별로 배열에 저장. 사용 후 delete 필요 


    if(isOdd(digit)){ //홀수 자리면? xxxyxxx 꼴 , cycle은 y전 x임!

            
        for (int i = 0; i < cycle; i++) {
            if(digitArry[cycle - 1 - i] != digitArry[cycle + 1 + i]){
                return false;
            }
            /*안쪽에서 부터 비교, 전꺼 - 1 : 인덱스 0부터 시작이라서,
            나중꺼 +1 : 홀수 자릿수라 가운데 꺼 무시 + 2에 인덱스 0부터 시작으로 -1 총 +!
            
            저 if 문이 한번이라도 false가 나오면 팰린드롬이 아님.
            그래서 return으로 for 탈출
            */
        }
        
        return true;

    }

    else{ //짝수이면
        
        for (int i = 0; i < cycle; i++) {
            if(digitArry[cycle - 1 - i] != digitArry[cycle + i]){
                return false;
            } //홀수는 가운데에 숫자가 없어서, 위 로직에서 뒤에꺼 +1이 없음.
    
        }

        return true; 
    }
}

bool isPrime(int num){




}