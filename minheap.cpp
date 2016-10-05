#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return (2*i+1);
}
int parent(int i)
{
    return i/2;
}
typedef struct {
	int data;
	int ind;
}node;
void swap(int& a,int& b)
{  int tmp;
   tmp=a;
    a=b;
    b=tmp;
}

void swap(node& a,node& b)
{ node tmp;
  tmp=a;
  a=b;
  b=tmp;

}

void minheapify(node H[],int i,int n)
{
  int l=left(i);
  int r=right(i);
  int smallest=i;
  if ((l<=n)&&(H[l].data<H[i].data))
    smallest=l;
  if ((r<=n)&&(H[r].data<H[smallest].data))
    smallest=r;
  if(smallest!=i)
    {swap(H[smallest],H[i]);
      minheapify(H,smallest,n);
    }

}

void makeheap(node *H,int n){
    int i;
    for(i=n/2;i>=1;i--)
        minheapify(H,i,n);
}
node extractmin(node H[],int* l)
{   if ((*l)==0)
      { cout<<"heap underflow"<<endl;
      node ret;
      ret.data=INT_MAX;
      ret.ind=-1;
      return ret;}
     node min=H[1];
     swap(H[1],H[*l]);
     (*l)--;
     minheapify(H,1,(*l));
     return min;
}



node getmin(node *H,int n){
	return H[1];
}
void insert(node H[],int* n,node p)
{  (*n)++;
  H[*n]=p;

  int k=(*n);
  while(k>1)
    { int par=parent(k);
      if (H[k].data<H[par].data)
	swap(H[k],H[par]);
      k=parent(k);
    }

}
int main()
{
    cout<<"N\n";
    int n;
    cin>>n;
    node v[n+1];
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        v[i].data=tmp;
        v[i].ind=i;
    }
    makeheap(v,n);
    for(int i=1;i<=n;i++)
        cout<<v[i].data<<" "<<v[i].ind<<endl;
    int size=n;
}

