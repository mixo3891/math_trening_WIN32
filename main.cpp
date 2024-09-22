#include <iostream>
#include"Console.h"
#include<cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



#define DEF_INTERVAL_MAX	20
#define DEF_INTERVAL_MIN	0
#define DEF_SIGN	0
#define DEF_mnumber	20

long P_interval_max = DEF_INTERVAL_MAX;		//// ramdenis farglebshi ikos amocanebi
long P_interval_min = DEF_INTERVAL_MIN;		//// ramdenis farglebshi ikos amocanebi
unsigned long P_sign = DEF_SIGN;			//// tu aris 0 mashin mxolod dadebiTi ricxvebi
unsigned long P_number = DEF_mnumber;		//// magalitebis raodenoba


unsigned long correct_counter=0;
namespace con = JadedHoboConsole;
using namespace std;





int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}





int main(int argc, char** argv) {
	int i;
	long dumi_v;
	
	while(1){
	
	cout << con::fg_red << "---------------------------------------------------------------"<<endl;
	cout << con::fg_red << "---------------------------------------------------------------"<<endl;
	cout << con::fg_red << "---------------------------------------------------------------"<<endl;
	cout << con::fg_red << "---------------------------------------------------------------"<<endl<<endl<<endl;
	
	cout << con::fg_cyan << "Math starts"<<endl;	
	cout <<endl; cout <<endl;
	
	cout << "sheikvanet farglebi: "<<endl; cin >> P_interval_max;
	
	if(cin.fail()){
		cin.clear();
     	cin.ignore();
		P_interval_max = DEF_INTERVAL_MAX;
	}
	cout << "sheikvanet urkofiti ricxvebi gindat tu ara, tu ki miutitet 1 tu ara 0: "<<endl; cin >> P_sign; dumi_v = P_sign;
	
	if(cin.fail()){
		cin.clear();
     	cin.ignore();
		P_sign = DEF_SIGN;
	
	}
	
	
	if(P_sign>0){
		P_interval_min = -P_interval_max;		
	}else{
		P_interval_min = DEF_INTERVAL_MIN;
	}

	cout << "sheikvanet magalitebis raodenoba: "<<endl; cin >> P_number;
	
	if(cin.fail()){
		cin.clear();
     	cin.ignore();
		P_number = DEF_mnumber;
	}	
	cout << con::fg_yellow<< "ricxvebis farglebi: "<<P_interval_min<<"-"<<P_interval_max<<endl;
	cout << "magalitebis raodenoba: "<<P_number<<endl;
	
	if(P_sign>0){
		cout << "gamokenebuli iqneba uarkofiti ricxvebic"<<endl<<endl<<endl;
	}else{
		cout << "gamokenebuli iqneba mxolod dadebiti ricxvebi"<<endl<<endl<<endl;
	}	
	
	cout << con::fg_white<< "magalitebi: "<<endl<<endl<<endl<< con::fg_green;
	
	
	for(i=0; i<P_number; i++){
	
		switch(0){
			case 0:{
			
				long n1, n2, nn, p;
				
			
				if(random(0,20)&2)	//// mimateba
				{
					//cout<<"+"<<endl;
					n1 = random(P_interval_min, P_interval_max);
					n2 = random(P_interval_min, P_interval_max);
					
					//cout <<n1 <<" + " << n2 <<" = "<< (n1+n2)<<endl; ////////							
					cout <<n1 <<" + " << n2 <<" = "; cin >> p;
					if(p==(n1+n2)){cout<<"SCORIA";	correct_counter++;				
					}else{cout<<con::fg_red<< "SHECDOMAA, SCORI PASUXIA: "<<(n1+n2);}			
		
				}else //// gamokleba
				{
					//cout<<"-"<<endl;
					n1 = random(P_interval_min, P_interval_max);				
					n2 = random(0, P_interval_max);
					if(P_sign==0 && n2>n1){nn=n2; n2=n1; n1=nn;}	
					//cout <<n1 <<" - " << n2 <<" = "<< (n1-n2)<<endl; ////////							
					cout <<n1 <<" - " << n2 <<" = "; cin >> p;
					if(p==(n1-n2)){cout<<"SCORIA";		correct_counter++;			
					}else{cout<<con::fg_red<< "SHECDOMAA, SCORI PASUXIA: "<<(n1-n2);}			
				}
				
				cout<<endl;				
				cout<<con::fg_green;
			
				break;
			}
			default:{
			
				break;
			}
		}
	}
	
	
	cout<<endl<<endl<<endl<<endl<<con::fg_cyan;
	
	if(correct_counter>=P_number){
		cout << " K O CH A G "<<endl;
	}
	
	cout << "TQVEN SCORAD GAECIT "<<P_number<<"-dan  " << correct_counter <<"  scori pasuxi, carmatebebi"<<endl<<endl;


	cout<<endl<<endl<<endl<<endl<<con::fg_yellow;
	
		cout << con::fg_yellow<< "ricxvebis farglebi: "<<P_interval_min<<"-"<<P_interval_max<<endl;
	cout << "magalitebis raodenoba: "<<P_number<<endl;
	
	if(P_sign>0){
		cout << "gamokenebuli iqneba uarkofiti ricxvebic"<<endl<<endl<<endl;
	}else{
		cout << "gamokenebuli iqneba mxolod dadebiti ricxvebi"<<endl<<endl<<endl;
	}
	
	cout<<endl<<endl<<endl<<endl<<con::fg_yellow;
	
}

	return 0;
}
