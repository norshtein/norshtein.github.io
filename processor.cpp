#include<bits/stdc++.h>

using namespace std;

int main()
{
    fprintf(stderr, "reopening...\n");
    freopen("demo.cast","r",stdin);
    freopen("demo-processed.cast","w+",stdout);

    fprintf(stderr, "processing...\n");
    char format[300];
    char items[1000][300];
    double timeStamp[10000];
    scanf("%[^\n]s",format);

    fprintf(stderr, "%s\n", format);

    int ln;
    for(ln = 0;getchar(),getchar(),scanf("%lf",timeStamp + ln) != EOF;ln++)
    {
        scanf("%[^\n]", items[ln]);
        fprintf(stderr, "[%lf%s\n",timeStamp[ln],items[ln]);
    }

    double prevTimeStamp = timeStamp[0];
    for(int i = 1;i < ln;i++)
    {
        double delta = timeStamp[i] - prevTimeStamp;
        prevTimeStamp = timeStamp[i];
        timeStamp[i] = timeStamp[i - 1] + min(delta, 2.0);
    }

    printf("%s\n",format);
    for(int i = 0;i < ln;i++)
        printf("[%lf%s\n",timeStamp[i],items[i]);

    return 0;
}
