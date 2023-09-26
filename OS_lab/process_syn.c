#include<stdio.h>
#define BUFFER_SIZE 5
int count=0;
void producer()
{
    while (true)
    {
        /* produce an item in next produced */
        while (count == BUFFER_SIZE) ;
        /* do nothing */
        bs[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
        count++;
    }
}
void consumer()
{
    while (true)
    {
        while (counter == 0); /* do nothing */
        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        counter--;
        /* consume the item in next consumed */
    }
}
int main()
{
    int bs[5],n,in=0;

    return 0;
}
