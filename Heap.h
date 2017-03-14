
class Heap{
 public:
  Heap();
  ~Heap();
  void print(int i, int indent);
  void add(int newInt);
  int pop();
  int getCount();

 private:
  int size;
  int* data;
  int count;

  void bubbleDown(int i);
  void bubbleUp(int i);

};

