#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static bool comparePairs(std::pair<int, int> & a, std::pair<int, int> & b)
{
    return a.first < b.first;
}

/* static int	mergeInsertSequenceRek(unsigned int k)
{
	if (k <= 1)
		return 1;
	return std::pow(2, k) - mergeInsertSequenceRek(k - 1);
} */

static size_t mergeInsertSequenceIte(unsigned int k)
{
	unsigned int i = 1;
	unsigned int tk = 1;
	unsigned int tPrev = tk;
	while (i <= k)
	{
		tk = std::pow(2, i) - tPrev;
		tPrev = tk;
		i++;
	}
	return tk;
}

/*
		Merge-insert sort implementations for list container:
			//	build pairs
			//	sort by greater elements
			//	insertions according to sequence (Ford-Johnson)
*/

static void buildRelativePairs(const std::list<int> & src, std::list<std::pair<int, int> > & pairedList)
{
	std::list<int>::const_iterator a = src.begin();
	std::list<int>::const_iterator b = ++(src.begin());
	int n = src.size();
	for (int i = 0; i < (n / 2); ++i)
	{
		if (*a < *b)
			pairedList.push_back(std::make_pair(*b, *a));
		else
			pairedList.push_back(std::make_pair(*a, *b));
		std::advance(a, 2);
		std::advance(b, 2);
		// std::cout << "(" << pairedList.back().first << ", " << pairedList.back().second << ")\n";
	}
	// printContainer(src);
}

static void insertAccordingToSequence(int tk, int tPrev, std::list<int> & l, std::list<std::pair<int, int> > & pairedList)
{
	if (tk == 1)
	{
		l.push_front(pairedList.front().second);
		return ;
	}
	std::list<std::pair<int, int> >::iterator pairedIt = pairedList.begin();
	std::advance(pairedIt, tk - 1);
	for (int t = tk; t > tPrev; --t, --pairedIt)
	{
		std::list<int>::iterator listIt = l.begin();
		while (*listIt != (*pairedIt).first)
			listIt++;
		int elementToInsert = (*pairedIt).second;
		while (*listIt > elementToInsert && listIt != l.begin())
			listIt--;
		if (*listIt < elementToInsert)
			listIt++;
		std::list<int>::iterator insertHere = listIt;
		l.insert(insertHere, elementToInsert);		
	}
}

static void sortAndInitializeGreaterPaired(std::list<int> & l, std::list<std::pair<int, int> > & pairedList)
{
	pairedList.sort();
	l.clear();
	for (std::list<std::pair<int, int> >::iterator it = pairedList.begin(); it != pairedList.end(); ++it)
		l.push_back((*it).first);
	// printContainer(l);
}

static void mergeInsert(std::list<int> & l, std::list<std::pair<int, int> > & pairedList)
{
	unsigned int t = 1;
	unsigned int tPrev = t;
	unsigned int k = 1;
	
	// printContainer(l);
	while (true)
	{
		t = mergeInsertSequenceIte(k++);
		t = std::min((size_t)t, pairedList.size());
		insertAccordingToSequence(t, tPrev, l, pairedList);
		// printContainer(l);
		if (t == pairedList.size())
			break;
		tPrev = t;
	}
}

const std::list<int> PmergeMe::sort(std::list<int> & l)
{
	std::list<std::pair<int, int> > pairedList;
	bool hasUnpaired;
	int unpaired;

	hasUnpaired = l.size() % 2 == 1;
	if (hasUnpaired)
		unpaired = l.back();
	buildRelativePairs(l, pairedList);
	sortAndInitializeGreaterPaired(l, pairedList);
	mergeInsert(l, pairedList);
	if (hasUnpaired)
	{
		std::list<std::pair<int, int> > temp;
		temp.push_back(std::make_pair(l.front(), unpaired));
		mergeInsert(l, temp);
	}
	return l;
}

/* 
		It follows a merge-insert sort implementation for **VECTOR** container:
			//	build pairs
			//	sort by greater elements
			//	insertions according to sequence (Ford-Johnson)
*/

static void buildRelativePairs(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, const std::vector<int> & src)
{
	int n = src.size();
	for (int i = 0; i < (n / 2); ++i)
	{
		int a = src[n - (2 * i + 1)];
		int b = src[n - (2 * i + 2)];
		if (a < b)
		{
			smallerPaired[i] = a;
			greaterPaired[i] = b;
		}
		else
		{
			smallerPaired[i] = b;
			greaterPaired[i] = a;
		}
		a++;
		b++;
	}
	if (n % 2 == 1)
		smallerPaired.push_back(n - 1);
}

static void sortByGreaterPaired(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src)
{
	std::vector<std::pair<int, int> > pairedVector(greaterPaired.size());
	for (unsigned int i = 0; i < greaterPaired.size(); ++i)
		pairedVector[i] = std::make_pair(greaterPaired[i], smallerPaired[i]);
	
	std::sort(pairedVector.begin(), pairedVector.end(), comparePairs);
	std::fill(src.begin(), src.end(), 0);
	for (unsigned int i = 0; i < greaterPaired.size(); ++i)
	{
		greaterPaired[i] = pairedVector[i].first;
		smallerPaired[i] = pairedVector[i].second;
		src[(src.size() - greaterPaired.size() + i)] = pairedVector[i].first;
	}
	// printContainer(src);
}

static void insertAccordingToSequence(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src, int tk, int tPrev)
{
	if (tk == 1)
		src[src.size() - greaterPaired.size() - 1] = smallerPaired[0];
	for (int t = tk; t > tPrev; --t)
	{
		int end = src.size() - greaterPaired.size() + (t - 1);
		int index = t - 1;
		while (src[end - 1] > smallerPaired[index])
			end -= 2;
		if (src[end] < smallerPaired[index])
			end++;
		if (src[end] != 0)
		{
			std::rotate(src.begin(), src.begin() + 1, src.begin() + end);
			src[end - 1] = smallerPaired[index];
		}
		else
		{
			src[end] = smallerPaired[index];
		}
	}
}

static void mergeInsert(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src)
{
	unsigned int t = 1;
	unsigned int tPrev = t;
	unsigned int k = 1;
	while (true)
	{
		t = mergeInsertSequenceIte(k++);
		t = std::min((size_t)t, smallerPaired.size());
		insertAccordingToSequence(smallerPaired, greaterPaired, src, t, tPrev);
		if (t == smallerPaired.size())
			break;
		tPrev = t;
	}
}

const std::vector<int> PmergeMe::sort(std::vector<int> & v)
{
	std::vector<int> smallerPaired(v.size() / 2);
	std::vector<int> greaterPaired(v.size() / 2);

	buildRelativePairs(smallerPaired, greaterPaired, v);
	sortByGreaterPaired(smallerPaired, greaterPaired, v);
	mergeInsert(smallerPaired, greaterPaired, v);
	// printContainer(v);
	return v;
}
