
template<typename T>void push_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1]{};
	/*for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}*/

	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i];
	}

	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;
	arr = buffer;
	arr[m] = new T[n]{};
	m++;
}
template<typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
}
template<typename T>void insert_row(T**& arr, int& m, const int n, const int index) {
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[n]{};
	m++;
}
template<typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
template<typename T>void pop_row_front(T**& arr, int& m, const int n) {
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>void erase_row(T**& arr, int& m, const int n, const int index) {
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++) {
		if (i < index)
			buffer[i] = arr[i];
		else
			buffer[i] = arr[i + 1];
	}
}
template<typename T>void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}