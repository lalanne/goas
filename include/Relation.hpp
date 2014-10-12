#ifndef RELATION_Q9HF9QWHEF98WHEF9
#define RELATION_Q9HF9QWHEF98WHEF9

#include "Meta.hpp"
#include "Record.hpp"

#include <vector>
#include <string>

//class Record;

class Relation{
    public:
        void add_record(Record rec);
        Meta get_meta();
        void print() const;
        void set_size();
        void project(std::vector<unsigned int>& indexes);
        void erase(std::vector<std::string>& predicates);

    private:
        std::vector<Record> records;
        Meta meta;
        std::vector<std::string> predicates;
};

#endif //RELATION_Q9HF9QWHEF98WHEF9
