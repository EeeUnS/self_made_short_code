
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
int sorting_insertion(T a[], int num, T item)
{
		int j = num;
		while (--j >= 0 && item < a[j])
		{
			a[j + 1] = a[j];
		}
		a[++j] = item;

	return num+1;
}

