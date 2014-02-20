#ifndef IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE
#define IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE

#include "Meta.hpp"
#include "Relation.hpp"

#include <string>
#include <iostream>

template<typename FormatPolicy, typename MemoryMappingPolicy, typename MetaDataPolicy>
class ImportStrategy{
    public:
        ImportStrategy(std::string file_name);
        
        Meta meta() const {}
        Relation relation() const {}

    private:
        FormatPolicy _format;
        MemoryMappingPolicy _map;
        MetaDataPolicy _meta;
        std::string _file_name;
};

template<typename FormatPolicy, typename MemoryMappingPolicy, typename MetaDataPolicy>
ImportStrategy<FormatPolicy, MemoryMappingPolicy, MetaDataPolicy>::ImportStrategy(std::string file_name) : 
                                                                    _map(file_name), _file_name(file_name) {
    std::cout<<"name of file: "<<_file_name<<"\n";
    _map.open_file();
} 

#endif //IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE
