#include <stdio.h>
#include <math.h>
#include <iostream>
// #include <time.h>


using namespace std;


int getDigit(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;    
        count++;
    }
    return count;
}

bool isOdd(int n){
    if (n % 2 == 0) { //2로 나뉘어지면 짝수
        return false;
    }
    return true;
}

int* digitSeparate(int n){

    int digit = getDigit(n);
    int* arr = new int[digit]; //heap에 배열 할당 
    
    for(int i = 0; i < digit; i++){
        arr[digit - i - 1] = n % 10; //배열에 inverse저장이 되서 digit - i - 1로 123 -> 1, 2, 3 저장.
        n /= 10; //각 자리수 배열에 저장
        
    }

    return arr; //주소 리턴
}
 

bool isPalin(int num, int digit){ //팰린드롬s 판별 함수.
    
    int cycle = digit / 2; //자릿수의 반만큼만 비교하면 됨.

    int* digitArry = digitSeparate(num); //자릿수 별로 배열에 저장. 사용 후 delete 필요 


    if(isOdd(digit)){ //홀수 자리면? xxxyxxx 꼴 , cycle은 y전 x임!

            
        for (int i = 0; i < cycle; i++) {
            if(digitArry[cycle -1 - i] != digitArry[cycle + 1 + i]){
                delete[] digitArry; //사용 후 메모리 해제
                return false;
            }
            /*
            안쪽에서 부터 비교, 전꺼 - 1 : 인덱스 0부터 시작이라서,
            나중꺼 +1 : 홀수 자릿수라 가운데 꺼 무시 + 2에 인덱스 0부터 시작으로 -1 총 +!
            
            저 if 문이 한번이라도 false가 나오면 팰린드롬이 아님.
            그래서 return으로 for 탈출
            */
        }
        

        delete[] digitArry; //사용 후 메모리 해제

        return true;

    }

    else{ //짝수이면
        
        for (int i = 0; i < cycle; i++) {
            if(digitArry[cycle - 1 - i] != digitArry[cycle + i]){
                delete[] digitArry; //사용 후 메모리 해제
                return false;
            } //홀수는 가운데에 숫자가 없어서, 위 로직에서 뒤에꺼 +1이 없음.
    
        }
        delete[] digitArry; //사용 후 메모리 해제
        return true; 
    }
}

bool isPrime(int num){

    if(num == 1){
        return false;
    }

    for(int i = 2; i <= sqrt(num); i++){ //fix error: i < sqrt(num) -> i <= sqrt(num)

        if(num % i == 0){
            return false;
        }
    }
    return true;
}




int main(){

    // clock_t start, end, checker; //시간 측정 초기화.
    // double duration; //시간 측정 값 초기화.
    
    bool isOver = false; //종료 조건 초기화.


    int num = 0; //입력 값 초기화.
    cin >> num; //입력 받기.

    
    // start = clock(); //측정 시작.

    /**
     * 
     * num 이상 숫자에서, 펠린드롬 and 소수를 만족하는 작은 숫자 판별
     * 
     * num 순차 반복, 펠린드롬 확인 시 소수 확인 하는 logic.
     * 
     */

    while (!isOver) //fix err num++ 위치 변경, 문제조건 때문 ( n "이상" 숫자)
    {

        // // checker = clock(); //소요 시간 중간 확인.

        // if(checker - start > 2000){ //2초가 넘어가면 종료.

        //     cout << "Time Over" << endl;

        //     isOver = true;
        //     break;
        // }

         
        if(!isPalin(num, getDigit(num))){
            num++;
            continue; //펠린드롬이 아니면 다음 숫자로 넘어감.   
        }

        if(!isPrime(num)){
            num++;
            continue; //소수가 아니면 다음 숫자로 넘어감.
        }

        cout << num << endl; //펠린드롬 and 소수를 만족하는 작은 숫자 출력.
        isOver = true; //종료 조건.
        break;
    }

    // end = clock(); //시간 측정 종료.

    // cout << "Time : " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl; //소요 시간 출력.

    return 0;
}

