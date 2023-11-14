struct node{
  void* data;
  node *next;
};

class SList{
  private:
    int num;
  public:
    node *head;
    // Constructor
    SList();
    // Destructor
    ~SList();
    void add(void* value);
    void clear();
    bool equals(SList x);
    void* get(int index);
    void insert (int index, void* value);
    void exchg(int index1, int index2);
    void swap (int index1, int index2);
    bool isEmpty();
    void remove(int index);
    void set(int index, void* value);
    int size();
};