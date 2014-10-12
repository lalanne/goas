
#include "MemoryMap.hpp"
#include "NotFileFoundException.hpp"
#include "NotAFileException.hpp"
#include "ErrorInGettingStateOfFileException.hpp"
#include "ErrorInMmapException.hpp"
#include "StringUtilities.hpp"
#include "IntegerField.hpp"
#include "Record.hpp"

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

MemoryMap::MemoryMap() {}
MemoryMap::MemoryMap(string file_name) : _file_name{file_name}{}

MemoryMap::~MemoryMap(){
    close(fd);
}


//check call to desctructor when exception is thrown
void MemoryMap::open_file(){
    struct stat sb;
    fd = open(_file_name.c_str(), O_RDONLY);
    if(fd == -1) throw NotFileFoundException();
    if(fstat(fd, &sb) == -1) throw ErrorInGettingStateOfFileException();
    if(!S_ISREG(sb.st_mode)) throw NotAFileException();

    data = (char*)mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if(data == MAP_FAILED) throw ErrorInMmapException();
}

Meta MemoryMap::import_meta_data(){
    unsigned short n_columns;
    Meta meta;

    memcpy(&n_columns, data, sizeof(n_columns));
    data = data + sizeof(n_columns);
    meta.set_columns(n_columns);

    unsigned int n_rows;
    memcpy(&n_rows, data, sizeof(n_rows));
    data = data + sizeof(n_rows);
    meta.set_rows(n_rows);

    for(int i = 0; i< n_columns; ++i){
        char type_column;
        memcpy(&type_column, data, sizeof(type_column));
        data = data + sizeof(type_column);
        meta.add_column_type(type_column);

        string column_name = StringUtilities::read_string_type(data);
        meta.add_column_name(column_name);
    }
    
    return meta;
}

Relation MemoryMap::import_data(Meta meta){
    Relation relation;
    unsigned int number_of_rows = meta.rows();
    for(int i=0; i<number_of_rows; ++i){
        unsigned int number_of_columns = meta.columns();
        Record record(number_of_columns, meta);

        for(int j=0; j<number_of_columns; ++j){
            if(meta.get_type(j)==TYPE_INTEGER) {
                int number = 0;
                memcpy(&number, data, sizeof(number));
                data = data + sizeof(int);

                IntegerField tmp(number);
                record.add(tmp);
            }
            else if(meta.get_type(j)==TYPE_STRING){
                const unsigned int size = strlen(data) + 1;
                RawStringField field(size);

                memcpy(field.raw_ptr(), data, size);
                data = data + size;

                record.add(field);
            }
        }
        relation.add_record(record);
    }
    relation.print();
    return relation;
}


