#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>

struct IOrderedNumberInputStream {
    virtual unsigned long long Get() = 0;
    virtual bool IsEndOfStream() const = 0;
    virtual ~IOrderedNumberInputStream() {}
};

class OrderedRandomNumberSequence : public IOrderedNumberInputStream {
public:
    OrderedRandomNumberSequence(size_t s, unsigned seed) : size_(s), curr_index_{0}, random_generator_{seed}, last_value_{0} {}
    OrderedRandomNumberSequence(const OrderedRandomNumberSequence&) = delete;
    OrderedRandomNumberSequence& operator=(const OrderedRandomNumberSequence&) = delete;
    unsigned long long Get() {
        ++curr_index_;
        last_value_ = last_value_ + random_generator_() % 100;
        return last_value_;
    }
    bool IsEndOfStream() const {
        return curr_index_ >= size_;
    }
private:
    size_t size_;
    size_t curr_index_;
    std::mt19937 random_generator_;
    unsigned long long last_value_;
};

// [YOUR CODE WILL BE PLACED HERE] 




// =========================================

#include<bits/stdc++.h>

// 排序，最快，沒有之一
void merge_sort_recursive(std::vector<unsigned long long> & arr , std::vector<unsigned long long> & reg, int start, int end ) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
	{
		// 判斷
		if( arr[start1] <= arr[start2] )
			reg[k++] =  arr[start1++] ;
		else 
		{

			reg[k++] = arr[start2++];

		}
	}
	while (start1 <= end1)
	{
		reg[k++] = arr[start1++];
	}

	while (start2 <= end2)
	{
		reg[k++] = arr[start2++];
	}
	for (k = start; k <= end; k++)
	{
		arr[k] = reg[k];
	}
}


class CompositeOrderedNumberInputStream : public IOrderedNumberInputStream 
{
//	const std::vector<IOrderedNumberInputStream*> _buf ;
	std::vector<unsigned long long> _buf ;
	size_t _pos ;
public :
	CompositeOrderedNumberInputStream( const std::vector<IOrderedNumberInputStream*> &buf );

public :
	unsigned long long Get() ;
	bool IsEndOfStream() const ;
};

CompositeOrderedNumberInputStream::CompositeOrderedNumberInputStream( const std::vector<IOrderedNumberInputStream*> &buf )
{
	int i ;
	_pos = 0 ;
	int n = buf.size();
	IOrderedNumberInputStream* input ;
	for( i = 0 ; i < n ; ++i )
	{
		input = buf[i] ;
		while( input->IsEndOfStream() == false )
		{
			_buf.push_back( input->Get());
		}
	}
	std::vector<unsigned long long> temp( _buf.size());
	merge_sort_recursive( _buf , temp , 0 , _buf.size() - 1 );
}
unsigned long long CompositeOrderedNumberInputStream::Get()
{
	//
	unsigned long long ret = _buf[_pos] ;
	_pos ++ ;

	return ret ; 
}
bool CompositeOrderedNumberInputStream::IsEndOfStream() const
{
	return _pos >= _buf.size() ;
}


// =========================================


std::ostream& operator<<(std::ostream&, IOrderedNumberInputStream&);

void Test1(); // Sample1
void Test2(); // All
void Test3(); // All
void Test4(); // All
void Test5(); // All
void Test6(); // All
void Test7(); // All

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int id;
    std::cin >> id;
    void (*f[])() = { Test1, Test2, Test3, Test4, Test5, Test6, Test7};
    f[id-1]();
}

std::ostream& operator<<(std::ostream& os, IOrderedNumberInputStream& input) {
    bool isFirst = true;
    os << '[';
    while (!input.IsEndOfStream()) {
        if (!isFirst) {
            os << ", ";
        } else {
            isFirst = false;
        }
        os << input.Get();
    }
    return os << ']';
}

namespace Feis {}

void Test1() {
    // OrderedRandomNumberSequence
    {
        OrderedRandomNumberSequence a1(10, 10), b1(10, 20);
        std::cout << "01) " << a1 << std::endl;
        std::cout << "02) " << b1 << std::endl;
    }

    // CompositeOrderedNumberInputStream (1)
    {
        OrderedRandomNumberSequence a1(10, 10), b1(10, 20);
        CompositeOrderedNumberInputStream o1({&a1, &b1});
        std::cout << "03) " << o1 << std::endl;
    }

    // CompositeOrderedNumberInputStream (2)
    {
        OrderedRandomNumberSequence a1(10, 10), b1(10, 20), a2(20, 30), b2(0, 40), c2(10, 50), d1(5, 60);

        CompositeOrderedNumberInputStream o1({&a1, &b1});
        CompositeOrderedNumberInputStream o2({&a2, &b2, &c2});
        CompositeOrderedNumberInputStream o3({&d1});

        CompositeOrderedNumberInputStream o4({&o1, &o2, &o3});

        std::cout << "04) " << o4 << std::endl;
    }
}

void Test2() {}
void Test3() {}
void Test4() {}
void Test5() {}
void Test6() {}
void Test7() {}