#include "/home/champon1020/repos/CLionWorkspace/silica/tasks/CTakAndCards.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
	std::string input;
	std::string output;
	bool active;
	bool has_output;
};

bool check(std::string expected, std::string actual) {
	while(!expected.empty() && isspace(*--expected.end()))
		expected.erase(--expected.end());
	while(!actual.empty() && isspace(*--actual.end()))
		actual.erase(--actual.end());
	return expected == actual;
}

} // namespace jhelper

int main() {
	std::vector<jhelper::Test> tests = {
		{"4 8\n7 9 8 9\n", "5\n", true, true},{"3 8\n6 6 9\n", "0\n", true, true},{"8 5\n3 6 2 8 7 6 5 9\n", "19\n", true, true},{"33 3\n3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n", "8589934591\n", true, true},{"43 21\n38 40 25 5 16 16 18 7 2 12 4 4 26 17 3 46 46 34 50 8 48 14 44 42 45 6 32 33 42 1 11 11 45 8 7 49 18 32 41 31 23 38 42", "17632158863", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "\033[32m" << "Test #" << ++testID << "\033[m" << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		if (test.has_output) {
			std::cout << "Expected output: \n" << test.output << std::endl;
		}
		else {
			std::cout << "Expected output: \n" << "N/A" << std::endl;
		}
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			std::clock_t start = std::clock();
			CTakAndCards solver;
			solver.solve(in, out);
			std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
				allOK = allOK && result;
				std::cout << "Result: " << (result ? "\033[34m OK \033[m" : "\033[31m Wrong answer \033[m") << std::endl;
			}
			std::cout << "Time: " << currentTime << std::endl;
		}
		else {
			std::cout << "SKIPPED\n";
		}

		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "\033[34m All OK \033[m" << std::endl;
	}
	else {
		std::cout << "\033[31m Some cases failed \033[m" << std::endl;
	}
	std::cout << "Maximal time: " << maxTime << "s." << std::endl;
	return 0;
}
