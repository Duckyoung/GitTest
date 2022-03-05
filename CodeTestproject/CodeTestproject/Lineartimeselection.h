#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

class Lineartimeselection
{
	template<typename T>
	auto partition(typename vector<T>::iterator begin,
		typename vector<T>::iterator end)
	{
		//세개의 반복자를 생성
		//피벗, 시작, 끝

		auto pivot_val = *begin;
		auto left_iter = begin + 1;
		auto right_iter = end;

		while (true)
		{
			//벡터의 첫 번째 원소부터 시작 해서 피벗보도 큰 원소를 찾는다.
			while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
				left_iter++;
			//벡터의 마지막 원소로 부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
			while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
				right_iter--;

			//만약 left_iter와 right_iter가 같다면 교환할 원소가 없음을 의미 합니다.
			//그렇지 않으면 left_iter 와 right_iter가 가르키는 원소를 서로 교환 합니다.

			if (left_iter == right_iter)
				break;
			else
				iter_swap(left_iter, right_iter);
		}
		//가장 큰 값이 피벗 값으로 지정되서 자기 위치에 맞게 스왑 
		//왜 피벗보다 큰 오른쪽 반복자를 찾아서 바꿔주는지 잘모르겠다.
		//의심 되는 부분은 
		if (pivot_val > *right_iter)
			iter_swap(begin, right_iter);

		return right_iter;
	}
	template<typename T>
	void quick_sort(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		//한개 이상의 벡터가 들어 있을 경우
		if (distance(begin, last) >= 1)
		{
			//분활 작업
			auto partition_iter = partition<T>(begin, last);
			//분할 작업에 의해 생성된 벡터를 재귀적으로 정렬
			quick_sort<T>(begin, partition_iter - 1);
			quick_sort<T>(partition_iter, last);

		}
	}

	template<typename T>
	void print_vector(vector<T> arr)
	{
		for (auto i : arr)
			cout << i << " ";
		cout << endl;

	}

	//두 반복자 사이의 중간 값을 찾는 함수
	template<typename T>
	auto find_median(typename vector<T>::iterator begin,
		typename vector<T>::iterator last)
	{
		quick_sort<T>(begin, last);

		return begin + (distance(begin, last) / 2);
	}

	//분할 함수 
	template<typename T>
	auto partition_using_given_pivot(typename vector<T>::iterator begin,
		typename vector<T>::iterator end,
		typename vector<T>::iterator pivot)
	{
		//피벗 위치는 함수 인자로 받음
		//벡터의 시작 과 끝을 정의
		auto left_iter = begin;
		auto right_iter = end;
		while (true)
		{
			//left 값이 피벗 보다 큰값 
			while (*left_iter < *pivot && left_iter != right_iter)
				left_iter++;
			//right 값이 피벗 보다 같거나 작은 값
			while (*right_iter >= *pivot && left_iter != right_iter)
				right_iter--;

			//같은 원소면 break;
			if (left_iter == right_iter)
				break;
			else
				iter_swap(left_iter, right_iter);

		}
		//피벗이 가장 큰 원소 일때 변
		if (*pivot > *right_iter)
			iter_swap(pivot, right_iter);

		return right_iter;
	}
	
	//선형 시간 검색 알고리즘 
	template<typename T>
	typename vector<T>::iterator linear_time_select
	(typename vector<T>::iterator begin,
		typename vector<T>::iterator last,
		size_t i)
	{
		auto size = distance(begin, last);
		if (size > 0 && i < size)
		{
			//다섯 개 원소로 구분 하여 만들 부분 벡터 vi 개수 계산
			auto num_Vi = (size + 4) / 5;
			size_t j = 0;
			//각각의 Vi 중앙값을 찾아 벡터 M 에 저장
			vector<T> M;
			
			for (; j < size / 5; j++)
			{
				auto b = begin + (j * 5);//0,5,10
				auto l = begin + (j * 5) + 4;//5,10,15
				M.push_back(*find_median<T>(b, l));
			}

			if (j * 5 < size)
			{
				auto b = begin + (j * 5);
				auto l = begin + (j * 5) + (size %5);
				M.push_back(*find_median<T>(b, l));
			}

			//vi 의 중앙값으로 구성된 벡터 M에서 다시 중앙값 q를 찾음
			auto median_of_medians = (M.size() == 1) ? M.begin() :
				linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);//size 값은 0을 포함

			//반복자로 들어와야 하는데 상수로 들어와서 컴파일에 문제가 생긴다.
			//
			//분활 연산을 적용, 피벗 q의 위치 K를 찾음
			auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);

			auto k = distance(begin, partition_iter);
			if (i == k)
				return partition_iter;
			else if (i < k)
				return linear_time_select<T>(begin, partition_iter - 1, i-1);
			else if (i > k)
				return linear_time_select<T>(partition_iter + 1, last, i - (k+1));//이부분 문제 발생하네
		}
		else
		{
			return begin;
		}
	}
	template<typename T>
	vector<T> merge(vector<T>& arr1, vector<T>& arr2)
	{
		vector<T> merged;
		auto iter1 = arr1.begin();
		auto iter2 = arr2.begin();

		while (iter1 != arr1.end() && iter2 != arr2.end())
		{
			if (*iter1 < *iter2)
			{
				merged.emplace_back(*iter1);
				iter1++;
			}
			else
			{
				merged.emplace_back(*iter2);
				iter2++;
			}
		}

		if (iter1 != arr1.end())
		{
			for (; iter1 != arr1.end(); iter1++)
				merged.emplace_back(*iter1);
		}
		else
		{
			for (; iter2 != arr2.end(); iter2++)
				merged.emplace_back(*iter2);
		}
		return merged;
	}
	template<typename T>
	vector<T>merge_sort(vector<T> arr)
	{
		if (arr.size() > 1)
		{
			auto mid = size_t(arr.size()/2);
			auto left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
			auto right_half = merge_sort(vector<T>(arr.begin() + mid, arr.end()));

			return merge<T>(left_half, right_half);

		}
		return arr;
	}
	public:
	void run_linear_select_test()
	{
		vector<int>S1{ 45,1, 3,1,2,3,45,5,1,2,44,5,7 };
		cout << "입력 벡터" << endl;
		print_vector<int>(S1);

		cout << "정렬된 벡터: " << endl;
		print_vector<int>(merge_sort<int>(S1));
		//어 11번째 연산 하고 그후에다시 정렬 해서 데이터를 찾으면 비 정상적으로 동작 한다.
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		cout << "5번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 4) << endl;
		//부분 정렬 실행
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;

		int size = 100;
		random_device rd;
		mt19937 rand(rd());

		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);
	
		////int 형 난수 추가
		for (auto i = 0; i < size; i++)
		{
			S1.push_back(unifrom_dist(rand));
		}
		 begin = chrono::steady_clock::now();
		cout << "5번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 4) << endl;
		//부분 정렬 실행
		 end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;

		begin = chrono::steady_clock::now();
		cout << "11번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 50) << endl;
		//부분 정렬 실행
		end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "" << diff.count() << endl;
	
		
		cout << "10번째 원소 : " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 10) << endl;

		cout << "test" << endl;
	}
};

