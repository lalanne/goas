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

Relation set_expected_relation(Meta meta){
    Relation relation;
    Record record(16, meta);

    
    IntegerField i(9);
    record.add(i);
    record.add(i = IntegerField(0));
    record.add(i = IntegerField(1));
    record.add(i = IntegerField(1));
    record.add(i = IntegerField(9));
    record.add(i = IntegerField(9));
    record.add(i = IntegerField(9));
    record.add(i = IntegerField(9));
    record.add(i = IntegerField(4));
    record.add(i = IntegerField(1));
    record.add(i = IntegerField(9));
    record.add(i = IntegerField(18));
    record.add(i = IntegerField(19));

    char raw_h[] = "HHHHHHH";
    RawStringField s_h(8);
    memcpy(s_h.raw_ptr(), raw_h, 8);
    record.add(s_h);

    char raw_a[] = "AAAAAAA";
    RawStringField s_a(8);
    memcpy(s_a.raw_ptr(), raw_a, 8);
    record.add(s_a);

    RawStringField s_h1(8);
    memcpy(s_h1.raw_ptr(), raw_h, 8);
    record.add(s_h1);

    Record record1(16, meta);

    IntegerField i1(1);
    record1.add(i1);
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(1));
    record1.add(i1 = IntegerField(2));
    record1.add(i1 = IntegerField(3));

    RawStringField s_h2(8);
    memcpy(s_h2.raw_ptr(), raw_h, 8);
    record1.add(s_h2);

    RawStringField s_h3(8);
    memcpy(s_h3.raw_ptr(), raw_h, 8);
    record1.add(s_h3);

    RawStringField s_h4(8);
    memcpy(s_h4.raw_ptr(), raw_h, 8);
    record1.add(s_h4);

    Record record2(16, meta);

    IntegerField i2(2);
    record2.add(i2);
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(0));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(0));
    record2.add(i2 = IntegerField(2));
    record2.add(i2 = IntegerField(4));
    record2.add(i2 = IntegerField(5));

    char raw_v[] = "VVVVVVV";
    RawStringField s_v(8);
    memcpy(s_v.raw_ptr(), raw_v, 8);
    record2.add(s_v);

    RawStringField s_v1(8);
    memcpy(s_v1.raw_ptr(), raw_v, 8);
    record2.add(s_v1);

    RawStringField s_v2(8);
    memcpy(s_v2.raw_ptr(), raw_v, 8);
    record2.add(s_v2);

    Record record3(16, meta);

    IntegerField i3(3);
    record3.add(i3);
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(1));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(1));
    record3.add(i3 = IntegerField(3));
    record3.add(i3 = IntegerField(6));
    record3.add(i3 = IntegerField(7));

    char raw_o[] = "OOOOOOO";
    RawStringField s_o(8);
    memcpy(s_o.raw_ptr(), raw_o, 8);
    record3.add(s_o);

    RawStringField s_o1(8);
    memcpy(s_o1.raw_ptr(), raw_o, 8);
    record3.add(s_o1);

    RawStringField s_o2(8);
    memcpy(s_o2.raw_ptr(), raw_o, 8);
    record3.add(s_o2);

    Record record4(16, meta);

    IntegerField i4(5);
    record4.add(i4);
    record4.add(i4 = IntegerField(4));
    record4.add(i4 = IntegerField(1));
    record4.add(i4 = IntegerField(1));
    record4.add(i4 = IntegerField(5));
    record4.add(i4 = IntegerField(5));
    record4.add(i4 = IntegerField(5));
    record4.add(i4 = IntegerField(5));
    record4.add(i4 = IntegerField(0));
    record4.add(i4 = IntegerField(1));
    record4.add(i4 = IntegerField(5));
    record4.add(i4 = IntegerField(10));
    record4.add(i4 = IntegerField(11));

    RawStringField s_h5(8);
    memcpy(s_h5.raw_ptr(), raw_h, 8);
    record4.add(s_h5);

    RawStringField s_a1(8);
    memcpy(s_a1.raw_ptr(), raw_a, 8);
    record4.add(s_a1);

    RawStringField s_h6(8);
    memcpy(s_h6.raw_ptr(), raw_h, 8);
    record4.add(s_h6);

    Record record5(16, meta);

    IntegerField i5(7);
    record5.add(i5);
    record5.add(i5 = IntegerField(5));
    record5.add(i5 = IntegerField(1));
    record5.add(i5 = IntegerField(3));
    record5.add(i5 = IntegerField(7));
    record5.add(i5 = IntegerField(7));
    record5.add(i5 = IntegerField(7));
    record5.add(i5 = IntegerField(7));
    record5.add(i5 = IntegerField(2));
    record5.add(i5 = IntegerField(1));
    record5.add(i5 = IntegerField(7));
    record5.add(i5 = IntegerField(14));
    record5.add(i5 = IntegerField(15));

    RawStringField s_o3(8);
    memcpy(s_o3.raw_ptr(), raw_o, 8);
    record5.add(s_o3);

    RawStringField s_h7(8);
    memcpy(s_h7.raw_ptr(), raw_h, 8);
    record5.add(s_h7);

    RawStringField s_o4(8);
    memcpy(s_o4.raw_ptr(), raw_o, 8);
    record5.add(s_o4);

    Record record6(16, meta);

    IntegerField i6(8);
    record6.add(i6);
    record6.add(i6 = IntegerField(6));
    record6.add(i6 = IntegerField(0));
    record6.add(i6 = IntegerField(0));
    record6.add(i6 = IntegerField(8));
    record6.add(i6 = IntegerField(8));
    record6.add(i6 = IntegerField(8));
    record6.add(i6 = IntegerField(8));
    record6.add(i6 = IntegerField(3));
    record6.add(i6 = IntegerField(0));
    record6.add(i6 = IntegerField(8));
    record6.add(i6 = IntegerField(16));
    record6.add(i6 = IntegerField(17));

    RawStringField s_a2(8);
    memcpy(s_a2.raw_ptr(), raw_a, 8);
    record6.add(s_a2);

    RawStringField s_v3(8);
    memcpy(s_v3.raw_ptr(), raw_v, 8);
    record6.add(s_v3);

    RawStringField s_a3(8);
    memcpy(s_a3.raw_ptr(), raw_a, 8);
    record6.add(s_a3);

    Record record7(16, meta);

    IntegerField i7(4);
    record7.add(i7);
    record7.add(i7 = IntegerField(7));
    record7.add(i7 = IntegerField(0));
    record7.add(i7 = IntegerField(0));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(0));
    record7.add(i7 = IntegerField(4));
    record7.add(i7 = IntegerField(8));
    record7.add(i7 = IntegerField(9));

    RawStringField s_a4(8);
    memcpy(s_a4.raw_ptr(), raw_a, 8);
    record7.add(s_a4);

    RawStringField s_o6(8);
    memcpy(s_o6.raw_ptr(), raw_o, 8);
    record7.add(s_o6);

    RawStringField s_a5(8);
    memcpy(s_a5.raw_ptr(), raw_a, 8);
    record7.add(s_a5);

    Record record8(16, meta);

    IntegerField i8(6);
    record8.add(i8);
    record8.add(i8 = IntegerField(8));
    record8.add(i8 = IntegerField(0));
    record8.add(i8 = IntegerField(2));
    record8.add(i8 = IntegerField(6));
    record8.add(i8 = IntegerField(6));
    record8.add(i8 = IntegerField(6));
    record8.add(i8 = IntegerField(6));
    record8.add(i8 = IntegerField(1));
    record8.add(i8 = IntegerField(0));
    record8.add(i8 = IntegerField(6));
    record8.add(i8 = IntegerField(12));
    record8.add(i8 = IntegerField(13));

    RawStringField s_v4(8);
    memcpy(s_v4.raw_ptr(), raw_v, 8);
    record8.add(s_v4);

    RawStringField s_a6(8);
    memcpy(s_a6.raw_ptr(), raw_a, 8);
    record8.add(s_a6);

    RawStringField s_v5(8);
    memcpy(s_v5.raw_ptr(), raw_v, 8);
    record8.add(s_v5);

    Record record9(16, meta);

    IntegerField i9(0);
    record9.add(i9);
    record9.add(i9 = IntegerField(9));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(0));
    record9.add(i9 = IntegerField(1));

    RawStringField s_a7(8);
    memcpy(s_a7.raw_ptr(), raw_a, 8);
    record9.add(s_a7);

    RawStringField s_h8(8);
    memcpy(s_h8.raw_ptr(), raw_h, 8);
    record9.add(s_h8);

    RawStringField s_a8(8);
    memcpy(s_a8.raw_ptr(), raw_a, 8);
    record9.add(s_a8);

    relation.add_record(record);
    relation.add_record(record1);
    relation.add_record(record2);
    relation.add_record(record3);
    relation.add_record(record4);
    relation.add_record(record5);
    relation.add_record(record6);
    relation.add_record(record7);
    relation.add_record(record8);
    relation.add_record(record9);

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




