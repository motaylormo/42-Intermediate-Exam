# Subject tests
## Test 1
```
int mine[][] = {
	{ 1, 0, 0 },
	{ 0, 3, 4 },
	{ 0, 0, 0 },
};
int n = 3;
```
correct return = 8
```
Max possible gold for each point. From the left column, 8 is max.
{
	{ 8, 4, 0 },
	{ 7, 7, 4 },
	{ 7, 4, 0 },
}
```

## Test 2
```
int mine[][] = {
	{ 1, 2, 3 },
	{ 3, 4, 8 },
	{ 9, 6, 7 },
};
int n = 3;
```
correct return = 23
```
Max possible gold for each point. From the left column, 23 is max.
{
	{ 13, 10, 3 },
	{ 17, 12, 8 },
	{ 23, 14, 7 },
}
```

## Test 3
```
int mine[][] = {
	{ 1, 3, 1, 5 },
	{ 2, 2, 4, 1 },
	{ 5, 0, 2, 3 },
	{ 0, 6, 1, 2 },
};
int n = 4;
```
correct return = 16
```
Max possible gold for each point.  From the left column, 16 is max.
{
	{ 13, 12, 6, 5 },
	{ 14, 11, 9, 1 },
	{ 16,  9, 5, 3 },
	{ 11, 11, 4, 2 },
}
```
