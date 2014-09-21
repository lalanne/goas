#include "ImportStrategy.hpp"
#include "MemoryMap.hpp"
#include "MetaData.hpp"
#include "NotFileFoundException.hpp"
#include "Meta.hpp"
#include "BinaryImport.hpp"

#include <gtest/gtest.h>

#include <string>
#include <iostream>

using namespace std;

Meta set_expected_meta(){
    Meta meta;
    const unsigned int columns_expected = 16;
    const unsigned int rows_expected = 10;

    meta.set_columns(columns_expected);
    meta.set_rows(rows_expected);

    meta.add_column_name("unique1");
    meta.add_column_name("unique2");
    meta.add_column_name("two");
    meta.add_column_name("four");
    meta.add_column_name("ten");
    meta.add_column_name("twenty");
    meta.add_column_name("onepercent");
    meta.add_column_name("tenpercent");
    meta.add_column_name("twentypercent");
    meta.add_column_name("fiftypercent");
    meta.add_column_name("unique3");
    meta.add_column_name("even");
    meta.add_column_name("odd");
    meta.add_column_name("stringu1");
    meta.add_column_name("stringu2");
    meta.add_column_name("stringu4");

    const unsigned int number_of_integer_types = 13;
    const unsigned int number_of_string_types = 3;

    for(int i = 0; i<number_of_integer_types; ++i) meta.add_column_type(0);
    for(int i = 0; i<number_of_string_types; ++i) meta.add_column_type(1);

    return meta;
}


class DummyStrategy {
    public:
        DummyStrategy(string file_name){}

        void open_file() {}
        Meta import_meta_data(){Meta meta; return meta;}
        void import_data(){}
};

/*TEST(ImportStrategyTests, dummy_import){
    unique_ptr<ImportStrategy> import_strategy(new DummyStrategy("dummy_file_name"));
    import_strategy->open_file();
    import_strategy->import_meta_data();
    import_strategy->import_data();

    EXPECT_EQ(1, 0);
}*/


//this test should not be here!
//this should be where I test the concrete open, not the design!
/*TEST(ImportStrategyTests, no_file_found_by_mmap_binary_strategy_import){
    unique_ptr<ImportStrategy> import_strategy(new MemoryMap("binary_file_name"));

    EXPECT_THROW(import_strategy->open_file(), NotFileFoundException);
}

TEST(ImportStrategyTests, meta_mmap_binary_strategy_import){
    Meta expected_meta = set_expected_meta();

    unique_ptr<ImportStrategy> import_strategy(new MemoryMap("binary_file_10_rows.dat"));
    import_strategy->open_file();
    Meta meta = import_strategy->import_meta_data();

    EXPECT_TRUE(expected_meta == meta);
}*/

TEST(ImportStrategyTests, basic_import_meta_BINARY_MEMORYMAP_METADATA){
    ImportStrategy<BinaryImport, 
                MemoryMap, 
                MetaData> import("binary_file_10_rows.dat");
    Meta meta = import.meta();
    Meta expected_meta = set_expected_meta();
    EXPECT_TRUE(expected_meta == meta);
}



