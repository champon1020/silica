#include "/home/champon1020/repos/CLionWorkspace/silica/tasks/D.cpp"

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
		{"4 4\n##..\n##..\n..##\n..##\n", "possible\n#...\n....\n....\n...#\n", true, true},{"4 4\n###.\n####\n..##\n..##\n", "possible\n##..\n....\n...#\n...#\n", true, true},{"4 4\n###.\n##.#\n..##\n..##\n", "impossible\n", true, true},
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
			D solver;
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