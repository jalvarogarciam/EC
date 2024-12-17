#include <algorithm>    // min_element
#include <chrono>       // high_resolution_clock
#include <iomanip>      // setw
#include <iostream>     // cout

using namespace std::chrono;

const unsigned MINSIZE = 1 << 10; // minimun line size to test:  1KB
const unsigned MAXSIZE = 1 << 26; // maximun line size to test: 64MB
const unsigned GAP = 12;          // gap for cout columns
const unsigned REP = 100;         // number of repetitions of every test
const unsigned STEPS = 1e6;       // steps

char bytes[MAXSIZE], r = 0;

const unsigned int LINE_SIZE = 64;

int main()
{
	std::cout << "#" 
	          << std::setw(GAP - 1) << "line (B)"
	          << std::setw(GAP + 1) << "time (µs)"
	          << std::endl;

	for (unsigned size = MINSIZE; size <= MAXSIZE; size *= 2)
	{
		duration<double, std::micro> score[REP];

		unsigned tam = size-1;

		for (auto &s: score)
		{
			auto start = high_resolution_clock::now();

			for (unsigned i = 0; i < STEPS; ++i){
				// completar aquÃ­...
				r ^= bytes[(i * LINE_SIZE) & tam]; // ... o mejora esto...
			}
			auto stop = high_resolution_clock::now();

			s = stop - start;
		}

		std::cout << std::setw(GAP) << size
		          << std::setw(GAP) << std::fixed << std::setprecision(2)
		          << std::setw(GAP) << std::min_element(std::begin(score), std::end(score))->count()
		          << std::endl;
	}
}