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
     // ���¸� ó�� �ؾ� �ȴ�.
    while (v.front() < K)
    {
        //-1�� ���� �ϴ� ��Ȳ
        if (v.size() == 1)
        {
            result = -1;
            break;
        }


        int value;

        //���� ù��° ���� ����, 
        pop_heap(v.begin(), v.end(), greater<int>());
        value = v.back();
        v.pop_back();

        //�� ��° ���� ����
        pop_heap(v.begin(), v.end(), greater<int>());
        int value_2 = v.back();
        v.pop_back();

        int Key = value + (value_2 * 2);
        cout << value << "\n";

        cout << value_2 << "\n";
        //key���� �ٽ� ���Ϳ� ����
        v.push_back(Key);
        push_heap(v.begin(), v.end(), greater<int>());
        //cout << "test\n" << v.front() << "\n";
        result += 1;

        //���� �迭�� ���� ������ �ȴ�.

    }

    cout << result;
}
