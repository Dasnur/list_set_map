#include <iostream>

using namespace std;

template <typename T>
class smartPointer{
    public:
	smartPointer(T* ptr) {
        ref = ptr;
		ref_count++;
	}

	smartPointer(smartPointer& ptr) {
		ref = ptr.ref;
		ref_count = ptr.ref_count;
		++ref_count;
	}

	smartPointer& operator=(smartPointer& ptr) {
		if (ref_count > 0) {
			remove();
		}
		if (this != &ptr) {
			ref = ptr.ref;
			ref_count = ptr.ref_count;
			ref_count++;
		}
		return *this;
	}

	~smartPointer() {
		remove();
	}

	T operator*() {
		return *ref;
	}

	void remove() {
		--(ref_count);
		if (ref_count == 0) {
			delete ref;
			ref = NULL;
		}
	}
private:
	T* ref;
	size_t ref_count = 0;
};