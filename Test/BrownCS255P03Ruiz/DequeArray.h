
template<typename T>
class DequeArray {
private:
	int size;
	int front;
	int back;
	int array;
public:

	bool isEmpty();
	int size();
	void dequeueAll();
	T* peek();
	void enqueue(T* item);
	T* dequeue();
	T* peekDeque();
	void enqueueDeque(T* item);
	T* deqeueDeque();

};
