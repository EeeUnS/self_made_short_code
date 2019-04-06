
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



### merge sort
