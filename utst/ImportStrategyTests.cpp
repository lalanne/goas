#include "ImportStrategy.hpp"
#include "MMapBinaryImportStrategy.hpp"

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

TEST(ImportStrategyTests, mmap_binary_import){
    unique_ptr<ImportStrategy> import_strategy(new MMapBinaryImportStrategy("binary_file_name"));
    import_strategy->open_file();
    import_strategy->import_meta_data();
    import_strategy->import_data();

    EXPECT_EQ(1, 0);
}


