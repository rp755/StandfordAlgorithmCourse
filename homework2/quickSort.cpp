#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
unsigned long long calledTimes;

void saveNums();
void quickSort(int leftLimit, int rightLimit);
int pivotPartition(const int leftMostIndex, const int rightMostIndex);

int main()
{
    freopen("in.txt", "r", stdin);
    saveNums();
    quickSort(0, nums.size());
    cout << calledTimes << endl;


    cout << (is_sorted(nums.begin(), nums.end()) ? "yes" : "no") << endl;

    return 0;
}

void saveNums()
{
    int num;
    while (cin >> num)
        nums.push_back(num);
}

void quickSort(int leftLimit, int rightLimit)
{
    if ((rightLimit - leftLimit) <= 1)
        return;

    calledTimes += (rightLimit - leftLimit) - 1;
    //for the second assignment
    int temp = nums[rightLimit - 1];
    nums.erase(nums.begin() + rightLimit-1);
    nums.insert(nums.begin() + leftLimit, temp);

    int pivotPosition = pivotPartition(leftLimit, rightLimit); //  if pivot is not in the first, i could change it

    quickSort(leftLimit, pivotPosition);

    quickSort(pivotPosition + 1, rightLimit);
}

// que pasa si es la ultima pos del array
int pivotPartition(const int leftMostIndex, const int rightMostIndex)
{
    const int pivot = nums[leftMostIndex];
    int pivotEndingLocation = leftMostIndex; // to make sure that is rearenged
    for (int j = leftMostIndex + 1; j < rightMostIndex; ++j)
    {
        // im not considering an equals case
        if (nums[j] < pivot)
        {
            pivotEndingLocation += 1;
            int temp = nums[j];
            nums[j] = nums[pivotEndingLocation];
            nums[pivotEndingLocation] = temp;
        }
    }
    int temp = nums[pivotEndingLocation];
    nums[pivotEndingLocation] = pivot;
    nums[leftMostIndex] = temp;
    return pivotEndingLocation;
}