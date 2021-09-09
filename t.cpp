/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/

/*
One hot summer day Pete and his friend Billy decided to buy a watermelon. They chose the biggest and the ripest one, in their opinion. After that the watermelon was weighed, and the scales showed w kilos. They rushed home, dying of thirst, and decided to divide the berry, however they faced a hard problem.

Pete and Billy are great fans of even numbers, that's why they want to divide the watermelon in such a way that each of the two parts weighs even number of kilos, at the same time it is not obligatory that the parts are equal. The boys are extremely tired and want to start their meal as soon as possible, that's why you should help them and find out, if they can divide the watermelon in the way they want. For sure, each of them should get a part of positive weight.
*/

#include<stdio.h>
int main()
{
    int w;
    scanf("%d", &w); // 100>=w>=1

    if (w == 2) // When weight is 2
    {
        printf("NO");   // Because 2 can't be divided into two even numbers(>0) . [ 2 = 1 + 1 ]
    }

    else if (w % 2 == 0) // When weight is an even number(>2)
    {
        printf("YES");  // Because every even number(>2) can be divided into two even numbers(>0). [ Even = Even + Even ]
    }

    else    // When weight is an odd number
    {
        printf("NO");   // Because odd number can't be divided into two even numbers. [ Odd = Even + Odd ]
    }

    return 0;
}