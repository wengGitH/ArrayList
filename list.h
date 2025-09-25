class List {
    public:
        virtual ~List() = default;
        virtual void add(int num) = 0;
        virtual void removeAt(int pos) = 0;
        virtual int get(int pos) = 0;
        virtual void addAt(int num, int pos) = 0;
        virtual int remove(int num) = 0;
        // virtual void removeAll(int num) = 0;
        virtual void print() = 0;
};