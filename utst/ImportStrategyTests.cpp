#include "ImportStrategy.hpp"

#include <gtest/gtest.h>

#include <string>

using namespace std;

class DummyStrategy : public ImportStrategy{
    public:
        DummyStrategy(string file_name){}

        void open_file() {}
        void import_meta_data(){}
        void import_data(){}
};

TEST(ImportStrategyTests, dummy){
    unique_ptr<ImportStrategy> dummy_strategy(new DummyStrategy("file_name"));
    dummy_strategy->open_file();
    dummy_strategy->import_meta_data();
    dummy_strategy->import_data();

    EXPECT_EQ(1, 0);
}

