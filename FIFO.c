#include <stdio.h>
int n, pg[30], fr[10];
void fifo();
int main()
{
 int i;
 printf("Enter total number of pages: ");
 scanf("%d", &n);
 printf("Enter page sequence:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &pg[i]);
 }
 fifo();
 return 0;
}
void fifo()
{
 int i, f = 0, r = 0, s = 0, count = 0, flag = 0, num, psize;
 printf("Enter the size of page frame: ");
 scanf("%d", &psize);
 for (i = 0; i < psize; i++) {
 fr[i] = -1; // Initialize all frames to -1 (empty)
 }
 while (s < n)
{
 flag = 0;
 num = pg[s];
 // Check if page is already in frame
 for (i = 0; i < psize; i++)
{
 if (num == fr[i])
{
 flag = 1;
 break;
 }
 }
 // If page is not in frame, we have a page fault
 if (flag == 0)
{
 fr[f] = pg[s]; // Replace page in the FIFO order
 f = (f + 1) % psize; // Move FIFO pointer
 count++; // Increment page fault counter
 }
 s++; // Move to next page in sequence
 // Print the current page frame state
 printf("\nPage Frame: ");
 for (i = 0; i < psize; i++)
{
 if (fr[i] != -1)
{
 printf("%d ", fr[i]);
 }
else
{
 printf("- ");
 }
 }
 }
 printf("\n\nTotal Page Faults: %d\n", count);
}
