#ifndef IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE
#define IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE

class ImportStrategy{
    public:
        virtual void open_file() = 0;
        virtual void import_meta_data() = 0;
        virtual void import_data() = 0;
};

#endif //IMPORT_STRATEGY_9Q87HE9Q8HE9F8HWE