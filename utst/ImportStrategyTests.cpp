#include "ImportStrategy.hpp"
#include "MMapBinaryImportStrategy.hpp"
#include "NotFileFoundException.hpp"

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

TEST(ImportStrategyTests, dummy_import){
    unique_ptr<ImportStrategy> import_strategy(new DummyStrategy("dummy_file_name"));
    import_strategy->open_file();
    import_strategy->import_meta_data();
    import_strategy->import_data();

    EXPECT_EQ(1, 0);
}

TEST(ImportStrategyTests, no_file_found_by_mmap_binary_strategy_import){
    unique_ptr<ImportStrategy> import_strategy(new MMapBinaryImportStrategy("binary_file_name"));

    EXPECT_THROW(import_strategy->open_file(), NotFileFoundException);
}

TEST(ImportStrategyTests, 1){
    unique_ptr<ImportStrategy> import_strategy(new MMapBinaryImportStrategy("binary_file_10_rows.dat"));
    import_strategy->open_file();
    import_strategy->import_meta_data();
    import_strategy->import_data();

    EXPECT_EQ(1, 0);
}



