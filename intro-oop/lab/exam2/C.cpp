#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size, time;
    cin >> time;
    for (int i = 0; i < time; i++)
    {
        cin >> size;
        int array[size];
        int subsequenceArr[size];
        int subSize = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        };
        int point = 0;
        // gettin subsequence array
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] < array[i + 1])
            {
                if (point != 1)
                {
                    subsequenceArr[subSize] = array[i];
                    subSize++;
                }
                if (point == 0)
                {
                    subsequenceArr[subSize] = array[i + 1];
                    subSize++;
                    point = 1;
                }
            }
            else
            {
                point = 0;
            }
        }
        int subArrAvg = 0, subArrSum = 0, deleteCount = 0;
        for (int i = 0; i < subSize; i++)
        {
            subArrSum = subArrSum + subsequenceArr[i];
        };
        if (subArrSum != 0)
        {
            subArrAvg = subArrSum / subSize;
            for (int i = 0; i < size; i++)
            {
                if (array[i] >= subArrAvg)
                {
                    deleteCount++;
                }
            };
        };
        cout << "subArrAvg => " << subArrAvg << endl;
        cout << deleteCount << endl;
    }

    return 0;
}
