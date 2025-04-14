#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct REGISTER
{
	char fname[100];
	char lname[100];
	char u[100];                                 
	int p;
	int a;
};


REGISTER Rread();
REGISTER Rread2();
void write(REGISTER);
int max(int x,int y);

int main()
{
	int x=0,i=0,p=0,f=0,j=0,k=0,a=0;
	float m=0,z=0;
	char ch;
	
	REGISTER r[100];
	REGISTER r2[100];
	
	bool user;
	char temp[100];
		
	cout<<"Welcom!  Who are you (pls enter number)"<<endl<<"A-USER"<<endl<<"B-ADMIN"<<endl;
	cin>>ch;
	cin.ignore();
	
	if(ch=='A' || ch=='a')
	{
		cout<<"How can I help you? (pls enter number)"<<endl
		<<"1-REGISTER(2 percent initial gift)"<<endl<<"2-DEPOSIT(The fee is 1 percent)"<<endl<<"3-WITHDRAW(The fee is 1 percent)"<<endl
		<<"4-TRANSFER(The fee is 1 percent)"<<endl<<"5-GET_BALANCE(The fee is 5000 Rial)"
		<<endl<<"6-CHANGE PASSWORD(The fee is 1 percent)"<<endl<<"7-EXIT"<<endl;
		
	do
	{
		cin>>x;
		cin.ignore();
		i++;
	}while(x<1 || x>7);
	
	if(x==1)
	{
		
		do
		{

			user=false;
			
            r[i-1]=Rread();
            cin.ignore();
            
            ifstream f1("user.txt");
            

            while (f1>>temp)
			{
                if(strcmp(r[i-1].u , temp)==0) 
				{
                    user=true;
                    break;
                }
               
            }
        


            if (user==false)
			{
                
                cout << "User registered successfully!" << endl;
            }
			
			else
			{
				
                cout << "Username already exists. Please choose a different username: " << endl;
            
            }


			f1.close();
			
        }while(user==true); 
        
        	strcpy(r[i].u , temp);
        	
        	z=( r[i-1].a * 2) / 100;
			r[i-1].a+=z;
        
        	ofstream f2("user.txt" , ios :: app);
        		
         	f2 << r[i-1].fname << endl;
            f2 << r[i-1].lname << endl;
            f2 << r[i-1].u << endl;
            f2 << r[i-1].p << endl;
            f2 << r[i-1].a << endl;
            
            f2.close();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
else if(x==2)
{
		user=false;
		x=0;
		p=0;
		

	
		ifstream f3("user.txt");
	
		cout<<"Please enter username: "<<endl;
	
			cin.getline(temp,100);
	
		while(f3 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
		{
		
           if(strcmp(r[p].u , temp)==0) 
			{
                user=true;
                break;
            }
            
            p++;
            
    	}
            
   		f3.close();
			   
        if(user==false)
       	{
       		cout<<"No Such User Found!";
       		return 0;
		}
        		
        
        	cout<<"Please enter password: "<<endl;
        	cin>>x;
        	cin.ignore();
        	
    
        		
        	if(x!=r[p].p)
        	{
        		cout<<"The password is not correct!"<<endl;
      			return 0;
			}
        			
   			
   			m=0;
   			z=0;
			
			cout<<"Please enter the amount of money you want to transfer: ";
			cin>>m;
			cin.ignore();
			z=m/100;
			
			
			if(r[p].a<z)
			{
				cout<<"Not Enough Fund!";
				return 0;
			}
			
			r[p].a+=(m-z);
			
			
			ofstream f4("user.txt" , ios::app);
					
			for(j=0;j<=p;j++)
			{ 
				f4 << r[j].fname << endl;
          		f4 << r[j].lname << endl;
            	f4 << r[j].u << endl;
            	f4 << r[j].p << endl;
            	f4 << r[j].a << endl;
        	}
				
			cout<<"The deposit was made successfully"<<endl<<"your amount is: "<<r[p].a;
					
			f4.close();
        
		
		
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
else if(x==3)
	{
		user=false;
		x=0;
		p=0;
		m=0;
		z=0;
		
		
		ifstream f5("user.txt");
				
		cout<<"Please enter username: "<<endl;
	
		cin.getline(temp,100);
		
		while(f5 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
		{
			
			if(strcmp(r[p].u , temp)==0) 
			{
                user=true;
                break;
            }
            
            p++;	
			
    	}
            
		f5.close();
               
        if(user==false)
       	{
       		cout<<"No Such User Found!";
       		return 0;
		}
        		
        
        	cout<<"Please enter password: "<<endl;
        	cin>>x;
        	cin.ignore();
        		
        	if(x!=r[p].p)
        	{
        		cout<<"The password is not correct!"<<endl;
      			return 0;
			}
        			
   
			
			cout<<"Please enter the amount of money you want to transfer: ";
			cin>>m;
			cin.ignore();
			
			z=m/100;
			
			if(r[p].a<(m+z))
			{
				cout<<"Not Enough Fund!"<<endl;
				return 0;
			}
			
			r[p].a-=(m-z);
			
			ofstream f6("user.txt" , ios::app);
					
			for (j=0;j<=p;j++)
			{ 
				f6 << r[j].fname << endl;
          		f6 << r[j].lname << endl;
            	f6 << r[j].u << endl;
          		f6 << r[j].p << endl;
            	f6 << r[j].a << endl;
        	}
				
			cout<<"The deposit was made successfully"<<endl<<"your amount is: "<<r[p].a;
					
			f6.close();
        
		
	
		
}
////////////////////////////////////////////////////////////////////////////////////////////////////
else if(x==4)
{
	user=false;
	x=0;
	p=0;
	z=0;
	m=0;
		
		
	ifstream f7("user.txt");
				
	cout<<"Please enter username: "<<endl;
	
	cin.getline(temp,100);
		
	while(f7 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
	{
		if(strcmp(r[p].u , temp)==0) 
		{
            user=true;
            break;
        }
            
        p++;	
		
    }
            
    f7.close();
               
    if(user==false)
    {
       	cout<<"No Such User Found!";
       	return 0;
	}
        		
        
        cout<<"Please enter password: "<<endl;
        cin>>x;
        cin.ignore();
        		
        if(x!=r[p].p)
        {
        	cout<<"The password is not correct!"<<endl;
      		return 0;
		}
        		
					
		cout<<"Please enter Destination username: "<<endl;
					
		f=0;
		user=false;
		x=0;
	
					
		cin>>temp;
					
		ifstream f8("user.txt");
		
		while(f8 >> r[f].fname >> r[f].lname >> r[f].u >> r[f].p >> r[f].a)
		{
				
			if(strcmp(r[f].u , temp)==0) 
			{
                user=true;
                break;
            }
            
            f++;
       	
    	}
					
		f8.close();
					
		if(user==false)
    	{
      		cout<<"No Such User Found!";
      		return 0;
		}
					
					
		cout<<"Please enter the required amount of money to transfer: "<<endl;
		cin>>m;
		cin.ignore();
					
		if(m>3000000)
		{
			cout<<"Maximum Amount Exceeded!";
			return 0;
		}
						
		z=m/100;	
						
		r[p].a-=(m+z);
		r[f].a+=m;
					
		cout<<"SENDER_USERNAME"<<endl<<"Your amount is: "<<r[p].a<<endl;
					
			
		ofstream f9("user.txt" , ios::app);
		
		a=max(p,f);
					
		for(j=0;j<=a;j++)
		{ 
  			f9 << r[j].fname << endl;
            f9 << r[j].lname << endl;
            f9 << r[j].u << endl;
            f9 << r[j].p << endl;
            f9 << r[j].a << endl;
        }

					
		f9.close();
		
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////	
else if(x==5)
{
	user=false;
	x=0;
	p=0;

		
	ifstream f10("user.txt");
				
	cout<<"Please enter username: "<<endl;
	
	cin.getline(temp,100);
		
	while(f10 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
	{
				
		if(strcmp(r[p].u , temp)==0) 
		{
            user=true;
            break;
        }
            
            
        p++;
    }
            
    f10.close();
               
    if(user==false)
    {
       	cout<<"No Such User Found!";
       	return 0;
	}
        		
        
        cout<<"Please enter password: "<<endl;
        cin>>x;
        cin.ignore();
        		
        if(x!=r[p].p)
        {
        	cout<<"The password is not correct!"<<endl;
      		return 0;
		}
        		
				
		else
		{
			if(r[p].a>5000)
			{
				r[p].a-=5000;
					
			}
				
	
			else
			{
					cout<<"Not Enough Fund!";
					return 0;
			}
			
		}	
   

			
		ofstream f11("user.txt" , ios::app);
					
		for (j=0;j<=p;j++)
		{ 
 			f11 << r[j].fname << endl;
            f11 << r[j].lname << endl;
            f11 << r[j].u << endl;
            f11 << r[j].p << endl;
            f11 << r[j].a << endl;
        }
				
		cout<<"The deposit was made successfully"<<endl<<"Your amount is: "<<r[p].a;
					
		f11.close();
		
}

//////////////////////////////////////////////////////////////////////////////////////////////////////	
else if(x==6)
{
	user=false;
	x=0;
	p=0;
		
	ifstream f12("user.txt");
				
	cout<<"Please enter username: "<<endl;
	
	cin.getline(temp,100);
		
	while(f12 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
	{
				
		if(strcmp(r[p].u , temp)==0) 
		{
            user=true;
            break;
        }
            	 
        p++;
    }
            
    f12.close();
               
    if(user==false)
    {
       	cout<<"No Such User Found!";
       	return 0;
	}
        		
        
        cout<<"Please enter password: "<<endl;
        cin>>x;
        cin.ignore();
        		
        if(x!=r[p].p)
        {
        	cout<<"The password is not correct!"<<endl;
      		return 0;
		}
        		
		z= r[p].a / 100;	
	
	
		if(r[p].a>z)
				r[p].a-=z;
				
		else
		{
			cout<<"Not Enough Fund!";
			return 0;
		}
			
   		
   		cout<<"Enter your new password: "<<endl;
   		cin>>x;
   		cin.ignore();
   		
   		r[p].p=x;

			
		ofstream f13("user.txt" , ios::app);
					
		for (j=0;j<=p;j++)
		{ 
			f13 << r[j].fname << endl;
            f13 << r[j].lname << endl;
            f13 << r[j].u << endl;
            f13 << r[j].p << endl;
            f13 << r[j].a << endl;
        }
				
					
		f13.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

	
	else
		return (0);

	
}                                          //a

	else if(ch=='B' || ch=='b')
	{
		x=0;
		k=0;
		
		cout<<"How can I help you? (pls enter number)"<<endl
		<<"1-REGISTER"<<endl<<"2-VIEW USER INFORMATION"<<endl;
	
		
		do
		{
			cin>>x;
			cin.ignore();
			k++;
		}while(x<1 || x>2);
		
		
		if(x==1)
		{
			user=false;
			x=0;
			p=0;
			
			do
			{

				user=false;
           		r2[k-1]=Rread2();
           		cin.ignore();
            
            	ifstream f14("admin.txt");
            

            	while (f14>>temp)
				{

        			if(strcmp(r2[k-1].u , temp)==0)
					{
                    	user=true;
                   		break;
                	}
                
            	}
        


            	if (user==false)
                	cout << "User registered successfully!" << endl;
      
			
				else
              		cout << "Username already exists. Please choose a different username: " << endl;
   


				f14.close();
			
        	}while(user==true); 
        
        
 		strcpy(r2[k].u , temp);
        	
        
        ofstream f15("admin.txt" , ios :: app);
        
        f15<<r2[k-1].fname<<endl;
        f15<<r2[k-1].lname<<endl;
        f15<<r2[k-1].u<<endl;
        f15<<r2[k-1].p<<endl;
    
            
        f15.close();
        
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		
	else if(x==2)
	{
		user=false;
		x=0;
		p=0;
		
		
		ifstream f16("admin.txt");
		
		cout<<"Please enter username: "<<endl;
	
		cin.getline(temp,100);
		
		while(f16 >> r2[p].fname >> r2[p].lname >> r2[p].u >> r2[p].p)
		{
				
			if(strcmp(r2[p].u , temp)==0) 
			{
                user=true;
                break;
            }
            
        	p++;
   		}
            
               
               
   		if(user==false)
   		{
       		cout<<"No Such User Found!";
       		return 0;
		}
        		
        
        cout<<"Please enter password: "<<endl;
        cin>>x;
        cin.ignore();
        		
        if(x!=r2[p].p)
        {
        	cout<<"The password is not correct!"<<endl;
      		return 0;
		}
		
		
		   	f16.close();
		ifstream f17("user.txt");
		
		while(f17 >> r[p].fname >> r[p].lname >> r[p].u >> r[p].p >> r[p].a)
		{
            write(r[p]);
       		p++;
       		 
  		}
  		
  		f17.close();
  		
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////      
      
      
	}                                      ///b



	return 0;
}                                          ///main
////////////////////////////////////////////////////////////////////////////////////////////////////////
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
REGISTER Rread()
{
	REGISTER r;
	
	cout<<"Please enter first name: ";
	cin.getline(r.fname,100);

	
	cout<<"Please enter last name: ";
	cin.getline(r.lname,100);

		
	cout<<"Please enter user name: ";
	cin.getline(r.u,100);
	
	
	cout<<"Please enter password: ";
	cin>>r.p;
	cin.ignore();
		
	
	cout<<"Please enter amout (Rial): ";
	cin>>r.a;
	cin.ignore();
			
	cout<<endl;	
	
	return r;
}

REGISTER Rread2()
{
	REGISTER r;
	
	cout<<"Please enter first name: ";
	cin.getline(r.fname,100);

	
	cout<<"Please enter last name: ";
	cin.getline(r.lname,100);

		
	cout<<"Please enter user name: ";
	cin.getline(r.u,100);
	
	
	cout<<"Please enter password: ";
	cin>>r.p;
	cin.ignore();
		

			
	cout<<endl;	
	
	return r;
}




void write(REGISTER r) 
{

	cout<<"First name: "<<r.fname<<endl;

	cout<<"Last name: "<<r.lname<<endl;

	cout<<"User name: "<<r.u<<endl;
	
	cout<<"Password: "<<r.p<<endl;
		
	cout<<"Amout: "<<r.a<<endl;

			
	cout<<endl;	
}


