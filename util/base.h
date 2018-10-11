
#ifndef _H_UTIL_BASE

template <class T>
void swap(T &a, T &b) {
	T temp = b;
	b = a;
	a = temp;
}

#endif
