#ifndef MMAP_BINARY_IMPORT_STRATEGY_38EFH98WHEF9WH8FE9HW
#define MMAP_BINARY_IMPORT_STRATEGY_38EFH98WHEF9WH8FE9HW

#include "ImportStrategy.hpp"

#include <string>

class MMapBinaryImportStrategy : public ImportStrategy{
    
    public:
        MMapBinaryImportStrategy(std::string file_name);

        void open_file();
        void import_meta_data();
        void import_data();

    private:
        std::string _file_name;
        char* data;
};

#endif //MMAP_BINARY_IMPORT_STRATEGY_38EFH98WHEF9WH8FE9HW

