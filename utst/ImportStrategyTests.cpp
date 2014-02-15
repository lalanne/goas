#include "ImportStrategy.hpp"
#include "MMapBinaryImportStrategy.hpp"
#include "NotFileFoundException.hpp"
#include "Meta.hpp"

#include <gtest/gtest.h>

#include <string>

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

    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(0);
    meta.add_column_type(1);
    meta.add_column_type(1);
    meta.add_column_type(1);

    return meta;
}


class DummyStrategy : public ImportStrategy{
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

TEST(ImportStrategyTests, no_file_found_by_mmap_binary_strategy_import){
    unique_ptr<ImportStrategy> import_strategy(new MMapBinaryImportStrategy("binary_file_name"));

    EXPECT_THROW(import_strategy->open_file(), NotFileFoundException);
}

TEST(ImportStrategyTests, meta_mmap_binary_strategy_import){
    Meta expected_meta = set_expected_meta();

    unique_ptr<ImportStrategy> import_strategy(new MMapBinaryImportStrategy("binary_file_10_rows.dat"));
    import_strategy->open_file();
    Meta meta = import_strategy->import_meta_data();

    EXPECT_TRUE(expected_meta == meta);
}

TEST(ImportStrategyTests, whishful_thinking){
    /*Fucking configurable algorithms*/

    /*How im going to read the file from disk*/
    /*----------------------------------------*/
    /*Format of the file: text, binary*/
    /*Strategy to read: memory map, no memory map*/
    /*Meta data, No meta data*/

    BinaryImport binary_import; //TextImport
    MemoryMap memory_map; //NoMemoryMap
    MetaData meta_data; //NoMetaData

    ImportStrategy<binary_import, memory_map, meta_data> import("test_file.dat");
    Meta meta = import.meta();
    Relation relation = import.relation()

    EXPECT_TRUE(false);
}



