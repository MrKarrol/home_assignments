#pragma once

#include <vector>


namespace task2
{

int GetDifferentItemsCount(std::vector<int>& numbers)
{
	if (not numbers.size())
		return 0;

	int diff_count = 1;
	int i, j, tmp;
	for (i = 0; i < numbers.size(); ++i)
	{
		tmp = numbers.at(i);
		for (j = i - 1; j >= 0 && numbers.at(j) > tmp; j--)
			numbers.at(j + 1) = numbers.at(j);
		numbers.at(j + 1) = tmp;
		if (j >= 0 and numbers.at(j) != numbers.at(j + 1))
			++diff_count;
	}
	return diff_count;
}

} // end of namespace task2