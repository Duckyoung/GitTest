#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

//�л� ������
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

			if (dis == 1)//1�� �϶��� �̹� ��� �˻� �� 
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
		auto last = S.end();//���� �´����� �𸣰ڴ�. �ּ� ���� ���;� �ϴ°� �ƴѰ�?

		while (true)
		{
			
				//�߰� ���� ����
				auto range_length = std::distance(first, last);
				if (range_length == 0)
					cout << "code error" << endl;
				auto mid_element_index = first + floor(range_length / 2);//�߰� Index
				auto mid_element = *(mid_element_index); //�߰� ���� ��
				

				if (mid_element == N)
					return true;
				else if (mid_element > N)
				{
					//--mid_element_index;//���� �κ�.
					//advance(last, 5);//���� ����
					last = mid_element_index;
					//advance(last, mid_element_index);//���� ����
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
		sort(data.begin(), data.end());//ó�� �Ҷ��� ���� ���ߴµ� ���۷����� �߰� �� ���� ���� �մϴ�.


		if (binary_search(test, data))
			cout << "���� �ؾߵ˴ϴ�." << endl;
		else
			cout << "���� ����" << endl;

	}
	void run_small_search_test()
	{
		auto N = 2;
		vector<int> S{ 1,3,2,4,5,7,9,8,6};
		sort(S.begin(), S.end());

		if (linerar_search(N, S))
			cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�." << endl;
		else
			cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;

		if(binary_search(N,S))
			cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�." << endl;
		else
			cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;
	}
	void run_large_search_test(int size, int N)
	{
		vector<int> S;
		random_device rd;
		mt19937 rand(rd());

		//1, size ���� ���� �䤩��
		uniform_int_distribution<mt19937::result_type> unifrom_dist(1, size);

		//int �� ���� �߰�
		for (auto i = 0; i < size; i++)
		{
			S.push_back(unifrom_dist(rand));
		}

		sort(S.begin(), S.end());
		//�˻� �ð� ���� ����
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		bool search_result = binary_search(N, S);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "���� �˻� ���� �ð� : " << diff.count() << endl;

		if (search_result)
			cout << "���Ҹ� ã�ҽ��ϴ�." << endl;
		else
			cout << "���Ҹ� ã�� ���߽��ϴ�." << endl;

		 begin = chrono::steady_clock::now();
		search_result = linerar_search(N, S);
		 end = chrono::steady_clock::now();

		 diff = chrono::duration_cast<chrono::microseconds>(end - begin);
		cout << "���� �˻� ���� �ð� : " << diff.count() << endl;

		if (search_result)
			cout << "���Ҹ� ã�ҽ��ϴ�." << endl;
		else
			cout << "���Ҹ� ã�� ���߽��ϴ�." << endl;

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

