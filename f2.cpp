/*g++ -o BTP1 -fopenmp BTP1.cpp */
#include <omp.h>
#include<bits/stdc++.h>
using namespace std;

int WITNESS[100];
string pattern = "#aaaaaaaaaabaaabaaaaaaaaaaaaaaaaaaa";
const int m = pattern.size()-1;
const int kmax = 5; 
int ck = 1;
int PERIODICITY[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int Left [6][17] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31},
    {0,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
	

void BOX2();
void BOX3();
void BOX4();
void BOX5();
void terminal();



void BOX2()
{		
		printf("Box2 -> %d \n",ck);
       
		if(ck > kmax)
		{
			terminal();
		}

		if(Left[ck][2] != 0)
		{	
			int x  = Left[ck][2];
			int to = pow(2,ck+2) - x +1;
			#pragma omp parallel
			{
				#pragma omp for 
				for(int j=1;j<= to;j++)
				{	
					if(pattern[j] != pattern[x-1+j])
					{
						WITNESS[x] = j;
					}
				}
			}
			if(WITNESS[x] == 0)
			{
				PERIODICITY[ck+1] = x-1;
                  
			}
            ck = ck+2;
            BOX4();
			
		}else{
			BOX3();
		}

}

void BOX3()
{			
			printf("Box3 -> %d \n",ck);
            if(ck > kmax)
		    {
			    terminal();
		    }

			int to = ceil(32/pow(2,ck+1));
			#pragma omp parallel
			{
				#pragma omp for 
				for(int a=2; a<= to;a++)
				{
					if(Left[ck][2*a] == 0)
					{	
						Left[ck+1][a] = Left[ck][2*a-1];
					}
					else if (Left[ck][2*a - 1] == 0)
					{
						Left[ck+1][a] = Left[ck][2*a];
					}
					else{
							int j1 = Left[ck][2*a];
							int j2 = Left[ck][2*a-1];
							int w = WITNESS[j1-j2+1];
							char x = pattern[w];
							char y = pattern[j1-j2+w];
							char z = pattern[j1-1+w];
							cout<<j1<<" "<<j2<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl;
							//if z !=y
                            if(z != y)
                            {
                                WITNESS[j2] = j1 -j2 +w;
                            }

							// if z!=x
							if( x != z)
							{
								WITNESS[j1] = w;
							}

							if(WITNESS[j2] == 0)
							{
								Left[ck+1][a] = j2;
							}
							else if(WITNESS[j1] == 0)
							{
								Left[ck+1][a]=j1;
							}
							else{
								Left[ck+1][a] = -1;
							}
					}
				}
			}

			BOX2();
}

void BOX4()
{   	
	printf("Box4 -> %d \n",ck);
	if(ck > kmax)
	{
			terminal();
	}
	int P = PERIODICITY[ck];
	int p2k= pow(2,ck);
	int p2k1 = pow(2,ck+1);
	int p2k2 = pow(2,ck+2);
	#pragma omp parallel
	{
		#pragma omp for 
			for(int j=p2k+1;j<=p2k1;j++)
			{
				if(WITNESS[j] == 0 && (j %P)!= 1)
				{
					int w = WITNESS[j%P];
					// string temp = pattern.substr(j-1+w);
					// int pl = temp.size();
					if(pattern[w] != pattern[j-1+w] )
					{
						WITNESS[j] = w;
					}
				}
			}
	}
	
	#pragma omp parallel
	{
		#pragma omp for 
			for(int j=p2k1+1;j<=p2k2;j++)
			{	
				// string temp = pattern.substr(j%P);
				// int pl = temp.size();
				if( pattern[j] != pattern[j%P]  )
				{
					WITNESS[P+1] = j-P;
				}
			}
	}
	if(WITNESS[P+1] == 0)
	{
		ck = ck+2;
		BOX4();
	}
	else{
		#pragma omp parallel
		{
		    #pragma omp for 
			for(int j=2;j<=(p2k1-1)/P;j++)
			{	
				WITNESS[j*P +1] = WITNESS[P+1] - (j-1)*P; 
			}
		}
	}
	for(int i= pow(2,ck)+1 ; i<= pow(2,ck+1);i++)
	{
		if(WITNESS[i] == 0)
		{
			#pragma omp parallel
			{
				#pragma omp for 
				for(int j=1;j<=p2k2-i+1;j++)
				{	
					// string temp = pattern.substr(i-1+j);
					// int pl = temp.size();
					if(pattern[j] != pattern[i-1+j])
					{
						WITNESS[i] = j;
					}
				}
			}
		}
		if(WITNESS[i] == 0)
		{
			PERIODICITY[ck+1] = i-1;
		}
	}

	BOX5();
}

void BOX5()
{	
	printf("Box5 -> %d \n",ck);
    if(ck > kmax)
	{
			terminal();
	}

	if(PERIODICITY[ck+1] != -1)
	{
		ck= ck+2;
		BOX4();
	}
	else{
        ck = ck+1;
		BOX3();
	}
}

void terminal()
{	// Periodicity of whole pattern;
	printf("terminal \n");
	int  P = PERIODICITY[4];
	#pragma omp parallel
	{
		#pragma omp for 
		for(int j=pow(2,3);j<=32;j++)
		 {	
			// string temp = pattern.substr(j%P);
			// int pl = temp.size();
			if(pattern[j] == pattern[j%P])
			{
				WITNESS[P+1] = j-P;
			}
		 }				
	}

	if(WITNESS[P+1] != 0)
	{
		#pragma omp parallel
		{
			#pragma omp for 
			for(int j=2;j<=(P+WITNESS[P+1])/P;j++)
		 	{	
				WITNESS[j*P+1] = WITNESS[P+1]-(j-1)*P;
				if(WITNESS[P+1] + P <= (m/2)+1)
				{
					if(PERIODICITY[3] != -1 ) // logm-2 sparsity;
					{
						ck= 4;
						BOX4();
					}
					else{
                        ck = ck+1;
						BOX3();
					}	
				}
		 	}				
		}
	}
	if(WITNESS[P+1] == 0 || WITNESS[P+1]+P > (m/2)+1)
	{
		#pragma omp parallel
		{
			#pragma omp for 
			for(int j=pow(2,3);j<=(m/2)+1;j++) // log[m]-2
		 	{		
				int x = WITNESS[(j-1) % P] ;
				int y = j-1 + x;

				// string f = pattern.substr(x);
				// string s = pattern.substr(y);
				// int ls = s.size();
				if(WITNESS[j] == 0 && j%P != 1 && pattern[x] != pattern[y]  )
				{
					WITNESS[j] = x;
				}

		 	}				
		}
	}
}

int main(int argc, char* argv[])
{

   
	
	// Beginning of parallel region
	#pragma omp parallel
	{
		#pragma omp for 
		for(int i=1;i<pattern.size();i++)
		{
			WITNESS[i] = 0;
		}
	}

	char s1 = pattern[1];
	char s2 = pattern[2];

	// string s1 = "a";
	// string s2 = "a";

	// cout<<s1<<" "<<s2<<endl; pattern(1) , pattern(2)

	if(s1 != s2)
	{
		cout<<"Not Matched"<<endl;
		BOX2();
	}
	else{
		cout<<"Matched"<<endl;
		BOX4();
	}

	for(int i=2;i<=(32/2)+1;i++)
	{
		cout<<"WITNESS of "<<i <<": "<<WITNESS[i]<<endl;
	}

    cout<<"-----------"<<endl;
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=32;j++)
        {
            cout<<Left[i][j]<<" ";
        }
        cout<<endl;
    }

	return 0;
}