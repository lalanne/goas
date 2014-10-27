#include "ImportStrategy.hpp"
#include "MemoryMap.hpp"
#include "MetaData.hpp"
#include "NotFileFoundException.hpp"
#include "Meta.hpp"
#include "BinaryImport.hpp"
#include "IntegerField.hpp"
#include "RawStringField.hpp"

#include <gtest/gtest.h>

#include <string>
#include <iostream>

using namespace std;

const unsigned int INTEGER_TYPE = 0;
const unsigned int STRING_TYPE = 1;

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

    for(unsigned int i = 0; i<number_of_integer_types; ++i){
        meta.add_column_type(INTEGER_TYPE);
    }
    for(unsigned int i = 0; i<number_of_string_types; ++i){
        meta.add_column_type(STRING_TYPE);
    }

    return meta;
}

void set_record(int numbers[13],
                string strings[13],
                Relation& relation,
                Meta& meta){
    Record record(16, meta);

    IntegerField x;
    for(unsigned int i=0; i<13; ++i) record.add( x = IntegerField(numbers[i]));

    for(unsigned int i=0; i<3; ++i){
        RawStringField s(8);
        memcpy(s.raw_ptr(), strings[i].c_str(), 8);
        record.add(s);
    }

    relation.add_record(record);
}

Relation set_expected_relation(Meta meta){
    Relation relation;

    int numbers[] = {9, 0, 1, 1, 9, 9, 9, 9, 4, 1, 9, 18, 19};
    string strings[] = {"HHHHHHH", "AAAAAAA", "HHHHHHH"};
    set_record(numbers, strings, relation, meta);

    int numbers1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3};
    string strings1[] = {"HHHHHHH", "HHHHHHH", "HHHHHHH"};
    set_record(numbers1, strings1, relation, meta);

    int numbers2[] = {2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 4, 5};
    string strings2[] = {"VVVVVVV", "VVVVVVV", "VVVVVVV"};
    set_record(numbers2, strings2, relation, meta);

    int numbers3[] = {3, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 6, 7};
    string strings3[] = {"OOOOOOO", "OOOOOOO", "OOOOOOO"};
    set_record(numbers3, strings3, relation, meta);

    int numbers4[] = {5, 4, 1, 1, 5, 5, 5, 5, 0, 1, 5, 10, 11};
    string strings4[] = {"HHHHHHH", "AAAAAAA", "HHHHHHH"};
    set_record(numbers4, strings4, relation, meta);

    int numbers5[] = {7, 5, 1, 3, 7, 7, 7, 7, 2, 1, 7, 14, 15};
    string strings5[] = {"OOOOOOO", "HHHHHHH", "OOOOOOO"};
    set_record(numbers5, strings5, relation, meta);

    int numbers6[] = {8, 6, 0, 0, 8, 8, 8, 8, 3, 0, 8, 16, 17};
    string strings6[] = {"AAAAAAA", "VVVVVVV", "AAAAAAA"};
    set_record(numbers6, strings6, relation, meta);

    int numbers7[] = {4, 7, 0, 0, 4, 4, 4, 4, 4, 0, 4, 8, 9};
    string strings7[] = {"AAAAAAA", "OOOOOOO", "AAAAAAA"};
    set_record(numbers7, strings7, relation, meta);

    int numbers8[] = {6, 8, 0, 2, 6, 6, 6, 6, 1, 0, 6, 12, 13};
    string strings8[] = {"VVVVVVV", "AAAAAAA", "VVVVVVV"};
    set_record(numbers8, strings8, relation, meta);

    int numbers9[] = {0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    string strings9[] = {"AAAAAAA", "HHHHHHH", "AAAAAAA"};
    set_record(numbers9, strings9, relation, meta);

    return relation;
}

TEST(ImportStrategyTests, basic_import_meta_BINARY_MEMORYMAP_METADATA){
    ImportStrategy<BinaryImport, 
                MemoryMap, 
                MetaData> import("binary_file_10_rows.dat");
    Meta meta = import.meta();
    Meta expected_meta = set_expected_meta();
    EXPECT_TRUE(expected_meta == meta);
}

TEST(ImportStrategyTests, basic_import_meta_BINARY_MEMORYMAP_DATA){
    ImportStrategy<BinaryImport, 
                MemoryMap, 
                MetaData> import("binary_file_10_rows.dat");
    Meta meta = import.meta();
    Relation relation = import.relation(meta);
    Relation expected_relation = set_expected_relation(meta);

    EXPECT_TRUE(expected_relation == relation);
}




