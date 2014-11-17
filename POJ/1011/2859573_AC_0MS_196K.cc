#include <stdio.h>
#include <stdlib.h>

int N;
int le[80], use[80], len, sum, no, found;

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

void DFS(int remain, int nu, int last_id)
{
	int i;
	if (found)
	{
		return;
	}
	if (remain == 0)
	{
		if (nu == no - 1)
		{
			printf("%d\n", len);
			found = 1;
			return;
		}
		i = 0;
		while (use[i] == 1) i++;
		use[i] = 1;
		DFS(len - le[i], nu + 1, i);
		use[i] = 0;
		return;
	}
	else
	{
		if (last_id + 1 >= N)
		{
			return;
		}
		for (i = last_id + 1; i < N; i++)
		{
			if (use[i] == 0 && le[i] <= remain)
			{
				use[i] = 1;
				DFS(remain - le[i], nu, i);
				use[i] = 0;
				if (found || le[i] == remain)
				{
					return;
				}
			}
		}
	}
}

int main()
{
	int i;
	while (scanf("%d", &N) != -1 && N > 0)
	{
		found = 0;
		for (i = 0, sum = 0, len = 0; i < N; i++)
		{
			scanf("%d", &le[i]);
			sum += le[i];
			if (le[i] > len)
			{
				len = le[i];
			}
		}
		qsort(le, N, sizeof(le[0]), cmp);
		while (len <= sum)
		{
			if (sum % len == 0)
			{
				for (i = 0; i < N; i++)
				{
					use[i] = 0;
				}
				no = sum / len;
				DFS(0, 0, 0);
			}
			if (found)
			{
				break;
			}
			len++;
		}
	}
}