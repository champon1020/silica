//
// Created by champon1020 on 2020/04/11.
//

#include <string>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "combination_test.hpp"
#include "kruskal_test.hpp"

using json = nlohmann::json;
using namespace std;

class MathTest : public ::testing::Test{
protected:
    string env_p = getenv("SILICA_TEST_DATA");

    virtual void SetUp() {
        // setup of testing.
    }

    void Execute(json data, function<void(istream&, ostream&)> TestFunc) {
        for(json j : data["tests"]) {
            string tin = j["in"];
            stringbuf buf(tin);
            istream in(&buf);

            stringbuf tout;
            ostream out(&tout);

            TestFunc(in, out);

            string answer = tout.str();
            EXPECT_EQ(answer, j["out"]);
        }
    }
};

namespace {
    TEST_F(MathTest, Combination){
        ifstream f(env_p + "/combination.json");
        json data;
        f >> data;

        Execute(data, TestCombination);
    }

    TEST_F(MathTest, Kruskal){
        // kruskal
    }
}