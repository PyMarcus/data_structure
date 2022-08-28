
typedef struct queue{
    int queue[10];
    int header;
    int tail;
}queue;


void add(int value);

int pop();

int clear();

void print();
