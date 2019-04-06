
### c++

swap함수는 있는걸 씁니다
swap 함수는 다음 라이브러리에 있습니다.
```
#include<utility>
```


### bubble 
```
template<typename T>
void buble_sort(T a[], int num)
{
	for (int i = 0; i < num -1; i++)
	{
		for (int j = 0; j < num - i -1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

}
```

### selection

```
template<typename T>
void buble_sort(T a[], int num)
{
	for (int i = 0; i < num -1; i++)
	{
		for (int j = 0; j < num - i -1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

```

###  selection_sort
```
template<typename T>
void selection_sort(T a[], int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int Minindex = i;
		for (int j =  i + 1 ; j < num ; j++)
		{
			if (a[j] < a[Minindex])
			{
				Minindex = j;
			}
		}
		swap(a[Minindex], a[i]);
	}
	return ;
}
```
실제 삽입을 했을때,
```

template<typename T>
void insertion_sort(T a[], int num)
{
	for (int i = 1; i < num; i++)
	{
		int remember = a[i];
		int j = i;
		while (--j >= 0 && remember < a[j]) 
		{
			a[j + 1] = a[j];
		}
		a[++j] = remember;
	}
	return;
}
```
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
