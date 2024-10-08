#include "alg.h"

void alg::qsort(std::vector<int>& vec)
{
	std::vector<int> uni;
	if (vec.size() < 2)
	{
		return;
	}

	int sup = vec[vec.size()/2];
	std::vector<int> right;
	std::vector<int> left;

	for (int i = 0; i < vec.size(); i++)
	{
		if (sup > vec[i])
		{
			left.push_back(vec[i]);
		}else if(sup < vec[i])
		{
			right.push_back(vec[i]);
		}
	}
	if (!(right.empty()))
	{
		qsort(right);
	}
	if (!(left.empty()))
	{
		qsort(left);
	}

	for (auto i : left)
	{
		uni.push_back(i);
	}
	uni.push_back(sup);
	for (auto i : right)
	{
		uni.push_back(i);
	}
	vec = uni;
}

int alg::binSch(std::vector<int>& vec, int item)
{
	int index = 0;
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right)
	{
		index = (left + right) / 2;
		if (item < vec[index])
		{
			right = index - 1;
		}
		else if (item > vec[index])
		{
			left = index + 1;
		}
		else if (item == vec[index])
		{
			return index;
		}
	}
	return -1;
}
