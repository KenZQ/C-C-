#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int j, int k)
{
	int tmp = arr[j];
	arr[j] = arr[k];
	arr[k] = tmp;
}

void bubble_sort(int arr[], int len)
{
	int i, j;
	int count = 0;
	int exchange = 1;
	for (i = 0; i < len && exchange; i++)
	{
		count++;
		exchange = 0;
		for (j = 0; j < len-i-1; j++)
		{
			if (arr[j+1] < arr[j])
			{
				swap(arr, j, j+1);
				exchange = 1;
			}
		}
				
	}
	printf("count == %d \n", count);
}

void select_sort(int arr[], int len)
{
	int i, j, k, count = 0;
	for (i = 0; i < len; i++)
	{
		count++;
		k = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[k] > arr[j])
				k = j;
		}
		
		if (k == i)
		{
			printf("count == %d \n", count);
			break;
		}
			
		swap(arr, i, k);
	}
}

void insert_sort(int arr[], int len)
{
	
	int i, j;
	for (i = 0; i < len; i++)
	{

		for (j = i; j > 0; j--)
		{
			if (arr[j] >= arr[j-1])
				break;
			else
				swap(arr, j, j-1);
		}
		
	}

	// for (i = 1; i < len; i++)
	// {
	// 	int k,tmp;
	// 	k = i;
	// 	tmp = arr[i];
	// 	for (j = i-1; j>0; j--)
	// 	{
	// 		if (arr[j] <= tmp)
	// 			break;
	// 		else
	// 		{
	// 			k = j;
	// 			arr[j+1] = arr[j];
	// 		}
				
	// 	}
	// 	arr[k] = tmp;
	// }

}

void shell_sort(int arr[], int len)
{
	int i = 0;
	int j= 0;
	int k = 0;
	int tmp = 0;
	int step = len;


	do 
	{
		step = step / 3 + 1;
		for (i = step; i < len; i++) 
		{
			k = i;
			tmp = arr[k];
			for (j = i-step; j >= 0; j -= step)
			{
					
				if (arr[j] <= tmp)
					break;
				else
				{
					arr[j+step] = arr[j];
					k = j;
				}
				
			}
			arr[k] = tmp;

		
		}

		
	} while(step > 1);
}

void quick_sort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int mid = arr[left];
	int left_index = left;
	int right_index = right;

	while(left_index < right_index)
	{
		while (arr[right_index] >= mid && left_index < right_index)
			right_index--;

		arr[left_index] = arr[right_index];

		while (arr[left_index] <= mid && left_index < right_index)
			left_index++;

		arr[right_index] = arr[left_index];

	}
	arr[left_index] = mid;

	quick_sort(arr, 0, left_index - 1);
	quick_sort(arr, right_index + 1, right);
	
}


void merge(int arr[], int tmp[], int left, int right, int RightEnd)
{
	int LeftEnd = right - 1;
	int l = left;
	int i;
	int len = RightEnd - left + 1;

	while (left <= LeftEnd && right <= RightEnd)
	{
		if (arr[left] <= arr[right])
			tmp[l++] = arr[left++];
		else
			tmp[l++] = arr[right++];
	}
	while (left <= LeftEnd)
		tmp[l++] = arr[left++];

	while (right <= RightEnd)
		tmp[l++] = arr[right++];

	for(i = 0; i < len; i++, RightEnd--)
        arr[RightEnd] = tmp[RightEnd];

	
}


void mSort(int arr[], int tmp[], int left, int RightEnd)
{
	int mid;
	if (left < RightEnd)
	{
		mid = (left + RightEnd) / 2;
		mSort(arr, tmp, left, mid);
		mSort(arr, tmp, mid+1, RightEnd);
		merge(arr, tmp, left, mid+1, RightEnd);
	}
	
}


void merge_sort(int arr[], int len)
{
	if (len <= 1)
		return;

	int* tmp = (int *)malloc(len * sizeof(int));
	if (tmp)
	{
		mSort(arr, tmp, 0, len-1);
		free(tmp);
	}
}




int main()
{
    int arr[] = {99, 0, 21, 0, 66, 33, 11, 0, 77, 88, 55};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i;
    // select_sort(arr, len)
    // bubble_sort(arr, len);
    // insert_sort(arr, len);

    // shell_sort(arr, len);
    // quick_sort(arr, 0, len - 1);
    merge_sort(arr, len);

    for (i = 0; i < len; i++)
    	printf("%d \n", arr[i]);

	return 0;
}