/* 
 * Project akhir algortima pemerogrman
 * informatika 01 kelompok 1
 * aplikasi reservasi perkuliahan blendet
 * by
 * Yuza Nugrahadita P	  21.11.3855
 * Hafizh Mohammad Fathan 21.11.3844
 * Raden Kusuma Arya Dewa 21.11.3833
 * Ilham Putra Firmansyah 21.11.3868
 * Muhammad Rizky K		  21.11.3846
 */
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0;



class a

{

  char kelas[5], dosen[10], matkul[10], prodi[11], seat[8][4][10];
	string arrival, depart;
public:

  void install();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);
  

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::install() //bulding kelas

{
	system("cls");
cout << "---------------------------------------------------------------"<<endl;                                                             
cout << "   _|_|    _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << " _|    _|  _|_|  _|_|    _|    _|  _|    _|    _|  _|_|  _|_|  "<<endl;
cout << " _|_|_|_|  _|  _|  _|    _|    _|_|      _|    _|  _|  _|  _|  "<<endl;
cout << " _|    _|  _|      _|    _|    _|  _|    _|    _|  _|      _|  "<<endl;
cout << " _|    _|  _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout << " 	 Reservasi Untuk Perkuliahan Blended					"<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout <<endl;

  cout<<"Kelas			: "; //kelas / angkatan

  cin>>bus[p].kelas;

  cout<<"Nama dosen		: "; //dosen

  cin>>bus[p].dosen;

  cout<<"Jam mulai		: "; // jam mulai

  cin>>bus[p].arrival;

  cout<<"Jam akhir		: "; // jam akhir

  cin>>bus[p].depart;

  cout<<"Mata Kuliah		: "; // algprog

  cin>>bus[p].matkul;

  cout<<"Prodi			: "; // if o1

  cin>>bus[p].prodi;

  bus[p].empty();

  p++;

}

void a::allotment()

{
		system("cls");
cout << "---------------------------------------------------------------"<<endl;                                                             
cout << "   _|_|    _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << " _|    _|  _|_|  _|_|    _|    _|  _|    _|    _|  _|_|  _|_|  "<<endl;
cout << " _|_|_|_|  _|  _|  _|    _|    _|_|      _|    _|  _|  _|  _|  "<<endl;
cout << " _|    _|  _|      _|    _|    _|  _|    _|    _|  _|      _|  "<<endl;
cout << " _|    _|  _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout << " 	 Reservasi Untuk Perkuliahan Blended					"<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout <<endl;


  int seat;

  char number[5];

  top:

  cout<<"kelas		: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].kelas, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"Bangku ke	: ";

    cin>>seat;

    if(seat>15)

    {

      cout<<"Hanya Tersedia 15 kursi untuk kuliah blended ini";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"NIM		: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct class\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<5;i++)

  {

    for(int j=0;j<3;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"Kelas		: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].kelas, number)==0)

    break;

  }

while(n<=p)

{
	
	cout<< "----------------------------------------------------------" <<endl;
	cout<< "kelas 		: "<<bus[n].kelas                            	        <<endl;
	cout<< "Dosen 		: "<<bus[n].dosen                                      <<endl;
	cout<< "Jam	mulai 	: "<<bus[n].arrival                                     <<endl;
	cout<< "jam akhir 	: "<<bus[n].depart                                      <<endl;
	cout<< "Matkul		: "<<bus[n].matkul                                        <<endl;
	cout<< "Prodi		: "<<bus[n].prodi                                     		<<endl;
	cout<< "----------------------------------------------------------" <<endl;
	
	
	
	
///////////////////////////////////////////////////////////

  bus[0].position(n);

  int a=1;

  for (int i=0; i<5; i++)

  {

    for(int j=0;j<3;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<5;i++)

  {

    cout<<"\n";

    for (int j = 0;j<3; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in class : "<<bus[l].kelas;
  cout<<endl;

  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

   cout<< "----------------------------------------------------------" <<endl;
	cout<< "kelas 		: "<<bus[n].kelas                            	        <<endl;
	cout<< "Dosen 		: "<<bus[n].dosen                                      <<endl;
	cout<< "Jam	mulai 	: "<<bus[n].arrival                                     <<endl;
	cout<< "jam akhir 	: "<<bus[n].depart                                      <<endl;
	cout<< "Matkul		: "<<bus[n].matkul                                        <<endl;
	cout<< "Prodi		: "<<bus[n].prodi                                     		<<endl;
	cout<< "----------------------------------------------------------" <<endl;
  }

}





int main()

{

system("cls");

int w;

while(1)

{

    //system("cls");
cout << "---------------------------------------------------------------"<<endl;                                                             
cout << "   _|_|    _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << " _|    _|  _|_|  _|_|    _|    _|  _|    _|    _|  _|_|  _|_|  "<<endl;
cout << " _|_|_|_|  _|  _|  _|    _|    _|_|      _|    _|  _|  _|  _|  "<<endl;
cout << " _|    _|  _|      _|    _|    _|  _|    _|    _|  _|      _|  "<<endl;
cout << " _|    _|  _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout << " 	 Reservasi Untuk Perkuliahan Blended					"<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout <<endl;

  cout<<"1.Install"<<endl;

  cout <<"2.Reservation"<<endl;

  cout <<"3.Show"<<endl;

  //cout <<"4.Buses Available"<<endl;

  cout <<"4.Exit"<<endl;

  cout<<"Enter your choice:-> ";

  cin>>w;
  
  	system("cls");
cout << "---------------------------------------------------------------"<<endl;                                                             
cout << "   _|_|    _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << " _|    _|  _|_|  _|_|    _|    _|  _|    _|    _|  _|_|  _|_|  "<<endl;
cout << " _|_|_|_|  _|  _|  _|    _|    _|_|      _|    _|  _|  _|  _|  "<<endl;
cout << " _|    _|  _|      _|    _|    _|  _|    _|    _|  _|      _|  "<<endl;
cout << " _|    _|  _|      _|  _|_|_|  _|    _|    _|_|    _|      _|  "<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout << " 	 Reservasi Untuk Perkuliahan Blended					"<<endl;
cout << "---------------------------------------------------------------"<<endl;
cout <<endl;


  switch(w)

  {

    case 1:  bus[p].install();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    //case 4:  bus[0].avail();

   //   break;

    case 4:  exit(0);

  }
  


}

return 0;

}
