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
	if (k == 0) return 0;
	if (k == 1) return 1;
	
	unsigned int tPrev = 1;
	unsigned int tCur = 1;
	
	for (unsigned int i = 2; i <= k; i++)
	{
		unsigned int tNext = std::pow(2, i) - tPrev;
		tPrev = tCur;
		tCur = tNext;
	}
	return tCur;
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
	if (tk == 1 && tPrev == 0)
	{
		l.push_front(pairedList.front().second);
		return ;
	}
	std::list<std::pair<int, int> >::iterator pairedIt = pairedList.begin();
	std::advance(pairedIt, tk - 1);
	for (int t = tk; t > tPrev; --t, --pairedIt)
	{
		int elementToInsert = (*pairedIt).second;
		std::list<int>::iterator insertPos = l.begin();
		while (insertPos != l.end() && *insertPos < elementToInsert)
			insertPos++;
		l.insert(insertPos, elementToInsert);		
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
	unsigned int tPrev = 0;
	unsigned int k = 1;
	
	// printContainer(l);
	while (tPrev < pairedList.size())
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
	if (l.size() <= 1) return l;
	
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
		std::list<int>::iterator insertPos = l.begin();
		while (insertPos != l.end() && *insertPos < unpaired)
			insertPos++;
		l.insert(insertPos, unpaired);
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
	int pairCount = n / 2;
	
	for (int i = 0; i < pairCount; ++i)
	{
		int a = src[2 * i];
		int b = src[2 * i + 1];
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
	}
}

static void sortByGreaterPaired(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src)
{
	std::vector<std::pair<int, int> > pairedVector(greaterPaired.size());
	for (unsigned int i = 0; i < greaterPaired.size(); ++i)
		pairedVector[i] = std::make_pair(greaterPaired[i], smallerPaired[i]);
	
	std::sort(pairedVector.begin(), pairedVector.end(), comparePairs);
	src.clear();
	for (unsigned int i = 0; i < greaterPaired.size(); ++i)
	{
		greaterPaired[i] = pairedVector[i].first;
		smallerPaired[i] = pairedVector[i].second;
		src.push_back(pairedVector[i].first);
	}
	// printContainer(src);
}

static void insertAccordingToSequence(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src, int tk, int tPrev)
{
	(void)greaterPaired;
	if (tk == 1 && tPrev == 0)
	{
		src.insert(src.begin(), smallerPaired[0]);
		return;
	}
	
	for (int t = tk; t > tPrev; --t)
	{
		int index = t - 1;
		if (index >= (int)smallerPaired.size()) continue;
		
		int elementToInsert = smallerPaired[index];
		std::vector<int>::iterator insertPos = std::lower_bound(src.begin(), src.end(), elementToInsert);
		src.insert(insertPos, elementToInsert);
	}
}

static void mergeInsert(std::vector<int> & smallerPaired, std::vector<int> & greaterPaired, std::vector<int> & src)
{
	unsigned int t = 1;
	unsigned int tPrev = 0;
	unsigned int k = 1;
	while (tPrev < smallerPaired.size())
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
	if (v.size() <= 1) return v;
	
	bool hasUnpaired = v.size() % 2 == 1;
	int unpaired = 0;
	if (hasUnpaired)
		unpaired = v.back();
	
	std::vector<int> smallerPaired(v.size() / 2);
	std::vector<int> greaterPaired(v.size() / 2);

	buildRelativePairs(smallerPaired, greaterPaired, v);
	sortByGreaterPaired(smallerPaired, greaterPaired, v);
	mergeInsert(smallerPaired, greaterPaired, v);
	
	if (hasUnpaired)
	{
		std::vector<int>::iterator insertPos = std::lower_bound(v.begin(), v.end(), unpaired);
		v.insert(insertPos, unpaired);
	}
	
	// printContainer(v);
	return v;
}
