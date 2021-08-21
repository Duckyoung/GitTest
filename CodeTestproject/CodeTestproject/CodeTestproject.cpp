// CodeTestproject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    vector<int> v = { 1, 1};
    int K = 7;
    int result = 0;

    make_heap(v.begin(), v.end(), greater<int>());//max
   
    cout<< "test"<<endl;
   
   // cout << "test\n" << v.front() << "\n";
    // 형태를 처리 해야 된다.
    while (v.front() < K)
    {
        //-1를 리턴 하는 상황
        if (v.size() == 1)
        {
            result = -1;
            break;
        }
          

        int value;

        //가장 첫번째 값을 저장, 
        pop_heap(v.begin(), v.end(), greater<int>());
        value = v.back();
        v.pop_back();

        //두 번째 값을 저장
        pop_heap(v.begin(), v.end(), greater<int>());
        int value_2 = v.back();
        v.pop_back();

        int Key = value + (value_2 * 2);
        cout << value << "\n";

        cout << value_2 << "\n";
        //key값은 다시 벡터에 저장
        v.push_back(Key);
        push_heap(v.begin(), v.end(), greater<int>());
        //cout << "test\n" << v.front() << "\n";
        result += 1;
       
        //실제 배열의 값을 꺼내야 된다.

    }
    
    cout  << result ;
    
}

//heap
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
