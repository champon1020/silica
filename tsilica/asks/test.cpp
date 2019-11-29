#include "/Users/macuser/CLionProjects/silica/tasks/BPCAS.cpp"

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
		{"\n3 5 R\n790319030\n091076399\n143245946\n590051196\n398226115\n442567154\n112705290\n716433235\n221041645\n\n", "8226\n\n\n\n\n	\n\n", true, true},{"\n8 9 LU\n206932999\n471100777\n973172688\n108989704\n246954192\n399039569\n944715218\n003664867\n219006823\n\n", "2853\n\n\n\n\n	\n\n", true, true},{"\n5 7 D\n271573743\n915078603\n102553534\n996473623\n595593497\n573572507\n340348994\n253066837\n643845096\n\n", "4646\n\n\n\n\n	\n\n", true, true},{"\n2 2 LU\n729142134\n509607882\n640003027\n215270061\n214055727\n745319402\n777708131\n018697986\n277156993\n\n", "0700\n\n\n\n\n	\n\n", true, true},{"\n8 7 RD\n985877833\n469488482\n218647263\n856777094\n012249580\n845463670\n919136580\n011130808\n874387671\n\n", "8878\n\n\n\n\n	\n\n", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	for(const jhelper::Test& test: tests ) {
		std::cout << "\033[4m" << "Test #" << ++testID << "\033[m" << std::endl;
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
			BPCAS solver;
			solver.solve(in, out);
			std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
				allOK = allOK && result;
				std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
			}
			std::cout << "Time: " << currentTime << std::endl;
		}
		else {
			std::cout << "SKIPPED\n";
		}

		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "All OK" << std::endl;
	}
	else {
		std::cout << "Some cases failed" << std::endl;
	}
	std::cout << "Maximal time: " << maxTime << "s." << std::endl;
	return 0;
}
