#include <stdio.h>
int arr[10], bur[10], rt[10], n, pr[10], t = 0, ft[10], wt[10], tat[10], pos, total = 0, ttat = 0, twt = 0;
float avgtat, avgwt;
int main() 
{
 int comp = 0, i;
 // Input for number of processes
 printf("\nEnter the number of processes: ");
 scanf("%d", &n);
 // Input for arrival time and burst time for each process
 for (i = 0; i < n; i++)
{
 printf("\nEnter the arrival and burst time for process %d: ", i + 1);
 scanf("%d %d", &arr[i], &bur[i]);
 pr[i] = i + 1; // Process ID
 }
 // Initialize remaining time (rt) with burst time (bur)
 for (i = 0; i < n; i++)
 rt[i] = bur[i];
 // Main loop to simulate SRTF
 while (comp < n)
{
 // Finding the process with shortest remaining time that has arrived
 pos = -1; // Reset pos before each loop
 for (i = 0; i < n; i++) 
{
 if (arr[i] <= t && rt[i] > 0) 
{ // Process must have arrived and still have burst time left
 if (pos == -1 || rt[i] < rt[pos]) 
{ // First eligible process or shorter burst time
 pos = i;
 }
 }
 }
 // If no process found, move time forward
 if (pos == -1) 
{
 t++;
 continue;
 }
 // Decrease the remaining time for the selected process
 rt[pos]--;
 t++;
 // If process is completed
 if (rt[pos] == 0)
