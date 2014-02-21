#ifndef MEMORY_MAP_38EFH98WHEF9WH8FE9HW
#define MEMORY_MAP_38EFH98WHEF9WH8FE9HW

#include "Meta.hpp"
#include "Relation.hpp"

#include <string>

class MemoryMap{
    
    public:
        MemoryMap();
        MemoryMap(std::string file_name);

        void open_file();
        Meta import_meta_data();
        Relation import_data(Meta meta);

    private:
        std::string _file_name;
        char* data;
};

#endif //MEMORY_MAP_38EFH98WHEF9WH8FE9HW

