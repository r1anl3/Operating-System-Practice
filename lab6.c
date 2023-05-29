#include <stdio.h>
#include <stdlib.h>


void FIFO(int string[], int frames[], int number_of_frames, int n)
{
    printf(" _____________________________________\n");
    printf("|---FIFO Page Replacement Algorithm---|\n");
    printf("|_____________________________________|\n");
    int i, j, k, available, count = 0;

	for(i = 0; i < number_of_frames; i++)
        frames[i] = -1; // Giả sử ban đầu các frame trống
    j = 0;
    printf("\t|Chuoi|\t|Khung trang");
    for(k = 0; k < number_of_frames - 1; k++)
		printf("\t");
	printf("|\n");
	for(i = 0; i < n; i++)
    {
        printf("\t|  %d  |\t", string[i]);
        available = 0; // trang không có sẵn
        for(k = 0; k < number_of_frames; k++)
            if(frames[k] == string[i]) // kiểm tra trang có sẵn
                available = 1; // trang có sẵn
        if (available == 0) // thay thế trang nếu không có sẵn
        {
            frames[j] = string[i];
            j = (j + 1) % number_of_frames;
            count++;
            printf("|");
            for(k = 0; k < number_of_frames; k++)
                printf("%d\t", frames[k]);
            printf("| *"); // Dấu hiệu nhận biết xảy ra lỗi trang
        }
        else
        {
            printf("|");
            for(k = 0; k < number_of_frames; k++)
                printf("%d\t", frames[k]);
            printf("|");
        }
        printf("\n");
	}
    printf("So trang loi la: %d\n", count);
}

void OPT(int string[], int frames[], int number_of_frames, int n)
{
    printf(" ____________________________________\n");
    printf("|---OPT Page Replacement Algorithm---|\n");
    printf("|____________________________________|\n");
    int i, j, k, available;
    int x, y, z;
    int tmp[5], count = 0;
    for (i = 0; i < number_of_frames; i++)
			frames[i] = -1; // Giả sử ban đầu các frame trống
		j = 0;
		printf("\t|Chuoi| \t|Khung trang");
		for (k = 0; k < number_of_frames - 1; k++)
			printf("\t");
		printf("| \n");
		for (i = 0; i < n; i++)
		{
			printf("\t| %d | \t", string[i]);
			available = 0; // trang không có sẵn
			for (k = 0; k < number_of_frames; k++)
				if (frames[k] == string[i]) // kiểm tra trang có sẵn
					available = 1; // trang có sẵn
			if (available == 0) // thay thế trang nếu không có sẵn
			{
				if (i <= number_of_frames)
				{
					frames[j] = string[i];
					j = (j + 1) % number_of_frames;
				}
				else
				{
					j = 0;
					for (x = 0; x < number_of_frames; x++)
						for (y = i + 1; y <= n; y++)
							if (frames[x] == string[y])
							{
								tmp[x] = y;
								y = n;
							}
					for (x = 0; x < number_of_frames; x++)
						if (tmp[x] > j)
						{
							j = tmp[x];
							z = x;
						}
					for (j = 0; j < number_of_frames; j++)
						tmp[j] = n;
					frames[z] = string[i];
				}
				count++;
				printf("|");
				for (k = 0; k < number_of_frames; k++)
					printf("%d\t", frames[k]);
				printf("| *"); // Dấu hiệu nhận biết xảy ra lỗi trang
			}
			else
			{
				printf("|");
				for (k = 0; k < number_of_frames; k++)
					printf("%d\t", frames[k]);
				printf("|");
			}
			printf("\n");
		}
		printf("So trang loi la: %d\n", count);

}

void LRU(int string[], int frames[], int number_of_frames, int n)
{
    printf(" ____________________________________\n");
    printf("|---LRU Page Replacement Algorithm---|\n");
    printf("|____________________________________|\n");
    int i, j, k, available;
    int a, b, c;
    int count = 0;
    int tmp[5];
    for (i = 0; i < number_of_frames; i++)
			frames[i] = -1; // Giả sử ban đầu các frame trống
		j = 0;
		printf("\t|Chuoi|\t|Khung trang");
		for (k = 0; k < number_of_frames - 1; k++)
			printf("\t");
		printf("| \n");
		for (i = 0; i < n; i++)
		{
			printf("\t| %d | \t", string[i]);
			available = 0; // trang không có sẵn
			for (k = 0; k < number_of_frames; k++)
				if (frames[k] == string[i]) // kiểm tra trang có sẵn
					available = 1; // trang có sẵn
			if (available == 0) // thay thế trang nếu không có sẵn
			{

				if (i <= number_of_frames)
				{
					frames[j] = string[i];
					j = (j + 1) % number_of_frames;
				}
				else
				{
					j = n;
					for (a = 0; a < number_of_frames; a++)
						for (b = i - 1; b >= 0; b--)
							if (frames[a] == string[b])
							{
								tmp[a] = b;
								b = 0;
							}
					for (a = 0; a < number_of_frames; a++)
						if (tmp[a] < j)
						{
							j = tmp[a];
							c = a;
						}
					for (j = 0; j < number_of_frames; j++)
						tmp[j] = -1;

					frames[c] = string[i];
				}
				count++;
				printf("|");
				for (k = 0; k < number_of_frames; k++)
					printf("%d\t", frames[k]);
				printf("| *"); // Dấu hiệu nhận biết xảy ra lỗi trang
			}
			else
			{
				printf("|");
				for (k = 0; k < number_of_frames; k++)
					printf("%d\t", frames[k]);
				printf("|");
			}
			printf("\n");
		}
		printf("So trang loi la: %d\n", count);

}

void Selection()
{
    int choice;
    int string[11] = {2,1,5,2,2,7,9,7,0,0,7};
    int n = 11;
    int frames[5];
    int number_of_frames = 3;

    printf("--- Page Replacement algorithm ---\n");
    printf("1. Default referenced sequence \n");
    printf("2. Manual input sequence \n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            break;

        case 2:
            printf("Input page frames: ");
            for (int i = 0; i < n; i ++)
            {
                scanf("%d", &string[i]);
            }
            break;
        
        default:
            printf("Choose again! \n");
            break;
    }

    printf("\n--- Page Replacement algorithm ---\n");
    printf("1. FIFO algorithm \n");
    printf("2. OPT algorithm \n");
    printf("3. LRU algorithm \n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            FIFO(string, frames, number_of_frames, n);
            break;

        case 2:
            OPT(string, frames, number_of_frames, n);
            break;
        
        case 3:
            LRU(string, frames, number_of_frames, n);
            break;

        default:
            printf("Choose again! \n");
            break;
    }
}

void main()
{
    while (1)
    {
        Selection();
    }
    
}