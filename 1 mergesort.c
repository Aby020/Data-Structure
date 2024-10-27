# include<stdio.h>
void main()
{
    int arr1[10],arr2[10],n,m,temp,i;
    printf("Enter the size of array 1\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            
            }
        }

    }
    printf("sorted array1 elements are\n");
    for(i=0;i<n;i++)
    {
    printf("%d\n",arr1[i]);
    }


    printf("Enter the size of array 2\n");
    scanf("%d",&m);
    printf("Enter the elements\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<m;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(arr2[j]>arr2[j+1])
            {
                temp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=temp;
            
            }
        }

    }
    printf("sorted array2 elements are\n");
    for(i=0;i<m;i++)
    {
    printf("%d\n",arr2[i]);
    }

    int merge[n+m];
    for(i=0;i<n;i++)
    {
        merge[i]=arr1[i];
    }
    for(i=0;i<m;i++)
    {
        merge[n+i]=arr2[i];
    }
    for(i=0;i<n+m;i++)
    {
        for(int j=0;j<n+m-1;j++)
        {
            if(merge[j]>merge[j+1])
            {
                temp=merge[j];
                merge[j]=merge[j+1];
                merge[j+1]=temp;
            }
        }
    }
    printf("Merged array elements\n");
    for(i=0;i<n+m;i++)
    {
        printf("%d\n",merge[i]);

    }

}