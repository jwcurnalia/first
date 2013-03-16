void BubbleSort(int Array[], int n)
{
bool done = false;
int temp;

while(!done) 
     {
     done = true;

     for(int i=0; i<n-1; i++) 
        {
        if(Array[i] > Array[i+1]) 
          {
          temp = Array[i];
          Array[i] = Array[i+1];
          Array[i+1] = temp;
          done = false;
          }
        }
     }
}

void SelectSortLesser(int Array[], int n) 
{
int hold, temp;

for (int i = 0; i < n-2; i++)
    {
    hold = i;
    for (int j = 1+i; j < n; j++)
        {
        if (Array[j] < Array[hold])
           {
           hold = j;
           }
        }
    if (hold != i)
       {
       temp = Array[i];
       Array[i] = Array[hold];
       Array[hold] = temp;
       }
    }
}

//This next one may not work.

void SelectSortGreater(int Array[], int n) 
{
int hold, temp;

for (int i = n-1; i >= 0; i--)
    {
    hold = i;
    for (int j = 0; j < (n-(n-i)); j++)
        {
        if (Array[j] > Array[hold])
           {
           hold = j;
           }
        }
    if (hold != i)
       {
       temp = Array[i];
       Array[i] = Array[hold];
       Array[hold] = temp;
       }
    }
}

void EvenOddSort(int Array[], int n)
{
bool done = false;
int temp;

while(!done) 
     {
     done = true;

     for(int i=0; i<n; i+2) 
        {
        if(Array[i] > Array[i+1]) 
          {
          temp = Array[i];
          Array[i] = Array[i+1];
          Array[i+1] = temp;
          done = false;
          }
        }
     for(int i=1; i<n; i+2) 
        {
        if(Array[i] > Array[i+1]) 
          {
          temp = Array[i];
          Array[i] = Array[i+1];
          Array[i+1] = temp;
          done = false;
          }
        }
     }
}

void ShellSort(int Array[], int n)
{
int temp, interval = n/2;
bool done;

while (interval > 0)
      {
      while (!done)
            {
            done = true;
            for (int i = 0 ; i < (n-interval-1); i++)
                {
                if (Array[i] > Array[i+interval])
                   {
                   temp = Array[i];
                   Array[i] = Array[i+interval];
                   Array[i+interval] = temp;
                   done = false;
                   }
                }
            }
      interval = interval/2;
      } 
}

