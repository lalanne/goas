
#include "MMapBinaryImportStrategy.hpp"

#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

MMapBinaryImportStrategy::MMapBinaryImportStrategy(string file_name) : _file_name(file_name){}

/*it is necessary to create an error handling system through exceptions*/
void MMapBinaryImportStrategy::open_file(){
    cout<<"opening "<<_file_name<<"\n";
    struct stat sb;
    int fd = open(_file_name.c_str(), O_RDONLY);
    if(fd == -1){
        perror ("open");
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

void MMapBinaryImportStrategy::import_meta_data(){
    cout<<"importing meta data from "<<_file_name<<"\n";
}

void MMapBinaryImportStrategy::import_data(){
    cout<<"importing data from "<<_file_name<<"\n";
}


