#include<iostream>
using namespace std;
double a[1000][1000],b[1000][1000],d[1000][1000]={0};;
int x(double e[1000][1000],int n);

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	x(b,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}

	int c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		b[i][i]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i][i]!=0)
		{
			for(int j=i+1;j<=n;j++)
			{
				c=a[j][i]/a[i][i];
				b[j][i]=-c;
				for(int k=i;k<=n;k++)
				{
					a[j][k]=a[j][k]-c*a[i][k];
				}
			}
		}
		else
		{
			cout<<"Error"<<endl;
			return 0;
		}
	}
	x(b,n); 
	cout<<"L="<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"U="<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	

 } 
 

 int x(double e[1000][1000],int n)
 {
	double c;
	for(int i=1;i<=n;i++)
	{
		d[i][i]=1;
	 } 
	for(int i=1;i<=n;i++)
	{
		if(e[i][i]!=0)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					c=e[j][i]/e[i][i];
					for(int k=1;k<=n;k++)
					{
						e[j][k]=e[j][k]-c*e[i][k];
						d[j][k]=d[j][k]-c*d[i][k];	
					}
					
				}
			}
		}
		else 
		if(i==n)
		{
			cout<<"Error"<<endl;
			return 0;
		}
		else
		for(int j=i+1;j<=n;j++)
		{
			if(e[j][i]!=0)
			{
			for(int k=1;k<=n;k++)
				{
					e[i][k]=e[j][k]+e[i][k];
					e[j][k]=e[i][k]-e[j][k];
					e[i][k]=e[i][k]-e[j][k];
					d[i][k]=d[j][k]+d[i][k];
					d[j][k]=d[i][k]-d[j][k];
					d[i][k]=d[i][k]-d[j][k]; 
				}
			
			i=i-1;
			break;
			}
			if(j==n)
			{
			cout<<"Error"<<endl;
			return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		c=e[i][i];
		for(int j=1;j<=n;j++)
		{
			e[i][j]=e[i][j]/c;
			d[i][j]=d[i][j]/c;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[i][j] = d [i][j];
		 } 
	
	}
 }
