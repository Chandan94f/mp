/*g++ -o BTP -fopenmp BTP.cpp */

#include <omp.h>
#include<bits/stdc++.h>
using namespace std;


#define SIZE_TEXT 16384
#define SIZE_pattern 2064

int total_count=0;
char TEXT[SIZE_TEXT];
char pattern[SIZE_pattern];

int n,m;
int Left[17][100000];
int WITNESS[] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,277,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
bool MATCH[SIZE_TEXT]; 

int mxk;
int ck=1;


//Left Find
int Lt(int k , int a)
{	
    if(k == 0)
    {
        Left[k][a] = a;
        return Left[k][a]=a;
    }   

	int start = pow(2,k) * (a-1) +1 ; // K=1 ,A =1 , start = 1 ,end=2   
	int end = pow(2,k)*(a);
	for(int i = start; i <= min(end,n); i++)
	{
		if(MATCH[i] == true )
		{		
			return i;
		}
	}

	return 0;
}

void BOX3(int k,int last)
{   
    #pragma omp parallel
    {
        #pragma omp for 
            for(int a=1; a<= last;a++)
            {	
                int ltk = Lt(k-1,2*a-1) ;
                int rtk = Lt(k-1,2*a);
                if(ltk == 0)
                {	
                    Left[k][a]=rtk;
                }
                else if (rtk == 0)
                {	
                    Left[k][a] = ltk;
                }
                else{	
                        
                        int j1 = Lt(k-1, 2*a);  //j1 //rtk
                        int j2 = Lt(k-1, 2*a-1); //j2 // ltk
                        int w = WITNESS[j1-j2+1];
                        char x = pattern[w];
                        char y = pattern[j1-j2+w];
                        char z = TEXT[j1-1+w];


                        if(z != y)
                        {
                            MATCH[j2] = false;
                        }

                        if( x != z)
                        {
                            MATCH[j1] = false;
                        }

                        if(MATCH[j2] == true)
                        {
                            Left[k][a] = j2;
                        }
                        else if(MATCH[j1] == true)
                        {
                            Left[k][a]=j1;
                        }
                        else{
                            Left[k][a] = 0;
                        }
                }
        }
    }
}

void step3()
{

    int num = (n-m+1);
    int denom = pow(2,floor(log2(m))-1);
    int end = num/denom;
    if(num%denom)
    {
        end ++;
    }


     for(int kk=1;kk<=n-m+1;kk++)
     {  
        
        if(MATCH[kk])
        {
            #pragma omp parallel
            {
                #pragma omp for 
                    for(int j=1;j<=end;j++)
                    {
                        #pragma omp parallel
                        {
                            #pragma omp for
                                for(int i=1 ; i<=m; i++)
                                {
                                    
                                    int lgm = floor(log2(m))-1;
                                    int tj=Left[lgm][j];
                                    
                                    if(tj != 0)
                                    {
                                        
                                        if(TEXT[tj+i-1] != pattern[i])
                                        {
                                            MATCH[tj]=false;
                                        }
                                    }
                                }
                        }
                    }
            }    
        }
     }

}


void Runner()
{
    
    // cout<<TEXT<<endl;

    // cout << "\n\n";
    // cout<<pattern<<endl;
    // cout << "\n\n";
    
    cout<<n<<endl;
    cout<<m<<endl;
    memset(Left,0,sizeof(Left));
    memset(MATCH,0,sizeof(MATCH));
    #pragma omp parallel
	{
		#pragma omp for 
		for(int i=1;i<=n-m+1;i++)
		{
			MATCH[i] = true;
		}
	}
    

	for(int k=1;k<=mxk;k++)
	{   
        int last = (n-m+1)/(1<<k);
        if((n-m+1) % (1<<k))
        {
            last++;
        }
        // printf("%lf calci\n", (n-m+1)/pow(2,k));
        // printf("%d , %d, %d, %lf last\n\n",k,last, n-m+1, pow(2,k));
		BOX3(k,last);

	}


    step3();

    int count=0;

    for(int i=1;i<=n-m+1;i++)
    {   
        if(MATCH[i])
        {   
            count++;
            total_count++;
            // string pt ="";
            // for(int j =i;j<i+m;j++)
            // {
            //     pt+= TEXT[j];
            // }
            printf("MATCH[%d]:= %d \n",i,MATCH[i]);
            // cout<<pt<<"\n";
        }
    }

    cout<<"Found : "<<count<<endl;

}


int main()
{   

    int count=0;

    fstream T_Read;
    fstream P_Read;
    T_Read.open("input_text.txt",ios::in);
    P_Read.open("input_pattern.txt",ios::in);

    memset(Left,0,sizeof(Left));
    memset(MATCH,false,sizeof(MATCH));

    if(!P_Read || !T_Read)
    {
        cout<<"Error while Reading  File \n";
    }
    else
    {
        
        pattern[0]= '#';
        TEXT[0] ='#';

        P_Read.read((char *)&pattern[1],sizeof(pattern)-2); // reading input pattern.
        
        string TEMP_PATTERN = pattern;
        m =TEMP_PATTERN.size()-1;
        mxk = log2(m)-1;

        // T_Read.read((char *)&TEXT[1],sizeof(TEXT)-1);
        while(T_Read.read((char *)&TEXT[1],sizeof(TEXT)-2)) // reading input text;
        {
            count++;
            printf("Reading %d \n",count);
            
            string TEMP_TEXT = TEXT;
            n = TEMP_TEXT.size() -1;
            Runner();

            
            memset(MATCH,0,sizeof(MATCH));
            memset(TEXT,0,sizeof(TEXT));
            TEXT[0]='#';
        }
        string TEMP_TEXT = TEXT;
        n = TEMP_TEXT.size() -1;
        Runner();

    }

    cout<<"Total Count Found :"<<total_count<<endl;

    return 0;
}