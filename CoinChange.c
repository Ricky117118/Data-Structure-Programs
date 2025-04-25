#include <stdio.h>
void findMinCoins(int coins[], int n, int amount) 
{
    int i, j, k = 0, temp, count = 0;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
	{
            if (coins[j] < coins[j+1]) 
	    {
                temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }
    printf("Coins used: ");
    for (i = 0; i < n; i++) 
    {
	j=0;
        while (amount >= coins[i]) 
	{
            amount -= coins[i];
	    j++;
            count++;
        }
	if(j)
	    k++?printf(", %d x %d ", coins[i],j):printf("%d x %d ", coins[i],j);
    }
    if(amount)
	printf("\nRemaining amount: Rs. %d", amount);
    printf("\nNumber of coins used: %d\n", count);
}
int main() 
{
    int n = 0, i, amount, coins[100];
    printf("Enter the denominations available (0 to exit) : ");
    do
    {
	scanf("%d", &i);
	if(!i)
	    break;
	coins[n++]=i;
    }
    while(1);
    printf("Enter the amount: ");
    scanf("%d", &amount);
    findMinCoins(coins, n, amount);
    return 0;
}
