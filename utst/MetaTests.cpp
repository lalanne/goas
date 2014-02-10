
#include "Meta.hpp"
#include "MetaBasicPopulator.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(MetaTests, number_of_integers_and_strings_in_a_record){
    const unsigned int rows = 100;
    const unsigned short columns = 16;

    Meta meta;
    MetaBasicPopulator meta_populator(meta);

    meta_populator.columns(columns);
    meta_populator.rows(rows);   
    meta_populator.colum_names();
    meta_populator.column_types();

    const unsigned short expected_strings = 8;
    const unsigned short expected_integers = 8;
    
    EXPECT_EQ(expected_strings, meta.strings_in_record());
    EXPECT_EQ(expected_integers, meta.integers_in_record());
}

TEST(MetaTests, copy_constructor){
    const unsigned int rows = 100;
    const unsigned short columns = 16;

    Meta meta;
    MetaBasicPopulator meta_populator(meta);

    meta_populator.columns(columns);
    meta_populator.rows(rows);   
    meta_populator.colum_names();
    meta_populator.column_types();
     
    Meta new_meta(meta);

    EXPECT_EQ(new_meta, meta);
}

TEST(MetaTests, assignment){
    const unsigned int rows = 100;
    const unsigned short columns = 16;

    Meta meta;
    MetaBasicPopulator meta_populator(meta);

    meta_populator.columns(columns);
    meta_populator.rows(rows);   
    meta_populator.colum_names();
    meta_populator.column_types();
     
    Meta new_meta;
    MetaBasicPopulator new_meta_populator(new_meta);
    
    new_meta_populator.columns(columns);
    new_meta_populator.rows(rows);
    new_meta_populator.column_names_and_types("t1"); 

    new_meta = meta;

    EXPECT_EQ(new_meta, meta);
}










