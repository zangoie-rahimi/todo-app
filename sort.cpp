#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
int main()
{
    int n=10;
    int i,j,sat,st;
    int sal,sl;
    fstream fout;
    fout.open("output.txt");
    int dagigeh,dg;
    int rooz,rz;
    int mah,mh;
    int sanieh,sn;
    string name[n];
    string tarikh[n];
    string saat[n];
    int vaz[n];
    string t;
    for(i=0;i<n;i++)
    {
        cout<<i+1<<") name - tarikh(2021/12/12) - saat(12:20:00) ra vared konid : ";
        cin>>name[i]>>tarikh[i]>>saat[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
          if(tarikh[i]>tarikh[j])
          {
              t=tarikh[i];
              tarikh[i]=tarikh[j];
              tarikh[j]=t;

              t=saat[i];
              saat[i]=saat[j];
              saat[j]=t;

              t=name[i];
              name[i]=name[j];
              name[j]=t;
          }
          else if((tarikh[i]==tarikh[j]) && (saat[i]>saat[j]))
          {
              t=tarikh[i];
              tarikh[i]=tarikh[j];
              tarikh[j]=t;

              t=saat[i];
              saat[i]=saat[j];
              saat[j]=t;

              t=name[i];
              name[i]=name[j];
              name[j]=t;
          }
    }

    cout<<"\n-----------";
    for(i=0;i<n;i++)
     cout<<"\n"<<name[i]<<"\n"<<tarikh[i]<<"\n"<<saat[i];
    cout<<"\n-----------";
    time_t now = time(0);
    tm *ltm = localtime(&now);


    sal = 1900 + ltm->tm_year;
    mah = 1 + ltm->tm_mon ;
    rooz =  ltm->tm_mday ;
    sat = 5+ltm->tm_hour ;
    dagigeh = 30+ltm->tm_min ;
    sanieh = ltm->tm_sec ;

    for(i=0;i<n;i++)
    {
        sl=stoi(tarikh[i].substr(0,4));
        mh=stoi(tarikh[i].substr(5,2));
        rz=stoi(tarikh[i].substr(8,2));

        st=stoi(saat[i].substr(0,2));
        dg=stoi(saat[i].substr(3,2));
        sn=stoi(saat[i].substr(6,2));


        if(sl<sal) vaz[i]=0;
        else if((sl==sal) && (mh<mah)) vaz[i]=0;
        else if((sl==sal) && (mh==mah) && (rz<rooz)) vaz[i]=0;
        else if((sl==sal) && (mh==mah) && (rz==rooz) && (st<sat)) vaz[i]=0;
        else if((sl==sal) && (mh==mah) && (rz==rooz)
             && (st==sat) && (dg<dagigeh)) vaz[i]=0;
        else if((sl==sal) && (mh==mah) && (rz==rooz)
             && (st==sat) && (dg==dagigeh) && (sn<sanieh)) vaz[i]=0;
        else vaz[i]=1;
    }

    for(i=0;i<n;i++)
    {
        if(vaz[i]==0)
        {
            fout<<"\nName= "<<name[i];
            fout<<"\nTarikh= "<<tarikh[i];
            fout<<"\nSaat= "<<saat[i];
        }
    }

    fout<<"\n\n";
    for(i=0;i<n;i++)
    {
        if(vaz[i]==1)
        {
            fout<<"\nName= "<<name[i];
            fout<<"\nTarikh= "<<tarikh[i];
            fout<<"\nSaat= "<<saat[i];
        }
    }


    fout.close();


}
