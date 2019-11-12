int	find_pivot(int *arr, int n)
{
	int left = 0;
	int right = 0;
	for (int i = 1; i < n; ++i)
		right += arr[i];

	for (int i = 0; i < n; ++i)
	{
		if (left == right)
			return (i);
		right -= arr[i + 1];
		left += arr[i];
	}
	return (-1);
}
