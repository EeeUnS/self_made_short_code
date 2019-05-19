

### merge sort
```
template<typename T>
void mergesort(T a[], int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = (low + high) / 2;
		mergesort(a, low, pivot);
		mergesort(a, pivot + 1, high);

		int i = low, j = pivot + 1;
		queue<int>arr;

		while ((i <= pivot) && (j <= high))
		{
			if (a[i] <= a[j])
			{
				arr.push(a[i]);
				i++;
			}
			else
			{
				arr.push(a[j]);
				j++;
			}
		}

		while (i <= pivot)
		{
			arr.push(a[i]);
			i++;
		}

		while (j <= high)
		{
			arr.push(a[j]);
			j++;
		}

		for (int i = low; i <= high; i++)
		{
			a[i] = arr.front();
			arr.pop();
		}
	}
}
``` 

### quick sort

```

template<typename T>
void quicksort(T A[], int start, int end)
{
	if (start < end)
	{
		int x = A[end];
		int i = start - 1;

		for (int j = start; j < end - 1; j++)
		{
			if (A[j] <= x)
			{
				i++;
				swap(A[i], A[j]);
			}
		}
		swap(A[i + 1], A[end]);
		int q = i + 1;
		quicksort(A, start, q - 1);
		quicksort(A, q + 1, end);
	}
	return;
}

```
### shell sort 
삽입 정렬의 응용판
h = 3h' +1

```

template<typename T>
void shell_sort(T a[], int num)
{
    int h =1;

    while(h < num/2)
    {
        h = 3*h+1;
    }
    while(h > 1)
    {
        h = h/3;

        for (int i = h ; i < num ; i++ )
        {
            T item = a[i];
            int j = i-h ;
            while (j >= 0 && item < a[j])
            {
                a[j + h] = a[j];
                j = j-h;
            }
            a[j + h] = item;
        }
    }
}

```

### HEAP SORT
parent는 실제로 사용하지는 않음
실제 과정은 MAX_HEAPIFY와HEAPSORT 두개로 나타낼수있음

```
int parent(int i)
{
	return i / 2;
}

int left(int i)
{
	return 2 * i;
}


int right(int i)
{
	return 2 * i + 1;
}

void MAX_HEAPIFY(int A[], int i, int heapsize) //I인덱스의 노드가 자식 노드보다 작을 때 이를 밑으로 내려 힙트리 구조를 만든다 
{
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= heapsize && A[l] > A[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heapsize && A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(A[i], A[largest]);
		MAX_HEAPIFY(A, largest, heapsize);
	}
}

void BUILD_MAX_HEAP(int A[], int n) //전체 배열을 힙트리로 나타내기 위한 함수
{
	int heapsize = n;
	for (int i = n / 2; i >= 1; i--)
	{
		MAX_HEAPIFY(A, i, heapsize);
	}
}

void HEAPSORT(int A[], int size)
{
	int* B = A - 1;//C에 맞게 인덱스값을 하나씩 내린다
	BUILD_MAX_HEAP(B, size);
	int heapsize = size;
	for (int i = size; i > 0; i--) 
	{
		swap(B[1], B[i]);
		heapsize--;
		MAX_HEAPIFY(B, 1, heapsize);

	}
}
```

### COUNTING SORT
persude code
```
COUNTING-SORT.A;B; k/
1 letCOE0: : k be a new array
2 for i D 0 to k
3 COEi D 0
4 for j D 1 to A:length
5 COEAOEj  D COEAOEj  C 1
6 // COEi now contains the number of elements equal to i .
7 for i D 1 to k
8 COEi D COEi C COEi  1
9 // COEi now contains the number of elements less than or equal to i .
10 for j D A:length downto 1
11 BOEC OEAOEj  D AOEj 
12 COEAOEj  D COEAOEj   1
```
