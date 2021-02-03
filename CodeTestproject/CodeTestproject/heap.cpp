#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void heapTest()
{
    std::cout << "Hello World!\n";
    vector<int> v = { 1, 1 };
    int K = 7;
    int result = 0;

    make_heap(v.begin(), v.end(), greater<int>());//max



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

    cout << result;
}
