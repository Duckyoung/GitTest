#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

//학생 데이터
class Student
{
	
public:
	pair<int, int> student;
	bool vaccinated;

	Student(int first, int second, bool _vaccinated)
	{
		student = make_pair(first, second);
		vaccinated = _vaccinated;
	}
	bool operator== (Student&_student)
	{
		if (student == _student.student)
			return true;
		return false;
	}
	bool operator<(Student& _student)
	{
		if (student < _student.student)
			return true;
		return false;
	}
	bool operator>(Student& _student)
	{
		if (student > _student.student)
			return true;
		return false;
	}

};

class Binary_search
{
	

	bool binary_search(Student _student ,vector<Student>& S)
	{
		auto first = S.begin();
		auto end = S.end();

		while (true)
		{
			auto dis = distance(first, end);
			auto midindex = first + floor(dis / 2);
			auto midelement = *midindex;

			if (_student == midelement)
			{
				if (!midelement.vaccinated)
					return true;
				return false;
			}
				
			else if (_student < midelement)//2, 4
			{
				
				end = midindex;
			}
			else if (_student > midelement)
			{
				first = midindex;
			}

			if (dis == 1)//1개 일때는 이미 모든 검사 후 
				return true;
		}
	}
	
	bool linerar_search(int N, vector<int>& S)
	{
		for (auto i : S)
		{
			if (i == N)
				return true;
		}
		return false;
	}
	bool binary_search(int N, vector<int>& S)
	{
		auto first = S.begin();
		auto last = S.end();//값이 맞느건지 모르겠다. 주소 값이 나와야 하는거 아닌가?

		while (true)
		{
			
				//중간 원소 저장
				auto range_length = std::distance(first, last);
				if (range_length == 0)
					cout << "code error" << endl;
				auto mid_element_index = first + floor(range_length / 2);//중간 Index
				auto mid_element = *(mid_element_index); //중간 벨류 값
				

				if (mid_element == N)
					return true;
				else if (mid_element > N)
				{
					//--mid_element_index;//에러 부분.
					//advance(last, 5);//문제 지점
					last = mid_element_index;
					//advance(last, mid_element_index);//문제 지점
				}

				if (mid_element < N)
					first = mid_element_index;
					//advance(first, mid_element_index);



				if (range_length == 1)
					return false;
			

		}
	}
public:
	void Student_main()
	{
		vector<Student> data;
		int size = 10;

		for (int i = 0; i < size; i++)
		{
			Student test(i, i, false);
			data.push_back(test);
		}

		Student test(7, 9, false);
		data.push_back(test);
		sort(data.begin(), data.end());//처음 할때는 동작 안했는데 오퍼레이터 추가 시 정상 동작 합니다.


		if (binary_search(test, data))
			cout << "접종 해야됩니다." << endl;
		else
			cout << "접종 했음" << endl;

	}
	void run_small_search_test()
	{
		auto N = 2;
		vector<int> S{ 1,3,2,4,5,7,9,8,6};
		sort(S.begin(), S.end());

		if (linerar_search(N, S))
			cout << "선형 검색으로 원소를 찾았습니다." << endl;
		else
			cout << "선형 검색으로 원소를 찾지 못했습니다." << endl;

		if(binary_search(N,S))
			cout << "이진 검색으로 원소를 찾았습니다." << endl;
		else
			cout << "이진 검색으로 원소를 찾지 못했습니다." << endl;
	}
	void run_large_search_test(int size, int N)
	{
		vector<int> S;
		random_device rd;
		mt19937 rand(rd());

		//1, size 정수 난수 밥ㄹ생
		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);

		//int 형 난수 추가
		for (auto i = 0; i < size; i++)
		{
			S.push_back(unifrom_dist(rand));
		}

		sort(S.begin(), S.end());
		//검색 시간 측정 시작
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		bool search_result = binary_search(N, S);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "이진 검색 수행 시간 : " << diff.count() << endl;

		if (search_result)
			cout << "원소를 찾았습니다." << endl;
		else
			cout << "원소를 찾지 못했습니다." << endl;

		 begin = chrono::steady_clock::now();
		search_result = linerar_search(N, S);
		 end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "선형 검색 수행 시간 : " << diff.count() << endl;

		if (search_result)
			cout << "원소를 찾았습니다." << endl;
		else
			cout << "원소를 찾지 못했습니다." << endl;

		cout << "\n" << endl;
	}

	void main()
	{
		run_small_search_test();

		run_large_search_test(10000, 36543);
		run_large_search_test(100000, 36543);
		run_large_search_test(1000000, 36543);
	}
};

