
#include "MemoryMap.hpp"
#include "NotFileFoundException.hpp"
#include "StringUtilities.hpp"

#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

MemoryMap::MemoryMap() {}
MemoryMap::MemoryMap(string file_name) : _file_name(file_name){}

/*it is necessary to create an error handling system through exceptions*/
void MemoryMap::open_file(){
    struct stat sb;
    int fd = open(_file_name.c_str(), O_RDONLY);
    if(fd == -1){
        //leaking resource, no close call!!!!!
        throw NotFileFoundException();
    }

    if(fstat(fd, &sb) == -1){
        perror ("fstat");
    }

    if(!S_ISREG(sb.st_mode)){
        fprintf (stderr, "%s is not a file\n", _file_name.c_str());
    }

    data = (char*)mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if(data == MAP_FAILED){
        perror ("mmap");
    }
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

void MemoryMap::import_data(){
    cout<<"importing data from "<<_file_name<<"\n";
}

