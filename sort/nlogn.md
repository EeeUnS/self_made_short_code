

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
