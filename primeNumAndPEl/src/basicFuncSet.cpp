// #include "basicFuncSet.h"

// #include <iostream>

// int getDigit(int n) {
//     int count = 0;
//     while (n != 0) {
//         n /= 10;
//         count++;
//     }
//     return count;
// }

// bool isOdd(int n){
//     if (n % 2 == 0) { //2로 나뉘어지면 짝수
//         return false;
//     }
//     return true;
// }

// int* digitSeparate(int n){

//     int digit = getDigit(n);
//     int* arr = new int[digit]; //heap에 배열 할당 
    
//     for(int i = 0; i < digit; i++){
//         arr[digit - i - 1] = n % 10; //배열에 inverse저장이 되서 digit - i - 1로 123 -> 1, 2, 3 저장.
//         n /= 10; //각 자리수 배열에 저장
        
//     }

//     return arr; //주소 리턴
// }
 