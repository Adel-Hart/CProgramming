#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

#include "basicFuncSet.h"
#include "funcSet.h"


using namespace std;

int main(){

    clock_t start, end, checker; //시간 측정 초기화.
    double duration; //시간 측정 값 초기화.
    
    bool isOver = false; //종료 조건 초기화.


    int num = 0; //입력 값 초기화.
    cin >> num; //입력 받기.

    
    start = clock(); //측정 시작.

    /**
     * 
     * num 이상 숫자에서, 펠린드롬 and 소수를 만족하는 작은 숫자 판별
     * 
     * num 순차 반복, 펠린드롬 확인 시 소수 확인 하는 logic.
     * 
     */

    while (!isOver) 
    {
        /**
         * fix err 

           1. main의 num++ 위치 변경, 문제조건 때문 ( n "이상" 숫자)
         */

        checker = clock(); //소요 시간 중간 확인.

        if(checker - start > 2000){ //2초가 넘어가면 종료.

            cout << "Time Over" << endl;

            isOver = true;
            break;
        }

         
        if(!isPalin(num, getDigit(num))){
            num++;
            continue; //펠린드롬이 아니면 다음 숫자로 넘어감.   
        }

        if(!isPrime(num)){
            num++;
            continue; //소수가 아니면 다음 숫자로 넘어감.
        }

        cout << num << endl; //펠린드롬 and 소수를 만족하는 작은 숫자 출력.
        break;
    }

    end = clock(); //시간 측정 종료.

    cout << "Time : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl; //소요 시간 출력.

    return 0;
}

