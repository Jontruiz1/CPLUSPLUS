


template <typename T>
class CustomVector {

private:
	int size;
	int capacity;
	int back;
	T* vector;

public:
	CustomVector(int c) {
		vector = new T[c];
		size = 0;
		capacity = c;
		back = 0;
	}
	~CustomVector() {
		delete[] vector;
	}

	template <typename T>
	void pushToBack(T element) {
		if (back > capacity) {
			++capacity;
		}
		vector[back] = element;
		++size;
		back++;

	}

	void popFromBack() {

	}


	void pushToRandom() {

	}

	void remFromRandom() {

	}

	void output() {

	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	T getElement(int i) {
		return vector[i];
	}

};