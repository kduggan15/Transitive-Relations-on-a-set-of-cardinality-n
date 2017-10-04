//============================================================================
// Name        : trans.cpp
// Author      : Kieran Duggan
// Version     :
// Copyright   : GNU
// Description : Calculates # of transitive relations in set
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>


using namespace std;

int main()
{
	int card;//Set this to the cardinality of a set that you want to find transitive relations of.
	int temp;
	bool hasTrans;
	bool hasATrans;
	bool isTrans;
	vector<int> A;
	vector<pair<int,int> > AxA;
	vector<pair<int,int> > tempR;
	vector<vector<pair<int,int> > > R;//Relations on A
	vector<vector<pair<int,int> > > TR;//Transitive relations on A

	cout<<"Enter the number of 'n' elements in the set "<<endl;
	cin>>card;

	for(int i=1; i<=card;i++)
		A.push_back(i);

	for(unsigned int i=0; i<A.size();i++)
	{
		for(unsigned int j=0; j<A.size();j++)
		{
			AxA.push_back(pair<int,int>(i,j));
		}
	}
	//cout<<"AxA of size: "<<AxA.size()<<endl;
	int cardcard = pow(2,(card*card));
	for(int i=0; i<cardcard;i++)// This fills R with every relation on A
	{
			tempR = vector<pair<int,int> >();
			temp = i;
			for(int j=0; j<card*card; j++)
			{
				if(temp%2==0) tempR.push_back(AxA.at(j));//weird integer to bit conversion to exhaust all binary combinations
				temp/=2;
			}
			R.push_back(tempR);
			//cout<<i<<'/'<<cardcard<<" relations computed"<<endl;
	}
	cout<<"Total number of relations "<<R.size()<<endl;

	for(int i=0; i<R.size(); i++)
	{
		isTrans = true;
		for(int j=0; j<R.at(i).size(); j++)
		{
			for(int k=0; k<R.at(i).size(); k++)
			{

				if((R.at(i).at(j).second == R.at(i).at(k).first))
				{
					hasATrans = false;
					for(int m=0; m<R.at(i).size(); m++)
					{
						if((R.at(i).at(j).first == R.at(i).at(m).first) && (R.at(i).at(k).second == R.at(i).at(m).second))
						{
							hasATrans = true;
							break;
						}

					}
					if(!hasATrans)isTrans = false;;
				}
			}

		}
		if(isTrans) TR.push_back(R.at(i));
		//cout<<i<<'/'<<R.size()<<" checked"<<endl;
	}
	cout<<"For a set of cardinality "<<card<<" there are "<<TR.size()<<" transitive relations"<<endl;
	return 0;
}
















