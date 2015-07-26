#include <cstdio>
#include <string>

using namespace std;

int n;
bool isBST(int Arr[],const int &Index,const int &cmpValue,const bool &isOnLeft)
{
  if(Index!=0) {
    bool f=(Index%2 && Arr[Index]>=Arr[(Index-1)/2]);
    bool s=(Index%2==0 && Arr[Index]<=Arr[(Index-1)/2]);
    bool r=(isOnLeft && Arr[Index]>=cmpValue) || (!isOnLeft && Arr[Index]<=cmpValue);
    if(f || s || r)
      return false;
  }

  int leftChild=Index*2+1;
  int rightChild=Index*2+2;
  if(leftChild<n && Arr[leftChild]>0) { // if there is left child
    if(Arr[leftChild]>Arr[Index] ||
       isBST(Arr,leftChild,cmpValue,isOnLeft)==false ||
       isBST(Arr,leftChild,Arr[Index],true)==false)
      return false;
    }
  if(rightChild<n && Arr[rightChild]>0) { // if there is left child
    if(Arr[rightChild]<Arr[Index] ||
       isBST(Arr,rightChild,cmpValue,isOnLeft)==false ||
       isBST(Arr,rightChild,Arr[Index],false)==false)
      return false;
    }

  return true;
}

int main()
{
  scanf("%d",&n);
  if(n<=0)
    return 0;

  int *Arr = new int[n];
  for(int i=0;i<n;i++)
    scanf("%d",&Arr[i]);

  if(n==1 || (isBST(Arr,1,Arr[0],true) && isBST(Arr,2,Arr[0],false)))
    printf("YES");
  else
    printf("NO");

  return 0;
}
